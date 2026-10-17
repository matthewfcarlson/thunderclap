// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure4<CRenderManager,unsigned_int,const_char_*,float,float,float>::vfunc_2 @ 0x001ba7a0
struct CRenderManager {
    unsigned int FUN_001ba7a0(unsigned int, const char *, float, float);
};
struct Arguments {
    unsigned int id;
    const char *name;
    float first;
    float second;
};
struct Closure4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, Arguments *, unsigned int *);
    char pad[0x18];
    unsigned int (CRenderManager::*method)(unsigned int, const char *, float, float);
    CRenderManager *manager;
};
void Closure4::vfunc_2(void *, Arguments *args, unsigned int *result)
{
    unsigned int value = (manager->*method)(args->id, args->name, args->first, args->second);
    if (result) *result = value;
}