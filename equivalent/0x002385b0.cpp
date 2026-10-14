// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_002385b0 @ 0x002385b0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace fight {
class MaybeCondition {
public:
    void FUN_002381c0();
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern ParamRegistry DAT_004e5c0c;
extern int DAT_004e5c10;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_002385b0()
{
    if (DAT_004e5c10 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<fight::MaybeCondition>("percent", &fight::MaybeCondition::FUN_002381c0);
        FUN_002347b0(&DAT_004e5c0c, params, 1);
    }
    DAT_004e5c10++;
}
