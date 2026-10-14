struct Entity {
    char pad[0x1d40];
    char active;
    void Update();
};
struct EntList_65b80 {
    char pad[0xc];
    int count;
    Entity* Get(int i);
};
struct Game_65b80 {
    char pad[0x20];
    EntList_65b80* list;
    char pad2[0x8];
    int val;
};
extern Game_65b80* g_game_65b80;

struct Clock_65b80 {
    float Now();
};

struct Obj_65b80 {
    int mType;
    Clock_65b80* mClock;
    char pad[0x354];
    float mNext;
    float mInterval;
    void Tick(int a);
};

void Obj_65b80::Tick(int a) {
    if (!mClock)
        return;
    if (mType == 0) {
        int v = *(int*)((char*)g_game_65b80 + 0x2c);
        mType = v;
        if (!v)
            return;
    }
    if (mClock->Now() >= mNext) {
        EntList_65b80* l = g_game_65b80->list;
        int n = l->count;
        for (int i = 0; i < n; i++) {
            Entity* e = g_game_65b80->list->Get(i);
            if (e && e->active)
                e->Update();
        }
        mNext = mClock->Now() + mInterval;
    }
}
