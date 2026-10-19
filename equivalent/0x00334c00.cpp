// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// FUN_00334c00 @ 0x00334c00
class Item {
  public:
    char pad[0x1c];
    void* a;
    void* b;
};
extern "C" void __cdecl check();
struct Owner_334c00 {
// equiv-conv: FUN_00334b00 esi
    void FUN_00334b00();
};
void* __stdcall target(Item* p) {
    if (p->a)
        return 0;
    if (p->b) {
        check();
        if (!p->b)
            ((Owner_334c00*)p)->FUN_00334b00();
    } else
        ((Owner_334c00*)p)->FUN_00334b00();
    return p->b;
}