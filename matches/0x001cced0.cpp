class Obj {
  public:
    char pad0[0x11a4];
    float value;
    int a;
    int b;
    int c;
    int d;
    int entries[16];
    char pad[0x13f8 - 0x11b8 - 64];
    char flag;
    void init();
};
void Obj::init() {
    int i;
    for (i = 0; i < 16; i++) {
        entries[i] = 0;
        *((char*)this + 0x11f8 + i * 0x20) = 0;
    }
    flag = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    value = 0.75f;
}
