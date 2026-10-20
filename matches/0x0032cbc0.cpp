extern "C" char DAT_00433a8c[];
class d3dProjectedTextureShader_32cbc0 {
  public:
    void InitBase(void*);
    char pad[0x80];
    int a, b;
    void InitMember();
    d3dProjectedTextureShader_32cbc0* Target(void*);
};
d3dProjectedTextureShader_32cbc0* d3dProjectedTextureShader_32cbc0::Target(void* arg) {
    InitBase(arg);
    *(void**)this = (void*)((int)DAT_00433a8c);
    a = 0;
    b = 0;
    ((d3dProjectedTextureShader_32cbc0*)((char*)this + 0x88))->InitMember();
    return this;
}