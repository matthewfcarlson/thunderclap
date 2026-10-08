namespace pure3d {

class pddiObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

class pddiShader {
public:
};

class pddiBaseShader : public pddiShader {
public:
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_15();
    virtual void vfunc_19();
    virtual void vfunc_20();
};

class d3dShader : public pddiBaseShader {
public:
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
};

class d3dFBEffectsShader : public d3dShader {
public:
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
};

void d3dFBEffectsShader::vfunc_12() {
    return;
}

} // namespace pure3d
