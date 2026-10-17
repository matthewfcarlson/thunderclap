// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CWorldStreamManager,int,float,float,float>::vfunc_2 @ 0x00205230
struct CWorldStreamManager {};
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CWorldStreamManager* manager, const float* args, int* result);
    char padding[0x18];
    int (CWorldStreamManager::*callback)(float, float, float);
};
void Method3::vfunc_2(CWorldStreamManager* manager, const float* args, int* result)
{
    int value = (manager->*callback)(args[0], args[1], args[2]);
    if (result) *result = value;
}