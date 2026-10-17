// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CWorldStreamManager,void,const_char_*,int,bool>::vfunc_2 @ 0x002061c0
struct CWorldStreamManager {
    void FUN_002061c0(const char *, int, bool);
};
struct Args { const char *name; int number; bool flag; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, const Args *, void *);
    char padding[0x18];
    void (CWorldStreamManager::*method)(const char *, int, bool);
    CWorldStreamManager *object;
};
void Closure3::vfunc_2(void *, const Args *args, void *) {
    (object->*method)(args->name, args->number, args->flag);
}
