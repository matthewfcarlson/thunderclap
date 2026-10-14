class X_14cb10 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool X_14cb10::Set(int v) {
    mValue = v;
    return true;
}
