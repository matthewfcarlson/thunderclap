#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

class D {
  public:
    void Init(hulk_intptr, hulk_intptr, hulk_intptr, hulk_intptr, hulk_intptr, int, int, int);
};
class C_bf260 {
  public:
    char p[16];
    int state;
    char q[28];
    int m30, m34;
    void Next();
};
extern D* __stdcall Make();
void __fastcall Target(C_bf260* self) {
    if (self->m34 && self->m30) {
        Make()->Init(((hulk_intptr)((char*)&DAT_0040914c)), ((hulk_intptr)((char*)&DAT_0040915c)), ((hulk_intptr)((char*)&DAT_003f335c)), ((hulk_intptr)((char*)&DAT_00408ee8)), ((hulk_intptr)((char*)&DAT_00408fa0)), 2, 0, 0);
        self->state = 0x13;
        self->Next();
    }
}
