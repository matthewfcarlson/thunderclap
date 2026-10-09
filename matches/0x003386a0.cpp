struct Src {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Read(char*, int);
    virtual bool More();
};
struct Rd {
    int pad0;
    Src* src;
    int size;
    int pos;
    int len;
    int pad14;
    char* buf;
    bool Get(char* out);
};
bool Rd::Get(char* out) {
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