class X_12e000 {
  public:
    char pad[0x10];
    char m10;
    char Set(char v);
};

char X_12e000::Set(char v) {
    m10 = v;
    return 1;
}
