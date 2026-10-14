typedef unsigned char u8_2478d0;
struct Obj_2478d0 {
    char pad[0xb4];
    u8_2478d0 value;
};
void FUN_002478d0(Obj_2478d0* obj, u8_2478d0 param) {
    obj->value = obj->value ^ ((obj->value ^ param) & 1);
}