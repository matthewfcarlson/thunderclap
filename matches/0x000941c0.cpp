struct Obj {
    void Run(int, int, int, int, int, int);
};
typedef void (Obj::*Fn)(int, int, int, int, int, int);
void dispatch(Obj* obj, int* a, int unused, Fn fn) {
    int x0 = *a;
    ++a;
    int x1 = *a;
    ++a;
    int x2 = *a;
    ++a;
    int x3 = *a;
    ++a;
    int x4 = *a;
    int x5 = a[1];
    (obj->*fn)(x0, x1, x2, x3, x4, x5);
}