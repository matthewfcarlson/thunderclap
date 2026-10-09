extern void __cdecl Scan(unsigned int, const char*, ...);
extern void __cdecl Fmt(char*, int, const char*, ...);
extern int __stdcall Check(void*);
struct CO {
    int pad;
    int val;
};
extern CO gCheckObj;
extern void __cdecl StopMsg(const char*);
struct Res {
    void Done();
};
struct Svc {
    Res* Run(unsigned int);
};
struct Glob {
    char pad[0x54];
    Svc* svc;
};
extern Glob* gGlob;
struct Obj {
    int a;
    int b;
    char buf[32];
    void target(unsigned int);
};
void Obj::target(unsigned int arg) {
    Scan(arg, "c%dm%d", &a, &b);
    Fmt(buf, 32, "c%02dm%02d", a, b);
    gGlob->svc->Run(arg)->Done();
    if (a > 1) {
        if (Check(&gCheckObj) != gCheckObj.val) {
            do {
                StopMsg("TBS_STOP_PIRATING");
            } while (1);
        }
    }
}
