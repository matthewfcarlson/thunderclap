// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSoundSystem,void,char_*,float,float>::vfunc_2 @ 0x001f2190
struct CSoundSystem {};
struct SoundArgs { char *name; float first; float second; };
struct Closure3 {
    char padding[0x1c];
    void (CSoundSystem::*method)(char *, float, float);
    CSoundSystem *object;
    void vfunc_2(void *unused, SoundArgs *args, void *unused2);
};
void Closure3::vfunc_2(void *unused, SoundArgs *args, void *unused2) {
    (object->*method)(args->name, args->first, args->second);
}