class X {
  public:
    char pad[0x30];
    int m30;
    bool Set(int v);
};

bool X::Set(int v) {
    m30 = v;
    return true;
}
