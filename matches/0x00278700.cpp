class XboxSaveDrive {
  public:
    char pad[0x2f4];
    int field;
    int vfunc_20(int* p);
};
void __stdcall ReleaseThing(int);
int XboxSaveDrive::vfunc_20(int* p) {
    int v = *(int*)((char*)this + *p * 0x208 + 0x2f4);
    if (v != -1) {
        ReleaseThing(v);
        *(int*)((char*)this + *p * 0x208 + 0x2f4) = -1;
    }
    return 1;
}