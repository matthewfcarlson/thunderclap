class C {
  public:
    char pad[0x14];
    int m14;
    bool Set(int v);
};

bool C::Set(int v) {
    m14 = v;
    return true;
}
