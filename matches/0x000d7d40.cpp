#include "gen/owners.h"
class Thing_d7d40 {
    char pad[0x30];

  public:
    char a;
    char pad2[7];
    char b;
    Thing_d7d40* Init();
};
Thing_d7d40* Thing_d7d40::Init() {
    ((owners::State_f7930 *)this)->FUN_000f7930();
    a = 0;
    b = 0;
    return this;
}