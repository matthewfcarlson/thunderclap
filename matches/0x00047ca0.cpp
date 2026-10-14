const float PiDiv180 = 0.0174532925f;
struct Obj_47ca0 {
    char pad[12];
    float v;
    char Set(float x);
};

char Obj_47ca0::Set(float x) {
    v = x * PiDiv180;
    return 1;
}
