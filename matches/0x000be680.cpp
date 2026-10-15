class Obj {
  public:
    void act(int, int, int, int, int, int);
};
typedef void (Obj::*Func)(int, int, int, int, int, int);
void forward(Obj* obj, int* v, int unused, Func fn) {
    int a = *v++;
    int b = *v++;
    int c = *v++;
    int d = *v++;
    int e = v[1];
    int f = v[0];
    (obj->*fn)(a, b, c, d, f, e);
}