class C_77e00 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool C_77e00::Set(int v) {
    mValue = v;
    return true;
}
