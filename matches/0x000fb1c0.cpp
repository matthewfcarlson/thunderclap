#include "decls/data/game/global.h"
// data: inventory = DAT_004dd9cc

#include "compat/ptr.h"
extern "C" __int64 FUN_0027b020(hulk_intptr);
struct DynamicCaster_fb1c0 {
    virtual void cast();
};
struct Inventory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int get(DynamicCaster_fb1c0*, __int64);
    virtual void d();
    virtual void use(int);
};
inline int find(Inventory* inv, __int64 key) {
    DynamicCaster_fb1c0 caster;
    return inv->get(&caster, key);
}
char FUN_000fb1c0(int id) {
    char result = 0;
    __int64 key = FUN_0027b020(id);
    int item = find((*(Inventory**)&DAT_004dd9cc), key);
    if (item) {
        (*(Inventory**)&DAT_004dd9cc)->use(item);
        result = 1;
    }
    return result;
}