class Obj {
  public:
    char pad[0x40];
    int field;
    void Init();
    Obj* Target();
};
Obj* Obj::Target() {
    Obj* p = this;
    for (int i = 0; i < 8; ++i) {
        p->Init();
        p = (Obj*)((char*)p + 8);
    }
    field = 0;
    return this;
}