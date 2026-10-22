typedef unsigned int size_t;
void* operator new(size_t) throw();
class d3dRefractVertexShader_327fe0 {
  public:
    d3dRefractVertexShader_327fe0(void*) throw();
    char pad[0x9c];
};
d3dRefractVertexShader_327fe0* __cdecl makeItem(void* p) {
    return new d3dRefractVertexShader_327fe0(p);
}