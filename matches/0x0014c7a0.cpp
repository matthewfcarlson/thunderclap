class X {
  public:
    bool Set(int v);
    char pad[0x10];
    int m10;
};

bool X::Set(int v) {
    m10 = v;
    return true;
}
