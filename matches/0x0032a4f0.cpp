class Obj_32a4f0 {
  public:
    char pad[0x84];
    unsigned char flag;
    void SetFlag(void* p);
};
void Obj_32a4f0::SetFlag(void* p) {
    flag = (p != 0);
}