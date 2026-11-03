typedef unsigned int uint_2d7e90;
struct Obj_2d7e90 {
    char pad[8];
    uint_2d7e90 value;
};
extern "C" uint_2d7e90 FUN_002d7e90(int handle, Obj_2d7e90* object, uint_2d7e90 mask) {
    if (handle != 0 && object != 0)
        return object->value & mask;
    return 0;
}