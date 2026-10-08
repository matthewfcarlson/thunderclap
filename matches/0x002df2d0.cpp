class ShadowSkin { public: char pad[0x48]; void *p; int vfunc_25(); };
int ShadowSkin::vfunc_25() { return *(int *)(*(int *)p + 0x7c); }