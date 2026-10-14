// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CActorManager,bool,const_char_*,math::Vector,math::Vector>::vfunc_2 @ 0x0002e3d0
namespace math {
struct Vector {
    float x, y, z;
};
}
class CActorManager {
public:
    bool Dummy(const char* name, math::Vector a, math::Vector b);
};
typedef bool (CActorManager::*ActorFn_2e3d0)(const char* name, math::Vector a, math::Vector b);
struct Args_2e3d0 {
    const char* name;
    math::Vector a;
    math::Vector b;
};
class Function {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method3 : public Function {
public:
    char pad04[0x18];
    ActorFn_2e3d0 fn;
    virtual void vfunc_2(CActorManager* owner, Args_2e3d0* args, bool* result);
};
void Method3::vfunc_2(CActorManager* owner, Args_2e3d0* args, bool* result) {
    bool r = (owner->*fn)(args->name, args->a, args->b);
    if (result)
        *result = r;
}
