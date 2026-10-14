class X {
  public:
    char pad[0x10];
    unsigned int m;
    char Set(unsigned int v);
};
char X::Set(unsigned int v) {
    m = v;
    return 1;
}
