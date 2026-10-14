class Obj {
  public:
    char pad[0x84];
    unsigned char flag;
    void SetFlag(void* p);
};
void Obj::SetFlag(void* p) {
    flag = (p != 0);
}