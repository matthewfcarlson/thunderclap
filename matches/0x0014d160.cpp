class T_14d160 {
  public:
    char pad[0x1c];
    unsigned char value;
    unsigned char Set(unsigned char v);
};
unsigned char T_14d160::Set(unsigned char v) {
    value = v;
    return 1;
}