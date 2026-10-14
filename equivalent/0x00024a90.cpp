// STATUS: equivalent (tools/equiv.py level 3: 599 inputs, branch coverage 8/8)
// FUN_00024a90 @ 0x00024a90
union Id64_24a90 {
    unsigned __int64 q;
    unsigned int w[2];
};

unsigned __int64 __cdecl FUN_0027b020(const char *name);

struct Clock_24a90 {
    unsigned __int64 FUN_000443c0();
};

struct Entity {
    char pad[0x11c];
    Clock_24a90 *clock;
};

struct World {
    Entity *FUN_00059c10(int handle);
};

struct Game_24a90 {
    char pad[0x44];
    World *world;
};

struct Roster_24a90 {
    Game_24a90 *game;
    char pad04[8];
    int count;
    int handles[1];
    int FUN_00024a90(const char *name);
};

int Roster_24a90::FUN_00024a90(const char *name)
{
    Id64_24a90 key;
    key.q = FUN_0027b020(name);
    int matches = 0;
    for (int i = 0; i < count; i++) {
        Id64_24a90 id;
        id.q = game->world->FUN_00059c10(handles[i])->clock->FUN_000443c0();
        if (key.w[0] == id.w[0] && key.w[1] == id.w[1])
            matches++;
    }
    return matches;
}
