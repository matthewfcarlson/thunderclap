// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CActorManager,const_char_*,int>::vfunc_2 @ 0x0002ef20
class CActorManager;
template<class T, class A, class R> class Closure1 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **argument, int *result);
private:
    char padding[0x18];
    int (CActorManager::*method)(const char *);
    CActorManager *object;
};
class CActorManager {};

template<> void Closure1<CActorManager, const char *, int>::vfunc_2(void *unused, const char **argument, int *result)
{
    int value = (object->*method)(*argument);
    if (result) *result = value;
}
