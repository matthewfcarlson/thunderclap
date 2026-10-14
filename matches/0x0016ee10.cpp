class X {
  public:
    char pad[0x14];
    int value;
    char Set(int v);
};

char X::Set(int v) {
    value = v;
    return 1;
}
