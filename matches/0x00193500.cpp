class X_193500 {
  public:
    char pad[0xd4];
    int mValue;
    bool Set(int a);
};

bool X_193500::Set(int a) {
    mValue = a;
    return true;
}
