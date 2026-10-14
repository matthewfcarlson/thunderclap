class Obj_11bcc0 {
  public:
    char pad[0x2c];
    char value;
    unsigned char Set(unsigned char x);
};
unsigned char Obj_11bcc0::Set(unsigned char x) {
    value = x;
    return 1;
}
