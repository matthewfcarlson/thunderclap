class C_17f430 {
  public:
    char pad[12];
    int mValue;
    bool Set(int value);
};

bool C_17f430::Set(int value) {
    mValue = value;
    return true;
}
