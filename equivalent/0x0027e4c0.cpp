// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 31/34, incomplete)
// pure3d::prop::StateProp::vfunc_16 @ 0x0027e4c0
// equiv-map: ?thunk_FUN_002ee510@Cache@@QAEXPAUChoice@@@Z = 0x002ee700
// equiv-map: ?thunk_FUN_002ee710@Cache@@QAEXH@Z = 0x002eecb0
extern "C" void *memset(void *dst, int c, unsigned int n);

struct Res {
    virtual void vfn0();
    virtual void vfn1();
};
struct Stage {
    virtual void vfn0();
    virtual void vfn1();
    char pad[0x74 - 4 - 4];
    int key;                 // 0x74
};
struct Slot {                // 0x18 bytes
    char pad0[0x10];
    Stage *stage;            // 0x10
    Res *aux;                // 0x14
};
struct Choice {
    char pad[0x10];
    int value;               // 0x10
};
struct Cache {
    void thunk_FUN_002ee710(int key);
    void thunk_FUN_002ee510(Choice *c);
    void FUN_002ee6d0(Choice *c);
};
struct Entry {
    char pad[0x2c];
    int slotCount;           // 0x2c
};
struct Table {
    char pad[0x1c];
    Entry **entries;         // 0x1c
    Entry **entriesEnd;      // 0x20
};
struct Layout {
    void FUN_00283460(int a, int b, int c);
    void FUN_002834b0(int v);
};
Layout *FUN_0027f250();
extern Cache *DAT_00554c14;

class Scene {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6(int a, int b);
    char pad04[4];
    int f8;
    int fc;
    char pad10[0x40 - 0x10];
    int current;             // 0x40
    int f44;
    char pad48[0x88 - 0x48];
    Res *f88;
    char f8c;
    char pad8d[0x98 - 0x8d];
    Table *table;            // 0x98
    char pad9c[0xa4 - 0x9c];
    Slot *slots;             // 0xa4
    int slotsPerEntry;       // 0xa8
    Choice **choices;        // 0xac
    void FUN_0027d780();
    void FUN_0027dca0();
    void FUN_0027e4c0(int index, bool notify);
};

void Scene::FUN_0027e4c0(int index, bool notify)
{
    if (index < 0) return;
    if (index >= (int)(table->entriesEnd - table->entries)) return;
    if (current == -1) {
        if (f88 != 0) {
            f88->vfn1();
            f88 = 0;
        }
    }
    Layout *layout = FUN_0027f250();
    if (layout != 0) {
        layout->FUN_00283460(f8, fc, 0);
    }
    if (current != -1) {
        int n = table->entries[current]->slotCount;
        for (int i = 0; i < n; i++) {
            Slot *s = &slots[i];
            if (slots[i].stage != 0) {
                DAT_00554c14->thunk_FUN_002ee710(slots[i].stage->key);
                s->stage->vfn1();
                if (s->aux != 0)
                    s->aux->vfn1();
            }
        }
    }
    if (current != index && current != -1) {
        Choice *old = choices[current];
        if (old != 0) {
            if (old != choices[index]) {
                Layout *l2 = FUN_0027f250();
                l2->FUN_002834b0(choices[current]->value);
            }
            DAT_00554c14->thunk_FUN_002ee510(choices[current]);
        }
        if (choices[index] != 0) {
            DAT_00554c14->FUN_002ee6d0(choices[index]);
        }
    }
    memset(slots, 0, slotsPerEntry * 24);
    current = index;
    f44 = 0;
    FUN_0027d780();
    if (notify)
        vfn6(0, 0);
    if (f8c == 1)
        FUN_0027dca0();
}
