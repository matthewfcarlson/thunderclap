extern "C" {
void FUN_00213550(void* L, const void* p);
void FUN_00213600(void* L, int i);
int FUN_00212f00(void* L, int i);
void FUN_002133d0(void* L, const char* s);
void FUN_00213360(void* L, int n);
void FUN_00213320(void* L);
void FUN_002139a0(void* L, int a, int b);
}

extern const char* g_names[];
extern const char g_key[];

void FUN_0033a620(void* L, int* p) {
    FUN_00213550(L, g_key);
    FUN_00213600(L, -10000);
    FUN_00213550(L, L);
    FUN_00213600(L, -2);
    if (FUN_00212f00(L, -1) == 6) {
        FUN_002133d0(L, g_names[*p]);
        if (p[5] >= 0) {
            FUN_00213360(L, p[5]);
        } else {
            FUN_00213320(L);
        }
        FUN_002139a0(L, 2, 0);
    }
}
