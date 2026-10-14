class X_14cf40 {
  public:
    char pad[0x15];
    char m;
    char Set(char v);
};

char X_14cf40::Set(char v) {
    m = v;
    return 1;
}
