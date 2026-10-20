class Item {
  public:
    char pad[0x1c];
    void* a;
    void* b;
};
extern "C" void __cdecl check();
extern "C" void __cdecl fallback();
void* __stdcall target(Item* p) {
    if (p->a)
        return 0;
    if (p->b) {
        check();
        if (!p->b)
            fallback();
    } else
        fallback();
    return p->b;
}