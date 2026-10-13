class X {
  public:
    char pad[0x18];
    int m18;
    void Set(int v);
};

void X::Set(int v) {
    m18 = v;
}
