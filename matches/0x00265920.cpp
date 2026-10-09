extern "C" char* strncpy(char*, const char*, unsigned);
struct S {
    char buf[256];
    int a;
    int b;
    int c;
    char f;
};
class C {
  public:
    void Fn(S*, int);
    void Go(const char* s, int x, int z);
};
void C::Go(const char* s, int x, int z) {
    S l;
    l.f = (z == 0);
    l.buf[0] = 0;
    l.a = 0;
    l.b = 0;
    l.c = 0;
    if (s)
        strncpy(l.buf, s, 0xff);
    Fn(&l, x);
}
