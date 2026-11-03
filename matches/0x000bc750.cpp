#include "gen/global.h"
#include "gen/owners.h"
class Manager_bc750 {
  public:
    void A(int);
    void* B();
    void D(void*);
};
class Other_bc750 {
  public:
    void F(void*);
};
class Obj_bc750 {
  public:
    char pad0[0x34];
    Manager_bc750* m34;
    Other_bc750* m38;
    char pad40[0x10];
    Other_bc750* m4c;
    void End();
};
extern "C" void FUN_000fc300();
void Obj_bc750::End() {
    if (m34 && m38) {
        ((::CScenarioManager *)m38)->FUN_001cc620(9);
        m34->A(0);
        void* edi = m34->B();
        if (edi) {
            int ebx = ((int)((owners::NameTable_b4cf0 *)this)->FUN_000b4cf0((const char *)edi));
            if (ebx) {
                if (m4c)
                    m4c->F(edi);
                ((owners::LevelName_895e0 *)m34)->FUN_000895e0((const char *)(hulk_uintptr)(int)ebx);
                m34->D(edi);
                FUN_000fc300();
            }
        }
    }
}
