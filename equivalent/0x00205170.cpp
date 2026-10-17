// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CWorldStreamManager,bool,float,float,float>::vfunc_2 @ 0x00205170
struct CWorldStreamManager {
    bool FUN_00205170(float, float, float);
};

struct Method3 {
    char pad[0x1c];
    bool (CWorldStreamManager::*callback)(float, float, float);
    void vfunc_2(CWorldStreamManager* object, const float* args, bool* result);
};

void Method3::vfunc_2(CWorldStreamManager* object, const float* args, bool* result)
{
    bool value = (object->*callback)(args[0], args[1], args[2]);
    if (result)
        *result = value;
}