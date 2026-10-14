class Obj_99a30 {
  public:
    char pad[0xc4];
    char* ptr;
    void Set(unsigned char v);
};
void Obj_99a30::Set(unsigned char v) {
    ptr[0x2cd] = v;
}
