// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 6/6)
// FUN_00111df0 @ 0x00111df0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace ai {
class HulkActionLargestCondition {
public:
    void FUN_0010c180();
    void FUN_0010c9b0();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
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
class ParamString : public ParamStringBase {
public:
    ParamString(const char* name, void (T::*s)()) : ParamStringBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0b00;
extern int DAT_004e0b04;

extern const char* DAT_0042773c[1];

extern int DAT_00427754;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00111df0()
{
    if (DAT_004e0b04 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>("compare", DAT_0042773c, DAT_00427754, &hulkfight::ai::HulkActionLargestCondition::FUN_0010c180);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamString<hulkfight::ai::HulkActionLargestCondition>("text", &hulkfight::ai::HulkActionLargestCondition::FUN_0010c9b0);
        FUN_002347b0(&DAT_004e0b00, params, 2);
    }
    DAT_004e0b04++;
}
