// FUN_0008b4b0 @ 0x0008b4b0
struct Vec3_8b4b0 {
    int x, y, z;
};

struct Record_8b4b0 {
    char pad0[4];
    char flag;                 // 0x04
    char pad5[7];
    Vec3_8b4b0 pos;                  // 0x0c
    char pad18[0xb68 - 0x18];
    char sub[0xbe8 - 0xb68];   // 0xb68
};

union Slot_8b4b0 {
    char *ptr;
    int value;
};

void __cdecl FUN_000964a0(char *dst, int size, const char *fmt, ...);

class Missions_8b4b0 {
public:
    char pad0[0xabf];
    char complete;             // 0xabf
    char padac0[0xac8 - 0xac0];
    Record_8b4b0 *records;           // 0xac8
    void FUN_0008ad90(int *chapter, int *mission);
    bool FUN_0008b4b0(int index, Slot_8b4b0 out, char *name, int nameSize, Vec3_8b4b0 *pos, void **sub);
};

bool Missions_8b4b0::FUN_0008b4b0(int index, Slot_8b4b0 out, char *name, int nameSize, Vec3_8b4b0 *pos, void **sub)
{
    Record_8b4b0 *rec = records + index;
    if (out.ptr != 0)
        *out.ptr = rec->flag;
    if (name != 0) {
        FUN_0008ad90(&out.value, &index);
        if (complete)
            FUN_000964a0(name, nameSize, "TBS_COMPLETE_PROMPT");
        else
            FUN_000964a0(name, nameSize, "TBS_C%dM%d_NAME", out.value, index);
    }
    if (pos != 0)
        *pos = rec->pos;
    if (sub != 0)
        *sub = rec->sub;
    return true;
}
