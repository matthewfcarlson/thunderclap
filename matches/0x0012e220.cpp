class C {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool C::Set(int v) {
    mValue = v;
    return true;
}
