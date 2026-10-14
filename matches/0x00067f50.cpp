class X_67f50 {
  public:
    char pad[0x20];
    char m20;
    char Set(char v);
};

char X_67f50::Set(char v) {
    m20 = v;
    return 1;
}
