class Obj {
  public:
    char pad[0x19];
    char mVal;
    void Set(unsigned char v);
};
void Obj::Set(unsigned char v) {
    mVal = (char)v;
}
