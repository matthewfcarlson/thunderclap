// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSPManager,void,int,int,const_char_*>::vfunc_2 @ 0x001e2420
struct CSPManager { };
struct Arguments { int a; int b; const char *c; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, Arguments *args, void *unused2);
    char padding[0x18];
    void (CSPManager::*method)(int,int,const char *);
    CSPManager *object;
};
void Closure3::vfunc_2(void *unused, Arguments *args, void *unused2) {
    (object->*method)(args->a, args->b, args->c);
}