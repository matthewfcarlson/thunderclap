#include "decls/data/game/unknown.h"
// data: gCheckObj = DAT_004dd830
#include "gen/owners.h"

extern void __cdecl Scan(unsigned int, const char*, ...);
extern "C" void __cdecl FUN_00267760(char*, int, const char*, ...);
extern int __stdcall Check(void*);
struct CO {
    int pad;
    int val;
};
extern "C" void __cdecl FUN_001bb0b0(const char*);
struct Res_88fe0 {
};
struct Svc_88fe0 {
    Res_88fe0* Run();
};
struct Glob_88fe0 {
    char pad[0x54];
    Svc_88fe0* svc;
};
extern Glob_88fe0* gGlob_88fe0;
void owners::Obj_88fe0::FUN_00088fe0(unsigned int arg) {
    Scan(arg, "c%dm%d", &a, &b);
    FUN_00267760(buf, 32, "c%02dm%02d", a, b);
    ((owners::K_b4c10 *)(gGlob_88fe0->svc->Run()))->FUN_000b4c10((const char *)(hulk_uintptr)(unsigned int)arg);
    if (a > 1) {
        if (Check(((CO*)&DAT_004dd830)) != (*(CO*)&DAT_004dd830).val) {
            do {
                FUN_001bb0b0("TBS_STOP_PIRATING");
            } while (1);
        }
    }
}
