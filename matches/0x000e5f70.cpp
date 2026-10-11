extern "C" void _ReadWriteBarrier();
class Probe {
  public:
    short* Find(int);
};
class Item {
    char pad[0x14];

  public:
    int id;
    char pad2[0x5c];
    unsigned char f74;
    char pad3[0xcc];
    unsigned char f141;
};
class Manager {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual int get(int);
};
class Owner {
    char pad[4];

  public:
    Manager* mgr;
    char pad2[0x40];
    int selected;
    char pad3[0x94c];
    Item* items[3];
    char pad4[4];
    unsigned char done;
    void Update();
};
void Owner::Update() {
    Item* a[3];
    a[0] = items[0];
    a[1] = items[1];
    a[2] = items[2];
    int i = 0;
    do {
        Item* p = a[i];
        if (p) {
            int x = mgr->get(0);
            short* q = ((Probe*)((char*)p + 0x18))->Find(x);
            if (q && *q) {
                p->f141 = 1;
                p->f74 = 1;
                if (!selected)
                    selected = p->id;
            } else {
                p->f141 = 0;
                p->f74 = 0;
                _ReadWriteBarrier();
                if (selected == p->id)
                    selected = 0;
            }
        }
        i++;
    } while (i < 3);
    done = 1;
}