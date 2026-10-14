class Obj_1653a0 {
  public:
    char pad[0x14];
    void* mValue;
    bool Set(void* p);
};
bool Obj_1653a0::Set(void* p) {
    mValue = p;
    return true;
}