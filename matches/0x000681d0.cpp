class Obj_681d0 {
  public:
    char pad[0x2c];
    void* m2c;
    bool Set(void* p);
};
bool Obj_681d0::Set(void* p) {
    m2c = p;
    return true;
}
