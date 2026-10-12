// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 26/26)
// FUN_00120a90 @ 0x00120a90
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class PathLocatorTestCondition {
public:
    void FUN_0011c290();
    void FUN_0011b810();
    void FUN_0011b830();
    void FUN_0011b850();
    void FUN_0011b870();
    void FUN_0011b890();
    void FUN_0011b8b0();
    void FUN_0011b8d0();
    void FUN_0011b8f0();
    void FUN_0011b910();
    void FUN_0011b930();
    void FUN_0011b960();
};
}
}

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0ca8;
extern int DAT_004e0cac;
extern const char* DAT_0042773c[3];
extern int DAT_00427754;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00120a90()
{
    if (DAT_004e0cac == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString<hulkfight::ai::PathLocatorTestCondition>("locatorType", &hulkfight::ai::PathLocatorTestCondition::FUN_0011c290);
        mem = FUN_0008d690(0x20);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>("compare", DAT_0042773c, DAT_00427754, &hulkfight::ai::PathLocatorTestCondition::FUN_0011b810);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>("distance", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b830);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>("distanceTest", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b850);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>("min", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b870);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>("max", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b890);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>("defendLocator", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b8b0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>("myLocator", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b8d0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>("namedLocator", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b8f0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>("testLocatorExists", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b910);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>("defaulttoVicinityCheck", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b930);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>("vicinityLimits", &hulkfight::ai::PathLocatorTestCondition::FUN_0011b960);
        FUN_002347b0(&DAT_004e0ca8, params, 12);
    }
    DAT_004e0cac++;
}
