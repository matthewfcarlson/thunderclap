class Item {
  public:
    char pad[0x1c];
    void* a;
    void* b;
};
extern "C" void __cdecl check();
extern "C" void __cdecl create();
void* __stdcall target(Item* p) {
    if (p->a)
        return 0;
    if (p->b) {
        check();
        if (!p->b)
            create();
    } else
        create();
    return p->b;
}