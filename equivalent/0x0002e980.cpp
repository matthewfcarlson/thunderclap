// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,const_char_*,float,const_char_*>::vfunc_2 @ 0x0002e980
class CActorManager {};
struct Arguments { const char *name; float value; const char *other; };
class Closure3 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, Arguments *args, int unused2);
private:
    char padding[0x18];
public:
    void (CActorManager::*method)(const char *, float, const char *);
    CActorManager *actor;
};
void Closure3::vfunc_2(int unused, Arguments *args, int unused2) {
    (actor->*method)(args->name, args->value, args->other);
}
