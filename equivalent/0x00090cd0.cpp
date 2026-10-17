// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CStatsManager,void,char_*,char_*,int>::vfunc_2 @ 0x00090cd0
struct CStatsManager { void FUN_00090cd0(char *, char *, int); };
struct Arguments { char *first; char *second; int third; };
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CStatsManager *manager, Arguments *args, void *unused);
    char pad[24];
    void (CStatsManager::*method)(char *, char *, int);
};
void Method3::vfunc_2(CStatsManager *manager, Arguments *args, void *unused) {
    (manager->*method)(args->first, args->second, args->third);
}