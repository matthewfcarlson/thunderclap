typedef void(__fastcall* Fn_283480)(void*);
struct Obj_283480 {
    Fn_283480* v;
};
extern Obj_283480* gObj_283480;
struct U_283480 {
    void f(int);
};
struct T_283480 {
    char pad[0x10];
    U_283480* m;
    void go(int);
};
void T_283480::go(int x) {
    gObj_283480->v[91](gObj_283480);
    m->f(x);
}
