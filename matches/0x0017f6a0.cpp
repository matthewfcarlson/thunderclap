class C {
  public:
    char pad[12];
    unsigned char mValue;
    bool Set(unsigned char x);
};

bool C::Set(unsigned char x) {
    mValue = x;
    return true;
}
