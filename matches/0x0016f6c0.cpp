// cl-flags: /O1
struct Obj_16f6c0 {
    char pad[0x28];
    float f;
    char Fn(float x);
};
char Obj_16f6c0::Fn(float x) {
    f = x * 0.017453292519943295f;
    return 1;
}