// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_2 @ 0x0007e100
struct CAmbientsManager {};
struct AmbientArgs { const char* name; int number; bool enabled; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const AmbientArgs* arguments, void* unused2);
    char padding[0x1c - 4];
    void (CAmbientsManager::*method)(const char*, int, bool);
    CAmbientsManager* object;
};
void Closure3::vfunc_2(void* unused, const AmbientArgs* arguments, void* unused2) {
    (object->*method)(arguments->name, arguments->number, arguments->enabled);
}
