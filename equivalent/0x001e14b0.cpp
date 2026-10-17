// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,bool>::vfunc_2 @ 0x001e14b0
struct CSPManager {
    bool FUN_001e14b0(const char *text, bool flag);
};
struct Arguments {
    const char *text;
    bool flag;
};
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, Arguments *arguments, bool *result);
    char padding[0x18];
    bool (CSPManager::*method)(const char *, bool);
    CSPManager *object;
};
void Closure2::vfunc_2(void *unused, Arguments *arguments, bool *result)
{
    bool value = (object->*method)(arguments->text, arguments->flag);
    if (result) *result = value;
}
