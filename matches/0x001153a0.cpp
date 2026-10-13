class X {
  public:
    char pad[0x2a];
    char m2a;
    char Set(char v);
};

char X::Set(char v) {
    m2a = v;
    return 1;
}
