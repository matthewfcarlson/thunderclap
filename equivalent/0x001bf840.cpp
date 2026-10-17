// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x001bf840
struct CSubtitleManager { };
struct Arguments { const char *first; const char *second; float third; };
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSubtitleManager *manager, Arguments *args, void *unused);
    char padding[0x18];
    void (CSubtitleManager::*method)(const char *, const char *, float);
};
void Method3::vfunc_2(CSubtitleManager *manager, Arguments *args, void *unused) {
    (manager->*method)(args->first, args->second, args->third);
}