class C {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int v);
};
bool C::Set(int v) {
    mValue = v;
    return true;
}
