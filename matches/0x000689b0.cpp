class X {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};

bool X::Set(int v) {
    mValue = v;
    return true;
}
