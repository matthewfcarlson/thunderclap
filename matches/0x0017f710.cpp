class Obj_17f710 {
  public:
    char pad[0x15];
    char m15;
    unsigned char SetAtEnd_0017f710(unsigned char value);
};

unsigned char Obj_17f710::SetAtEnd_0017f710(unsigned char value) {
    m15 = value;
    return 1;
}
