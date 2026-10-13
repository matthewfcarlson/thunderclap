class Obj {
  public:
    char pad[0x24];
    unsigned char value;
    void Set(unsigned char x);
};

void Obj::Set(unsigned char x) {
    value = x;
}