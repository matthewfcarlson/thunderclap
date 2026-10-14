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
extern "C" void* __cdecl Cast(void*);
extern "C" Obj_c0630* __cdecl Convert(void*, void*, void*, void*, int);
extern char type1_c0630, type2;
int Handler_c0630::Handle(int msg, Obj_c0630** arg) {
    if (mgr && msg == 1) {
        Obj_c0630* v = *arg;
        Obj_c0630* q = Convert(Cast(v), 0, &type1_c0630, &type2, 0);
        if (q) {
            mgr->Set(q->id, 1);
            return 0;
        }
    }
    return -1;
}