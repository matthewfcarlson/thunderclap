class d3dShader_32dba0 {
  public:
    virtual void V();
    d3dShader_32dba0(int);
};
class d3dLayeredShader_32dba0 : public d3dShader_32dba0 {
  public:
    char pad[0x7c];
    int a;
    int b;
    int special;
    int c;
    unsigned char d;
    unsigned char e;
    char pad2[2];
    int f;
    int g;
    d3dLayeredShader_32dba0(int);
};
d3dLayeredShader_32dba0::d3dLayeredShader_32dba0(int x) : d3dShader_32dba0(x), special(4) {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
}