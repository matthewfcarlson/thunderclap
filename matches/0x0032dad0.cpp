class Obj_32dad0 {
  public:
    char pad[0x91];
    unsigned char flag;
    void Set(void* p);
};
void Obj_32dad0::Set(void* p) {
    flag = (p != 0);
}
