extern "C" void* __cdecl Cast(void*, int, const void*, const void*, int);
struct Owner {
    void* items[1];
    void Set(int index, char value);
};
struct Gallery {
    char pad[0xb0];
    char value;
};
struct Move {
    char pad[0x2d];
    char value;
};
struct File {
    char pad[0xa8];
    char value;
};
extern int typeUnlockable;
extern int typeGallery;
extern int typeMove;
extern int typeFile;
void Owner::Set(int index, char value) {
    Gallery* a = (Gallery*)Cast(items[index], 0, &typeUnlockable, &typeGallery, 0);
    if (a && a->value != value)
        a->value = value;
    Move* b = (Move*)Cast(items[index], 0, &typeUnlockable, &typeMove, 0);
    if (b && b->value != value)
        b->value = value;
    File* c = (File*)Cast(items[index], 0, &typeUnlockable, &typeFile, 0);
    if (c && c->value != value)
        c->value = value;
}