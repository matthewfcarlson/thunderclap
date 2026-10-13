class X {
  public:
    char pad[0x10];
    int value;
    unsigned char Set(int v);
};

unsigned char X::Set(int v) {
    value = v;
    return 1;
}
