class Obj_16eb30 {
  public:
    char pad[0x21];
    unsigned char value;
    unsigned char Set(unsigned char c);
};
unsigned char Obj_16eb30::Set(unsigned char c) {
    value = c;
    return 1;
}