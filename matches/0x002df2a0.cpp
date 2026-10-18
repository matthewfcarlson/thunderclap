// Same code shape as 0x002df210 (propagated; names are from that function)
class Helper_2df2a0 {
  public:
    void run(int, int);
};
class ShadowMesh {
  public:
    char pad[0x48];
    Helper_2df2a0** p;
    void vfunc_21(int, int);
};
void ShadowMesh::vfunc_21(int a0, int a1) {
    (*p)->run(a0, a1);
}