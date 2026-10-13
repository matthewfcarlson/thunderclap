class Obj {
  public:
    char pad[0x50];
    char m50;
    void Set(unsigned char v);
};
void Obj::Set(unsigned char v) {
    m50 = v;
}
