#include "decls/data/game/global.h"
// data: scale = DAT_003ffaa4

class Counter {
  public:
    char pad[0x20];
    unsigned __int64 value;
    double Get();
};
double Counter::Get() {
    return (double)value * DAT_003ffaa4;
}