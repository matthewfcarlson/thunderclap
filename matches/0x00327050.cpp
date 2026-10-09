void Cleanup(void*);
void __stdcall Release(void*);
class PrimBuffer {
  public:
    virtual void V0();
    char pad[0x28];
    void* a;
    void* b;
    void BaseDestroy();
    void Destroy();
};
void PrimBuffer::Destroy() {
    *(int*)this = 0x4334b4;
    if (a) {
        Cleanup(a);
        Release(a);
    }
    if (b) {
        Cleanup(b);
        Release(b);
    }
    *(int*)this = 0x433424;
    BaseDestroy();
}