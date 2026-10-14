class C {
  public:
    char pad[12];
    int mValue;
    bool Set(int value);
};

bool C::Set(int value) {
    mValue = value;
    return true;
}
