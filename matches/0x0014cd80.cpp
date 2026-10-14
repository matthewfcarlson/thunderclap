class X {
  public:
    char pad[0x18];
    int value;
    bool Set(int v);
};

bool X::Set(int v) {
    value = v;
    return true;
}
