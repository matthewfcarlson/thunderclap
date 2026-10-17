// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_2 @ 0x001f0da0
struct CSoundSystem {
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSoundSystem *, void *, void *);
};
struct Arguments {
    char *first;
    char *second;
    float third;
    float fourth;
};
struct Method4 : Function {
    char padding[0x18];
    void (CSoundSystem::*method)(char *, char *, float, float);
    virtual void vfunc_2(CSoundSystem *sound, void *args, void *unused);
};
void Method4::vfunc_2(CSoundSystem *sound, void *args, void *unused) {
    Arguments *a = (Arguments *)args;
    (sound->*method)(a->first, a->second, a->third, a->fourth);
}