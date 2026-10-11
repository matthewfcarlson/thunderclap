extern "C" char DAT_00433424[];
extern "C" char DAT_004334b4[];
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
    *(int*)this = ((int)DAT_004334b4);
    if (a) {
        Cleanup(a);
        Release(a);
    }
    if (b) {
        Cleanup(b);
        Release(b);
    }
    *(int*)this = ((int)DAT_00433424);
    BaseDestroy();
}