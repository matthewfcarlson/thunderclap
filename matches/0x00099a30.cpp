class Obj {
  public:
    char pad[0xc4];
    char* ptr;
    void Set(unsigned char v);
};
void Obj::Set(unsigned char v) {
    ptr[0x2cd] = v;
}
