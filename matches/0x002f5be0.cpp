class BlockA {
  public:
    int m_x;
    int m_y;
    int m_data[5];
    void Set(void* p);
};

class BlockB {
  public:
    void Copy(BlockA* a);
};

class PhysicsObject {
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vfunc_39();

    char pad1[0x54];
    int m_58;
    char pad2[0x84];
    int m_e0;
    int m_src[5];
    BlockA m_blockA;
    BlockB m_blockB;
};

void PhysicsObject::vfunc_39() {
    m_blockA.m_y = m_e0;
    int* ps = &m_src[0];
    BlockA* p = &m_blockA;
    p->m_data[0] = ps[0];
    p->m_data[1] = ps[1];
    p->m_data[2] = ps[2];
    p->m_data[3] = ps[3];
    p->m_data[4] = ps[4];
    p->Set(&m_58);
    m_blockB.Copy(p);
}
