extern void* __cdecl Alloc(unsigned int);
class Obj { public: int Build(int, int, int); };
class Thing { public: int value; int ref; volatile int slots[32]; int Run(int, int); };
int Thing::Run(int a, int b) {
    if (ref == 0) return 0;
    Obj* p = (Obj*)Alloc(0x68);
    int result;
    if (p != 0) result = p->Build(ref, a, b);
    else result = 0;
    int i = 0;
    while (i < 32) {
        if (slots[i] == 0) {
            if (result != 0) slots[i] = result;
            return result;
        }
        ++i;
    }
    return result;
}