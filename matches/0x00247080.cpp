typedef int FILE;
extern "C" int __cdecl fclose(FILE*);
extern "C" void __cdecl destroy(void*);
extern int stdvt[];
extern int streamvt_247080[];
namespace om { class StdStream {
  public:
    void* vt;
    char pad[0x18];
    FILE* file;
    unsigned char opened;
    StdStream* vfunc_0(unsigned char);
}; }
om::StdStream* om::StdStream::vfunc_0(unsigned char flags) {
    vt = stdvt;
    if (opened)
        fclose(file);
    vt = streamvt_247080;
    if (flags & 1)
        destroy(this);
    return this;
}