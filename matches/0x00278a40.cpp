extern int gLast;
struct Obj {
    int Init(int, int);
};
extern "C" Obj* __cdecl Alloc(int, int);
int __cdecl Make(int* out, int arg, int size) {
    gLast = size;
    Obj* p = Alloc(size, 0x910);
    *out = p ? p->Init(arg, size) : 0;
    return (int)(*out);
}
