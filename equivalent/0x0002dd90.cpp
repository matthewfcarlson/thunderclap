// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CActorManager,void,const_char_*,const_char_*,float,float>::vfunc_2 @ 0x0002dd90
struct CActorManager {};
struct Arguments { const char* first; const char* second; float third; float fourth; };
struct Method4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager* manager, const Arguments* arguments, void* unused);
    char padding[0x18];
    void (CActorManager::*callback)(const char*, const char*, float, float);
};
void Method4::vfunc_2(CActorManager* manager, const Arguments* arguments, void* unused) {
    (manager->*callback)(arguments->first, arguments->second, arguments->third, arguments->fourth);
}
