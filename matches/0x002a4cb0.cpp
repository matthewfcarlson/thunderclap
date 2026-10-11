extern "C" void _ReadWriteBarrier();
extern "C" void* alloc(unsigned int) throw();
struct E {
    int a, b, c, d;
};
struct Buffer {
    E* begin;
    E* end;
    Buffer* target(unsigned int count, int unused);
};
Buffer* Buffer::target(unsigned int count, int unused) {
    if (count > 0) {
        begin = (E*)alloc(count * 16);
        if (begin != 0) {
            E* e = begin + count;
            end = e;
            for (E* p = begin; p != e; ++p) {
                if (p != 0) {
                    p->a = 0;
                    p->b = 0;
                    p->c = 0;
                }
            }
            _ReadWriteBarrier();
            return this;
        }
    }
    begin = 0;
    end = 0;
    return this;
}
