// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00029f20 @ 0x00029f20
// Distance between two named pawns (-1 when either is missing or has no position).
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct Vec3 {
    float x, y, z;
};

struct Body {
    bool FUN_00059a50(Vec3 *out);
};

struct Pawn {
    char pad[0x10];
    Body *body;
};

float __cdecl FUN_00025990(Vec3 *a, Vec3 *b);

struct Group {
    Pawn *FUN_00024280(unsigned __int64 key);
    float FUN_00029f20(const char *nameA, const char *nameB);
};

float Group::FUN_00029f20(const char *nameA, const char *nameB)
{
    struct Frame {
        Vec3 b;
        Vec3 a;
    } fr;
    Pawn *pa = FUN_00024280(FUN_002672f0(nameA, 0, 0));
    if (pa) {
        Pawn *pb = FUN_00024280(FUN_002672f0(nameB, 0, 0));
        if (pb && pa->body->FUN_00059a50(&fr.a) && pb->body->FUN_00059a50(&fr.b))
            return FUN_00025990(&fr.a, &fr.b);
    }
    return -1.0f;
}
