extern int g_d8190;
struct R_d8190 {
    void finish();
};
struct A_d8190 {
    R_d8190* call(int, int, int);
};
struct Obj_d8190 {
    char pad[0x150];
    A_d8190* ptr;
    void target(int, int);
};
void Obj_d8190::target(int a, int b) {
    R_d8190* r = ptr->call(a, b, g_d8190);
    r->finish();
}
