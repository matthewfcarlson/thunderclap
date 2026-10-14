struct Base_333130 {
    void Init(int);
};
struct Shader {
    unsigned int* vptr;
    char pad[0x7c];
    unsigned int a, b, c;
    Shader* Make(int);
};
extern const float zeroF;
extern unsigned int vtblBump;
void __stdcall CreatePixelShader(const float* src, unsigned int* out);

Shader* Shader::Make(int n) {
    ((Base_333130*)this)->Init(n);
    vptr = (unsigned int*)&vtblBump;
    a = 0;
    b = 0;
    c = 0;
    CreatePixelShader(&zeroF, (unsigned int*)((char*)this + 0x8c));
    return this;
}
