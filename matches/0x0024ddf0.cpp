class MetaTypeAttribScalarInt {
    char pad0[0x14];
    int offset;
    char pad1[0x0c];
    int value;

  public:
    void vfunc_3(int);
};
void MetaTypeAttribScalarInt::vfunc_3(int p) {
    *(int*)((char*)p + offset) = value;
}