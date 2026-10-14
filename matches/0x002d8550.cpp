typedef unsigned int uint_2d8550;
typedef unsigned short ushort;
struct Data_2d8550 {
    char pad0[8];
    unsigned char flags;
    char pad9[7];
    unsigned int value;
    unsigned short size;
};
int __cdecl Target(int a, Data_2d8550* b, unsigned int* out, uint_2d8550* out2) {
    if (a && b && (b->flags & 8) && out) {
        *out = b->value;
        *out2 = (uint_2d8550)b->size;
        return 8;
    }
    return 0;
}