inline void* operator new(unsigned, void* p) {
    return p;
}
extern "C" void* memmove(void*, const void*, unsigned);
extern "C" void* memset(void*, int, unsigned);
void* Alloc(unsigned n);
class Hbase {
  public:
    Hbase() { a = 0; }
    virtual void f0();
    int a;
};
class Handler : public Hbase {
  public:
    virtual void f0();
};
class Lbase {
  public:
    Lbase() { a = 0; }
    virtual void f0();
    int a;
};
class ChannelLoader : public Lbase {
  public:
    ChannelLoader();
    virtual void f0();
    int count;
    Handler* tbl[16];
};
ChannelLoader::ChannelLoader() {
    count = 0;
    memset(tbl, 0, 64);
    Handler* h = new (Alloc(8)) Handler;
    if (h) {
        memmove(&tbl[1], &tbl[0], count << 2);
        tbl[0] = h;
        h->f0();
        count++;
    }
}
