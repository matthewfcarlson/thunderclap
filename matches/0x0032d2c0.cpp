class X {
  public:
    char pad[0x8c];
    int m;
    void Set(int v);
};

void X::Set(int v) {
    m = v;
}
