struct VTable {
    void* a;
    void* b;
    char(__cdecl* Read)(VTable*, char*, int, int);
};
class Stream {
  public:
    VTable* v;
    char ReverseRead(char* p, int n);
};
char Stream::ReverseRead(char* p, int n) {
    VTable* t = v;
    if (t->Read(t, p, n, 1)) {
        char* end = p + n - 1;
        char* q = p;
        if (q < end) {
            do {
                char c = *end;
                char d = *q;
                *q = c;
                ++q;
                *end = d;
                --end;
            } while (q < end);
        }
        return 1;
    }
    return 0;
}