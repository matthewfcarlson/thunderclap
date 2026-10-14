class Obj_14ca90 {
  public:
    char pad[0x50];
    char m50;
    unsigned char Set(unsigned char x);
};

unsigned char Obj_14ca90::Set(unsigned char x) {
    m50 = x;
    return 1;
}
