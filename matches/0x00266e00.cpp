#include "decls/data/engine/content.h"
#include "decls/data/engine/unknown.h"
// data: gContext = DAT_00527f68, gItems_266e00 = DAT_00527c60

class Item_266e00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Get(int);
};
struct Entry_266e00 {
    Item_266e00* p;
    char pad[12];
};
extern int(__cdecl* gCallback_266e00)(int, int, int, int);
int FUN_00266e00(int a, int b) {
    int r = ((Entry_266e00*)((char*)&DAT_00527c58 + 8))[a].p->Get(b);
    if (!r && gCallback_266e00)
        gCallback_266e00((*(int*)&DAT_00527f68), a, b, 1);
    return r;
}