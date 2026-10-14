class A {
  public:
    char pad[0xc];
    int mValue;
    bool Fn(int v);
};

bool A::Fn(int v) {
    mValue = v;
    return true;
}
