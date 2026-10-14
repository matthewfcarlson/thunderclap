class X_23ea30 {
  public:
    char pad[0x10];
    int m10;
    char Set(int value);
};

char X_23ea30::Set(int value) {
    m10 = value;
    return 1;
}
