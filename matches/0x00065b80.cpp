struct Entity {
    char pad[0x1d40];
    char active;
    void Update();
};
struct EntList {
    char pad[0xc];
    int count;
    Entity* Get(int i);
};
struct Game {
    char pad[0x20];
    EntList* list;
    char pad2[0x8];
    int val;
};
extern Game* g_game;

struct Clock {
    float Now();
};

struct Obj {
    int mType;
    Clock* mClock;
    char pad[0x354];
    float mNext;
    float mInterval;
    void Tick(int a);
};

void Obj::Tick(int a) {
    if (!mClock)
        return;
    if (mType == 0) {
        int v = *(int*)((char*)g_game + 0x2c);
        mType = v;
        if (!v)
            return;
    }
    if (mClock->Now() >= mNext) {
        EntList* l = g_game->list;
        int n = l->count;
        for (int i = 0; i < n; i++) {
            Entity* e = g_game->list->Get(i);
            if (e && e->active)
                e->Update();
        }
        mNext = mClock->Now() + mInterval;
    }
}
