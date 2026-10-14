// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 11/14, incomplete)
// FUN_0030f510 @ 0x0030f510
struct Mat_30f510 {
    float m[16];
};

struct Pose {
    Mat_30f510* FUN_0030f100();
};

struct Item_30f510 {
    Pose* FUN_0030ef30();
    Pose* FUN_0030edf0();
    char pad[0xc0];
};

struct Group_30f510 {
    char pad[0x10];
    int count;
};

struct Out_30f510 {
    char pad[8];
    Group_30f510* group;
    char pad2[8];
    Mat_30f510* dstA;
    char pad3[4];
    Mat_30f510* dstB;
    char flag20;
    char flag21;
    char flag22;
    char flag23;
};

class Skeleton {
public:
    void run(Out_30f510* out, bool both);
    char p0[8];
    Group_30f510* group;
    Item_30f510* items;
};

void Skeleton::run(Out_30f510* out, bool both)
{
    if (out->group != group)
        return;

    int n = group == 0 ? 0 : group->count;
    if (both) {
        for (int i = 0; i < n; i++) {
            Item_30f510* it = &items[i];
            out->dstA[i] = *it->FUN_0030ef30()->FUN_0030f100();
            out->dstB[i] = *it->FUN_0030edf0()->FUN_0030f100();
            out->flag22 = 0;
            out->flag23 = 0;
            out->flag20 = 0;
            out->flag21 = 0;
        }
    } else {
        for (int i = 0; i < n; i++)
            out->dstB[i] = *items[i].FUN_0030edf0()->FUN_0030f100();
        out->flag22 = 0;
        out->flag23 = 0;
        out->flag20 = 0;
        out->flag21 = 0;
    }
}
