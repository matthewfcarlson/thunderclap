class C {
  public:
    char pad[12];
    int mVal;
    bool Set(int x);
};

bool C::Set(int x) {
    mVal = x;
    return true;
}
