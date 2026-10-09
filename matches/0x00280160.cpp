class Item {
  public:
    virtual void A();
    virtual void Release();
};
class Owner {
  public:
    char pad0[0x10];
    int state;
    char pad14[4];
    int clear;
    char pad1c[0x44];
    int first;
    int second;
    int x;
    int y;
    void Init();
};
void Owner::Init() {
    Owner* p = this;
    int n = 100;
    state = 1;
    do {
        p->clear = 0;
        p->x = 0;
        p->y = 0;
        p = (Owner*)((char*)p + 0x60);
        p = (Owner*)((char*)p - 0x60);
        if (p->first) {
            ((Item*)p->first)->Release();
            p->first = 0;
        }
        if (p->second) {
            ((Item*)p->second)->Release();
            p->second = 0;
        }
        p = (Owner*)((unsigned char*)p + 0x60);
        --n;
    } while (n != 0);
}
