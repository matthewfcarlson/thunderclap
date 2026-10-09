extern "C" int __cdecl fclose(void*);
struct Stream {
    virtual ~Stream() {}
    char pad[0x18];
};
struct StdStream : Stream {
    void* file;
    unsigned char owns;
    ~StdStream();
};
StdStream::~StdStream() {
    if (owns)
        fclose(file);
}
