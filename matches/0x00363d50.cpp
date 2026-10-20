extern "C" void __cdecl freeItem(void*);
struct Pair {
    int a, b;
};
extern Pair DAT_004ddab4;
void FUN_00363d50() {
    Pair* p = &DAT_004ddab4;
    int n = 13;
    do {
        --p;
        int v = p[0].a;
        if (v) {
            freeItem((void*)v);
            p[-1].b = 0;
            p[0].a = 0;
        }
    } while (--n);
}