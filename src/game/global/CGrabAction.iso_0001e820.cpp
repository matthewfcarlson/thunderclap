// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001df20..0x0001e870 (kind game, layer game, confidence high), dominant class CGrabAction
// (tree_prelude.h: not needed)


// 0x0001e820 CGrabAction::vfunc_4 (77 B): matches/0x0001e820.cpp [isolated: conflict: FUN_001b6580; on include/gen/ and not mergeable]
// sym: ?vfunc_4@CGrabAction@@UAEXXZ
#include "gen/global.h"

class Mgr_1e820;
class Holder_1e820 {
  public:
    Holder_1e820* first_000592a0();
    Mgr_1e820* second_00059a30();
};
class Mgr_1e820 {
  public:
    char pad[0x1b64];
    void* ptr;
};
class Helper_1e820 {
  public:
    void run_001b4280(void*);
};
class Obj_1e820 {
  public:
    virtual void f0();
    virtual void f1();
};
Helper_1e820* __stdcall FUN_001b6580();

void CGrabAction::vfunc_4() {
    Mgr_1e820* m = ((Holder_1e820*)(*(void * *)&this->f_1c))->first_000592a0()->second_00059a30();
    if (m->ptr == this)
        m->ptr = 0;
    if ((*(void * *)&this->f_28)) {
        void* arg = (*(void * *)&this->f_28);
        FUN_001b6580()->run_001b4280(arg);
        Obj_1e820* q = (Obj_1e820*)(*(void * *)&this->f_28);
        if (q) {
            q->f1();
            (*(void * *)&this->f_28) = 0;
        }
    }
}

