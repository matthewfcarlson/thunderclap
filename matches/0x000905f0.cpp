class Obj_905f0 {
  public:
    char pad[0x19];
    unsigned char active;
    char rest[0xc80 - 0x1a];
    int count;
    void process();
    void target();
};
void Obj_905f0::target() {
    int i;
    for (i = 0; i < count; ++i) {
        Obj_905f0* cur = (Obj_905f0*)((char*)this + i * 0x40);
        if (cur->active)
            cur->process();
    }
}