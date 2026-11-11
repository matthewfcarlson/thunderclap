// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b020..0x0017b0c0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::MotionStateAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fd31ee0f {
#define TREE_TU_END }
namespace fn_fd31ee0f {} using namespace fn_fd31ee0f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fd31ee0f {
class Params_17b020 {
  public:
    int x;
};
extern Params_17b020 hulk_at_00494b44;
extern Params_17b020 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_17b020*, Params_17b020*, int);
class Object_17b020 {
  public:
    int Init_00173380(hulkfight::motion::MotionStateTrack*, hulk_intptr);
};
extern "C" Object_17b020* __cdecl FUN_0008d690(int);
struct RefCounted_17b070 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_00417dd4[];
class MotionStateAction_17b070 {
  public:
    MotionStateAction_17b070* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17b070* m_20;
};

} // namespace fn_fd31ee0f

// 0x0017b020 hulkfight::motion::MotionStateTrack::vfunc_10 (70 B): matches/0x0017b020.cpp
// sym: ?vfunc_10@MotionStateTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MotionStateTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        Object_17b020* p = FUN_0008d690(0x24);
        if (p)
            return p->Init_00173380(this, c);
    }
    return 0;
}

namespace fn_fd31ee0f {

// 0x0017b070 hulkfight::motion::MotionStateAction::vfunc_2 (71 B): matches/0x0017b070.cpp
// sym: ?vfunc_2@MotionStateAction_17b070@fn_fd31ee0f@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
MotionStateAction_17b070* MotionStateAction_17b070::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_00417dd4;
    RefCounted_17b070* q = *(RefCounted_17b070* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}

} // namespace fn_fd31ee0f
