class A_1a2560 {
  public:
    char pad[0x98];
    unsigned char value;
    unsigned char Set(unsigned char v);
};

unsigned char A_1a2560::Set(unsigned char v) {
    value = v;
    return 1;
}
