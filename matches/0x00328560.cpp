class Obj_328560 {
  public:
    char pad[0x94];
    unsigned char flag;
    void Set(void* p);
};

void Obj_328560::Set(void* p) {
    flag = (p != 0);
}
