// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSoundRealTimeManager,void,char_*,char_*,char_*>::vfunc_2 @ 0x001edd70
struct CSoundRealTimeManager { void placeholder(char *, char *, char *); };
struct Args { char *first; char *second; char *third; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    char pad[0x18];
    void (CSoundRealTimeManager::*method)(char *, char *, char *);
    virtual void vfunc_2(CSoundRealTimeManager *manager, Args *args, void *unused);
};
void Method3::vfunc_2(CSoundRealTimeManager *manager, Args *args, void *unused) {
    (manager->*method)(args->first, args->second, args->third);
}
