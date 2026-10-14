extern "C" char DAT_00428d60[];
struct Temp_23e3f0 {
    void* vptr;
};
struct A_23e3f0 {
    void G(void*);
};
struct B_23e3f0 {};
extern void* First(B_23e3f0*, Temp_23e3f0*);
void Target(A_23e3f0* a, B_23e3f0* b) {
    Temp_23e3f0 t;
    t.vptr = (void*)((int)DAT_00428d60);
    void* r = First(b, &t);
    a->G(r);
}