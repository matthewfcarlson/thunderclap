struct Args {
    int a, b, c;
};
class Inner {
  public:
    void A();
    void B(Args);
};
class Obj {
  public:
    char pad[0x88];
    Inner* m;
    void Run(Args x);
};
void Obj::Run(Args x) {
    if (m) {
        m->A();
        m->B(x);
    }
}