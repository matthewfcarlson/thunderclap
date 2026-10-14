const float PiDiv180 = 0.0174532925f;
struct Obj {
    char pad[12];
    float v;
    char Set(float x);
};

char Obj::Set(float x) {
    v = x * PiDiv180;
    return 1;
}
