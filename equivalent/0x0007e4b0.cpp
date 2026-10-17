// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_2 @ 0x0007e4b0
struct CAmbientsManager {};
struct AmbientArguments {
    const char *name;
    unsigned int id;
    float volume;
};
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, AmbientArguments *arguments, void *unused2);
    char padding[0x18];
    void (CAmbientsManager::*method)(const char *, unsigned int, float);
    CAmbientsManager *object;
};
void Closure3::vfunc_2(void *unused, AmbientArguments *arguments, void *unused2) {
    (object->*method)(arguments->name, arguments->id, arguments->volume);
}