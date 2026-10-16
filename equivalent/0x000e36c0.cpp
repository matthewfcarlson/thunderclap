// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 8/8)
// FUN_000e36c0 @ 0x000e36c0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
struct Label { char pad[0x24]; void FUN_000f7960(); };
void __cdecl thunk_FUN_00267090(void* p);
struct Group {
    Label* items;
    char pad[4];
    int f8, fc;
    char pad2[4];
    int f14;
    char pad3[0x38 - 0x18];
};
class HintList {
public:
    char pad[0x154];
    int f154;
    char pad1[0x17c - 0x158];
    Group group[0x80];
    void FUN_000e36c0();
};
void HintList::FUN_000e36c0() {
    for (int g = 0; g < 0x80; g++) {
        Group* e = &group[g];
        if (e->items) {
            int* hdr = (int*)e->items - 1;
            int n = *hdr;
            Label* p = e->items + n;
            for (int k = n; k > 0; k--) {
                p--;
                p->FUN_000f7960();
            }
            thunk_FUN_00267090(hdr);
            e->items = 0;
        }
        e->f8 = 0;
        e->fc = 0;
    }
    group[0x7f].f14 = 0;   // this+0x1d58
    f154 = 0;
}
