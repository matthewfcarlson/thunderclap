// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 4/4)
// FUN_0023dc90 @ 0x0023dc90
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace fight {
class CommentCondition {
public:
    void FUN_0023d880();
};
}

class __declspec(novtable) ParamStringBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002349e0(const char* name);
    ParamStringBase(const char* name) { FUN_002349e0(name); }
};
namespace fight {
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
extern ParamRegistry DAT_004e5c5c;
extern int DAT_004e5c60;

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0023dc90()
{
    if (DAT_004e5c60 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamString<fight::CommentCondition>("text", &fight::CommentCondition::FUN_0023d880);
        FUN_002347b0(&DAT_004e5c5c, params, 1);
    }
    DAT_004e5c60++;
}
