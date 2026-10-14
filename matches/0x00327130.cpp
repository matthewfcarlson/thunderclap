extern "C" void __stdcall D3DResource_Release(int);
extern "C" void FreeOld(int);
extern "C" int __stdcall CreateIndexBuffer(int);
extern "C" void CheckError(unsigned int);
extern "C" void InitIndex(int, int);
class Buffer_327130 {
  public:
    char pad0[0x20];
    int count;
    char pad24[8];
    int resource;
    void Set(int n);
};
void Buffer_327130::Set(int n) {
    int old = resource;
    count = n;
    if (old) {
        D3DResource_Release(old);
        FreeOld(resource);
    }
    resource = 0;
    if (n) {
        int size = n + n;
        resource = CreateIndexBuffer(size);
        CheckError((resource != 0) - 1 & 0x8007000e);
        InitIndex(resource, size);
    }
}