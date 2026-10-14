// cl-flags: /O1
struct Obj {
    char pad[0x28];
    float f;
    char Fn(float x);
};
char Obj::Fn(float x) {
    f = x * 0.017453292519943295f;
    return 1;
}