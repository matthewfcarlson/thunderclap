// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CActorManager,math::Vector,const_char_*>::vfunc_2 @ 0x0002d160
struct Vector { float x, y, z; };
struct CActorManager {
    Vector* FUN_0002d160(Vector*, const char*);
};
struct Method1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager* manager, const char** name, Vector* output);
    char padding[0x18];
    Vector* (CActorManager::*method)(Vector*, const char*);
};
void Method1::vfunc_2(CActorManager* manager, const char** name, Vector* output)
{
    Vector temporary;
    Vector result = *(manager->*method)(&temporary, *name);
    if (output) *output = result;
}