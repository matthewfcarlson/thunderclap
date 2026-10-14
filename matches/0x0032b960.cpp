class Obj_32b960 {
  public:
    char pad[0x89];
    char mFlag;
    void Set(void* x);
};
void Obj_32b960::Set(void* x) {
    mFlag = (x != 0);
}
