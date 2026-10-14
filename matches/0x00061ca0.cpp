class X {
  public:
    char Set(int v);
    char pad[0xc8];
    int value;
};
char X::Set(int v) {
    value = v;
    return 1;
}
