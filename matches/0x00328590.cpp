class Obj {
  public:
    char pad[0x84];
    void* mPtr;
    void Set(void* p);
};
void Obj::Set(void* p) {
    mPtr = p;
}
