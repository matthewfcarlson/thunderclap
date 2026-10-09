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
    t.vptr = (void*)0x428d60;
    void* r = First(b, &t);
    a->G(r);
}