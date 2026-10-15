struct Args {
    int a, b, c, d, e, f;
};
class Obj {
  public:
    void method(int, int, int, int, int, int);
};
typedef void (Obj::*Callback)(int, int, int, int, int, int);
void invoke(Obj* o, Args* p, int unused, Callback cb) {
    int* q = (int*)p;
    int a = *q++;
    int b = *q++;
    int c = *q++;
    int d = *q++;
    int e = *q++;
    int f = *q++;
    (o->*cb)(a, b, c, d, e, f);
}