struct Other { virtual void f0(); virtual void f1(); };
struct Helper { void f0(); void f1(); };
struct Obj { void* vf; char pad[8]; void* a; void* b; void run(); };
extern void* vtLoad;
extern void* vtRef;
extern void thunk(void*);
void Obj::run() {
    void* x = a;
    vf = &vtLoad;
    if (x) {
        ((Helper*)x)->f0();
        ((Helper*)x)->f1();
        thunk(x);
    }
    if (b) ((Other*)b)->f1();
    vf = &vtRef;
}