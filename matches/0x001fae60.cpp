extern void* g_vftable[];
void operator delete(void*);
class Stream_1fae60 {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual ~Stream_1fae60();
    int mRefCount;
};
class MyBufferStream : public Stream_1fae60 {
  public:
    virtual void* vfunc_0(unsigned int flags);
};
void* MyBufferStream::vfunc_0(unsigned int flags) {
    *(void**)this = g_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
