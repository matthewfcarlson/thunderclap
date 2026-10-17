// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSoundSystem,void,char_*,char_*,float>::vfunc_2 @ 0x001f1de0
struct CSoundSystem {
    void FUN_001f1de0(char *, char *, float);
};
struct SoundArgs { char *first; char *second; float volume; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, SoundArgs *, void *);
    char reserved[0x18];
    void (CSoundSystem::*method)(char *, char *, float);
    CSoundSystem *object;
};
void Closure3::vfunc_2(void *, SoundArgs *args, void *) {
    (object->*method)(args->first, args->second, args->volume);
}