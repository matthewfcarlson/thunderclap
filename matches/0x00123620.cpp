class C_123620 {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};
bool C_123620::Set(int v) {
    mValue = v;
    return true;
}