extern int g_d8190;
struct R_d8190 {
    int finish(int, int, int);
};
struct A_d8190 {
    R_d8190* call();
};
struct FEMemCardControl_d8190 {
    char pad[0x150];
    A_d8190* ptr;
    int target(int, int);
};
int FEMemCardControl_d8190::target(int a, int b) {
    return ptr->call()->finish(a, b, g_d8190);
}
