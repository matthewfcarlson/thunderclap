typedef unsigned int uint;
typedef unsigned short ushort;
struct Data {
    char pad0[8];
    unsigned char flags;
    char pad9[7];
    unsigned int value;
    unsigned short size;
};
int __cdecl Target(int a, Data* b, unsigned int* out, uint* out2) {
    if (a && b && (b->flags & 8) && out) {
        *out = b->value;
        *out2 = (uint)b->size;
        return 8;
    }
    return 0;
}