class C {
  public:
    char Set(int value);
    char pad[0x40];
    int mValue;
};

char C::Set(int value) {
    mValue = value;
    return 1;
}
