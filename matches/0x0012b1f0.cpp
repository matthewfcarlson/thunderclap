class Obj_12b1f0 {
  public:
    char pad[0x20];
    char m20;
    unsigned char SetThreatRespondOnlyOnce_0012b1f0(unsigned char v);
};

unsigned char Obj_12b1f0::SetThreatRespondOnlyOnce_0012b1f0(unsigned char v) {
    m20 = (char)v;
    return 1;
}
