extern "C" char* strncpy(char*, const char*, unsigned);
struct S_265920 {
    char buf[256];
    int a;
    int b;
    int c;
    char f;
};
class C_265920 {
  public:
    void Fn(S_265920*, int);
    void Go(const char* s, int x, int z);
};
void C_265920::Go(const char* s, int x, int z) {
    S_265920 l;
    l.f = (z == 0);
    l.buf[0] = 0;
    l.a = 0;
    l.b = 0;
    l.c = 0;
    if (s)
        strncpy(l.buf, s, 0xff);
    Fn(&l, x);
}
