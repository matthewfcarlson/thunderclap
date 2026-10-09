struct Msg {
    int type;
    int a;
    int b;
    int c;
    int d;
    int e;
    char f0, f1, f2, f3;
};
class C {
  public:
    char pad[0x9c];
    void* h;
    void Send(Msg* m);
    void Fn(int a, int b, int c, int d, char e, char f, char g, char h2, char i);
};
void C::Fn(int a, int b, int c, int d, char e, char f, char g, char h2, char i) {
    if (h) {
        Msg m;
        m.a = a;
        m.b = b;
        m.c = c;
        m.d = d;
        m.e = (int)e;
        m.f0 = f;
        m.f1 = g;
        m.f2 = h2;
        m.type = 2;
        m.f3 = i;
        Send(&m);
    }
}
