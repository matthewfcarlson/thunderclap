// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018cab0..0x0018ecb0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TimerCondition
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f597f6aa {
#define TREE_TU_END }
namespace fn_f597f6aa {} using namespace fn_f597f6aa;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f597f6aa {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_f597f6aa
namespace hulkfight { namespace motion {
class TimerCondition_18df00 {
public:
    char FUN_0018cab0(int); /* (unb4) as defined; address taken only */
    char FUN_0018cac0(int); /* (unb4) as defined; address taken only */
    bool FUN_0018cad0(int); /* (unb4) as defined; address taken only */
    char FUN_0018caf0(char); /* (unb4) as defined; address taken only */
    char FUN_0018cb10(int); /* (unb4) as defined; address taken only */
};
} }
namespace fn_f597f6aa {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f597f6aa
namespace fight {
template <class T>
class ParamIntConstRange_18df00 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18df00(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_18df00 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18df00(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamBool_18df00 : public ParamBoolBase {
public:
    ParamBool_18df00(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_18df00 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_18df00(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fn_f597f6aa {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
class VarAssignTrack {
public:
    char FUN_0018cbd0(int); /* (unb4) as defined; address taken only */
    void FUN_0018cbe0();
    char FUN_0018cc00(int); /* (unb4) as defined; address taken only */
    bool FUN_0018cc20(int); /* (unb4) as defined; address taken only */
    char FUN_0018cc40(int); /* (unb4) as defined; address taken only */
    char FUN_0018cc60(char); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_f597f6aa
namespace fight {
template <class T>
class ParamName_18e6e0 : public ParamNameBase {
public:
    ParamName_18e6e0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_18e6e0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_18e6e0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamBool_18e6e0 : public ParamBoolBase {
public:
    ParamBool_18e6e0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamFloatConstRange_18e6e0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_18e6e0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamEnumConstList_18e6e0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_18e6e0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}

namespace fn_f597f6aa {

// 0x0018df00 FUN_0018df00 (339 B): equivalent/0x0018df00.cpp
// sym: ?FUN_0018df00@fn_f597f6aa@@YAXXZ @ae5f51cbdb8d @w37a1f6d2c672
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0018df00 @ 0x0018df00
void FUN_0018df00()
{
    if (DAT_004e150c == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18df00<hulkfight::motion::TimerCondition_18df00>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange_18df00<hulkfight::motion::TimerCondition_18df00>("timer", (void (hulkfight::motion::TimerCondition_18df00::*)())&hulkfight::motion::TimerCondition_18df00::FUN_0018cab0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_18df00<hulkfight::motion::TimerCondition_18df00>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList_18df00<hulkfight::motion::TimerCondition_18df00>("compare", ((const char**)&DAT_0042773c), (*(int*)&DAT_00427754), (void (hulkfight::motion::TimerCondition_18df00::*)())&hulkfight::motion::TimerCondition_18df00::FUN_0018cac0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18df00<hulkfight::motion::TimerCondition_18df00>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_18df00<hulkfight::motion::TimerCondition_18df00>("value", (void (hulkfight::motion::TimerCondition_18df00::*)())&hulkfight::motion::TimerCondition_18df00::FUN_0018cad0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_18df00<hulkfight::motion::TimerCondition_18df00>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_18df00<hulkfight::motion::TimerCondition_18df00>("useKeyWordWait", (void (hulkfight::motion::TimerCondition_18df00::*)())&hulkfight::motion::TimerCondition_18df00::FUN_0018caf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_18df00<hulkfight::motion::TimerCondition_18df00>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamEnumConstList_18df00<hulkfight::motion::TimerCondition_18df00>("keyWord", ((const char**)&DAT_004bebb4), 15, (void (hulkfight::motion::TimerCondition_18df00::*)())&hulkfight::motion::TimerCondition_18df00::FUN_0018cb10);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1508), params, 5);
    }
    DAT_004e150c++;
}


// 0x0018e6e0 FUN_0018e6e0 (372 B): equivalent/0x0018e6e0.cpp
// sym: ?FUN_0018e6e0@fn_f597f6aa@@YAXXZ @6b1ff02959e0 @w733acf65c639
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 14/14)
// FUN_0018e6e0 @ 0x0018e6e0
void FUN_0018e6e0()
{
    if (DAT_004e152c == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_18e6e0<VarAssignTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_18e6e0<VarAssignTrack>("timeBegin", (void (VarAssignTrack::*)())&VarAssignTrack::FUN_0018cbd0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_18e6e0<VarAssignTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_18e6e0<VarAssignTrack>("variable", &VarAssignTrack::FUN_0018cbe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_18e6e0<VarAssignTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamEnumConstList_18e6e0<VarAssignTrack>("operator", ((const char**)&DAT_004beb94), 8, (void (VarAssignTrack::*)())&VarAssignTrack::FUN_0018cc00);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18e6e0<VarAssignTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamIntConstRange_18e6e0<VarAssignTrack>("value", (void (VarAssignTrack::*)())&VarAssignTrack::FUN_0018cc20);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_18e6e0<VarAssignTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamIntConstRange_18e6e0<VarAssignTrack>("valueAtEnd", (void (VarAssignTrack::*)())&VarAssignTrack::FUN_0018cc40);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_18e6e0<VarAssignTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_18e6e0<VarAssignTrack>("setToValueAtEnd", (void (VarAssignTrack::*)())&VarAssignTrack::FUN_0018cc60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1528), params, 6);
    }
    DAT_004e152c++;
}

} // namespace fn_f597f6aa
