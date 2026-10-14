inline unsigned short* cp(unsigned short* a, unsigned short* b, unsigned short* out) {
    for (; a != b; ++a, ++out)
        *out = *a;
    return out;
}
class Str_2f9d00 {
  public:
    unsigned short* first;
    unsigned short* last;
    unsigned short* cap;
    void init(unsigned);
    void grow(unsigned short*, unsigned, unsigned short*);
    void fn(unsigned n, unsigned short* p);
};
void Str_2f9d00::fn(unsigned n, unsigned short* p) {
    if (!first)
        init(n);
    unsigned count = (unsigned)(last - first);
    if (n > count) {
        grow(last, n - count, p);
        return;
    }
    if (n < count) {
        last = cp(last, last, first + n);
    }
}