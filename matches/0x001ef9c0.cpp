// FUN_001ef9c0 @ 0x001ef9c0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void __cdecl thunk_FUN_00267090(void* p);

struct Id_1ef9c0 {
    void FUN_0027b040(int v);
};

struct Slot_1ef9c0 {
    char pad0[8];
    int a;
    int b;
    int c;
    char flag;
    char pad15[3];
    Id_1ef9c0 id;       // 0x18
    char pad1c[4];
    float weight;
    int d;
};

struct Resource_1ef9c0 {
    void FUN_001f1c80();
};
struct Sub1_1ef9c0 { void FUN_001f4f00(); };
struct Sub2_1ef9c0 { void FUN_001eaea0(); };

class Pool_1ef9c0 {
public:
    Sub1_1ef9c0* sub1;
    Sub2_1ef9c0* sub2;
    Resource_1ef9c0* resource;
    Slot_1ef9c0* slots;
    void FUN_001ef9c0(bool release);
};

void Pool_1ef9c0::FUN_001ef9c0(bool release) {
    for (int off = 0; off < 100 * 0x28; off += 0x28) {
        Slot_1ef9c0* s = (Slot_1ef9c0*)((char*)slots + off);
        s->a = 0;
        s->b = 0;
        s->c = 0;
        s->flag = 0;
        s->weight = 100.0f;
        s->d = 0;
        s->id.FUN_0027b040(0);
    }
    if (release) {
        Resource_1ef9c0* r = resource;
        if (r) {
            r->FUN_001f1c80();
            thunk_FUN_00267090(r);
        }
        resource = 0;
    }
    sub1->FUN_001f4f00();
    if (release)
        sub2->FUN_001eaea0();
}
