struct Item {
    int a;
    void* h;
    char pad[0x10];
    void* buf;
};

struct Vec {
    int x;
    int y;
};

struct Mgr {
    char pad0[8];
    Item* items[32];
    int count;
    char pad1[0xc0 - 0x8c];
    Item* skipA;
    Item* skipB;
    void Release();
};

void FUN_00249a90(void* h, Vec* out);
void FUN_0024a800(void* h, int v);
void FUN_002497e0(void* p);

void Mgr::Release() {
    int i = 0;
    for (i = 0; i < count; i++) {
        Item* it = items[i];
        if (it == skipA)
            continue;
        if (it == skipB)
            continue;
        void* h = it->h;
        if (h == 0)
            continue;
        Vec v;
        v.x = 0;
        v.y = 0;
        FUN_00249a90(h, &v);
        FUN_0024a800(it->h, 0x32);
        void* b = it->buf;
        if (b != 0) {
            FUN_002497e0(b);
            it->buf = 0;
        }
    }
}
