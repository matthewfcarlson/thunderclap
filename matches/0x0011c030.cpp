class X {
  public:
    char pad[0x1c];
    int value;
    bool Set(int v);
};

bool X::Set(int v) {
    value = v;
    return true;
}
