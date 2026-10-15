class Lookup {
  public:
    char* Get();
};
class Heap {
  public:
    char* Alloc(unsigned, int);
};
extern Heap gHeap;
extern "C" unsigned strlen(const char*);
inline void Copy(char* dst, const char* src) {
    char c;
    do {
        c = *src++;
        *dst++ = c;
    } while (c);
}
extern "C" bool __stdcall FUN_00336430(char** out, Lookup* lookup, int a, int b) {
    char* s = lookup->Get();
    if (!s)
        return false;
    char* d = gHeap.Alloc(strlen(s) + 1, 4);
    *out = d;
    Copy(d, s);
    return true;
}