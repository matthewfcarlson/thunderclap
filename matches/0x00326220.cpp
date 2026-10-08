namespace pure3d {
class d3dTexture {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual unsigned int vfunc_4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    char pad[0xd0 - 4];
    unsigned int member;
};
unsigned int d3dTexture::vfunc_4() { return member; }
}