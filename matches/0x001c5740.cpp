class Arg {
  public:
    int convert(Arg*);
};
class X {
  public:
    void g(int);
    void f(Arg*);
};
void X::f(Arg* n) {
    g(n->convert(n));
}