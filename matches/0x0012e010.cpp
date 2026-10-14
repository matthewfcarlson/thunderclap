class X_12e010 {
  public:
    char pad[0x10];
    int m10;
    char Set(int v);
};
char X_12e010::Set(int v) {
    m10 = v;
    return 1;
}
