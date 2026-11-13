// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018ecb0..0x00192030 (kind game, layer game, confidence high), dominant class hulkfight::motion::TankLocomotionAction
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fca9d983 {
#define TREE_TU_END }
namespace fn_fca9d983 {} using namespace fn_fca9d983;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fca9d983 {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_fca9d983
namespace hulkfight { namespace motion {
class SimulationTrack_1910d0 {
public:
    char FUN_0018edd0(int); /* (unb4) as defined; address taken only */
    bool FUN_0018ede0(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_fca9d983 {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_fca9d983
namespace fight {
template <class T>
class ParamFloatConstRange_1910d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1910d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fca9d983 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_fca9d983
namespace hulkfight { namespace motion {
class TankLocomotionTrack_191170 {
public:
    char FUN_0018edf0(int); /* (unb4) as defined; address taken only */
    bool FUN_0018ee00(int); /* (unb4) as defined; address taken only */
    bool FUN_0018ee20(int); /* (unb4) as defined; address taken only */
    bool FUN_0018ee40(int); /* (unb4) as defined; address taken only */
    bool FUN_0018ee60(int); /* (unb4) as defined; address taken only */
    bool FUN_0018ee80(void*); /* (unb4) as defined; address taken only */
    char FUN_0018eea0(float); /* (unb4) as defined; address taken only */
    bool FUN_0018eed0(float); /* (unb4) as defined; address taken only */
    bool FUN_0018ef00(int); /* (unb4) as defined; address taken only */
    char FUN_0018ef20(int); /* (unb4) as defined; address taken only */
    bool FUN_0018ef50(void*); /* (unb4) as defined; address taken only */
    char FUN_0018ef80(int); /* (unb4) as defined; address taken only */
    bool FUN_0018efa0(int); /* (unb4) as defined; address taken only */
    bool FUN_0018efc0(int); /* (unb4) as defined; address taken only */
    char FUN_0018efe0(int); /* (unb4) as defined; address taken only */
    bool FUN_0018f000(float); /* (unb4) as defined; address taken only */
    char FUN_0018f030(float); /* (unb4) as defined; address taken only */
    bool FUN_0018f060(int); /* (unb4) as defined; address taken only */
    char FUN_0018f080(int); /* (unb4) as defined; address taken only */
    bool FUN_0018f0a0(int); /* (unb4) as defined; address taken only */
    char FUN_0018f0c0(int); /* (unb4) as defined; address taken only */
    char FUN_0018f0e0(int); /* (unb4) as defined; address taken only */
    bool FUN_0018f100(int); /* (unb4) as defined; address taken only */
    bool FUN_0018f120(int); /* (unb4) as defined; address taken only */
};
} }
namespace fight {
template <class T>
class ParamFloatConstRange_191170 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_191170(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_191170 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_191170(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_191170 : public ParamVectorBase {
public:
    ParamVector_191170(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fca9d983 {
class ImpulseVelocityTrack {
public:
    char FUN_0018ecb0(int); /* (unb4) as defined; address taken only */
    void FUN_0018ecc0();
    bool FUN_0018ecf0(void*); /* (unb4) as defined; address taken only */
    char FUN_0018ed30(void*); /* (unb4) as defined; address taken only */
    bool FUN_0018ed70(void*); /* (unb4) as defined; address taken only */
    char FUN_0018eda0(char); /* (unb4) as defined; address taken only */
    bool FUN_0018edc0(int); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};


// 0x001910d0 FUN_001910d0 (158 B): equivalent/0x001910d0.cpp
// sym: ?FUN_001910d0@fn_fca9d983@@YAXXZ @ce5235d6f544 @w4541e7fd2b9a
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_001910d0 @ 0x001910d0
void FUN_001910d0()
{
    if (DAT_004e153c == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1910d0<hulkfight::motion::SimulationTrack_1910d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1910d0<hulkfight::motion::SimulationTrack_1910d0>("timeBegin", (void (hulkfight::motion::SimulationTrack_1910d0::*)())&hulkfight::motion::SimulationTrack_1910d0::FUN_0018edd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1910d0<hulkfight::motion::SimulationTrack_1910d0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1910d0<hulkfight::motion::SimulationTrack_1910d0>("timeEnd", (void (hulkfight::motion::SimulationTrack_1910d0::*)())&hulkfight::motion::SimulationTrack_1910d0::FUN_0018ede0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1538), params, 2);
    }
    DAT_004e153c++;
}


// 0x00191170 FUN_00191170 (1276 B): equivalent/0x00191170.cpp
// sym: ?FUN_00191170@fn_fca9d983@@YAXXZ @98bbdd6ed323 @wbfb11c13f3cf
// STATUS: equivalent (tools/equiv.py level 3: 2339 inputs, branch coverage 50/50)
// FUN_00191170 @ 0x00191170
void FUN_00191170()
{
    if (DAT_004e1544 == 0) {
        void* params[24];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("timeBegin", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018edf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("timeEnd", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018ee00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("velocityForward", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018ee20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("velocityReverse", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018ee40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("acceleration", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018ee60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("deceleration", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018ee80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("turnVelocity", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018eea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("turnAcceleration", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018eed0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("treadLength", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018ef00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("treadWidth", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018ef20);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamVector_191170<hulkfight::motion::TankLocomotionTrack_191170>("treadOffset", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018ef50);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("springDistance", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018ef80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("springForce", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018efa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("damperForce", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018efc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("tiltForce", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018efe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("frictionSlope", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018f000);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("maxSlope", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018f030);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("gravity", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018f060);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("inAirGravity", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018f080);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("inAirMaxSpringVelocity", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018f0a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("maxSpringVelocity", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018f0c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamIntConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("priority", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018f0e0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("blendInTime", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018f100);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>));
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatConstRange_191170<hulkfight::motion::TankLocomotionTrack_191170>("blendOutTime", (void (hulkfight::motion::TankLocomotionTrack_191170::*)())&hulkfight::motion::TankLocomotionTrack_191170::FUN_0018f120);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1540), params, 24);
    }
    DAT_004e1544++;
}


// 0x00191940 FUN_00191940 (409 B): equivalent/0x00191940.cpp
// sym: ?FUN_00191940@fn_fca9d983@@YAXXZ @73dab1838f60 @we9592fc0b8e6
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 16/16)
// FUN_00191940 @ 0x00191940
void FUN_00191940()
{
    if (DAT_004e1534 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ImpulseVelocityTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<ImpulseVelocityTrack>("timeBegin", (void (ImpulseVelocityTrack::*)())&ImpulseVelocityTrack::FUN_0018ecb0);
        mem = FUN_0008d690((int)sizeof(ParamNameConstList<ImpulseVelocityTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamNameConstList<ImpulseVelocityTrack>("joint", &ImpulseVelocityTrack::FUN_0018ecc0);
        mem = FUN_0008d690((int)sizeof(ParamVector<ImpulseVelocityTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamVector<ImpulseVelocityTrack>("offset", (void (ImpulseVelocityTrack::*)())&ImpulseVelocityTrack::FUN_0018ecf0);
        mem = FUN_0008d690((int)sizeof(ParamVector<ImpulseVelocityTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamVector<ImpulseVelocityTrack>("velocity", (void (ImpulseVelocityTrack::*)())&ImpulseVelocityTrack::FUN_0018ed30);
        mem = FUN_0008d690((int)sizeof(ParamVector<ImpulseVelocityTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamVector<ImpulseVelocityTrack>("velocityMax", (void (ImpulseVelocityTrack::*)())&ImpulseVelocityTrack::FUN_0018ed70);
        mem = FUN_0008d690((int)sizeof(ParamBool<ImpulseVelocityTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<ImpulseVelocityTrack>("useCollision", (void (ImpulseVelocityTrack::*)())&ImpulseVelocityTrack::FUN_0018eda0);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<ImpulseVelocityTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<ImpulseVelocityTrack>("collisionScale", (void (ImpulseVelocityTrack::*)())&ImpulseVelocityTrack::FUN_0018edc0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1530), params, 7);
    }
    DAT_004e1534++;
}

} // namespace fn_fca9d983
