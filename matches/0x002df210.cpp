class Helper { public: void run(); };
class ShadowMesh { public: char pad[0x48]; Helper** p; void vfunc_21(); };
void ShadowMesh::vfunc_21() { (*p)->run(); }