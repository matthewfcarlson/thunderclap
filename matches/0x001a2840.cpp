class X_1a2840 {
  public:
    char pad[0xf4];
    int mF4;
    bool Set(int);
};

bool X_1a2840::Set(int v) {
    mF4 = v;
    return true;
}
