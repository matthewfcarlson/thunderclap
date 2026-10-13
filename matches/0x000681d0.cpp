class Obj {
  public:
    char pad[0x2c];
    void* m2c;
    bool Set(void* p);
};
bool Obj::Set(void* p) {
    m2c = p;
    return true;
}
