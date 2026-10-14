class A {
  public:
    char pad[0x98];
    unsigned char value;
    unsigned char Set(unsigned char v);
};

unsigned char A::Set(unsigned char v) {
    value = v;
    return 1;
}
