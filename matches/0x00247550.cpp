typedef void(__cdecl* Fn_247550)(void*, int, int);
struct T_247550 {
    void* x;
    void* y;
    Fn_247550 f;
};
extern T_247550* g_247550;
void target(int a, int b) {
    g_247550->f(g_247550, a, b);
}