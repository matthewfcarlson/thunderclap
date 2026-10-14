class C {
  public:
    char Pad[0x10];
    int mValue;
    char Fn(int value);
};
char C::Fn(int value) {
    mValue = value;
    return 1;
}
