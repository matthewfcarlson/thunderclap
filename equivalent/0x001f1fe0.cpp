// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure5<CSoundSystem,void,char_*,char_*,float,float,float>::vfunc_2 @ 0x001f1fe0
class CSoundSystem;
typedef void (CSoundSystem::*SoundMethod)(char *, char *, float, float, float);
class CSoundSystem { public: void dummy(); };
struct SoundArgs { char *first; char *second; float third; float fourth; float fifth; };
class Closure5 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, SoundArgs *, void *);
    char reserved[0x18];
    SoundMethod method;
    CSoundSystem *object;
};
void Closure5::vfunc_2(void *, SoundArgs *args, void *) {
    (object->*method)(args->first, args->second, args->third, args->fourth, args->fifth);
}