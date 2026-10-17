// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,int,const_char_*,const_char_*>::vfunc_2 @ 0x0002fc90
struct CActorManager { int FUN_0002fc90(const char *, const char *); };
struct Arguments { const char *first; const char *second; };
struct Closure2_CActorManager_int_const_char_const_char {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, const Arguments *arguments, int *result);
    char padding[0x18];
    int (CActorManager::*method)(const char *, const char *);
    CActorManager *object;
};
void Closure2_CActorManager_int_const_char_const_char::vfunc_2(int unused, const Arguments *arguments, int *result)
{
    int value = (object->*method)(arguments->first, arguments->second);
    if (result) *result = value;
}