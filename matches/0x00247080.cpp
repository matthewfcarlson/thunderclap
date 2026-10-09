typedef int FILE;
extern "C" int __cdecl fclose(FILE*);
extern "C" void __cdecl destroy(void*);
extern int stdvt[];
extern int streamvt[];
class om_StdStream {
  public:
    void* vt;
    char pad[0x18];
    FILE* file;
    unsigned char opened;
    om_StdStream* vfunc_0(unsigned char);
};
om_StdStream* om_StdStream::vfunc_0(unsigned char flags) {
    vt = stdvt;
    if (opened)
        fclose(file);
    vt = streamvt;
    if (flags & 1)
        destroy(this);
    return this;
}