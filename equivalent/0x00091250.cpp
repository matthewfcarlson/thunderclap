// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CStatsManager,void,char_*,char_*,int>::vfunc_2 @ 0x00091250
struct CStatsManager {
    void FUN_00091250(char *, char *, int);
};
struct Arguments { char *first; char *second; int third; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, Arguments *, void *);
    char padding[0x18];
    void (CStatsManager::*method)(char *, char *, int);
    CStatsManager *object;
};
void Closure3::vfunc_2(void *, Arguments *arguments, void *) {
    (object->*method)(arguments->first, arguments->second, arguments->third);
}
