class Helper_2df210 {
  public:
    void run();
};
class ShadowMesh {
  public:
    char pad[0x48];
    Helper_2df210** p;
    void vfunc_21();
};
void ShadowMesh::vfunc_21() {
    (*p)->run();
}