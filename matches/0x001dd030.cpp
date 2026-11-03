#include "gen/owners.h"
struct Entry {
    char pad[8];
};
class Obj {
    char pad[0x1e840];
    Entry entries[128];

  public:
    void Fn(int a, int b, int v);
};
void Obj::Fn(int a, int b, int v) {
    if (a < 4 && b < 32) {
        if (b == -1) {
            for (int i = 0; i < 32; i++)
                ((owners::Target_27b040 *)&(entries[a * 32 + i]))->FUN_0027b040((hulk_uintptr)v);
        } else
            ((owners::Target_27b040 *)&(entries[a * 32 + b]))->FUN_0027b040((hulk_uintptr)v);
    }
}