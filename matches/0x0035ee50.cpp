#include "decls/data/game/global.h"
// data: entries = DAT_004e37b8 (264 entries of three 8-byte objects built by 0x0027af00)

class Item_35ee50 {
    char data[4];

  public:
    void FUN_0027af00();
};
struct Entry_35ee50 {
    Item_35ee50 a;
    char pad0[4];
    Item_35ee50 b;
    char pad1[4];
    Item_35ee50 c;
    char pad2[12];
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_003640f0();
void __cdecl FUN_0035ee50() {
    Entry_35ee50* p = (Entry_35ee50*)DAT_004e37b8;
    for (int i = 264; i; --i, ++p) {
        p->a.FUN_0027af00();
        p->b.FUN_0027af00();
        p->c.FUN_0027af00();
    }
    atexit(FUN_003640f0);
}
