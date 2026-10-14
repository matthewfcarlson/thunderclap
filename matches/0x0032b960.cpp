class Obj {
  public:
    char pad[0x89];
    char mFlag;
    void Set(void* x);
};
void Obj::Set(void* x) {
    mFlag = (x != 0);
}
