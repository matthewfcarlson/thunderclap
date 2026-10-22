typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class d3dErrorShader_327e60 {
  public:
    d3dErrorShader_327e60(int) throw();
    char pad[0x80];
};
d3dErrorShader_327e60* __cdecl FUN_00327e60(int x) {
    return new d3dErrorShader_327e60(x);
}