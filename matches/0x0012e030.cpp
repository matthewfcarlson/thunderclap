class Obj_12e030 {
  public:
    char pad[0x14];
    void* m14;
    bool Set(void* p);
};
bool Obj_12e030::Set(void* p) {
    m14 = p;
    return true;
}
