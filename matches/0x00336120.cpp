extern "C" unsigned strlen(const char*);
inline void copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        ++s;
        *d = c;
        ++d;
    } while (c);
}
class Source {
  public:
    char* Lookup();
};
class Heap {
  public:
    void* Allocate(unsigned, unsigned);
};
extern Heap gHeap;
bool __stdcall Get(char** out, Source* src, int b, int c) {
    char* s = src->Lookup();
    if (!s)
        return false;
    char* d = (char*)gHeap.Allocate(strlen(s) + 1, 4);
    *out = d;
    copy(d, s);
    return true;
}