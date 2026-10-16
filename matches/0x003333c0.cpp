class Obj {
  public:
    char pad[0x40];
    int flag;
    void Set(void* p);
};
void Obj::Set(void* p) {
    flag = p != 0;
}