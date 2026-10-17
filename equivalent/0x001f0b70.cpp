// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSoundSystem,void,char_*,char_*,float>::vfunc_2 @ 0x001f0b70
struct CSoundSystem {};
struct CallArgs { char* first; char* second; float third; };
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSoundSystem* object, CallArgs* args, void* unused);
    char padding[24];
    void (CSoundSystem::*method)(char*, char*, float);
};
void Method3::vfunc_2(CSoundSystem* object, CallArgs* args, void* unused) {
    (object->*method)(args->first, args->second, args->third);
}
