// Same code shape as 0x00247170 (propagated; names are from that function)
struct Handle_2471f0 {
    virtual void a();
    virtual void close();
};
extern void* corevt[];
extern void* streamvt_2471f0[];
extern void cleanup(void*);
namespace om { class ContentStream {
  public:
    void* vt;
    char pad[0x18];
    Handle_2471f0* member;
    ContentStream* vfunc_0(unsigned char);
}; }
om::ContentStream* om::ContentStream::vfunc_0(unsigned char p) {
    Handle_2471f0* h = member;
    vt = corevt;
    h->close();
    vt = streamvt_2471f0;
    if (p & 1)
        cleanup(this);
    return this;
}