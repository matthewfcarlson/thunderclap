typedef unsigned __int64 u64_79530;
struct Obj_79530 {
    char pad[0x3650];
    u64_79530 FUN_00079530(int index);
};
u64_79530 Obj_79530::FUN_00079530(int index) {
    return *(u64_79530*)((char*)this + (index + 0x365) * 16);
}