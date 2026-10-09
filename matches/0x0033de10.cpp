extern "C" {
int FUN_00213120(void* L, int a);
void FUN_00339d70(void* L, int a, int b);
int FUN_00212f00(void* L, int a);
void FUN_002135a0(void* L, int a, const char* s);
void FUN_00212ed0(void* L, int a);
void FUN_00213360(void* L, int a);
void FUN_00213640(void* L, int a, int b);
}

int FUN_0033de10(void* L) {
    int n = FUN_00213120(L, 2);
    FUN_00339d70(L, 1, 5);
    if (n == 0 && FUN_00212f00(L, 2) == -1) {
        FUN_002135a0(L, -10001, "ipairs");
        FUN_00212ed0(L, 1);
        FUN_00213360(L, n);
        return 3;
    }
    n++;
    FUN_00213360(L, n);
    FUN_00213640(L, 1, n);
    return FUN_00212f00(L, -1) != 0 ? 2 : 0;
}
