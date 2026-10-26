#include "decls/data/game/global.h"
// data: scale = DAT_003ffaa4

class Clock {
    char pad[16];

  public:
    unsigned __int64 count;
    double Get();
};
double Clock::Get() {
    return (double)count * DAT_003ffaa4;
}