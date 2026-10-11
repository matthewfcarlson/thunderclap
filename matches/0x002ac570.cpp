extern "C" void _ReadWriteBarrier();
extern "C" void thunk_FUN_00267090(void*);

class ParticleAllocatorTemplate {
  public:
    virtual ~ParticleAllocatorTemplate() {}
    char _pad1[8];
    void* mCallback1;
    char _pad2[8];
    void* mCallback2;
    void FUN_002ac570();
    void FUN_002d3d80();
};

void ParticleAllocatorTemplate::FUN_002ac570() {
    *(void**)this = (void*)0x42e0c4;
    _ReadWriteBarrier();
    if (mCallback2)
        thunk_FUN_00267090(mCallback2);
    if (mCallback1)
        thunk_FUN_00267090(mCallback1);
    FUN_002d3d80();
}