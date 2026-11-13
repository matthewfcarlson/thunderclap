// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001399d0..0x0013e810 (kind game, layer game, confidence high), dominant class hulkfight::motion::AnimationVelocityScaledAction
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fa36bb23 {
#define TREE_TU_END }
namespace fn_fa36bb23 {} using namespace fn_fa36bb23;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fa36bb23 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_fa36bb23
namespace hulkfight { namespace motion {
class FrameReachedCondition_13c460 {
public:
    void FUN_001399d0();
    char FUN_001399e0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_fa36bb23 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_fa36bb23
namespace fight {
template <class T>
class ParamFloatConstRange_13c460 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_13c460(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_13c460 : public ParamNameBase {
public:
    ParamName_13c460(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa36bb23 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_fa36bb23
namespace hulkfight { namespace motion {
class AnimationTrack_13c650 {
public:
    bool FUN_00139a30(int); /* (unb4) as defined; address taken only */
    char FUN_00139a40(int); /* (unb4) as defined; address taken only */
    void FUN_00139a50();
    bool FUN_00139a70(int); /* (unb4) as defined; address taken only */
    bool FUN_00139a90(int); /* (unb4) as defined; address taken only */
    bool FUN_00139ab0(int); /* (unb4) as defined; address taken only */
    char FUN_00139ad0(int); /* (unb4) as defined; address taken only */
    char FUN_00139af0(int); /* (unb4) as defined; address taken only */
    char FUN_00139b10(char); /* (unb4) as defined; address taken only */
    void FUN_00139b20();
    char FUN_00139b40(int); /* (unb4) as defined; address taken only */
    char FUN_00139b60(int); /* (unb4) as defined; address taken only */
    bool FUN_00139b80(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_fa36bb23 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_fa36bb23
namespace fight {
template <class T>
class ParamBool_13c650 : public ParamBoolBase {
public:
    ParamBool_13c650(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_13c650 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_13c650(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_13c650 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_13c650(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_13c650 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_13c650(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_13c650 : public ParamNameBase {
public:
    ParamName_13c650(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa36bb23 {
class AnimationChargeTrack {
public:
    char FUN_00139b90(int); /* (unb4) as defined; address taken only */
    char FUN_00139ba0(int); /* (unb4) as defined; address taken only */
    void FUN_00139bb0();
    bool FUN_00139bd0(int); /* (unb4) as defined; address taken only */
    bool FUN_00139bf0(int); /* (unb4) as defined; address taken only */
    void FUN_00139c00();
    bool FUN_00139c20(int); /* (unb4) as defined; address taken only */
    char FUN_00139c40(int); /* (unb4) as defined; address taken only */
    char FUN_00139c60(int); /* (unb4) as defined; address taken only */
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamStringNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamStringNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
template <class T>
class ParamStringName : public ParamStringNameBase {
public:
    ParamStringName(const char* name, void (T::*s)()) : ParamStringNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class AnimationLinkedTrack {
public:
    bool FUN_00139c70(int); /* (unb4) as defined; address taken only */
    char FUN_00139c80(int); /* (unb4) as defined; address taken only */
    void FUN_00139c90();
    bool FUN_00139cb0(int); /* (unb4) as defined; address taken only */
    char FUN_00139cd0(int); /* (unb4) as defined; address taken only */
    bool FUN_00139cf0(int); /* (unb4) as defined; address taken only */
    void FUN_00139d00();
    bool FUN_00139d20(int); /* (unb4) as defined; address taken only */
    char FUN_00139d40(int); /* (unb4) as defined; address taken only */
    bool FUN_00139d60(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_fa36bb23
namespace fight {
template <class T>
class ParamFloatConstRange_13cb90 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_13cb90(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_13cb90 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_13cb90(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_13cb90 : public ParamNameBase {
public:
    ParamName_13cb90(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fa36bb23 {
class AnimationPhaseMatchedTrack {
public:
    char FUN_00139d70(int); /* (unb4) as defined; address taken only */
    char FUN_00139d80(int); /* (unb4) as defined; address taken only */
    void FUN_00139d90();
    char FUN_00139db0(int); /* (unb4) as defined; address taken only */
    char FUN_00139dd0(int); /* (unb4) as defined; address taken only */
    char FUN_00139df0(int); /* (unb4) as defined; address taken only */
    void FUN_00139e00();
    bool FUN_00139e20(int); /* (unb4) as defined; address taken only */
    bool FUN_00139e40(int); /* (unb4) as defined; address taken only */
    char FUN_00139e60(int); /* (unb4) as defined; address taken only */
};
} // namespace fn_fa36bb23
namespace fight {
template <class T>
class ParamFloatConstRange_13ce00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_13ce00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_13ce00 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_13ce00(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_13ce00 : public ParamNameBase {
public:
    ParamName_13ce00(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace motion {
class AnimationVelocityScaledTrack_13d070 {
public:
    char FUN_00139e70(int); /* (unb4) as defined; address taken only */
    bool FUN_00139e80(int); /* (unb4) as defined; address taken only */
    void FUN_00139e90();
    bool FUN_00139eb0(int); /* (unb4) as defined; address taken only */
    bool FUN_00139ec0(int); /* (unb4) as defined; address taken only */
    bool FUN_00139ee0(int); /* (unb4) as defined; address taken only */
    bool FUN_00139f00(int); /* (unb4) as defined; address taken only */
    char FUN_00139f20(void*); /* (unb4) as defined; address taken only */
    bool FUN_00139f40(int); /* (unb4) as defined; address taken only */
    bool FUN_00139f60(int); /* (unb4) as defined; address taken only */
    char FUN_00139f80(int); /* (unb4) as defined; address taken only */
    void FUN_00139f90();
    char FUN_00139fb0(int); /* (unb4) as defined; address taken only */
    bool FUN_00139fd0(int); /* (unb4) as defined; address taken only */
    char FUN_00139ff0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamEnumConstList_13d070 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_13d070(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_13d070 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_13d070(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_13d070 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_13d070(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_13d070 : public ParamNameBase {
public:
    ParamName_13d070(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_fa36bb23 {

// 0x0013c460 FUN_0013c460 (158 B): equivalent/0x0013c460.cpp
// sym: ?FUN_0013c460@fn_fa36bb23@@YAXXZ @c78259b1179e @weeec078a2fbb
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0013c460 @ 0x0013c460
void FUN_0013c460()
{
    if (DAT_004e0f0c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13c460<hulkfight::motion::FrameReachedCondition_13c460>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName_13c460<hulkfight::motion::FrameReachedCondition_13c460>("animation", &hulkfight::motion::FrameReachedCondition_13c460::FUN_001399d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c460<hulkfight::motion::FrameReachedCondition_13c460>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_13c460<hulkfight::motion::FrameReachedCondition_13c460>("frame", (void (hulkfight::motion::FrameReachedCondition_13c460::*)())&hulkfight::motion::FrameReachedCondition_13c460::FUN_001399e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f08), params, 2);
    }
    DAT_004e0f0c++;
}


// 0x0013c650 FUN_0013c650 (729 B): equivalent/0x0013c650.cpp
// sym: ?FUN_0013c650@fn_fa36bb23@@YAXXZ @a1a31b6d37f9 @w7774472863ee
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 28/28)
// FUN_0013c650 @ 0x0013c650
void FUN_0013c650()
{
    if (DAT_004e0f1c == 0) {
        void* params[13];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("timeBegin", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139a30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("timeEnd", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139a40);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_13c650<hulkfight::motion::AnimationTrack_13c650>("animation", &hulkfight::motion::AnimationTrack_13c650::FUN_00139a50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("speed", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139a70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("initFrame", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139a90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("startFrame", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139ab0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("endFrame", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139ad0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamEnumConstList_13c650<hulkfight::motion::AnimationTrack_13c650>("cyclic", ((const char**)&DAT_004abf70), 4, (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139af0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool_13c650<hulkfight::motion::AnimationTrack_13c650>("rootMotion", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139b10);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamName_13c650<hulkfight::motion::AnimationTrack_13c650>("partition", &hulkfight::motion::AnimationTrack_13c650::FUN_00139b20);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamIntConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("priority", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139b40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("blendInTime", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139b60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_13c650<hulkfight::motion::AnimationTrack_13c650>("blendOutTime", (void (hulkfight::motion::AnimationTrack_13c650::*)())&hulkfight::motion::AnimationTrack_13c650::FUN_00139b80);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f18), params, 13);
    }
    DAT_004e0f1c++;
}


// 0x0013c960 FUN_0013c960 (511 B): equivalent/0x0013c960.cpp
// sym: ?FUN_0013c960@fn_fa36bb23@@YAXXZ @10221a80dfa7 @wd93e50fa43c5
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 20/20)
// FUN_0013c960 @ 0x0013c960
void FUN_0013c960()
{
    if (DAT_004e0f24 == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AnimationChargeTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("timeBegin", (void (AnimationChargeTrack::*)())&AnimationChargeTrack::FUN_00139b90);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AnimationChargeTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("timeEnd", (void (AnimationChargeTrack::*)())&AnimationChargeTrack::FUN_00139ba0);
        mem = FUN_0008d690((int)sizeof(ParamStringName<AnimationChargeTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamStringName<AnimationChargeTrack>("animation", &AnimationChargeTrack::FUN_00139bb0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AnimationChargeTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("startFrame", (void (AnimationChargeTrack::*)())&AnimationChargeTrack::FUN_00139bd0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AnimationChargeTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("endFrame", (void (AnimationChargeTrack::*)())&AnimationChargeTrack::FUN_00139bf0);
        mem = FUN_0008d690((int)sizeof(ParamStringName<AnimationChargeTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamStringName<AnimationChargeTrack>("partition", &AnimationChargeTrack::FUN_00139c00);
        mem = FUN_0008d690((int)sizeof(ParamIntConstRange<AnimationChargeTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamIntConstRange<AnimationChargeTrack>("priority", (void (AnimationChargeTrack::*)())&AnimationChargeTrack::FUN_00139c20);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AnimationChargeTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("blendInTime", (void (AnimationChargeTrack::*)())&AnimationChargeTrack::FUN_00139c40);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<AnimationChargeTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<AnimationChargeTrack>("blendOutTime", (void (AnimationChargeTrack::*)())&AnimationChargeTrack::FUN_00139c60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f20), params, 9);
    }
    DAT_004e0f24++;
}


// 0x0013cb90 FUN_0013cb90 (562 B): equivalent/0x0013cb90.cpp
// sym: ?FUN_0013cb90@fn_fa36bb23@@YAXXZ @ab2a9344d73d @w0284d71f34e7
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 22/22)
// FUN_0013cb90 @ 0x0013cb90
void FUN_0013cb90()
{
    if (DAT_004e0f2c == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>("timeBegin", (void (AnimationLinkedTrack::*)())&AnimationLinkedTrack::FUN_00139c70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>("timeEnd", (void (AnimationLinkedTrack::*)())&AnimationLinkedTrack::FUN_00139c80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13cb90<AnimationLinkedTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_13cb90<AnimationLinkedTrack>("animation", &AnimationLinkedTrack::FUN_00139c90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>("speed", (void (AnimationLinkedTrack::*)())&AnimationLinkedTrack::FUN_00139cb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>("startFrame", (void (AnimationLinkedTrack::*)())&AnimationLinkedTrack::FUN_00139cd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>("endFrame", (void (AnimationLinkedTrack::*)())&AnimationLinkedTrack::FUN_00139cf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13cb90<AnimationLinkedTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName_13cb90<AnimationLinkedTrack>("partition", &AnimationLinkedTrack::FUN_00139d00);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_13cb90<AnimationLinkedTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_13cb90<AnimationLinkedTrack>("priority", (void (AnimationLinkedTrack::*)())&AnimationLinkedTrack::FUN_00139d20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>("blendInTime", (void (AnimationLinkedTrack::*)())&AnimationLinkedTrack::FUN_00139d40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_13cb90<AnimationLinkedTrack>("blendOutTime", (void (AnimationLinkedTrack::*)())&AnimationLinkedTrack::FUN_00139d60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f28), params, 10);
    }
    DAT_004e0f2c++;
}


// 0x0013ce00 FUN_0013ce00 (562 B): equivalent/0x0013ce00.cpp
// sym: ?FUN_0013ce00@fn_fa36bb23@@YAXXZ @986a276307f3 @w4ec1d71ccd32
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 22/22)
// FUN_0013ce00 @ 0x0013ce00
void FUN_0013ce00()
{
    if (DAT_004e0f34 == 0) {
        void* params[10];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>("timeBegin", (void (AnimationPhaseMatchedTrack::*)())&AnimationPhaseMatchedTrack::FUN_00139d70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>("timeEnd", (void (AnimationPhaseMatchedTrack::*)())&AnimationPhaseMatchedTrack::FUN_00139d80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13ce00<AnimationPhaseMatchedTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_13ce00<AnimationPhaseMatchedTrack>("animation", &AnimationPhaseMatchedTrack::FUN_00139d90);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>("syncFrame", (void (AnimationPhaseMatchedTrack::*)())&AnimationPhaseMatchedTrack::FUN_00139db0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>("startFrame", (void (AnimationPhaseMatchedTrack::*)())&AnimationPhaseMatchedTrack::FUN_00139dd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>("endFrame", (void (AnimationPhaseMatchedTrack::*)())&AnimationPhaseMatchedTrack::FUN_00139df0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13ce00<AnimationPhaseMatchedTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName_13ce00<AnimationPhaseMatchedTrack>("partition", &AnimationPhaseMatchedTrack::FUN_00139e00);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_13ce00<AnimationPhaseMatchedTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamIntConstRange_13ce00<AnimationPhaseMatchedTrack>("priority", (void (AnimationPhaseMatchedTrack::*)())&AnimationPhaseMatchedTrack::FUN_00139e20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>("blendInTime", (void (AnimationPhaseMatchedTrack::*)())&AnimationPhaseMatchedTrack::FUN_00139e40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_13ce00<AnimationPhaseMatchedTrack>("blendOutTime", (void (AnimationPhaseMatchedTrack::*)())&AnimationPhaseMatchedTrack::FUN_00139e60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f30), params, 10);
    }
    DAT_004e0f34++;
}


// 0x0013d070 FUN_0013d070 (845 B): equivalent/0x0013d070.cpp
// sym: ?FUN_0013d070@fn_fa36bb23@@YAXXZ @777671afcf75 @w2260005948db
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/32)
// FUN_0013d070 @ 0x0013d070
void FUN_0013d070()
{
    if (DAT_004e0f3c == 0) {
        void* params[15];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("timeBegin", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("timeEnd", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139e80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("animation", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139e90);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamEnumConstList_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("velocity", ((const char**)&DAT_004abf80), 6, (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139eb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("scale", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139ec0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("speedMin", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139ee0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("speedMax", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("initFrame", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("startFrame", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("endFrame", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f60);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamEnumConstList_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("cyclic", ((const char**)&DAT_004abf70), 4, (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f80);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("partition", &hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139f90);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamIntConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("priority", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139fb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("blendInTime", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139fd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_13d070<hulkfight::motion::AnimationVelocityScaledTrack_13d070>("blendOutTime", (void (hulkfight::motion::AnimationVelocityScaledTrack_13d070::*)())&hulkfight::motion::AnimationVelocityScaledTrack_13d070::FUN_00139ff0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0f38), params, 15);
    }
    DAT_004e0f3c++;
}

} // namespace fn_fa36bb23
