// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000bc010 @ 0x000bc010
struct Inner {
    void FUN_000b8d00();
};
struct Object {
    char padding[4];
    Inner* value;
    int FUN_000bc010(void* first, void* second);
};
int Object::FUN_000bc010(void* first, void* second) {
    if (!value || first) return -1;
    value->FUN_000b8d00();
    return 0;
}