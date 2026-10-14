extern void Release(void*);
extern int vtStatement;
extern int vtString;
extern int vtToken;
struct Obj_f9bc0 {
    int* vf;
    char pad[12];
    void* p;
};
void __fastcall FUN_000f9bc0(Obj_f9bc0* o) {
    o->vf = &vtStatement;
    if (o->p) {
        Release(o->p);
        o->p = 0;
    }
    o->vf = &vtString;
    if (o->p) {
        Release(o->p);
        o->p = 0;
    }
    o->vf = &vtToken;
}