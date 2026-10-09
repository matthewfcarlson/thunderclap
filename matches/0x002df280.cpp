// Same code shape as 0x002df200 (propagated; names are from that function)
class ShadowMesh {
  public:
    char pad[0x48];
    void* field;
    void vfunc_23(unsigned int);
};
void ShadowMesh::vfunc_23(unsigned int x) {
    *(unsigned int*)(*(unsigned int*)field + 0x50) = x;
}