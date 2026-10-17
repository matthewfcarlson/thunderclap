// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_2 @ 0x00106b70
struct Vector { float x, y, z; };
struct Arguments { const char* name; int value; Vector position; };
struct CPatrolPathManager {
    bool FUN_00106b70(const char*, int, Vector);
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method3 : Function {
    virtual void vfunc_2(CPatrolPathManager* owner, const Arguments* args, bool* result);
    char padding[24];
    bool (CPatrolPathManager::*method)(const char*, int, Vector);
};
void Method3::vfunc_2(CPatrolPathManager* owner, const Arguments* args, bool* result)
{
    bool value = (owner->*method)(args->name, args->value, args->position);
    if (result) *result = value;
}
