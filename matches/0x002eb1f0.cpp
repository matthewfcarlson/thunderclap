typedef unsigned int uint;
struct Obj_2eb1f0 {
    char pad[8];
    uint flags;
    char pad2[0x1c];
    float value;
};
void FUN_002eb1f0(int a, Obj_2eb1f0* b, double c) {
    if (a && b) {
        b->value = (float)c;
        b->flags |= 1;
    }
}