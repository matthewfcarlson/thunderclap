// Same code shape as 0x000c0500 (propagated; names are from that function)
extern long __cdecl atol(const char*);
struct Inner { void call(long); };
struct Obj { int pad; Inner* value; long run(int count, char** strings); };
long Obj::run(int count, char** strings) {
    if (!value) return -1;
    long n = 0;
    if (count > 0) n = atol(*strings);
    value->call(n);
    return 0;
}