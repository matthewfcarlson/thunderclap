// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,bool>::vfunc_2 @ 0x0002e570
struct CActorManager { char unused; };
struct Arguments { const char *text; bool flag; };
class Closure2_CActorManager_bool_const_char_bool {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, Arguments *arguments, bool *result);
private:
    char padding[0x18];
    bool (CActorManager::*method)(const char *, bool);
    CActorManager *object;
};
void Closure2_CActorManager_bool_const_char_bool::vfunc_2(void *unused, Arguments *arguments, bool *result)
{
    bool value = (object->*method)(arguments->text, arguments->flag);
    if (result) *result = value;
}