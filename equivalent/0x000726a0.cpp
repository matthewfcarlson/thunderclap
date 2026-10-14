// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_000726a0 @ 0x000726a0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CClearCollisionStun {
public:
    void FUN_00068b70();
    void FUN_00068b80();
};

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
extern ParamRegistry DAT_004dd010;
extern int DAT_004dd014;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_000726a0()
{
    if (DAT_004dd014 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CClearCollisionStun>("timeBegin", &::CClearCollisionStun::FUN_00068b70);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CClearCollisionStun>("timeEnd", &::CClearCollisionStun::FUN_00068b80);
        FUN_002347b0(&DAT_004dd010, params, 2);
    }
    DAT_004dd014++;
}
