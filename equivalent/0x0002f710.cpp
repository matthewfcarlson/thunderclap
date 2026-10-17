// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CActorManager,void,const_char_*,float,int,float>::vfunc_2 @ 0x0002f710
class CActorManager {};
class Closure4 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, const void *arguments, int other);
    char padding[0x18];
    typedef void (CActorManager::*Method)(const char *, float, int, float);
    Method method;
    CActorManager *actor;
};
void Closure4::vfunc_2(int unused, const void *arguments, int other)
{
    struct Args { const char *name; float value; int index; float last; };
    const Args *args = (const Args *)arguments;
    (actor->*method)(args->name, args->value, args->index, args->last);
}