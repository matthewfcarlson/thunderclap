class Obj_16f200 {
  public:
    char pad[0xc];
    void* mField;
    bool Set(void* p);
};
bool Obj_16f200::Set(void* p) {
    mField = p;
    return true;
}
