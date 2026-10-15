extern "C" int __cdecl length(const char*);
extern "C" int __cdecl check(const char*, int, int);
struct S {
    char pad[0x1c];
    const char* str;
};
char __cdecl FUN_002467e0(S* s, int* out) {
    int n = length(s->str);
    if (check(s->str, 0, 2))
        return 0;
    *out = length(s->str) - n;
    return check(s->str, n, 0) == 0;
}