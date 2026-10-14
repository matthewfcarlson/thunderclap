class Obj {
  public:
    char pad[0x1c];
    void* m1c;
    bool Set(void* p);
};
bool Obj::Set(void* p) {
    m1c = p;
    return true;
}