#include "decls/data/engine/content.h"
#include "decls/data/engine/core.h"
#include "decls/data/engine/unknown.h"
// data: tbl = DAT_00527c60

struct Ent_267280 {
    void* p;
    int a, b, c;
};
extern void* vt_267280;
extern char Vftable[];
extern void InitA();
extern void InitB();
extern void Tail();
void Target() {
    (*(unsigned char*)&DAT_00527f5c) = 1;
    InitA();
    (*(void**)&DAT_00527f50) = Vftable;
    InitB();
    (*(void**)&DAT_00527f58) = ((void**)&DAT_00527f50);
    (*(void**)&DAT_00527f40) = ((void**)&DAT_00527f50);
    (*(int*)&DAT_00527f44) = 0;
    (*(int*)&DAT_00527f48) = 0;
    (*(int*)&DAT_00527f4c) = 0;
    unsigned i = 0;
    do {
        Ent_267280* e = (Ent_267280*)((char*)((Ent_267280*)((char*)&DAT_00527c58 + 8)) + i);
        e->a = 0;
        e->c = 0;
        e->b = 0;
        e->p = ((void**)&DAT_00527f50);
        i += 0x10;
    } while (i < 0x2e0);
    Tail();
}
