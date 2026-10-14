class C_180430 {
  public:
    bool Set(int value);
    char pad[12];
    int mValue;
};

bool C_180430::Set(int value) {
    mValue = value;
    return true;
}
