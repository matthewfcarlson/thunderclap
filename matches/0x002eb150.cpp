extern "C" void* memcpy(void*, const void*, unsigned);
struct Obj {
    char pad[8];
    unsigned flags;
    char data[0x56];
};
void Set(int ok, Obj* obj, const void* src) {
    if (ok && obj) {
        memcpy(&obj->data[0x4e], src, 10);
        obj->flags |= 0x20;
    }
}