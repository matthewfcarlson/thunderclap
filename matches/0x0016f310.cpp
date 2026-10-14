class X_16f310 {
  public:
    char Set(int v);

  private:
    char pad[0x38];
    int m38;
};

char X_16f310::Set(int v) {
    m38 = v;
    return 1;
}
