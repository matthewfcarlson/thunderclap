// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CSubtitleManager,void,int,float,const_char_*,float>::vfunc_2 @ 0x001bf550
struct CSubtitleManager { void invoke(int, float, const char *, float); };
struct SubtitleArgs { int number; float start; const char *text; float end; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method4 : Function {
    virtual void vfunc_2(CSubtitleManager *manager, SubtitleArgs *arguments, void *unused);
    char padding[0x18];
    void (CSubtitleManager::*method)(int, float, const char *, float);
};
void Method4::vfunc_2(CSubtitleManager *manager, SubtitleArgs *arguments, void *unused)
{
    (manager->*method)(arguments->number, arguments->start, arguments->text, arguments->end);
}