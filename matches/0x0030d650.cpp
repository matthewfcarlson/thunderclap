extern "C" void* ALLOC(int);
extern int PhysicsJoint_vftable;
extern int PhysicsJoint3D_vftable;

class Sub_30d650 {
  public:
    char data[0x1c];
    void Init();
};

struct Obj_30d650 {
    void* m_vtable;
    char pad1[0x1c];
    int a, b, c;
    char pad2[0x1c];
    Sub_30d650 s1;
    Sub_30d650 s2;
    char pad3[0xdc];
    void Copy(void*);
};

class PhysicsJoint {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual Obj_30d650* vfunc_27();
    virtual void vfunc_28(Obj_30d650*);
};

class PhysicsJoint3D : public PhysicsJoint {
  public:
    Obj_30d650* vfunc_27();
};

Obj_30d650* PhysicsJoint3D::vfunc_27() {
    Obj_30d650* p = (Obj_30d650*)ALLOC(0x15c);
    if (p != 0) {
        *(void* volatile*)&p->m_vtable = (void*)&PhysicsJoint_vftable;
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->s1.Init();
        p->s2.Init();
        *(void* volatile*)&p->m_vtable = (void*)&PhysicsJoint3D_vftable;
    } else {
        p = 0;
    }
    p->Copy(this);
    this->vfunc_28(p);
    return p;
}
