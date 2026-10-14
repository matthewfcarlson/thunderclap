class Obj_1ef320 {
  public:
    char pad[0x40];
    int field;
    void Init();
    Obj_1ef320* Target();
};
Obj_1ef320* Obj_1ef320::Target() {
    Obj_1ef320* p = this;
    for (int i = 0; i < 8; ++i) {
        p->Init();
        p = (Obj_1ef320*)((char*)p + 8);
    }
    field = 0;
    return this;
}