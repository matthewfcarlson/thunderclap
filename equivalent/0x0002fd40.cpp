// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x0002fd40
class CActorManager {
public:
    int FUN_0002fd40(const char *, const char *);
};

class Closure2 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **arguments, int *result);
private:
    char padding[0x18];
    int (CActorManager::*method)(const char *, const char *);
    CActorManager *actorManager;
};

void Closure2::vfunc_2(void *unused, const char **arguments, int *result)
{
    int value = (actorManager->*method)(arguments[0], arguments[1]);
    if (result)
        *result = value;
}