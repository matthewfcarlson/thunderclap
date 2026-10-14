typedef unsigned int u32_e2130;
struct FELayout {
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
};
struct SingleLayout : FELayout {
    char pad[0x40 - 4];
    u32_e2130 field40;
    u32_e2130 field44;
    virtual void vfunc18(u32_e2130);
};
extern "C" u32_e2130 __cdecl helper(u32_e2130, int, const void*, const void*, int);
extern const char typeA_e2130[];
extern const char typeB_e2130[];
void SingleLayout::vfunc18(u32_e2130 x) {
    field40 = x;
    field44 = helper(x, 0, typeA_e2130, typeB_e2130, 0);
}