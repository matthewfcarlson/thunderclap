class Obj_2c100 {
  public:
    char pad[0x50];
    char m50;
    void Set(unsigned char v);
};
void Obj_2c100::Set(unsigned char v) {
    m50 = v;
}
