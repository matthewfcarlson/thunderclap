typedef unsigned int size_t;
extern "C" void* memset(void*, int, size_t);
class Thing {
  public:
    char pad0[0x0c];
    int count;
    void* a;
    void* b;
    void* c[4];
    void* d[2];
    void Clear();
};
void Thing::Clear() {
    if (a)
        memset(a, 0, count * 12);
    if (b)
        memset(b, 0, count * 12);
    for (int i = 0; i < 4; ++i)
        if (c[i])
            memset(c[i], 0, count * 8);
    for (int j = 0; j < 2; ++j)
        if (d[j])
            memset(d[j], 0, count * 8);
}