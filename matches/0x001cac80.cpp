extern "C" void* memset(void*, int, unsigned int);
struct Obj {
    int a, b, c, d, e, f, g;
    Obj(int x, int y);
};
Obj::Obj(int x, int y) {
    memset(this, 0, 28);
    a = 28;
    b = 24;
    f = x;
    g = y;
}