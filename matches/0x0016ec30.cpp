class X_16ec30 {
  public:
    char pad[0x44];
    int m44;
    char Set(int a);
};

char X_16ec30::Set(int a) {
    m44 = a;
    return 1;
}
