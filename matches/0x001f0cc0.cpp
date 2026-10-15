class Obj {
  public:
    void method(int, int, int, int, int, int);
};
typedef void (Obj::*Callback)(int, int, int, int, int, int);
void invoke(Obj* obj, int* data, int unused, Callback cb) {
    int a = *data++;
    int b = *data++;
    volatile int c = *data++;
    volatile int d = *data++;
    int f = data[1];
    int e = *data;
    (obj->*cb)(a, b, c, d, e, f);
}