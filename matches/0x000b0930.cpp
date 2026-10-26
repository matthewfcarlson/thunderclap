#include "decls/data/game/global.h"
// data: zeroValue_b0930 = DAT_003f335c

struct Entry_b0930 {
    int count;
    void* ptr;
};
class Obj_b0930 {
  public:
    char pad[0x290];
    Entry_b0930 entries[13];
    void* Get(int a, int b);
};
void* Obj_b0930::Get(int a, int b) {
    if (a < 0 || a >= 13)
        return ((float*)&DAT_003f335c);
    if (b >= 0 && b < entries[a].count)
        return (char*)entries[a].ptr + b * 32;
    return ((float*)&DAT_003f335c);
}