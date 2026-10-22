struct Ref_32e840 {
    virtual void f();
    virtual void Release();
};
struct d3dLayeredShader_32e840 {
    virtual void f();
    void dtorBase();
};
struct d3dLayeredLMapShader_32e840 : d3dLayeredShader_32e840 {
    char pad[0x9c - 4];
    Ref_32e840* m;
    virtual ~d3dLayeredLMapShader_32e840();
};
d3dLayeredLMapShader_32e840::~d3dLayeredLMapShader_32e840() {
    if (m)
        m->Release();
    d3dLayeredShader_32e840::dtorBase();
}
