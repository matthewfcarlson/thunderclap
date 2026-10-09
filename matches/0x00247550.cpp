typedef void(__cdecl* Fn)(void*, int, int);
struct T {
    void* x;
    void* y;
    Fn f;
};
extern T* g;
void target(int a, int b) {
    g->f(g, a, b);
}