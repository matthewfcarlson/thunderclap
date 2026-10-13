class X {
  public:
    char Set(char v);
    char pad[0x3b];
    char m3b;
};

char X::Set(char v) {
    m3b = v;
    return 1;
}
