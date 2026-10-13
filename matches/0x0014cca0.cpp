class X {
  public:
    char pad[0x44];
    char m44;
    char Set(char v);
};

char X::Set(char v) {
    m44 = v;
    return 1;
}
