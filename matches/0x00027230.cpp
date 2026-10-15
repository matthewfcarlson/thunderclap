struct Item {
    char pad[0x213c];
    float value;
};
struct Obj {
    Item* get(unsigned __int64 x);
    void fn(void* x, unsigned char b);
};
extern "C" unsigned __int64 __cdecl make(void*, int, int);
void Obj::fn(void* x, unsigned char b) {
    Item* p = get(make(x, 0, 0));
    if (p)
        p->value = (float)b;
}