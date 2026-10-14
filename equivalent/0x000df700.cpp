// STATUS: equivalent (tools/equiv.py level 3: 771 inputs, branch coverage 8/8)
// FUN_000df700 @ 0x000df700
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
struct Pair {
    void *first;
    void *second;
};

void __cdecl thunk_FUN_00267090(void *p);

class PairTable {
public:
    Pair a[64];                    // 0x000
    Pair b[64];                    // 0x200
    Pair c[64];                    // 0x400
    Pair d[64];                    // 0x600
    void FUN_000df700();
};

void PairTable::FUN_000df700()
{
    for (int i = 63; i >= 0; i--) {
        thunk_FUN_00267090(d[i].first);
        thunk_FUN_00267090(d[i].second);
    }
    for (int i = 63; i >= 0; i--) {
        thunk_FUN_00267090(c[i].first);
        thunk_FUN_00267090(c[i].second);
    }
    for (int i = 63; i >= 0; i--) {
        thunk_FUN_00267090(b[i].first);
        thunk_FUN_00267090(b[i].second);
    }
    for (int i = 63; i >= 0; i--) {
        thunk_FUN_00267090(a[i].first);
        thunk_FUN_00267090(a[i].second);
    }
}
