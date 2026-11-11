// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010b2a0..0x0010c0d0 (kind game, layer game, confidence high), dominant class hulkfight::ai::FaceTargetAction
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fd54d364 {
#define TREE_TU_END }
namespace fn_fd54d364 {} using namespace fn_fd54d364;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fd54d364 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_fd54d364
namespace hulkfight { namespace ai {
class FaceTargetTrack_10bc00 {
public:
    void FUN_0010b3d0();
    void FUN_0010b3e0();
};
} }
namespace fn_fd54d364 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_fd54d364
namespace fight {
template <class T>
class ParamFloatConstRange_10bc00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_10bc00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fd54d364 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_fd54d364
namespace hulkfight { namespace ai {
class FaceMotionTrack_10bca0 {
public:
    void FUN_0010b3f0();
    void FUN_0010b400();
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_10bca0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_10bca0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_fd54d364 {

// 0x0010bc00 FUN_0010bc00 (158 B): equivalent/0x0010bc00.cpp
// sym: ?FUN_0010bc00@fn_fd54d364@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_0010bc00 @ 0x0010bc00
void FUN_0010bc00()
{
    if (DAT_004e0ad4 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_10bc00<hulkfight::ai::FaceTargetTrack_10bc00>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_10bc00<hulkfight::ai::FaceTargetTrack_10bc00>("timeBegin", &hulkfight::ai::FaceTargetTrack_10bc00::FUN_0010b3d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_10bc00<hulkfight::ai::FaceTargetTrack_10bc00>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_10bc00<hulkfight::ai::FaceTargetTrack_10bc00>("timeEnd", &hulkfight::ai::FaceTargetTrack_10bc00::FUN_0010b3e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ad0), params, 2);
    }
    DAT_004e0ad4++;
}


// 0x0010bca0 FUN_0010bca0 (158 B): equivalent/0x0010bca0.cpp
// sym: ?FUN_0010bca0@fn_fd54d364@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0010bca0 @ 0x0010bca0
void FUN_0010bca0()
{
    if (DAT_004e0adc == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_10bca0<hulkfight::ai::FaceMotionTrack_10bca0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_10bca0<hulkfight::ai::FaceMotionTrack_10bca0>("timeBegin", &hulkfight::ai::FaceMotionTrack_10bca0::FUN_0010b3f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_10bca0<hulkfight::ai::FaceMotionTrack_10bca0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_10bca0<hulkfight::ai::FaceMotionTrack_10bca0>("timeEnd", &hulkfight::ai::FaceMotionTrack_10bca0::FUN_0010b400);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0ad8), params, 2);
    }
    DAT_004e0adc++;
}

} // namespace fn_fd54d364
