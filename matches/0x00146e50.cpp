class Obj {
  public:
    char pad[0x10];
    void* m10;
    bool Fn(void* p);
};
bool Obj::Fn(void* p) {
    m10 = p;
    return true;
}
