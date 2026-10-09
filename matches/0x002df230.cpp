// Same code shape as 0x002df210 (propagated; names are from that function)
class Helper {
  public:
    void run();
};
class ShadowMesh {
  public:
    char pad[0x48];
    Helper** p;
    void vfunc_21();
};
void ShadowMesh::vfunc_21() {
    (*p)->run();
}