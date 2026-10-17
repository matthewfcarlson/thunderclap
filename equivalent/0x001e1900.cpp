// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,int,const_char_*,const_char_*>::vfunc_2 @ 0x001e1900
struct CSPManager {
    int FUN_001e1900(const char *, const char *);
};

struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, const char **arguments, int *result);
    char padding[0x18];
    int (CSPManager::*method)(const char *, const char *);
    CSPManager *manager;
};

void Closure2::vfunc_2(int unused, const char **arguments, int *result)
{
    int value = (manager->*method)(arguments[0], arguments[1]);
    if (result)
        *result = value;
}
