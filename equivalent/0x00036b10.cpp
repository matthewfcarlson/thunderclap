// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00036b10 @ 0x00036b10
// Try the cheap test first; otherwise ask the manager, with the player's flag raised around the request.
struct Vec3_36b10 {
    float x, y, z;
};

class Player_36b10 {
public:
    void FUN_00035fa0(int flag);
};

class World {
public:
    char pad0[0x124];
    Player_36b10* player;
};

class Target_36b10 {
public:
    char FUN_0022d2b0(int a, float f);
};

class Manager_36b10 {
public:
    char FUN_001b4ab0(Target_36b10* target, int a, int b, Vec3_36b10* out, char* flagA, char* flagB);
};

class Owner_36b10 {
public:
    char pad0[0x10];
    Manager_36b10* manager;
    char pad14[0xc];
    World* world;
};

char __cdecl FUN_00036b10(Owner_36b10* owner, Target_36b10* target, int a, int b, Vec3_36b10* out, char* flagA, char* flagB)
{
    out->z = 0;
    out->y = 0;
    out->x = 0;
    *flagB = 0;
    *flagA = 1;

    Player_36b10* player = owner->world->player;
    if (player != 0) {
        player->FUN_00035fa0(0);
    }
    if (target->FUN_0022d2b0(a, 1.0f)) {
        return 1;
    }
    char result = owner->manager->FUN_001b4ab0(target, a, b, out, flagA, flagB);
    if (player != 0) {
        player->FUN_00035fa0(1);
    }
    return result;
}
