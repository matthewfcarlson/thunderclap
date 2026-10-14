class X {
  public:
    char pad[0x10];
    int m10;
    char Set(int value);
};

char X::Set(int value) {
    m10 = value;
    return 1;
}
