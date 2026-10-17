// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CActorManager,void,const_char_*,float,float,float>::vfunc_2 @ 0x0002d8c0
struct CActorManager { void FUN_0002d8c0(const char *, float, float, float); };
struct Method4 {
    char padding[0x1c];
    void (CActorManager::*method)(const char *, float, float, float);
    void target(CActorManager *manager, const unsigned *arguments, unsigned unused);
};
void Method4::target(CActorManager *manager, const unsigned *arguments, unsigned unused) {
    (manager->*method)((const char *)arguments[0], *(const float *)&arguments[1], *(const float *)&arguments[2], *(const float *)&arguments[3]);
}