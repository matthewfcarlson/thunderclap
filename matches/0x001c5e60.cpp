struct Result { char pad[0x30]; };
struct Registry {
    Result* FUN_001c3bd0(void* key);
};
Registry* FUN_001c3d90();

struct Obj_1c5e60 {
    char pad[8];
    Result* target();
};
Result* Obj_1c5e60::target() {
    return FUN_001c3d90()->FUN_001c3bd0((char*)this + 8);
}
