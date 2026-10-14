class C_15b350 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool C_15b350::Set(int v) {
    mValue = v;
    return true;
}