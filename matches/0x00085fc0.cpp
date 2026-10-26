#include "decls/data/game/global.h"
// data: scale = DAT_003ffaa4

class Timer {
  public:
    char pad[0x28];
    unsigned __int64 ticks;
    double GetTime();
};
double Timer::GetTime() {
    return (double)ticks * DAT_003ffaa4;
}