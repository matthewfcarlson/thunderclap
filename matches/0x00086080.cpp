#include "decls/data/game/global.h"
// data: scale = DAT_003ffaa4

class Obj {
  public:
    char pad[24];
    unsigned __int64 ticks;
    double Get();
};
double Obj::Get() {
    return (double)ticks * DAT_003ffaa4;
}