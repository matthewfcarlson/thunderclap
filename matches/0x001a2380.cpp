class Obj_1a2380 {
  public:
    char pad[0x59];
    char m59;
    char Set(unsigned char c);
};
char Obj_1a2380::Set(unsigned char c) {
    m59 = c;
    return 1;
}
