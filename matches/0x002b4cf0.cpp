class ShadowMeshBufferImpl { public: int x[17]; ShadowMeshBufferImpl* InitSelf(); };
void Init();
ShadowMeshBufferImpl* ShadowMeshBufferImpl::InitSelf() { Init(); *(int*)this = 0x42e584; *(int*)((char*)this + 0x40) = 0; *(int*)((char*)this + 0x10) = 2; return this; }