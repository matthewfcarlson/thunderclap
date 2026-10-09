struct S {
    int a, b, c;
};
class C {
  public:
    char pad[0xcc];
    S s;
    S* Get(S* p);
};
S* C::Get(S* p) {
    *p = s;
    return p;
}
