class C {
  public:
    bool Set(int value);
    char pad[12];
    int mValue;
};

bool C::Set(int value) {
    mValue = value;
    return true;
}
