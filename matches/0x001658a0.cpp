class T_1658a0 {
  public:
    char pad[0x35];
    unsigned char m35;
    unsigned char Set(unsigned char v);
};

unsigned char T_1658a0::Set(unsigned char v) {
    m35 = v;
    return 1;
}
