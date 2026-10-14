class C_12e220 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool C_12e220::Set(int v) {
    mValue = v;
    return true;
}
