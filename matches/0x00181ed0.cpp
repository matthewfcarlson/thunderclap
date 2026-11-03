#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

class Model_181ed0 {
  public:
    char pad[0x128];
    void* field;
    void Apply(void*, void*);
};
class Actor_181ed0 {
  public:
    virtual void* A();
    virtual void* B();
    virtual void* C();
    virtual void* D();
    Model_181ed0* ModelFor();
};
struct Vec_181ed0 {
    int a, b, c;
};

bool hulkfight::motion::PropActorThinkingAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    Actor_181ed0* x = (*(Actor_181ed0 * *)&this->f_20);
    Actor_181ed0* y = ((Actor_181ed0 *)((owners::Object_592a0 *)x)->FUN_000592a0());
    Model_181ed0* m = y->ModelFor();
    unsigned char v = *((unsigned char*)(*(Actor_181ed0 * *)&this->f_1c) + 0x10);
    ((owners::Obj_373c0 *)m)->FUN_000373c0(v);
    if (!v) {
        void* p = *((void**)((char*)m + 0x128));
        if (p) {
            void* q = (*(Actor_181ed0 * *)&this->f_20)->D();
            if (q) {
                Vec_181ed0 t = *((Vec_181ed0*)((char*)q + 0x38));
                ((Model_181ed0*)p)->Apply(&t, (char*)q + 8);
            }
        }
    }
    return true;
}
