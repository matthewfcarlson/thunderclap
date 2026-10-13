class X {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};
bool X::Set(int v) {
    mValue = v;
    return true;
}
