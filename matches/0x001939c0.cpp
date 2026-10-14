class C {
  public:
    char pad[0x60];
    int m60;
    bool Set(int v);
};

bool C::Set(int v) {
    m60 = v;
    return true;
}
