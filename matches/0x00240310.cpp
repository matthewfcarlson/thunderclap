extern "C" int strcmp(const char*, const char*);
extern const char* gEmpty;
extern const char gZero[];
struct S {
    const char* p;
    char Eq(const S& o);
};
char S::Eq(const S& o) {
    const char* b = o.p;
    if (b == gEmpty)
        return p == gEmpty;
    const char* a = p;
    if (a == gEmpty)
        a = gZero;
    return strcmp(a, b) == 0;
}
