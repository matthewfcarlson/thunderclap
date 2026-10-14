class X_133730 {
  public:
    char Set(int a);
    char pad[0x24];
    int m24;
};

char X_133730::Set(int a) {
    m24 = a;
    return 1;
}
