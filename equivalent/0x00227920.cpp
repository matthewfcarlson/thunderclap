// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00227920 @ 0x00227920
extern float __cdecl FUN_00224fc0(float, float);
struct Object {
    char pad[0x12e0];
    float value0;
    float value1;
    void FUN_00226a70(int, float);
    void FUN_00227920(int);
};
void Object::FUN_00227920(int arg) {
    float result = FUN_00224fc0(value1, value0);
    FUN_00226a70(arg, result);
}
