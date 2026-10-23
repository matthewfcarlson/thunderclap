struct Obj_c0630 {
    char pad[0x158];
    int id;
};
struct Mgr_c0630 {
    void Set(int, int);
};
struct Handler_c0630 {
    char pad[4];
    Mgr_c0630* mgr;
    int Handle(int, Obj_c0630**);
};
extern "C" void* __cdecl FUN_000fc260(void*);
extern "C" Obj_c0630* __cdecl FUN_00344e74(void*, void*, void*, void*, int);
extern char DAT_0049dba4, DAT_0049faf4;
int Handler_c0630::Handle(int msg, Obj_c0630** arg) {
    if (mgr && msg == 1) {
        Obj_c0630* v = *arg;
        Obj_c0630* q = FUN_00344e74(FUN_000fc260(v), 0, &DAT_0049dba4, &DAT_0049faf4, 0);
        if (q) {
            mgr->Set(q->id, 1);
            return 0;
        }
    }
    return -1;
}