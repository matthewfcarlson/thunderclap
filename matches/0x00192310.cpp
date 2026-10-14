class X {
  public:
    char pad[0x5c];
    int value;
    bool Set(int v);
};

bool X::Set(int v) {
    value = v;
    return true;
}
