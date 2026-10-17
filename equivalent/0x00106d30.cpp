// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_2 @ 0x00106d30
struct Vector { float x,y,z; };
struct CPatrolPathManager { bool invoke(const char*, int, Vector); };
struct Arguments { const char* name; int index; Vector position; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const Arguments* arguments, bool* result);
    char padding[0x18];
    bool (CPatrolPathManager::*callback)(const char*, int, Vector);
    CPatrolPathManager* object;
};
void Closure3::vfunc_2(void* unused, const Arguments* arguments, bool* result) {
    bool value = (object->*callback)(arguments->name, arguments->index, arguments->position);
    if (result) *result = value;
}
