class X_61ca0 {
  public:
    char Set(int v);
    char pad[0xc8];
    int value;
};
char X_61ca0::Set(int v) {
    value = v;
    return 1;
}
