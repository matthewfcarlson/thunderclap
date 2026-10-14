class X_17f890 {
  public:
    char pad[0x0c];
    int value;
    char Set(int v);
};
char X_17f890::Set(int v) {
    value = v;
    return 1;
}
