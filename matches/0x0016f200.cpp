class Obj {
  public:
    char pad[0xc];
    void* mField;
    bool Set(void* p);
};
bool Obj::Set(void* p) {
    mField = p;
    return true;
}
