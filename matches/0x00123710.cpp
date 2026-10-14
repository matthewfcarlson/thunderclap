class Obj_123710 {
  public:
    char pad[0x15];
    char m15;
    char Set(unsigned char value);
};

char Obj_123710::Set(unsigned char value) {
    m15 = value;
    return 1;
}
