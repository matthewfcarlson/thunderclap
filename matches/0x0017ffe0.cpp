class X {
  public:
    char pad[0x44];
    int mValue;
    char Set(int value);
};

char X::Set(int value) {
    mValue = value;
    return 1;
}
