extern "C" void _ReadWriteBarrier();
extern "C" void* alloc(unsigned int) throw();
struct E_2a4cb0 {
    int a, b, c, d;
};
struct Buffer_2a4cb0 {
    E_2a4cb0* begin;
    E_2a4cb0* end;
    Buffer_2a4cb0* target(unsigned int count, int unused);
};
Buffer_2a4cb0* Buffer_2a4cb0::target(unsigned int count, int unused) {
    if (count > 0) {
        begin = (E_2a4cb0*)alloc(count * 16);
        if (begin != 0) {
            E_2a4cb0* e = begin + count;
            end = e;
            for (E_2a4cb0* p = begin; p != e; ++p) {
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
