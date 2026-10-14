class C_5d7f0 {
  public:
    char pad[0x20];
    int mValue;
    bool Set(int x);
};

bool C_5d7f0::Set(int x) {
    mValue = x;
    return true;
}
