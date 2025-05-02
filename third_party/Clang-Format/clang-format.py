# ------------- Konata 2025 -------------
# copyright 2025


from __future__ import print_function

import difflib
import json
import platform
import subprocess
import sys
import vim

# set g:clang_format_path to the path to clang-format if it is not on the path
# Change this to the full path if clang-format is not on the path.
binary = 'clang-format'
if vim.eval('exists("g:clang_format_path")') == "1":
  binary = vim.eval('g:clang_format_path')

# Change this to format according to other formatting styles. See the output of
# 'clang-format --help' for a list of supported styles. The default looks for
# a '.clang-format' or '_clang-format' file to indicate the style that should be
# used.
style = 'file'
fallback_style = None
if vim.eval('exists("g:clang_format_fallback_style")') == "1":
  fallback_style = vim.eval('g:clang_format_fallback_style')

def get_buffer(encoding):
  if platform.python_version_tuple()[0] == '3':
    return vim.current.buffer
  return [ line.decode(encoding) for line in vim.current.buffer ]

def main():
  # Get the current text.
  encoding = vim.eval("&encoding")
  buf = get_buffer(encoding)
  text = '\n'.join(buf)

  # Determine range to format.
  if vim.eval('exists("l:lines")') == '1':
    lines = vim.eval('l:lines')
  elif vim.eval('exists("l:formatdiff")') == '1':
    with open(vim.current.buffer.name, 'r') as f:
      ondisk = f.read().splitlines();
    sequence = difflib.SequenceMatcher(None, ondisk, vim.current.buffer)
    lines = []
    for op in reversed(sequence.get_opcodes()):
      if op[0] not in ['equal', 'delete']:
        lines += ['-lines', '%s:%s' % (op[3] + 1, op[4])]
    if lines == []:
      return
  else:
    lines = ['-lines', '%s:%s' % (vim.current.range.start + 1,
                                  vim.current.range.end + 1)]

  # Determine the cursor position.
  cursor = int(vim.eval('line2byte(line("."))+col(".")')) - 2
  if cursor < 0:
    print('Couldn\'t determine cursor position. Is your file empty?')
    return

  # Avoid flashing an ugly, ugly cmd prompt on Windows when invoking clang-format.
  startupinfo = None
  if sys.platform.startswith('win32'):
    startupinfo = subprocess.STARTUPINFO()
    startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    startupinfo.wShowWindow = subprocess.SW_HIDE

  # Call formatter.
  command = [binary, '-style', style, '-cursor', str(cursor)]
  if lines != 'all':
    command += lines
  if fallback_style:
    command.extend(['-fallback-style', fallback_style])
  if vim.current.buffer.name:
    command.extend(['-assume-filename', vim.current.buffer.name])
  p = subprocess.Popen(command,
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                       stdin=subprocess.PIPE, startupinfo=startupinfo)
  stdout, stderr = p.communicate(input=text.encode(encoding))

  # If successful, replace buffer contents.
  if stderr:
    print(stderr)

  if not stdout:
    print(
        'No output from clang-format (crashed?).\n'
        'Please report to bugs.llvm.org.'
    )
  else:
    lines = stdout.decode(encoding).split('\n')
    output = json.loads(lines[0])
    lines = lines[1:]
    sequence = difflib.SequenceMatcher(None, buf, lines)
    for op in reversed(sequence.get_opcodes()):
      if op[0] is not 'equal':
        vim.current.buffer[op[1]:op[2]] = lines[op[3]:op[4]]
    if output.get('IncompleteFormat'):
      print('clang-format: incomplete (syntax errors)')
    vim.command('goto %d' % (output['Cursor'] + 1))

main()
