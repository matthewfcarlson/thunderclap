// cl-flags: /O2 /GR /GX

class CFMVManager;

class Base_1b7c00 {
  public:
    virtual ~Base_1b7c00() throw() {}
    virtual void VFunc1() throw() {}
    virtual void VFunc2() throw() {}
    int m_data[3];
    Base_1b7c00(int a, int b); // defined externally (FUN_001d0480)
};

class Delegate_1b7c00 : public Base_1b7c00 {
  public:
    unsigned char m_b10; // 0x10
    unsigned char m_b11; // 0x11
    unsigned char m_b12; // 0x12
    unsigned char m_b13; // 0x13
    char m_pad2[4];      // 0x14-0x17
    unsigned char m_b18; // 0x18
    char m_pad3[3];      // 0x19-0x1b
    void* m_ptr1c;       // 0x1c

    Delegate_1b7c00(int a1, void* a2);
    virtual void Invoke(float, float, float, float) throw() {}
    virtual ~Delegate_1b7c00() throw() {}
};

extern "C" unsigned char __cdecl FUN_001d04d0(void*);

extern "C" char g_48e100;
extern "C" char g_48e128;

Delegate_1b7c00::Delegate_1b7c00(int a1, void* a2) : Base_1b7c00(a1, 4) {
    m_ptr1c = a2;
    m_b18 = FUN_001d04d0(&g_48e100);
    m_b10 = FUN_001d04d0(&g_48e128);
    m_b11 = FUN_001d04d0(&g_48e128);
    m_b12 = FUN_001d04d0(&g_48e128);
    m_b13 = FUN_001d04d0(&g_48e128);
}