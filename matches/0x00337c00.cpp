extern int vtable;
class X {
  public:
    X();
    int* p;
};
X::X() {
    p = &vtable;
}