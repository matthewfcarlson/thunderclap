extern void* g_vftable_1cd150[];
extern "C" void* memset(void*, int, unsigned);
struct Slot_1cd150 {
    float f;
    char c;
    char pad[0xff];
    int m;
    Slot_1cd150() throw() {
        f = -1.0f;
        c = 0;
        m = -1;
    }
};
struct T_1cd150 {
    char b;
    char pad[0x1f];
};
struct Base_1cd150 {
    void* vptr;
    Base_1cd150() throw() { vptr = g_vftable_1cd150; }
};
class CScenarioManager_1cd150 : public Base_1cd150 {
  public:
    int m4;
    int m8;
    int mc;
    char buf[0x100];
    Slot_1cd150 s[16];
    int m1190;
    int m1194;
    int m1198;
    float m119c;
    char m11a0;
    char pad[0x1418 - 0x11a1];
    T_1cd150 t[4];
    int d[4];
    char m14a8;
    char m14a9;
    CScenarioManager_1cd150() throw();
    void Init() throw();
};
CScenarioManager_1cd150::CScenarioManager_1cd150() throw() {
    m4 = 0;
    mc = 0;
    m1198 = 0;
    m119c = -1.0f;
    m11a0 = 0;
    m1194 = 0;
    m14a8 = 0;
    m14a9 = 0;
    for (int i = 0; i < 0x40; i++)
        ((int*)buf)[i] = 0;
    {
        char* p = (char*)&s[0].m;
        for (int i = 0; i < 16; i++) {
            *(float*)(p - 0x104) = -1.0f;
            *(char*)(p - 0x100) = 0;
            *(int*)p = -1;
            p += 0x108;
        }
    }
    m1190 = 0;
    Init();
    for (int i = 0; i < 4; i++) {
        t[i].b = 0;
        d[i] = 0;
    }
}
