extern char gA, gB;
struct Inner {
    void Set(void*);
};
struct Result {
    char pad[16];
    Inner inner;
    void Finish(void*);
};
extern "C" Result* __cdecl Make(void*, int, void*, void*, int);
struct Owner {
    void* items[734];
    void Run(int, void*, void*);
};
void Owner::Run(int index, void* x, void* y) {
    if (index >= 0x2ca && index <= 0x2dd) {
        Result* r = Make(items[index], 0, &gA, &gB, 0);
        if (r) {
            r->inner.Set(x);
            r->Finish(y);
        }
    }
}