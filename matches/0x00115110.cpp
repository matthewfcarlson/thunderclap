class Body_115110 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int x);
};

bool Body_115110::Set(int x) {
    mValue = x;
    return true;
}
