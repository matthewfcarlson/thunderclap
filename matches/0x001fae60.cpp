extern void* g_vftable[];
void operator delete(void*);
class RefCounted {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual ~RefCounted();
    int mRefCount;
};
class MyBufferStream : public RefCounted {
  public:
    virtual void* vfunc_0(unsigned int flags);
};
void* MyBufferStream::vfunc_0(unsigned int flags) {
    *(void**)this = g_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
