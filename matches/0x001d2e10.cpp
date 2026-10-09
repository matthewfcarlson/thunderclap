void FUN_002133d0(int L, int a);
void FUN_00213600(int L, int a);
int FUN_00212f00(int L, int a);
void FUN_00212d80(int L, int a);
int FUN_00339650(int L, int a);
struct C {
    char pad[8]; int L;
    bool F(int a, int* out);
};
bool C::F(int a, int* out) {
    FUN_002133d0(L, a);
    FUN_00213600(L, -2);
    bool r = true;
    if (FUN_00212f00(L, -1) != 6) {
        r = false;
        FUN_00212d80(L, -2);
    } else {
        *out = FUN_00339650(L, -10000);
    }
    return r;
}
