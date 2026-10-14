class X {
  public:
    char pad[0x4c];
    int value;
    char Set(int x);
};

char X::Set(int x) {
    value = x;
    return 1;
}
