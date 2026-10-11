struct RTTI {
    char data[1];
};
extern RTTI DAT_004d3c0c, DAT_004d3bec;
extern void* __cdecl FUN_00344e74(void*, int, RTTI*, RTTI*, int);
struct Special {
    void FUN_003285d0(int);
};
struct Shader {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9(unsigned, void*);
    virtual void s10();
    virtual int s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual bool s22();
    virtual void s23();
    virtual void s24();
    void FUN_00327d00();
    void FUN_00327d20(int);
};
struct Output {
    void FUN_003272f0();
};
namespace pure3d {
struct d3dContext {
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
    virtual void v30();
    virtual void v31();
    virtual void vfunc_32(Shader*, Output*);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(int, void*);
    char pad[0x15c];
    Shader* defaultShader;
    char pad2[0x2b0];
    bool dirty;
    void FUN_00321310();
};
} // namespace pure3d
void pure3d::d3dContext::vfunc_32(Shader* shader, Output* output) {
    Special* special = (Special*)FUN_00344e74(shader, 0, &DAT_004d3bec, &DAT_004d3c0c, 0);
    if (special) {
        special->FUN_003285d0(0);
        return;
    }
    if (!shader)
        shader = defaultShader;
    if (dirty)
        FUN_00321310();
    unsigned values[3];
    v47(0, values);
    shader->s9(0x5654494c, values);
    if (shader->s22())
        shader->s24();
    int i = 0;
    if (shader->s11() > 0) {
        do {
            shader->FUN_00327d00();
            shader->FUN_00327d20(i);
            output->FUN_003272f0();
            ++i;
        } while (i < shader->s11());
    }
}
