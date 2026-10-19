extern "C" char DAT_0042e584[];
class ShadowMeshBufferImpl {
  public:
    int x[17];
    ShadowMeshBufferImpl* InitSelf();
};
struct ThisCall_002a5060 {
    void Init();
};
ShadowMeshBufferImpl* ShadowMeshBufferImpl::InitSelf() {
    ((ThisCall_002a5060*)(this))->Init();
    *(int*)this = ((int)DAT_0042e584);
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x10) = 2;
    return this;
}