// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_2 @ 0x001f1f60
struct CSoundSystem { void FUN_001f1f60(char*, char*, float, float); };
struct Arguments { char* first; char* second; float third; float fourth; };
struct Closure4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, Arguments* args, void* unused2);
    char padding[24];
    void (CSoundSystem::*method)(char*, char*, float, float);
    CSoundSystem* instance;
};
void Closure4::vfunc_2(void*, Arguments* args, void*) {
    (instance->*method)(args->first, args->second, args->third, args->fourth);
}
