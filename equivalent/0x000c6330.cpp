// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c6330 @ 0x000c6330
struct V3_c6330 {
    float x, y, z;
};

class Shader {
public:
    virtual void AddRef();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void setParam(unsigned int tag, int value);
};

class ShaderLib {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Shader *find(const char *name, int flag);
};

class Prim;

class Gfx_c6330 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Prim *begin(Shader *shader, int count, int kind, int stride, int flags);
    virtual void end(Prim *prim);
};

extern Shader *DAT_004dde68;
extern ShaderLib *DAT_0052c2a0;
extern Gfx_c6330 *DAT_0052c2a8;

void __cdecl FUN_000c5fa0(Prim *prim, V3_c6330 a, V3_c6330 b, unsigned int color);

void FUN_000c6330(V3_c6330 c0, V3_c6330 c1, V3_c6330 c2, V3_c6330 c3, V3_c6330 c4, V3_c6330 c5, V3_c6330 c6, V3_c6330 c7, unsigned int color, int count)
{
    if (DAT_004dde68 == 0) {
        DAT_004dde68 = DAT_0052c2a0->find("simple", 0);
        DAT_004dde68->AddRef();
        DAT_004dde68->setParam(0x444d4c42, 1);
    }
    Prim *prim = DAT_0052c2a8->begin(DAT_004dde68, count, 0x2020, 0x18, 0);
    if (prim) {
        FUN_000c5fa0(prim, c0, c1, color);
        FUN_000c5fa0(prim, c1, c3, color);
        FUN_000c5fa0(prim, c3, c2, color);
        FUN_000c5fa0(prim, c2, c0, color);
        FUN_000c5fa0(prim, c4, c5, color);
        FUN_000c5fa0(prim, c5, c7, color);
        FUN_000c5fa0(prim, c7, c6, color);
        FUN_000c5fa0(prim, c6, c4, color);
        FUN_000c5fa0(prim, c0, c4, color);
        FUN_000c5fa0(prim, c1, c5, color);
        FUN_000c5fa0(prim, c2, c6, color);
        FUN_000c5fa0(prim, c3, c7, color);
    }
    DAT_0052c2a8->end(prim);
}
