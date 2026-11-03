#include "gen/owners.h"
struct Cell {
    char pad[8];
};
class Obj {
  public:
    char pad[0xc];
    char flag;
    char rest[0x2f8 - 0xd];
    Cell cells[12];
    bool Fn(int a, int b, int c, int d);
};
bool Obj::Fn(int a, int b, int c, int d) {
    if (a < 0 || a >= 2 || b < 0 || b >= 2 || c < 0 || c >= 3)
        return false;
    ((owners::Target_b10a0 *)&(cells[(a * 2 + b) * 3 + c]))->FUN_000b10a0(0, (const void *)(hulk_uintptr)(int)d);
    flag = 1;
    return true;
}