// STATUS: equivalent (tools/equiv.py level 3: 2235 inputs, branch coverage 0/0)
// FUN_000c5fa0 @ 0x000c5fa0
struct Vec3 {
    unsigned int x, y, z;
};

struct Buffer {
    char pad00[8];
    Vec3 *vertex;
    int unused;
    unsigned int *color;
    void FUN_0008ef00();
};

static __forceinline void Emit(Buffer *buffer, const Vec3 &v, unsigned int color)
{
    *buffer->vertex = v;
    *buffer->color = color;
    buffer->FUN_0008ef00();
}

// Emits two vertices (a line) with the same colour into the buffer.
// The original builds the first vertex in the (dead) argument slots of the second one;
// the volatile writes keep that, because the tail call hands its argument block on.
void __cdecl FUN_000c5fa0(Buffer *buffer, Vec3 from, Vec3 to, unsigned int color)
{
    Vec3 second = to;
    volatile Vec3 *slot = &to;
    slot->x = from.x;
    slot->y = from.y;
    slot->z = from.z;
    Emit(buffer, to, color);
    Emit(buffer, second, color);
}
