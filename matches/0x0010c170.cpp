class Obj_10c170 {
  public:
    char pad[0x14];
    unsigned m14;
    unsigned char SetValue_0010c170(unsigned v);
};

unsigned char Obj_10c170::SetValue_0010c170(unsigned v) {
    m14 = v;
    return 1;
}
