typedef unsigned int size_t;
void* operator new(size_t) throw();
class MeshData {
  public:
    char pad[0x70];
    MeshData() throw();
};
class Shadow_2deeb0 {
  public:
    Shadow_2deeb0(int) throw();
    void Set(int, MeshData*) throw();
    virtual void dummy();
};
class ShadowMesh : public Shadow_2deeb0 {
  public:
    ShadowMesh() throw();
    virtual void dummy();
};
ShadowMesh::ShadowMesh() throw() : Shadow_2deeb0(1) {
    MeshData* p = new MeshData;
    Set(0, p);
}
