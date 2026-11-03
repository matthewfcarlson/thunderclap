#include "decls/data/game/global.h"
// data: gInfo = DAT_0048e100
#include "gen/owners.h"

void* operator new(unsigned int) throw();
struct Info_1bb690 {};
char GetFlag(Info_1bb690*) throw();
struct Function_1bb690 {
    Function_1bb690(void* h, int z) throw();
    virtual void Run();
    char pad[0x14];
};
struct Method0_1bb690 : Function_1bb690 {
    char f;
    int a;
    int b;
    Method0_1bb690(void* h, int y, int x) throw() : Function_1bb690(h, 0) {
        a = y;
        f = GetFlag(((Info_1bb690*)&DAT_0048e100));
        b = x;
    }
};
struct Closure0_1bb690 : Method0_1bb690 {
    virtual void Run();
    Closure0_1bb690(void* h, int y, int x) throw() : Method0_1bb690(h, y, x) {}
};
struct Owner_1bb690 {
    void Make(void* h, int x, int y);
};
void Owner_1bb690::Make(void* h, int x, int y) {
    Closure0_1bb690* c = new Closure0_1bb690(h, y, x);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)h, (hulk_intptr)(Method0_1bb690 *)c);
}