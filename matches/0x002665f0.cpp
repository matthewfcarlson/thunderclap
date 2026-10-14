struct Other_2665f0 {
    virtual void f0();
    virtual void f1();
};
struct Helper_2665f0 {
    void f0();
    void f1();
};
struct Obj_2665f0 {
    void* vf;
    char pad[8];
    void* a;
    void* b;
    void run();
};
extern void* vtLoad_2665f0;
extern void* vtRef_2665f0;
extern void thunk(void*);
void Obj_2665f0::run() {
    void* x = a;
    vf = &vtLoad_2665f0;
    if (x) {
        ((Helper_2665f0*)x)->f0();
        ((Helper_2665f0*)x)->f1();
        thunk(x);
    }
    if (b)
        ((Other_2665f0*)b)->f1();
    vf = &vtRef_2665f0;
}