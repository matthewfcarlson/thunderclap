class Arg {
  public:
    int convert();
};
class X {
  public:
    void g(int, Arg*);
    void f(Arg*);
};
void X::f(Arg* n) {
    g(n->convert(), n);
}