// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000675b0 @ 0x000675b0
struct Slot {
    char data[0x1c];
    void FUN_00230b60();
};

class Vehicle {
public:
    char pad0[0x150];
    int f150;
    char pad154[0x15c];
    int f2b0;
    int f2b4;
    float f2b8;
    float f2bc;
    int f2c0;
    int f2c4;
    int f2c8;
    int f2cc;
    int f2d0;
    int f2d4;
    Slot s2d8;
    Slot s2f4;
    Slot s310;
    int f32c;
    int f330;
    int f334;
    int f338;
    int f33c;
    int f340;
    int f344;
    int f348;
    int f34c;
    float f350;
    int f354;
    float f358;
    int f35c;
    float f360;
    int f364;
    float f368;
    char f36c;
    char pad36d[3];
    float f370;
    float f374;
    float f378;
    int f37c;
    int f380;
    int f384;
    int f388;
    int f38c;
    int f390;

    Vehicle *FUN_000675b0();
};

Vehicle *Vehicle::FUN_000675b0()
{
    f2b0 = 0;
    f2b4 = -1;
    f2b8 = 10.0f;
    f2bc = 20.0f;
    f2c0 = 1;
    f2c4 = 2;
    f2c8 = 3;
    f2cc = 10;
    f2d0 = 3;
    f2d4 = 10;
    s2d8.FUN_00230b60();
    s2f4.FUN_00230b60();
    s310.FUN_00230b60();
    f330 = 10;
    f338 = 10;
    f358 = 2.0f;
    f360 = 2.0f;
    f32c = 0;
    f334 = 0;
    f33c = 0;
    f340 = 0;
    f344 = 0;
    f348 = 0;
    f34c = 0;
    f354 = 0;
    f35c = 0;
    f364 = 0;
    f36c = 0;
    f390 = 0;
    f388 = 0;
    f38c = 0;
    f380 = 0;
    f384 = 0;
    f150 = 0;
    f350 = 4.5f;
    f368 = 1.1f;
    f370 = 10.0f;
    f374 = 200.0f;
    f378 = 1.5f;
    return this;
}
