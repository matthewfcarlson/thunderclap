// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSubtitleManager,void,float,float,float>::vfunc_2 @ 0x001bf790
struct CSubtitleManager { void FUN_001bf790(float, float, float); };
struct Float3 { float x, y, z; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSubtitleManager* manager, const Float3* values, void* unused);
    char padding[0x18];
    void (CSubtitleManager::*method)(float, float, float);
};
void Method3::vfunc_2(CSubtitleManager* manager, const Float3* values, void* unused) {
    (manager->*method)(values->x, values->y, values->z);
}
