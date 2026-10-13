class X {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int v);
};

bool X::Set(int v) {
    mValue = v;
    return true;
}
