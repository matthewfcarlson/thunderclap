struct Inner {
    void Do(int, int, int, int, int);
};
class X {
  public:
    char pad[0x1c];
    int sub;
    char p[0x5c - 0x20];
    int a;
    int b;
    int c;
    int d;
    unsigned char done;
    void f();
};
void X::f() {
    ((Inner*)*(int*)this)->Do((int)((char*)this + 0x1c), a, b, c, d);
    done = 1;
}