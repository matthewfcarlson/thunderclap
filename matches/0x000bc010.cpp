struct Inner {
    void FUN_000b8d00();
};
struct Object {
    char padding[4];
    Inner* value;
    int FUN_000bc010(void* first, void* second);
};
int Object::FUN_000bc010(void* first, void* second) {
    if (!value)
        return -1;
    if (first)
        return -1;
    value->FUN_000b8d00();
    return 0;
}