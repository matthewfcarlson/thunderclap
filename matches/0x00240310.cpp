extern "C" int strcmp(const char*, const char*);
extern const char* gEmpty_240310;
extern const char gZero_240310[];
struct S_240310 {
    const char* p;
    char Eq(const S_240310& o);
};
char S_240310::Eq(const S_240310& o) {
    const char* b = o.p;
    if (b == gEmpty_240310)
        return p == gEmpty_240310;
    const char* a = p;
    if (a == gEmpty_240310)
        a = gZero_240310;
    return strcmp(a, b) == 0;
}
