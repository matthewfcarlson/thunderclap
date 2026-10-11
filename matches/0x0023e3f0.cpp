extern "C" char DAT_00428d60[];
struct Temp {
    void* vptr;
};
struct A {
    void G(void*);
};
struct B {};
extern void* First(B*, Temp*);
void Target(A* a, B* b) {
    Temp t;
    t.vptr = (void*)((int)DAT_00428d60);
    void* r = First(b, &t);
    a->G(r);
}