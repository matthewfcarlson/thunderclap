struct Obj {
    char pad[0x158];
    int id;
};
struct Mgr {
    void Set(int, int);
};
struct Handler {
    char pad[4];
    Mgr* mgr;
    int Handle(int, Obj**);
};
extern "C" void* __cdecl Cast(void*);
extern "C" Obj* __cdecl Convert(void*, void*, void*, void*, int);
extern char type1, type2;
int Handler::Handle(int msg, Obj** arg) {
    if (mgr && msg == 1) {
        Obj* v = *arg;
        Obj* q = Convert(Cast(v), 0, &type1, &type2, 0);
        if (q) {
            mgr->Set(q->id, 1);
            return 0;
        }
    }
    return -1;
}