// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_2 @ 0x001f4b30
struct CSoundVoiceManager {};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method4 : Function {
    virtual void vfunc_2(CSoundVoiceManager *object, void **arguments, void *unused);
    char padding[24];
    void (CSoundVoiceManager::*method)(char *, char *, char *, int);
};
void Method4::vfunc_2(CSoundVoiceManager *object, void **arguments, void *unused) {
    (object->*method)((char *)arguments[0], (char *)arguments[1], (char *)arguments[2], (int)arguments[3]);
}
