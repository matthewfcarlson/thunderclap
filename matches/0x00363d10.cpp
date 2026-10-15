extern "C" void __cdecl release(void*);
struct Item {
    int a;
    void* p;
};
extern Item items[11];
void FUN_00363d10() {
    Item* it = items + 11;
    int n = 11;
    do {
        --it;
        if (it->p) {
            release(it->p);
            it->a = 0;
            it->p = 0;
        }
    } while (--n);
}