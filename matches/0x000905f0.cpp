class Obj {
  public:
    char pad[0x19];
    unsigned char active;
    char rest[0xc80 - 0x1a];
    int count;
    void process();
    void target();
};
void Obj::target() {
    int i;
    for (i = 0; i < count; ++i) {
        Obj* cur = (Obj*)((char*)this + i * 0x40);
        if (cur->active)
            cur->process();
    }
}