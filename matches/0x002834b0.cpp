// Same code shape as 0x00283480 (propagated; names are from that function)
typedef void(__fastcall* Fn_2834b0)(void*);
struct Obj_2834b0 {
    Fn_2834b0* v;
};
extern Obj_2834b0* gObj_2834b0;
struct U_2834b0 {
    void f(int);
};
struct T_2834b0 {
    char pad[0x10];
    U_2834b0* m;
    void go(int);
};
void T_2834b0::go(int x) {
    gObj_2834b0->v[91](gObj_2834b0);
    m->f(x);
}
