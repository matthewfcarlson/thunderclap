typedef unsigned int size_t;
void* operator new(size_t) throw();
class MeshData {
  public:
    char pad[0x70];
    MeshData() throw();
};
class ShadowBase {
  public:
    ShadowBase(int) throw();
    void Set(int, MeshData*) throw();
    virtual void dummy();
};
class ShadowMesh : public ShadowBase {
  public:
    ShadowMesh() throw();
    virtual void dummy();
};
ShadowMesh::ShadowMesh() throw() : ShadowBase(1) {
    MeshData* p = new MeshData;
    Set(0, p);
}
