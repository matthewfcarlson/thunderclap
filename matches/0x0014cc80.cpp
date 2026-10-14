class C_14cc80 {
  public:
    char Set(int value);
    char pad[0x40];
    int mValue;
};

char C_14cc80::Set(int value) {
    mValue = value;
    return 1;
}
