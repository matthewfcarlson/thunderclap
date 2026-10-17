// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSoundSystem,void,char_*,float,float>::vfunc_2 @ 0x001f10d0
struct CSoundSystem {
    void FUN_001f10d0(char *, float, float);
};
struct SoundArguments {
    char *name;
    float first;
    float second;
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method3 : Function {
    virtual void vfunc_2(CSoundSystem *system, SoundArguments *arguments, void *unused);
    char padding[24];
    void (CSoundSystem::*method)(char *, float, float);
};
void Method3::vfunc_2(CSoundSystem *system, SoundArguments *arguments, void *unused)
{
    (system->*method)(arguments->name, arguments->first, arguments->second);
}
