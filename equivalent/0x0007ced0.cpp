// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method5<CAmbientsManager,void,const_char_*,int,bool,math::Vector,math::Vector>::vfunc_2 @ 0x0007ced0
namespace math {
struct Vector {
    float x, y, z;
};
}
class CAmbientsManager {
public:
    // The flag is passed as a full dword (its upper bytes are whatever the caller's slot held).
    void Dummy(const char* name, int n, unsigned int flag, math::Vector a, math::Vector b);
};
typedef void (CAmbientsManager::*AmbientFn)(const char* name, int n, unsigned int flag, math::Vector a, math::Vector b);
struct Args_7ced0 {
    const char* name;
    int n;
    bool flag;
    char pad9[3];
    math::Vector a;
    math::Vector b;
};
// The incoming args pointer is dead once read, and its stack slot then carries the flag byte.
union ArgsSlot {
    Args_7ced0* args;
    bool flag;
    unsigned int word;
};
class Function {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method5 : public Function {
public:
    char pad04[0x18];
    AmbientFn fn;
    virtual void vfunc_2(CAmbientsManager* owner, ArgsSlot slot, void* result);
};
void Method5::vfunc_2(CAmbientsManager* owner, ArgsSlot slot, void* result) {
    Args_7ced0* args = slot.args;
    const char* name = args->name;
    int n = args->n;
    slot.flag = args->flag;
    (owner->*fn)(name, n, slot.word, args->a, args->b);
}
