struct Callee {
    unsigned char FUN_000aca40(int);
};
struct Object {
    char pad0[4];
    unsigned int flags;
    char pad8[8];
    Callee* value;
    char pad14[0xb0];
    Callee* other;
    int FUN_00099760();
};
int Object::FUN_00099760() {
    unsigned char f = (unsigned char)(flags >> 4);
    if ((f & 1) && value == other && !other->FUN_000aca40(0))
        return 1;
    return 0;
}