#include "gen/global.h"

class Mgr_1e820;
class Holder_1e820 {
  public:
    Holder_1e820* first();
    Mgr_1e820* second();
};
class Mgr_1e820 {
  public:
    char pad[0x1b64];
    void* ptr;
};
class Helper_1e820 {
  public:
    void run();
};
class Obj_1e820 {
  public:
    virtual void f0();
    virtual void f1();
};
Helper_1e820* __stdcall FUN_001b6580(void*);

void CGrabAction::vfunc_4() {
    Mgr_1e820* m = ((Holder_1e820*)(*(void * *)&this->f_1c))->first()->second();
    if (m->ptr == this)
        m->ptr = 0;
    if ((*(void * *)&this->f_28)) {
        FUN_001b6580((*(void * *)&this->f_28))->run();
        Obj_1e820* q = (Obj_1e820*)(*(void * *)&this->f_28);
        if (q) {
            q->f1();
            (*(void * *)&this->f_28) = 0;
        }
    }
}
