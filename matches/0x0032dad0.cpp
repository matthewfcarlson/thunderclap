class Obj {
  public:
    char pad[0x91];
    unsigned char flag;
    void Set(void* p);
};
void Obj::Set(void* p) {
    flag = (p != 0);
}
