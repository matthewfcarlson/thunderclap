struct Src_3386a0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Read(char*, int);
    virtual bool More();
};
struct Rd_3386a0 {
    int pad0;
    Src_3386a0* src;
    int size;
    int pos;
    int len;
    int pad14;
    char* buf;
    bool Get(char* out);
};
bool Rd_3386a0::Get(char* out) {
    if (pos < len) {
        *out = buf[pos];
        pos++;
        return true;
    }
    if (src->More()) {
        len = src->Read(buf, size);
        pos = 0;
        if (len > 0) {
            *out = *buf;
            pos++;
            return true;
        }
    }
    return false;
}