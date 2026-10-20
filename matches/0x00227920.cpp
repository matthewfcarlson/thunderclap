extern float __cdecl FUN_00224fc0(float, float);
struct Object {
    char pad[0x12e0];
    float value0;
    float value1;
    void FUN_00226a70(int, float);
    void FUN_00227920(int);
};
void Object::FUN_00227920(int arg) {
    float a = value0, b = value1;
    float result = FUN_00224fc0(b, a);
    FUN_00226a70(arg, result);
}