struct Obj {
    char pad[8];
    unsigned char field;
};
struct Root {
    char pad[4];
    Obj* ptr;
};
extern Root* gRoot;
void __cdecl FUN_000b3c80(unsigned char x) {
    gRoot->ptr->field = x;
}