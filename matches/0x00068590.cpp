class C {
  public:
    char pad[0x10];
    int m;
    bool Set(int v);
};
bool C::Set(int v) {
    m = v;
    return true;
}