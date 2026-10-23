extern "C" int strcmp(const char*, const char*);

struct Obj2_b7590 {
    char pad[0x141];
    char flag;
};

struct Inner_b7590 {
    const char* GetState(const char* n);
    const char* GetName();
};

struct Menu_b7590 {
    char pad[0x34];
    Inner_b7590* mInner;
    void Func();
};

extern int DAT_0049dba4;
extern int DAT_0049f4a4;
extern int FUN_000fc260(const char* s);
extern Obj2_b7590* __cdecl FUN_00344e74(int a, int b, int* c, int* d, int e);

void Menu_b7590::Func() {
    Obj2_b7590* o = FUN_00344e74(FUN_000fc260("restart_mission_button"), 0, &DAT_0049dba4, &DAT_0049f4a4, 0);
    if (!o)
        return;
    if (!mInner)
        return;
    const char* n = mInner->GetName();
    char r = 1;
    if (n) {
        if (strcmp(n, "c00m01") != 0) {
            const char* s = mInner->GetState(n);
            if (strcmp(s, "complete") == 0)
                r = 0;
        }
    }
    o->flag = r;
}
