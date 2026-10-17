// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_2 @ 0x001f5b40
struct CSoundVoiceManager { void callback(char*, char*, char*, int); };
struct VoiceArgs { char* first; char* second; char* third; int fourth; };
struct Closure4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, VoiceArgs* arguments, void* unused2);
    char padding[0x18];
    void (CSoundVoiceManager::*method)(char*, char*, char*, int);
    CSoundVoiceManager* object;
};
void Closure4::vfunc_2(void*, VoiceArgs* arguments, void*) {
    (object->*method)(arguments->first, arguments->second, arguments->third, arguments->fourth);
}
