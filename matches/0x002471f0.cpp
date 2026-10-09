// Same code shape as 0x00247170 (propagated; names are from that function)
struct Handle {
    virtual void a();
    virtual void close();
};
extern void* corevt[];
extern void* streamvt[];
extern void cleanup(void*);
class CoreFileStream {
  public:
    void* vt;
    char pad[0x18];
    Handle* member;
    CoreFileStream* vfunc_0(unsigned char);
};
CoreFileStream* CoreFileStream::vfunc_0(unsigned char p) {
    Handle* h = member;
    vt = corevt;
    h->close();
    vt = streamvt;
    if (p & 1)
        cleanup(this);
    return this;
}