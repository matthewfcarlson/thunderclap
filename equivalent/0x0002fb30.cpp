// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CActorManager,void,const_char_*,const_char_*,float,float>::vfunc_2 @ 0x0002fb30
struct CActorManager {
    void FUN_0002fb30(const char *, const char *, float, float);
};

struct Closure4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, const void *, int);
    char padding[0x18];
    void (CActorManager::*method)(const char *, const char *, float, float);
    CActorManager *actorManager;
};

void Closure4::vfunc_2(int, const void *arguments, int)
{
    struct Args {
        const char *first;
        const char *second;
        float third;
        float fourth;
    };
    const Args *args = (const Args *)arguments;
    (actorManager->*method)(args->first, args->second, args->third, args->fourth);
}
