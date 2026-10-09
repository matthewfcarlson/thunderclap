typedef unsigned char u8;
struct Obj {
    char pad[0xb4];
    u8 value;
};
void FUN_002478d0(Obj* obj, u8 param) {
    obj->value = obj->value ^ ((obj->value ^ param) & 1);
}