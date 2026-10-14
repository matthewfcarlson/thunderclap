class W_e2f80 {
  public:
    char p[8];
    int* Get(int);
};
class Z {
  public:
    char p[8];
    W_e2f80* w;
};
class Y_e2f80 {
  public:
    char p[4];
    Z* z;
};
class X_e2f80 {
  public:
    char p[8];
    Y_e2f80* y;
};
class Obj_e2f80 {
  public:
    char p[0x14];
    X_e2f80* x;
    char q[0x1d94 - 0x18];
    int* arr;
    void f(int);
};
void Obj_e2f80::f(int arg) {
    int* p = x->y->z->w->Get(arg);
    arr = p;
    if (p) {
        int i = 0;
        while (i < 4 && p[i + 1] != 0)
            ++i;
        if (i != 4)
            p[i + 1] = (int)this;
    }
}