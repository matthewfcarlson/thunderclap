typedef void(__fastcall* Fn)(void*);
struct Obj {
    Fn* v;
};
extern Obj* gObj;
struct U {
    void f(int);
};
struct T {
    char pad[0x10];
    U* m;
    void go(int);
};
void T::go(int x) {
    gObj->v[91](gObj);
    m->f(x);
}
