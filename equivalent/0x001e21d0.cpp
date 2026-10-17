// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,math::Vector,float>::vfunc_2 @ 0x001e21d0
namespace math { struct Vector { float x,y,z; }; }
struct CSPManager { };
struct Arguments { math::Vector vector; float value; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const Arguments* arguments, bool* result);
    char padding[0x18];
    bool (CSPManager::*method)(math::Vector,float);
    CSPManager* manager;
};
void Closure2::vfunc_2(void* unused, const Arguments* arguments, bool* result) {
    bool value = (manager->*method)(arguments->vector, arguments->value);
    if (result) *result = value;
}
