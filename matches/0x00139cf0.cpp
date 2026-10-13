class C {
  public:
    char pad[0x28];
    int m28;
    bool Set(int v);
};
bool C::Set(int v) {
    m28 = v;
    return true;
}
