class Obj_1a2b80 {
  public:
    char Set(unsigned char value);
    char pad[0x159];
    char m159;
};

char Obj_1a2b80::Set(unsigned char value) {
    m159 = value;
    return 1;
}
