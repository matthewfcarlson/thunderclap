typedef unsigned __int64 U64;
extern U64 __cdecl lookup(void*, int, int);
struct Result {
    char pad[0x1b40];
    int a;
    int b;
};
class Obj {
  public:
    Result* get(U64);
    void run(void*, int);
};
void Obj::run(void* p, int unused) {
    U64 v = lookup(p, 0, 0);
    Result* r = get(v);
    if (r) {
        r->a = 0;
        r->b = 0;
    }
}