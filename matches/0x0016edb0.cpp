class X {
  public:
    char Set(int value);
    char pad[0x48];
    int m48;
};

char X::Set(int value) {
    m48 = value;
    return 1;
}
