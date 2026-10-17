// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CSPManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001e02f0
namespace math { struct Vector { float x, y, z; }; }
struct CSPManager { };
struct Args { const char *name; math::Vector position; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
struct Method2 : Function {
    char pad[0x1c - sizeof(Function)];
    bool (CSPManager::*method)(const char *, math::Vector);
    void vfunc_2(CSPManager *manager, const Args *args, bool *result);
};
void Method2::vfunc_2(CSPManager *manager, const Args *args, bool *result) {
    bool value = (manager->*method)(args->name, args->position);
    if (result) *result = value;
}
