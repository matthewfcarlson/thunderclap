typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class d3dLayeredLMapShader_327fb0 {
    char pad[0xa0];

  public:
    d3dLayeredLMapShader_327fb0(int) throw();
};
d3dLayeredLMapShader_327fb0* __cdecl Make(int x) {
    return new d3dLayeredLMapShader_327fb0(x);
}
