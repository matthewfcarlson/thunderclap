// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSoundVoiceManager,void,bool,bool,bool>::vfunc_2 @ 0x001f4a00
struct CSoundVoiceManager {
    void FUN_001f4a00(unsigned int, unsigned int, unsigned int);
};
struct Args { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; };
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method3 : Function {
    virtual void vfunc_2(CSoundVoiceManager* manager, Args* args, void* unused);
    char padding[24];
    void (CSoundVoiceManager::*method)(unsigned int,unsigned int,unsigned int);
};
void Method3::vfunc_2(CSoundVoiceManager* manager, Args* args, void* unused) {
    unsigned int first = ((unsigned int)args & ~255u) | args->first;
    (manager->*method)(first, args->second, args->third);
}
