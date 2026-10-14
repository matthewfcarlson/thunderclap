class X {
  public:
    char pad[0x15];
    char m;
    char Set(char v);
};

char X::Set(char v) {
    m = v;
    return 1;
}
