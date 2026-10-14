class Obj {
  public:
    char pad[0x14];
    void* mValue;
    bool Set(void* p);
};
bool Obj::Set(void* p) {
    mValue = p;
    return true;
}