// cl-flags: /O2 /GR /GX

class NonCopyable {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

class QueuedNodeAction : public NonCopyable {
  public:
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(int param1, int param2);

    char pad_4[8];    // 0x4 - 0xc
    int m_flags;      // 0xc
    char pad_c[0x1c]; // 0x10 - 0x2c (28 bytes)
    struct Data {
        void func_22f0(int a, int b);
        void func_1f20(int a);
        bool func_24b0(int a);
        void func_1ee0();
        char pad[0x28]; // size 0x28 to reach 0x54
    } m_data;           // 0x2c
    int m_54;           // 0x54
    char m_58;          // 0x58
};

void QueuedNodeAction::vfunc_5(int param1, int param2) {
    if (param1 == 0 && m_58 == 0) {
        m_data.func_22f0(m_54, param2);
    }
    m_58 = 0;
    m_data.func_1f20(param1);
    if (param1 == m_54 - 1) {
        if (m_data.func_24b0(0)) {
            m_flags &= 0xfffffffc;
            m_data.func_1ee0();
            return;
        }
        m_flags = (m_flags & 0xfffffffd) | 1;
    }
    m_data.func_1ee0();
}