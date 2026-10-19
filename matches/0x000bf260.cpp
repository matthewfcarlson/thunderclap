#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

class D {
  public:
    void Init(int, int, int, int, int, int, int, int);
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
        Make()->Init(((int)((char*)&DAT_0040914c)), ((int)((char*)&DAT_0040915c)), ((int)((char*)&DAT_003f335c)), ((int)((char*)&DAT_00408ee8)), ((int)((char*)&DAT_00408fa0)), 2, 0, 0);
        self->state = 0x13;
        self->Next();
    }
}
