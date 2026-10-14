class T {
  public:
    char pad[0x1c];
    unsigned char value;
    unsigned char Set(unsigned char v);
};
unsigned char T::Set(unsigned char v) {
    value = v;
    return 1;
}