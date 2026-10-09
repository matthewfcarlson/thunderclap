class X {
  public:
    void call(int);
};
class C {
  public:
    char pad[0x374c];
    X* items[1];
    char pad2[0x379c - 0x3750];
    int count;
    void f(int);
};
void C::f(int p) {
    for (int i = 0; i < count; ++i)
        items[i]->call(p);
}