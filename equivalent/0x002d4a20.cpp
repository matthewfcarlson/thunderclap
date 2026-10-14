// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_002d4a20 @ 0x002d4a20
struct RefObj_2d4a20 {
    virtual void addRef();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual RefObj_2d4a20 *clone();
};

class __declspec(novtable) EmitterBase_2d4a20 {
  public:
    virtual void f0();
    char pad_04[0x3c];
    void FUN_002a5150(const EmitterBase_2d4a20 &src);
    EmitterBase_2d4a20(const EmitterBase_2d4a20 &src) { FUN_002a5150(src); }
};

class ParticleEmitter : public EmitterBase_2d4a20 {
  public:
    ParticleEmitter(const ParticleEmitter &src);
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
    virtual float f18(float);
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

    unsigned matrix[16];
    int field_80;
    RefObj_2d4a20 *ref_84;
    RefObj_2d4a20 *ref_88;
    RefObj_2d4a20 *ref_8c;
    RefObj_2d4a20 *ref_90;
    int field_94;
    int field_98;
    int field_9c;
    int field_a0;
    char flag_a4;
    char flag_a5;
    char flag_a6;
};

ParticleEmitter::ParticleEmitter(const ParticleEmitter &src) : EmitterBase_2d4a20(src)
{
    field_80 = 0;
    ref_84 = 0;
    ref_88 = 0;
    ref_8c = 0;
    ref_90 = 0;
    field_94 = src.field_94;
    field_98 = src.field_98;
    field_9c = src.field_9c;
    field_a0 = src.field_a0;
    flag_a4 = src.flag_a4;
    flag_a5 = src.flag_a5;
    flag_a6 = src.flag_a6;

    RefObj_2d4a20 *p = src.ref_84;
    if (p)
        p->addRef();
    if (ref_84)
        ref_84->release();
    ref_84 = p;

    RefObj_2d4a20 *q = src.ref_88;
    if (q) {
        RefObj_2d4a20 *c = q->clone();
        ref_88 = c;
        c->addRef();
    }

    p = src.ref_8c;
    if (p)
        p->addRef();
    if (ref_8c)
        ref_8c->release();
    ref_8c = p;

    p = src.ref_90;
    if (p)
        p->addRef();
    if (ref_90)
        ref_90->release();
    ref_90 = p;

    for (int i = 0; i < 16; i++)
        matrix[i] = src.matrix[i];
}
