#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" char DAT_00424398[];
extern "C" char Read(int*);
class Obj_1edcf0 {
  public:
    void Init(char*, int);
    Obj_1edcf0* Fn(char*, int);
};
struct Layout_1edcf0 {
    void* v;
    char pad04[0x0c];
    char b10, b11, b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int m1c;
};
Obj_1edcf0* Obj_1edcf0::Fn(char* p, int x) {
    Layout_1edcf0* s = (Layout_1edcf0*)this;
    Init(p, 3);
    s->v = (void*)((hulk_intptr)DAT_00424398);
    s->m1c = x;
    s->b18 = Read((int*)((hulk_intptr)((char*)&DAT_0048e100)));
    s->b10 = Read((int*)((hulk_intptr)((char*)&DAT_0049cad8)));
    s->b11 = Read((int*)((hulk_intptr)((char*)&DAT_0049cad8)));
    s->b12 = Read((int*)((hulk_intptr)((char*)&DAT_0049cad8)));
    return this;
}