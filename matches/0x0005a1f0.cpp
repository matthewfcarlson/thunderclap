class Obj_5a1f0 {
  public:
    char pad[0x5c];
    char m5c;
    char Set(unsigned char x);
};

char Obj_5a1f0::Set(unsigned char x) {
    m5c = x;
    return 1;
}