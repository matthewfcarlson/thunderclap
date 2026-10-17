// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x001c0230
struct CSubtitleManager { void placeholder(); };
struct SubtitleArgs { const char* first; const char* second; float time; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const SubtitleArgs* args, void* unused2);
    char padding[0x18];
    void (CSubtitleManager::*method)(const char*, const char*, float);
    CSubtitleManager* manager;
};
void Closure3::vfunc_2(void* unused, const SubtitleArgs* args, void* unused2) {
    (manager->*method)(args->first, args->second, args->time);
}
