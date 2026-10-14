struct Handle_247170 {
    virtual void a();
    virtual void close();
};
extern void* corevt[];
extern void* streamvt_247170[];
extern void cleanup(void*);
class CoreFileStream {
  public:
    void* vt;
    char pad[0x18];
    Handle_247170* member;
    CoreFileStream* vfunc_0(unsigned char);
};
CoreFileStream* CoreFileStream::vfunc_0(unsigned char p) {
    Handle_247170* h = member;
    vt = corevt;
    h->close();
    vt = streamvt_247170;
    if (p & 1)
        cleanup(this);
    return this;
}