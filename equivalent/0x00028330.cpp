// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00028330 @ 0x00028330
// Group method: is the named pawn's ground position in front of the given heading, within the given arc?
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
float __cdecl FUN_00224ea0(float x, float z);
float __cdecl FUN_00224fc0(float a, float b);

struct Vec3 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3 *other, float epsilon);
};

union AbsFloat {
    float f;
    unsigned int bits;
};

struct Pawn {
    char pad[0x2064];
    Vec3 pos;                       // 0x2064
};

struct Group {
    Pawn *FUN_00024280(unsigned __int64 key);
    bool FUN_00028330(const char *name, float heading, float arc);
};

bool Group::FUN_00028330(const char *name, float heading, float arc)
{
    Pawn *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn)
        return false;
    Vec3 p = pawn->pos;
    Vec3 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    if (p.FUN_0022d2b0(&zero, 1.0e-5f))
        return false;
    float bearing = FUN_00224ea0(p.x, p.z);
    AbsFloat diff;
    diff.f = FUN_00224fc0(heading, bearing);
    diff.bits &= 0x7fffffff;
    return arc * 0.00872665f > diff.f;
}
