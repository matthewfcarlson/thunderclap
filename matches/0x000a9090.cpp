// FUN_000a9090 @ 0x000a9090
extern "C" void __cdecl FUN_0009f790(float, void*, float*, float*);
class Orbit {
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(float, float);
    char pad[0xd4 - 4];
    float angle;
    float outA;
    float outB;
    void* ref;
    void FUN_000a9090(float value);
};
void Orbit::FUN_000a9090(float value) {
    if (value != angle) {
        angle = value;
        FUN_0009f790(value, ref, &outA, &outB);
        slot5(outA * 0.017453292f, 1.0f);
    }
}
