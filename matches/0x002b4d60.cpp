class ShadowMeshBufferImpl {
  public:
    char pad[0x40];
    ShadowMeshBufferImpl* target(int arg);
};
extern void __fastcall Init(void*);
ShadowMeshBufferImpl* ShadowMeshBufferImpl::target(int arg) {
    Init(this);
    *(void**)this = (void*)0x42e584;
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x10) = 2;
    return this;
}