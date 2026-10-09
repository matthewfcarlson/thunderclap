// Same code shape as 0x001c3830 (propagated; names are from that function)
class Inner {
  public:
    void f();
};
class Outer {
  public:
    Inner* p;
    void g();
};
void Outer::g() {
    p->f();
}