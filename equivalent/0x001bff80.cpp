// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_2 @ 0x001bff80
struct CSubtitleManager { void FUN_001bff80(int, float, const char *, float); };
struct Arguments { int number; float time; const char *text; float duration; };
struct Closure4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, Arguments *arguments, int other);
    char reserved[24];
    void (CSubtitleManager::*method)(int, float, const char *, float);
    CSubtitleManager *object;
};
void Closure4::vfunc_2(int unused, Arguments *arguments, int other) {
    float time = arguments->time;
    (object->*method)(arguments->number, time, arguments->text, arguments->duration);
}
