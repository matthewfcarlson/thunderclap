class X_143250 {
  public:
    char pad[0x10];
    int value;
    unsigned char Set(int v);
};

unsigned char X_143250::Set(int v) {
    value = v;
    return 1;
}
