// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<CEffectManager,unsigned_int,char_*,float,float>::vfunc_2 @ 0x001f7d50
class CEffectManager {
public:
    unsigned int FUN_001f7d50(unsigned int, char *, float);
};
struct Arguments { unsigned int id; char *name; float value; };
class Closure3 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual unsigned int vfunc_2(void *unused, Arguments *arguments, unsigned int *result);
private:
    char padding[0x18];
    unsigned int (CEffectManager::*method)(unsigned int, char *, float);
    CEffectManager *manager;
};
unsigned int Closure3::vfunc_2(void *unused, Arguments *arguments, unsigned int *result)
{
    unsigned int value = (manager->*method)(arguments->id, arguments->name, arguments->value);
    if (result) *result = value;
    return value;
}
