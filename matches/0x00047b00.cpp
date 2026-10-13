class C {
  public:
    char pad[12];
    int mValue;
    bool Fn(int x);
};

bool C::Fn(int x) {
    mValue = x;
    return true;
}
