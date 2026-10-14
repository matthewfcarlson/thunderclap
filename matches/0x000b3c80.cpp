struct Obj_b3c80 {
    char pad[8];
    unsigned char field;
};
struct Root_b3c80 {
    char pad[4];
    Obj_b3c80* ptr;
};
extern Root_b3c80* gRoot_b3c80;
void __cdecl FUN_000b3c80(unsigned char x) {
    gRoot_b3c80->ptr->field = x;
}