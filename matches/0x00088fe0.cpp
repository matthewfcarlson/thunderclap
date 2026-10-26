#include "decls/data/game/unknown.h"
// data: gCheckObj = DAT_004dd830

extern void __cdecl Scan(unsigned int, const char*, ...);
extern void __cdecl Fmt(char*, int, const char*, ...);
extern int __stdcall Check(void*);
struct CO {
    int pad;
    int val;
};
extern void __cdecl StopMsg(const char*);
struct Res_88fe0 {
    void Done(unsigned int);
};
struct Svc_88fe0 {
    Res_88fe0* Run();
};
struct Glob_88fe0 {
    char pad[0x54];
    Svc_88fe0* svc;
};
extern Glob_88fe0* gGlob_88fe0;
struct Obj_88fe0 {
    int a;
    int b;
    char buf[32];
    void target(unsigned int);
};
void Obj_88fe0::target(unsigned int arg) {
    Scan(arg, "c%dm%d", &a, &b);
    Fmt(buf, 32, "c%02dm%02d", a, b);
    gGlob_88fe0->svc->Run()->Done(arg);
    if (a > 1) {
        if (Check(((CO*)&DAT_004dd830)) != (*(CO*)&DAT_004dd830).val) {
            do {
                StopMsg("TBS_STOP_PIRATING");
            } while (1);
        }
    }
}
