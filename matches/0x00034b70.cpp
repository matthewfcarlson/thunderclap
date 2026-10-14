class Obj {
  public:
    char pad[0x1b48];
    unsigned char m;
    void Set(unsigned char v);
};

void Obj::Set(unsigned char v) {
    m = v;
}
