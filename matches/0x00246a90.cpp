extern void* g_vt_246a90[];
extern void* g_vt2[];
class Ref_246a90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Stream_246a90 {
  public:
    void* vptr;
};
class ContentStream_246a90 : public Stream_246a90 {
  public:
    char pad[0x1c - 4];
    Ref_246a90* m;
    ~ContentStream_246a90() throw();
};
ContentStream_246a90::~ContentStream_246a90() throw() {
    Ref_246a90* r = m;
    vptr = g_vt_246a90;
    r->Release();
    vptr = g_vt2;
}
