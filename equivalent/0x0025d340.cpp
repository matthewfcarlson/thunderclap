// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_0025d340 @ 0x0025d340
extern char DAT_004e7898[];

struct Sub {
    void FUN_0023fac0();
    void FUN_00240060();
};

struct Node {
    char pad0[8];
    char flag;          // 0x08
    char pad9[3];
    int arg;            // 0x0c
    int handle;         // 0x10
    int value;          // 0x14
    int field18;        // 0x18
    Sub sub;            // 0x1c
};

struct Registry {
    char pad0[0x14];
    char list[4];       // 0x14
};
extern Registry* DAT_004e5ce0;

Node* __cdecl FUN_00247530(char* pool);
void __cdecl FUN_00247550(char* pool, Node* node);
int __cdecl FUN_00240c20(int arg);
void __cdecl FUN_00257e80(char* list, Node* node);

// Allocates and registers a node; frees it again when the handle lookup fails.
Node* FUN_0025d340(int* src, int arg, char flag)
{
    Node* alloc = FUN_00247530(DAT_004e7898);
    Node* n = alloc ? (alloc->sub.FUN_0023fac0(), alloc) : 0;
    n->flag = flag;
    n->value = *src;
    n->arg = arg;
    n->field18 = 0;
    n->handle = FUN_00240c20(arg);
    if (n->handle == 0) {
        n->sub.FUN_00240060();
        FUN_00247550(DAT_004e7898, n);
        return 0;
    }
    FUN_00257e80(DAT_004e5ce0->list, n);
    return n;
}
