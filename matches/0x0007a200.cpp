class Obj {
  public:
    char pad[0x1920];
    int item;
    char rest[0x3f0 - 4];
};
int __fastcall find(Obj* self, void*, int key) {
    int i = 0;
    int* p = &self->item;
    do {
        if (*p == key)
            return i;
        ++i;
        p += 0xfc;
    } while (i < 7);
    return -1;
}