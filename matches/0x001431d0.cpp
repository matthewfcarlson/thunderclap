class X {
  public:
    char pad0[0x20];
    int value;
    char Set(int v);
};

char X::Set(int v) {
    value = v;
    return 1;
}
