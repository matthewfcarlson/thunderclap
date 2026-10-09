class d3dExtAntialiasControl {
  public:
    char pad[4];
    void* p;
    unsigned int vfunc_4();
};
unsigned int d3dExtAntialiasControl::vfunc_4() {
    return *(unsigned int*)((*(char**)((char*)p + 0x154)) + 0x460);
}