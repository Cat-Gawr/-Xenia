#ifndef XENIA_DISCORD_DISCORD_PRESENCE_H_
#define XENIA_DISCORD_DISCORD_PRESENCE_H_

#include <string>

namespace xe {
namespace discord {

class DiscordPresence {
 public:
  static void Initialize();
  static void NotPlaying();
  static void PlayingTitle(const std::string_view game_title);
  static void Shutdown();
};

}  // namespace discord
}  // namespace xe

#endif  // XENIA_DISCORD_DISCORD_PRESENCE_H_
