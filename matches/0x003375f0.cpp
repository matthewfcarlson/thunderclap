extern char g_vtbl[];

class Elem {
  public:
    void Init();
};

class Container {
  public:
    int m_vptr;         // 0x00
    int field4;         // 0x04
    char elems[0x5100]; // 0x08 .. 0x5108
    int f5108;          // 0x5108
    int f510c;          // 0x510c

    Container* Init();
};

Container* Container::Init() {
    *(int*)this = (int)g_vtbl;
    char* p = elems;
    for (int i = 0x20; i != 0; --i) {
        ((Elem*)p)->Init();
        p += 0x288;
    }
    field4 = 0;
    f5108 = 0;
    f510c = 0;
    return this;
}
