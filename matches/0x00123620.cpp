class C {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};
bool C::Set(int v) {
    mValue = v;
    return true;
}