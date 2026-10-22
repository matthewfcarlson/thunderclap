typedef unsigned int size_t;
void* __cdecl operator new(size_t);
class d3dPointSpriteShader_327f50 {
  public:
    d3dPointSpriteShader_327f50(int) throw();
    char pad[0xa4];
};
d3dPointSpriteShader_327f50* __cdecl FUN_00327f50(int n) {
    return new d3dPointSpriteShader_327f50(n);
}
