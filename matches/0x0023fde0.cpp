typedef unsigned short ushort;
extern int Fmt(char* buf, int n, const char* fmt, char* va);
extern void Mk(int* out, char* src, unsigned n, int len);
struct Out {
    int p;
    ushort flag;
    ushort pad;
    ushort len;
};
Out* Fn(Out* out, int x, const char* fmt, ...) {
    char buf[0x1000];
    char* va = (char*)&fmt + 4;
    int n = Fmt(buf, 0x1000, fmt, va);
    out->len = (ushort)n;
    buf[0xfff] = 0;
    out->flag = 2;
    int tmp;
    Mk(&tmp, buf, n, n);
    out->p = tmp;
    return out;
}
