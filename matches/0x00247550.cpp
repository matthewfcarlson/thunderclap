typedef int(__cdecl* Fn_247550)(void*, int, int);
struct T_247550 {
    void* x;
    void* y;
    Fn_247550 f;
};
extern T_247550* g_247550;
int target(int a, int b) {
    return g_247550->f(g_247550, a, b);
}