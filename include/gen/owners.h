// Source, edited by hand (generated from include/gen/evidence-owners.json until gen1, 2026-11-13; docs/headers.md).
// Classes RTTI never names: one per member function definition, from the defining source's own stub
// (first made by tools/owner_classes.py, docs/consolidation-plan.md section 11). Offsets: 32-bit (64-bit).
#ifndef HULK_GEN_OWNERS_H
#define HULK_GEN_OWNERS_H
#include "_prelude.h"
namespace owners {
// matches/0x000110d0.cpp (stub V3_110d0), size 0xc
struct V3_110d0 {
    float x, y, z; // +0x00
    void FUN_000110d0(V3_110d0*);
};
// matches/0x000110f0.cpp (stub Vec3_110f0), size 0xc
struct Vec3_110f0 {
    float x, y, z; // +0x00
    void FUN_000110f0(Vec3_110f0* other);
};
// matches/0x00011140.cpp (stub Vec3_11140), size 0xc
struct Vec3_11140 {
    float x, y, z; // +0x00
    void FUN_00011140(float);
};
// matches/0x00011160.cpp (stub Vec3_11160), size 0xc
struct Vec3_11160 {
    float x, y, z; // +0x00
    void FUN_00011160(float s, const Vec3_11160* v);
};
// matches/0x00011220.cpp (stub Vec3), size 0xc
struct Vec3_11220 {
    float x, y, z; // +0x00
    Vec3_11220* FUN_00011220(const Vec3_11220* other);
};
// matches/0x00011250.cpp (stub Vec3_11250), size 0xc
struct Vec3_11250 {
    float x, y, z; // +0x00
    Vec3_11250* FUN_00011250(Vec3_11250* out, Vec3_11250* rhs);
};
// equivalent/0x00011330.cpp (stub Random), size 0x8
struct Random_11330 {
    unsigned int low; // +0x00
    unsigned int high; // +0x04
    unsigned int FUN_00011330(unsigned int maximum);
};
// equivalent/0x00011380.cpp (stub Random), size 0x8
struct Random_11380 {
    unsigned int low; // +0x00
    unsigned int high; // +0x04
    int FUN_00011380(int minimum, int maximum);
};
// equivalent/0x00011750.cpp (stub Color_11750), size 0x4
struct Color_11750 {
    unsigned int value; // +0x00
    void FUN_00011750(unsigned int from, unsigned int to, float amount);
};
// matches/0x000118c0.cpp (stub C_118c0), size 0x8
struct C_118c0 {
    char pad[8]; // +0x00
    void Callee(int* p);
    void FUN_000118c0(int* p);
};
// matches/0x00011ce0.cpp (stub A_11ce0), size 0x18
struct A_11ce0 {
    char pad[0x18]; // +0x00
    void* FUN_00011ce0();
};
// matches/0x00011e20.cpp (stub Obj_11e20), size 0x10
struct Obj_11e20 {
    char pad[16]; // +0x00
    int* FUN_00011e20();
};
// matches/0x00011e40.cpp (stub Obj_11e40), size 0x60
struct Obj_11e40 {
    char pad[0x60]; // +0x00
    void* FUN_00011e40();
};
// matches/0x00012080.cpp (stub O_12080), size 0x20
struct O_12080 {
    char pad[0x20]; // +0x00
    void* FUN_00012080();
};
// matches/0x000120a0.cpp (stub Obj_120a0), size 0x28
struct Obj_120a0 {
    char pad[0x28]; // +0x00
    void* FUN_000120a0();
};
// matches/0x000120c0.cpp (stub Obj_120c0), size 0x30
struct Obj_120c0 {
    char pad[0x30]; // +0x00
    void* FUN_000120c0();
};
// matches/0x000120e0.cpp (stub Obj_120e0), size 0x1
struct Obj_120e0 {
    void* FUN_000120e0();
};
// matches/0x00012100.cpp (stub C_12100), size 0x40
struct C_12100 {
    char* FUN_00012100();
    char pad[0x40]; // +0x00
};
// matches/0x00012120.cpp (stub Obj_12120), size 0x48
struct Obj_12120 {
    char pad[0x48]; // +0x00
    char* FUN_00012120();
};
// matches/0x00012140.cpp (stub Obj_12140), size 0x50
struct Obj_12140 {
    char mBuf[0x50]; // +0x00
    char* FUN_00012140();
};
// matches/0x00012160.cpp (stub T_12160), size 0x58
struct T_12160 {
    char pad[0x58]; // +0x00
    void* FUN_00012160();
};
// matches/0x00012310.cpp (stub T_12310), size 0x18
struct T_12310 {
    char pad[0x18]; // +0x00
    int* FUN_00012310();
};
// matches/0x00012530.cpp (stub Obj_12530), size 0x2c
struct Obj_12530 {
    char pad[0x2c]; // +0x00
    int* FUN_00012530();
};
// matches/0x00012540.cpp (stub X_12540), size 0x38
struct X_12540 {
    char pad[0x38]; // +0x00
    char* FUN_00012540();
};
// matches/0x00012550.cpp (stub Thing_12550), size 0x49
struct Thing_12550 {
    char pad[0x49]; // +0x00
    void* FUN_00012550();
};
// matches/0x00012680.cpp (stub Obj_12680), size 0x24 (0x28)
struct Obj_12680 {
    char pad[0x20]; // +0x00
    void* member; // +0x20
    void* FUN_00012680();
};
// matches/0x00012740.cpp (stub Obj_12740), size 0x18
struct Obj_12740 {
    char pad[0x18]; // +0x00
    char* FUN_00012740();
};
// matches/0x00012750.cpp (stub Obj_12750), size 0x20
struct Obj_12750 {
    char pad[0x20]; // +0x00
    int* FUN_00012750();
};
// matches/0x000127d0.cpp (stub X_127d0), size 0xc8
struct X_127d0 {
    char pad[0xc8]; // +0x00
    char* FUN_000127d0();
};
// matches/0x000127e0.cpp (stub Obj_127e0), size 0x98
struct Obj_127e0 {
    char pad[0x98]; // +0x00
    char* FUN_000127e0();
};
// matches/0x000127f0.cpp (stub Obj_127f0), size 0xa0
struct Obj_127f0 {
    char pad[0xa0]; // +0x00
    void* FUN_000127f0();
};
// matches/0x00012900.cpp (stub Obj_12900), size 0x18
struct Obj_12900 {
    char pad[0x18]; // +0x00
    char* FUN_00012900();
};
// matches/0x00012910.cpp (stub Obj_12910), size 0x20
struct Obj_12910 {
    char pad[0x20]; // +0x00
    void* FUN_00012910();
};
// matches/0x00012920.cpp (stub X_12920), size 0x28
struct X_12920 {
    char pad[0x28]; // +0x00
    void* FUN_00012920();
};
// matches/0x00012930.cpp (stub X_12930), size 0x1
struct X_12930 {
    int* FUN_00012930();
};
// matches/0x00012940.cpp (stub Obj_12940), size 0x1
struct Obj_12940 {
    void* FUN_00012940();
};
// matches/0x00012950.cpp (stub C_12950), size 0x40
struct C_12950 {
    char pad[0x40]; // +0x00
    void* FUN_00012950();
};
// matches/0x000129a0.cpp (stub Obj_129a0), size 0x68
struct Obj_129a0 {
    char pad[0x68]; // +0x00
    char* FUN_000129a0();
};
// matches/0x000129e0.cpp (stub A_129e0), size 0x10
struct A_129e0 {
    char pad[0x10]; // +0x00
    int* FUN_000129e0();
};
// matches/0x000129f0.cpp (stub Obj_129f0), size 0x18
struct Obj_129f0 {
    char pad[0x18]; // +0x00
    void* FUN_000129f0();
};
// matches/0x00012a60.cpp (stub Obj_12a60), size 0x40
struct Obj_12a60 {
    char pad[0x40]; // +0x00
    char* FUN_00012a60() throw();
};
// matches/0x00012ae0.cpp (stub Obj_12ae0), size 0x10
struct Obj_12ae0 {
    char pad[0x10]; // +0x00
    char* FUN_00012ae0();
};
// matches/0x00012bd0.cpp (stub O_12bd0), size 0x38
struct O_12bd0 {
    char pad[0x38]; // +0x00
    void* FUN_00012bd0();
};
// matches/0x00012c40.cpp (stub Body_12c40), size 0x1
struct Body_12c40 {
    Body_12c40* FUN_00012c40();
};
// matches/0x00012c80.cpp (stub Obj_12c80), size 0xa8
struct Obj_12c80 {
    char pad[0xa8]; // +0x00
    void* FUN_00012c80();
};
// matches/0x00012d80.cpp (stub C_12d80), size 0x28
struct C_12d80 {
    char pad[0x28]; // +0x00
    void* FUN_00012d80();
};
// matches/0x00012da0.cpp (stub Obj_12da0), size 0x31
struct Obj_12da0 {
    char pad[0x30]; // +0x00
    char data; // +0x30
    char* FUN_00012da0();
};
// matches/0x00012db0.cpp (stub X_12db0), size 0x18
struct X_12db0 {
    char pad[0x18]; // +0x00
    void* FUN_00012db0();
};
// matches/0x00012ee0.cpp (stub Obj_12ee0), size 0x4c
struct Obj_12ee0 {
    char pad[0x4c]; // +0x00
    int* FUN_00012ee0();
};
// matches/0x00012ef0.cpp (stub Obj_12ef0), size 0x58
struct Obj_12ef0 {
    char pad[0x58]; // +0x00
    char* FUN_00012ef0();
};
// matches/0x00012f00.cpp (stub Obj_12f00), size 0x68
struct Obj_12f00 {
    char pad[0x68]; // +0x00
    char* FUN_00012f00();
};
// matches/0x00012f10.cpp (stub Obj_12f10), size 0x74
struct Obj_12f10 {
    char pad[0x70]; // +0x00
    int m70; // +0x70
    int* FUN_00012f10();
};
// matches/0x00013050.cpp (stub A_13050), size 0x34
struct A_13050 {
    char pad[0x34]; // +0x00
    int* FUN_00013050();
};
// matches/0x00013060.cpp (stub Obj_13060), size 0x40
struct Obj_13060 {
    char pad[0x40]; // +0x00
    void* FUN_00013060();
};
// matches/0x00013090.cpp (stub Obj_13090), size 0x18
struct Obj_13090 {
    char pad[0x18]; // +0x00
    void* FUN_00013090();
};
// matches/0x00013140.cpp (stub X_13140), size 0x10
struct X_13140 {
    char pad[16]; // +0x00
    char* FUN_00013140();
};
// matches/0x000131a0.cpp (stub Obj_131a0), size 0x30
struct Obj_131a0 {
    char pad[0x30]; // +0x00
    char* FUN_000131a0();
};
// matches/0x000134e0.cpp (stub C_134e0), size 0x100
struct C_134e0 {
    char pad[0xfc]; // +0x00
    int value; // +0xfc
    int FUN_000134e0();
};
// matches/0x000238b0.cpp (stub Obj_238b0), size 0x1
struct Obj_238b0 {
    int Second(unsigned __int64);
    hulk_intptr FUN_000238b0(hulk_uintptr);
};
// matches/0x000240b0.cpp (stub Obj), size 0x1
struct Obj_240b0 {
    int set(__int64);
    hulk_intptr FUN_000240b0(hulk_intptr);
};
// matches/0x00024320.cpp (stub ItemList_24320), size 0xd4
struct ItemList_24320 {
    int pad0[3]; // +0x00
    int count; // +0x0c
    int values[17]; // +0x10
    int field54[16]; // +0x54
    int field94[16]; // +0x94
    bool FUN_00024320(int index);
};
// matches/0x000243f0.cpp (stub X_243f0), size 0x4
struct X_243f0 {
    int value; // +0x00
    void FUN_000243f0(hulk_intptr);
};
// matches/0x00024540.cpp (stub Obj_24540), size 0xe4
struct Obj_24540 {
    char pad[0xe0]; // +0x00
    int values[1]; // +0xe0
    bool FUN_00024540(hulk_intptr);
    int Lookup(int);
};
// matches/0x00024720.cpp (stub ItemList_24720), size 0x32c
struct ItemList_24720 {
    char pad0[0x228]; // +0x00
    char pad1[0x100]; // +0x228
    int count; // +0x328
    int Find(int, int);
    bool FUN_00024720(int, int);
};
// matches/0x00025240.cpp (stub C_25240), size 0x344
struct C_25240 {
    char pad[0x340]; // +0x00
    float value; // +0x340
    void FUN_00025240(float);
};
// matches/0x00025260.cpp (stub C_25260), size 0x14 (0x18)
struct C_25260 {
    void* v; // +0x00
    int pad[2]; // +0x04 (+0x08)
    int count; // +0x0c (+0x10)
    int items[1]; // +0x10 (+0x14)
    void FUN_00025260(int, int, int);
};
// matches/0x00025370.cpp (stub Target_25370), size 0x14 (0x18)
struct Target_25370 {
    int* vt; // +0x00
    int pad[2]; // +0x04 (+0x08)
    int count; // +0x0c (+0x10)
    int items[1]; // +0x10 (+0x14)
    void FUN_00025370(int arg);
};
// matches/0x000253c0.cpp (stub Target_253c0), size 0x14 (0x18)
struct Target_253c0 {
    int* vt; // +0x00
    int pad[2]; // +0x04 (+0x08)
    int count; // +0x0c (+0x10)
    int items[1]; // +0x10 (+0x14)
    void FUN_000253c0(int arg);
};
// matches/0x00025720.cpp (stub C_25720), size 0x590
struct C_25720 {
    char pad[0x58c]; // +0x00
    int count; // +0x58c
    void FUN_00025720(int);
};
// matches/0x00025890.cpp (stub C_25890), size 0xc10
struct C_25890 {
    char pad[0xc10]; // +0x00
    void* FUN_00025890(int x);
};
// matches/0x00025930.cpp (stub Palette), size 0xd40
struct Palette_25930 {
    char pad[0xd30]; // +0x00
    unsigned int colors[4]; // +0xd30
    unsigned int* FUN_00025930(unsigned int* out, int index);
};
// matches/0x000259f0.cpp (stub Obj), size 0x1
struct Obj_259f0 {
    hulk_intptr FUN_000259f0(hulk_intptr a);
    int Sub(int x, int y);
};
// matches/0x00025eb0.cpp (stub Thing_25eb0), size 0x58c (0x598)
struct Thing_25eb0 {
    char pad000[4]; // +0x00
    void* mChild; // +0x04 (+0x08)
    char pad008[0x48]; // +0x08 (+0x10)
    unsigned char mFlag50; // +0x50 (+0x58)
    char pad051[0x83]; // +0x51 (+0x59)
    int mA; // +0xd4 (+0xdc)
    int mB; // +0xd8 (+0xe0)
    int mC; // +0xdc (+0xe4)
    char pad0e0[0x270]; // +0xe0 (+0xe8)
    unsigned char m350; // +0x350 (+0x358)
    unsigned char m351; // +0x351 (+0x359)
    unsigned char m352; // +0x352 (+0x35a)
    char pad353[0x231]; // +0x353 (+0x35b)
    int m584; // +0x584 (+0x58c)
    unsigned char m588; // +0x588 (+0x590)
    void FUN_00025eb0();
};
// matches/0x000269f0.cpp (stub C_269f0), size 0x32c
struct C_269f0 {
    char pad[0x228]; // +0x00
    char slots[0x100]; // +0x228
    int count; // +0x328
    int find(int, int);
    bool FUN_000269f0(int, int);
};
// matches/0x00034440.cpp (stub Vec3_34440), size 0xc
struct Vec3_34440 {
    float x, y, z; // +0x00
    void FUN_00034440(Vec3_34440* a, Vec3_34440* b);
};
// matches/0x000344b0.cpp (stub Vec3_344b0), size 0xc
struct Vec3_344b0 {
    float x, y, z; // +0x00
    Vec3_344b0* FUN_000344b0(float s);
};
// matches/0x00034c80.cpp (stub Wrapper), size 0x1
struct Wrapper_34c80 {
    void FUN_001c5080(float, int);
    void FUN_00034c80(int value);
};
// matches/0x00034ce0.cpp (stub Obj), size 0x1
struct Obj_34ce0 {
    int take(__int64);
    int FUN_00034ce0(const char*);
};
// matches/0x00034d80.cpp (stub C_34d80), size 0x18 (0x20)
struct C_34d80 {
    char pad[0x14]; // +0x00
    char* base; // +0x14 (+0x18)
    void FUN_00034d80(int index, unsigned int* src);
};
// matches/0x00034e60.cpp (stub C_34e60), size 0x18
struct C_34e60 {
    char pad[0x18]; // +0x00
    float FUN_00034e60();
};
// matches/0x00035230.cpp (stub Obj_35230), size 0x50
struct Obj_35230 {
    char pad[0x44]; // +0x00
    unsigned a, b, c; // +0x44
    bool FUN_00035230(unsigned* out);
};
// matches/0x000353d0.cpp (stub C_353d0), size 0x9c
struct C_353d0 {
    char pad[0x90]; // +0x00
    int a, b, c; // +0x90
    bool FUN_000353d0(const int* p);
};
// matches/0x00035400.cpp (stub Obj_35400), size 0xa8
struct Obj_35400 {
    char pad[0x9c]; // +0x00
    unsigned int a; // +0x9c
    unsigned int b; // +0xa0
    unsigned int c; // +0xa4
    bool FUN_00035400(unsigned int* out);
};
// matches/0x00035430.cpp (stub C_35430), size 0xa8
struct C_35430 {
    char pad[0x9c]; // +0x00
    unsigned a, b, c; // +0x9c
    bool FUN_00035430(unsigned*);
};
// matches/0x00035460.cpp (stub C_35460), size 0xb4
struct C_35460 {
    char pad[0xa8]; // +0x00
    unsigned a, b, c; // +0xa8
    bool FUN_00035460(unsigned* out);
};
// matches/0x00035490.cpp (stub Obj_35490), size 0xb4
struct Obj_35490 {
    char pad[0xa8]; // +0x00
    unsigned a, b, c; // +0xa8
    bool FUN_00035490(unsigned* p);
};
// matches/0x00035660.cpp (stub C_35660), size 0x80
struct C_35660 {
    char pad[0x74]; // +0x00
    int a, b, c; // +0x74
    bool FUN_00035660(int* out);
};
// matches/0x000356c0.cpp (stub Thing_356c0), size 0x8c
struct Thing_356c0 {
    char pad[0x80]; // +0x00
    unsigned int a; // +0x80
    unsigned int b; // +0x84
    unsigned int c; // +0x88
    bool FUN_000356c0(unsigned int* out);
};
// matches/0x000357a0.cpp (stub C_357a0), size 0x1c0
struct C_357a0 {
    char pad[0x1b4]; // +0x00
    volatile float a; // +0x1b4
    float b, c; // +0x1b8
    void FUN_000357a0(float* p);
};
// matches/0x000358c0.cpp (stub C_358c0), size 0x200
struct C_358c0 {
    char pad[0x1e4]; // +0x00
    int a; // +0x1e4
    int d; // +0x1e8
    int c; // +0x1ec
    int b; // +0x1f0
    int e; // +0x1f4
    int f; // +0x1f8
    int count; // +0x1fc
    void FUN_000358c0(bool x);
};
// matches/0x00035910.cpp (stub Widget_35910), size 0x138
struct Widget_35910 {
    char pad[0x134]; // +0x00
    int mValue; // +0x134
    hulk_intptr FUN_00035910();
};
// matches/0x00035930.cpp (stub Obj_35930), size 0x138 (0x140)
struct Obj_35930 {
    char pad[0x10]; // +0x00
    int* ptr; // +0x10
    char pad2[0x120]; // +0x14 (+0x18)
    int value; // +0x134 (+0x138)
    void FUN_00035930(int x);
};
// matches/0x00035980.cpp (stub C_35980), size 0x13c
struct C_35980 {
    char pad[0x138]; // +0x00
    int value; // +0x138
    void FUN_00035980(bool x);
};
// matches/0x000359c0.cpp (stub C_359c0), size 0x140
struct C_359c0 {
    char pad[0x13c]; // +0x00
    int value; // +0x13c
    void FUN_000359c0(int x);
};
// equivalent/0x00035b70.cpp (stub State_35b70), size 0x314
struct State_35b70 {
    char pad[0x308]; // +0x00
    float start, duration, end; // +0x308
    void FUN_00035b70(float a, float b, float c);
};
// matches/0x00035c30.cpp (stub Thing_35c30), size 0x304
struct Thing_35c30 {
    char pad[0x200]; // +0x00
    int values[64]; // +0x200
    int count; // +0x300
    bool FUN_00035c30(hulk_intptr x);
};
// matches/0x00035c70.cpp (stub Queue), size 0x308
struct Queue_35c70 {
    char pad[0x200]; // +0x00
    int entries[64]; // +0x200
    int count; // +0x300
    int index; // +0x304
    void FUN_00035c70(hulk_intptr value);
};
// matches/0x00035cd0.cpp (stub C_35cd0), size 0x308
struct C_35cd0 {
    char pad[0x300]; // +0x00
    int a; // +0x300
    int b; // +0x304
    void FUN_00035cd0();
};
// matches/0x00035ce0.cpp (stub Target_35ce0), size 0x1cf5
struct Target_35ce0 {
    char pad[0x1cf4]; // +0x00
    unsigned char value; // +0x1cf4
    void FUN_00035ce0(unsigned char x);
};
// matches/0x00035ef0.cpp (stub C_35ef0), size 0x628
struct C_35ef0 {
    char pad[0x3a8]; // +0x00
    int values[8][20]; // +0x3a8
    hulk_intptr FUN_00035ef0(hulk_intptr);
};
// matches/0x00035f20.cpp (stub C_35f20), size 0x628
struct C_35f20 {
    char pad[0x3a8]; // +0x00
    int a[8][0x14]; // +0x3a8
    bool FUN_00035f20();
};
// matches/0x00036020.cpp (stub Thing_36020), size 0x630
struct Thing_36020 {
    char pad[0x62c]; // +0x00
    unsigned int value; // +0x62c
    hulk_uintptr FUN_00036020();
};
// matches/0x00036030.cpp (stub C_36030), size 0x634
struct C_36030 {
    char pad[0x630]; // +0x00
    unsigned int value; // +0x630
    hulk_uintptr FUN_00036030();
};
// matches/0x00036040.cpp (stub Obj), size 0x1b14
struct Obj_36040 {
    char pad[0x1b0c]; // +0x00
    float a; // +0x1b0c
    float b; // +0x1b10
    char FUN_00036040(float x);
};
// matches/0x000360f0.cpp (stub Thing_360f0), size 0x118
struct Thing_360f0 {
    char pad[0x110]; // +0x00
    float value; // +0x110
    int count; // +0x114
    bool FUN_000360f0();
};
// matches/0x00036120.cpp (stub C_36120), size 0x114
struct C_36120 {
    char pad[0x110]; // +0x00
    float value; // +0x110
    void FUN_00036120(float x);
};
// matches/0x00036140.cpp (stub C_36140), size 0x118
struct C_36140 {
    char pad[0x114]; // +0x00
    int value; // +0x114
    void FUN_00036140(char b);
};
// matches/0x000361a0.cpp (stub A_361a0), size 0x1b1c
struct A_361a0 {
    char pad[0x1b18]; // +0x00
    float x; // +0x1b18
    void FUN_000361a0(float);
};
// matches/0x000361c0.cpp (stub C_361c0), size 0x1b20
struct C_361c0 {
    char pad[0x1b1c]; // +0x00
    int value; // +0x1b1c
    void FUN_000361c0(char b);
};
// matches/0x000361f0.cpp (stub X_361f0), size 0x1b24
struct X_361f0 {
    char pad[0x1b20]; // +0x00
    int value; // +0x1b20
    void FUN_000361f0(char b);
};
// matches/0x00036220.cpp (stub Thing_36220), size 0x1b28
struct Thing_36220 {
    char pad[0x1b24]; // +0x00
    int value; // +0x1b24
    void FUN_00036220(char up);
};
// matches/0x00036250.cpp (stub C_36250), size 0x1b30
struct C_36250 {
    char pad[0x1b28]; // +0x00
    int a; // +0x1b28
    int b; // +0x1b2c
    void FUN_00036250(int x);
};
// matches/0x000362f0.cpp (stub Obj_362f0), size 0x1d50
struct Obj_362f0 {
    char pad0[0x398]; // +0x00
    unsigned char flag; // +0x398
    char pad1[3]; // +0x399
    int mode; // +0x39c
    char pad2[0x1d4c - 0x3a0]; // +0x3a0
    unsigned char enabled; // +0x1d4c
    void FUN_000362f0();
};
// equivalent/0x00036350.cpp (stub Owner_36350), size 0x1ea8
struct Owner_36350 {
    char pad0[0x398]; // +0x00
    char flip; // +0x398
    char pad399[0x1e60 - 0x399]; // +0x399
    float values[14]; // +0x1e60
    char dirty[14]; // +0x1e98
    void FUN_00036350(int index, float offset);
};
// matches/0x00036910.cpp (stub C_36910), size 0x12c
struct C_36910 {
    char pad[0x12c]; // +0x00
    void FUN_00036910(unsigned char x);
};
// matches/0x00036950.cpp (stub A_36950), size 0x1d7a
struct A_36950 {
    char pad[0x1d78]; // +0x00
    unsigned char a; // +0x1d78
    unsigned char b; // +0x1d79
    unsigned char FUN_00036950(int x);
};
// matches/0x00036a80.cpp (stub Obj_36a80), size 0x12c (0x138)
struct Obj_36a80 {
    char pad[0x124]; // +0x00
    void* a; // +0x124 (+0x128)
    void* b; // +0x128 (+0x130)
    hulk_intptr FUN_00036a80(int unused);
};
// matches/0x00036c20.cpp (stub Thing_36c20), size 0x1e58
struct Thing_36c20 {
    char pad[0x1e50]; // +0x00
    int a; // +0x1e50
    int b; // +0x1e54
    void FUN_00036c20(hulk_intptr x);
};
// matches/0x00036c40.cpp (stub Obj_36c40), size 0x1e04
struct Obj_36c40 {
    char pad[0x1d84]; // +0x00
    unsigned int slots[0x20]; // +0x1d84
    void FUN_00036c40(unsigned int index, unsigned int value);
};
// matches/0x00036c60.cpp (stub C_36c60), size 0x1e04
struct C_36c60 {
    char pad[0x1d84]; // +0x00
    unsigned int values[32]; // +0x1d84
    hulk_uintptr FUN_00036c60(unsigned int i);
};
// matches/0x00036c90.cpp (stub C_36c90), size 0x1e04
struct C_36c90 {
    char pad[0x1e04]; // +0x00
    void FUN_00036c90(unsigned int index, unsigned int value);
};
// matches/0x00036cb0.cpp (stub X_36cb0), size 0x1e44
struct X_36cb0 {
    char pad[0x1e04]; // +0x00
    unsigned int values[16]; // +0x1e04
    unsigned int FUN_00036cb0(unsigned int i);
};
// matches/0x00036d40.cpp (stub C_36d40), size 0x2148
struct C_36d40 {
    char pad[0x2144]; // +0x00
    int value; // +0x2144
    void FUN_00036d40(int x);
};
// matches/0x00036d60.cpp (stub Obj_36d60), size 0x20b8
struct Obj_36d60 {
    char pad[0x20b8]; // +0x00
    void Finish(const char*);
    void FUN_00036d60(const char*);
};
// matches/0x00036e40.cpp (stub Obj_36e40), size 0x215c
struct Obj_36e40 {
    char pad[0x2158]; // +0x00
    unsigned int values[1]; // +0x2158
    int FUN_00036d90(unsigned int value);
    unsigned int FUN_00036e40(hulk_uintptr arg);
};
// matches/0x00036fd0.cpp (stub Thing_36fd0), size 0x1
struct Thing_36fd0 {
    int FUN_00036f00(int);
    unsigned char FUN_00036fd0(hulk_intptr);
};
// matches/0x00037040.cpp (stub C_37040), size 0x1
struct C_37040 {
    int Find(int);
    bool FUN_00037040(hulk_intptr key, int a, int b);
};
// matches/0x00037120.cpp (stub X_37120), size 0x22b0
struct X_37120 {
    char pad[0x22ac]; // +0x00
    int value; // +0x22ac
    void FUN_00037120(bool b);
};
// matches/0x00037160.cpp (stub Target_37160), size 0x22dc
struct Target_37160 {
    char pad[0x22d8]; // +0x00
    int value; // +0x22d8
    void FUN_00037160(int x);
};
// matches/0x00037170.cpp (stub Obj_37170), size 0x22dc
struct Obj_37170 {
    char pad[0x22dc]; // +0x00
    void FUN_00037170(int x);
};
// matches/0x00037180.cpp (stub O), size 0x22d4
struct O_37180 {
    char pad[0x22c8]; // +0x00
    int m1; // +0x22c8
    int m2; // +0x22cc
    int m3; // +0x22d0
    void FUN_00037180(int a, int b, int c);
};
// matches/0x000371b0.cpp (stub Obj_371b0), size 0x22d8
struct Obj_371b0 {
    char pad[0x22d4]; // +0x00
    int value; // +0x22d4
    void FUN_000371b0(int x);
};
// matches/0x00037300.cpp (stub Obj_37300), size 0x1c8d
struct Obj_37300 {
    char pad[0x1c8c]; // +0x00
    char value; // +0x1c8c
    void FUN_00037300(unsigned char b);
};
// matches/0x000373a0.cpp (stub Obj), size 0x20bd
struct Obj_373a0 {
    char pad[0x20b8]; // +0x00
    char m[5]; // +0x20b8
    char FUN_000373a0(int);
};
// matches/0x000373c0.cpp (stub Obj_373c0), size 0x22e1
struct Obj_373c0 {
    char pad[0x22e0]; // +0x00
    unsigned char field; // +0x22e0
    void FUN_000373c0(unsigned char);
};
// matches/0x000373e0.cpp (stub Target_373e0), size 0x22ea
struct Target_373e0 {
    char pad[0x22e9]; // +0x00
    unsigned char value; // +0x22e9
    void FUN_000373e0(unsigned char x);
};
// matches/0x00037410.cpp (stub Target_37410), size 0x22fc
struct Target_37410 {
    char pad[0x22fc]; // +0x00
    unsigned char FUN_00037410();
};
// matches/0x00037420.cpp (stub Target_37420), size 0x22fd
struct Target_37420 {
    char pad[0x22fc]; // +0x00
    unsigned char value; // +0x22fc
    void FUN_00037420(unsigned char);
};
// matches/0x00038de0.cpp (stub Obj_38de0), size 0x1
struct Obj_38de0 {
    void Lock(int);
    unsigned char FUN_00038de0(hulk_uintptr, hulk_uintptr, unsigned int, unsigned int, hulk_uintptr, hulk_uintptr, hulk_uintptr, hulk_uintptr);
};
// matches/0x00038e30.cpp (stub Obj_38e30), size 0x1
struct Obj_38e30 {
    void Gate(int);
    unsigned char FUN_00038e30(hulk_intptr a, hulk_intptr b, int c, int d, hulk_intptr e, hulk_intptr f);
};
// matches/0x0003ea10.cpp (stub Controller_3ea10), size 0x22ec (0x2300)
struct Controller_3ea10 {
    char pad0[0x10]; // +0x00
    int *ref10; // +0x10
    char pad14[0x12c - 0x14]; // +0x14 (+0x18)
    void *activeTarget; // +0x12c (+0x130)
    char pad130[0x20b0 - 0x130]; // +0x130 (+0x138)
    int mode; // +0x20b0 (+0x20b8)
    char pad20b4[0x22e4 - 0x20b4]; // +0x20b4 (+0x20bc)
    void *key; // +0x22e4 (+0x22f0)
    unsigned char flag; // +0x22e8 (+0x22f8)
    void FUN_0003b1c0(int a, int b);
    void FUN_0003ea10(int newMode);
};
// matches/0x0003ebb0.cpp (stub ClampOwner), size 0x1e60
struct ClampOwner_3ebb0 {
    char pad[0x1e58]; // +0x00
    float mValue; // +0x1e58
    int mKey; // +0x1e5c
    float FUN_0003ebb0(int key);
};
// equivalent/0x0003ec00.cpp (stub Progress_3ec00), size 0x1e60
struct Progress_3ec00 {
    char pad00[0x1e58]; // +0x00
    float value; // +0x1e58
    int key; // +0x1e5c
    float FUN_0003ec00(int k);
};
// matches/0x00042930.cpp (stub C_42930), size 0x33c
struct C_42930 {
    char pad0[0x118]; // +0x00
    unsigned char flag; // +0x118
    char pad1[0x314 - 0x119]; // +0x119
    float scale; // +0x314
    char pad2[0x338 - 0x318]; // +0x318
    int field338; // +0x338
    void FUN_00042930(int, float);
};
// matches/0x00042960.cpp (stub C_42960), size 0x33c
struct C_42960 {
    char pad0[0x118]; // +0x00
    unsigned char flag; // +0x118
    char pad1[0x314 - 0x119]; // +0x119
    float scale; // +0x314
    char pad2[0x338 - 0x318]; // +0x318
    int field338; // +0x338
    void FUN_00042960(int, float);
};
// matches/0x00044630.cpp (stub C_44630), size 0xa0
struct C_44630 {
    char pad[0xa0]; // +0x00
    int FUN_00044630(int i);
};
// matches/0x000446a0.cpp (stub C_446a0), size 0xd0
struct C_446a0 {
    char pad[0xd0]; // +0x00
    float FUN_000446a0(int index);
};
// matches/0x000446c0.cpp (stub Obj_446c0), size 0x1
struct Obj_446c0 {
    hulk_intptr FUN_000446c0(int index);
};
// matches/0x000447b0.cpp (stub Config_447b0), size 0x1b4
struct Config_447b0 {
    char pad0[0x1b0]; // +0x00
    int mode; // +0x1b0
    void FUN_000447b0(const char* name);
};
// matches/0x00044ab0.cpp (stub C_44ab0), size 0x14 (0x18)
struct C_44ab0 {
    char pad[12]; // +0x00
    int count; // +0x0c
    int* items; // +0x10
    hulk_intptr FUN_00044ab0(int i);
};
// matches/0x00045670.cpp (stub Obj_45670), size 0x320
struct Obj_45670 {
    char pad[0x314]; // +0x00
    float f314, f318, f31c; // +0x314
    float FUN_00045670();
};
// matches/0x000456e0.cpp (stub Obj_456e0), size 0x18
struct Obj_456e0 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    unsigned char FUN_000456e0();
};
// matches/0x00047a90.cpp (stub X_47a90), size 0x10
struct X_47a90 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    char FUN_00047a90(int v);
};
// matches/0x00047aa0.cpp (stub Obj_47aa0), size 0x14
struct Obj_47aa0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_00047aa0(int v);
};
// matches/0x00047ab0.cpp (stub Obj_47ab0), size 0xc
struct Obj_47ab0 {
    char FUN_00047ab0(int x);
    char pad[0xc]; // +0x00
};
// matches/0x00047ac0.cpp (stub Obj_47ac0), size 0x14
struct Obj_47ac0 {
    char pad[0x10]; // +0x00
    int mVal; // +0x10
    char FUN_00047ac0(int v);
};
// matches/0x00047ad0.cpp (stub C_47ad0), size 0x18
struct C_47ad0 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    char FUN_00047ad0(int v);
};
// matches/0x00047ae0.cpp (stub O_47ae0), size 0x1c
struct O_47ae0 {
    char pad[0x18]; // +0x00
    int mValue; // +0x18
    bool FUN_00047ae0(int x);
};
// matches/0x00047af0.cpp (stub C_47af0), size 0x20
struct C_47af0 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    bool FUN_00047af0(int x);
};
// matches/0x00047b00.cpp (stub C_47b00), size 0x10
struct C_47b00 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    bool FUN_00047b00(int x);
};
// matches/0x00047b10.cpp (stub Target_47b10), size 0x14
struct Target_47b10 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_00047b10(int v);
};
// matches/0x00047b20.cpp (stub A_47b20), size 0x18
struct A_47b20 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    bool FUN_00047b20(int v);
};
// matches/0x00047b50.cpp (stub C_47b50), size 0x1c
struct C_47b50 {
    char pad[0x18]; // +0x00
    int mValue; // +0x18
    char FUN_00047b50(int v);
};
// matches/0x00047b60.cpp (stub Obj_47b60), size 0x20
struct Obj_47b60 {
    char FUN_00047b60(int x);
    char pad[0x1c]; // +0x00
    int mVal; // +0x1c
};
// matches/0x00047b70.cpp (stub C_47b70), size 0x1c
struct C_47b70 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    bool FUN_00047b70(int x);
};
// matches/0x00047b80.cpp (stub O_47b80), size 0x20
struct O_47b80 {
    char pad[0x1c]; // +0x00
    float m; // +0x1c
    char FUN_00047b80(float angle);
};
// matches/0x00047ba0.cpp (stub Obj_47ba0), size 0x14
struct Obj_47ba0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_00047ba0(int v);
};
// matches/0x00047bb0.cpp (stub O_47bb0), size 0x18
struct O_47bb0 {
    char pad[0x14]; // +0x00
    float mAngle; // +0x14
    bool FUN_00047bb0(float a);
};
// matches/0x00047bd0.cpp (stub X_47bd0), size 0x1c
struct X_47bd0 {
    char pad[0x18]; // +0x00
    int m; // +0x18
    char FUN_00047bd0(int v);
};
// matches/0x00047be0.cpp (stub Obj_47be0), size 0x20
struct Obj_47be0 {
    char pad[0x1c]; // +0x00
    int m; // +0x1c
    char FUN_00047be0(int value);
};
// matches/0x00047c40.cpp (stub Obj_47c40), size 0x10
struct Obj_47c40 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    bool FUN_00047c40(int value);
};
// matches/0x00047ca0.cpp (stub Obj_47ca0), size 0x10
struct Obj_47ca0 {
    char pad[12]; // +0x00
    float v; // +0x0c
    char FUN_00047ca0(float x);
};
// matches/0x00047cc0.cpp (stub Obj_47cc0), size 0x14
struct Obj_47cc0 {
    char pad[0x10]; // +0x00
    float mVal; // +0x10
    unsigned char FUN_00047cc0(float x);
};
// matches/0x00047ce0.cpp (stub Obj_47ce0), size 0x10
struct Obj_47ce0 {
    char Pad[12]; // +0x00
    float mVal; // +0x0c
    char FUN_00047ce0(float x);
};
// matches/0x00047d00.cpp (stub V), size 0x14
struct V_47d00 {
    char FUN_00047d00(float x);
    char pad[0x10]; // +0x00
    float v; // +0x10
};
// matches/0x00047d20.cpp (stub Obj_47d20), size 0x10
struct Obj_47d20 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    char FUN_00047d20(int value);
};
// matches/0x00047d30.cpp (stub Obj_47d30), size 0x10
struct Obj_47d30 {
    char pad[16]; // +0x00
    void* FUN_00047d30();
};
// matches/0x00047d50.cpp (stub Obj), size 0x10
struct Obj_47d50 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_00047d50(int x);
};
// matches/0x00047d60.cpp (stub Obj_47d60), size 0x14
struct Obj_47d60 {
    char FUN_00047d60(int v);
    char pad[0x10]; // +0x00
    int mValue; // +0x10
};
// matches/0x00047d70.cpp (stub A_47d70), size 0x10
struct A_47d70 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_00047d70(int x);
};
// matches/0x00047d80.cpp (stub X_47d80), size 0x14
struct X_47d80 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    bool FUN_00047d80(int v);
};
// matches/0x00047d90.cpp (stub Obj_47d90), size 0xc
struct Obj_47d90 {
    char FUN_00047d90(int x);
    char pad[12]; // +0x00
};
// matches/0x00047da0.cpp (stub Obj_47da0), size 0x14
struct Obj_47da0 {
    char pad[0x10]; // +0x00
    int mVal; // +0x10
    char FUN_00047da0(int v);
};
// matches/0x00047db0.cpp (stub Obj_47db0), size 0x10
struct Obj_47db0 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_00047db0(int v);
};
// matches/0x00047dc0.cpp (stub Obj), size 0x14
struct Obj_47dc0 {
    char pad[16]; // +0x00
    float angle; // +0x10
    bool FUN_00047dc0(float x);
};
// matches/0x00047de0.cpp (stub O_47de0), size 0x10
struct O_47de0 {
    bool FUN_00047de0(int x);
    char pad[12]; // +0x00
    int m; // +0x0c
};
// matches/0x00047df0.cpp (stub X_47df0), size 0x14
struct X_47df0 {
    char FUN_00047df0(int a);
    char pad[16]; // +0x00
    int m10; // +0x10
};
// matches/0x00047e30.cpp (stub X_47e30), size 0x10
struct X_47e30 {
    char Pad[12]; // +0x00
    int Value; // +0x0c
    char FUN_00047e30(int arg);
};
// matches/0x00047e40.cpp (stub Obj_47e40), size 0x14
struct Obj_47e40 {
    char pad[0x10]; // +0x00
    int mVal; // +0x10
    bool FUN_00047e40(int v);
};
// matches/0x00047e50.cpp (stub Target_47e50), size 0x10
struct Target_47e50 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    bool FUN_00047e50(int value);
};
// matches/0x00047e60.cpp (stub Obj_47e60), size 0x14
struct Obj_47e60 {
    char pad[0x10]; // +0x00
    int mVal; // +0x10
    bool FUN_00047e60(int v);
};
// matches/0x00047ec0.cpp (stub Obj_47ec0), size 0x10
struct Obj_47ec0 {
    char FUN_00047ec0(float x);
    char mPad[12]; // +0x00
    float mAngle; // +0x0c
};
// matches/0x00047f30.cpp (stub X_47f30), size 0x10
struct X_47f30 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    char FUN_00047f30(int v);
};
// matches/0x00047f40.cpp (stub Obj_47f40), size 0x10
struct Obj_47f40 {
    char pad[0x10]; // +0x00
    char* FUN_00047f40();
};
// matches/0x00047f50.cpp (stub Obj_47f50), size 0x10 (0x18)
struct Obj_47f50 {
    char pad[0xc]; // +0x00
    void* mPointer; // +0x0c (+0x10)
    bool FUN_00047f50(void* p);
};
// matches/0x00047fe0.cpp (stub Obj_47fe0), size 0x10
struct Obj_47fe0 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_00047fe0(int x);
};
// matches/0x00047ff0.cpp (stub Obj_47ff0), size 0x10
struct Obj_47ff0 {
    char pad[0x10]; // +0x00
    void* FUN_00047ff0();
};
// matches/0x00048000.cpp (stub A_48000), size 0x10
struct A_48000 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    bool FUN_00048000(int x);
};
// matches/0x00048010.cpp (stub Obj_48010), size 0x10
struct Obj_48010 {
    char pad[16]; // +0x00
    void* FUN_00048010();
};
// matches/0x00048020.cpp (stub X_48020), size 0x10
struct X_48020 {
    char FUN_00048020(int v);
    char pad[12]; // +0x00
    int m; // +0x0c
};
// matches/0x00048030.cpp (stub Obj_48030), size 0x10
struct Obj_48030 {
    char pad[0x10]; // +0x00
    int* FUN_00048030();
};
// matches/0x00048100.cpp (stub Obj_48100), size 0xd
struct Obj_48100 {
    char pad[12]; // +0x00
    unsigned char value; // +0x0c
    unsigned char FUN_00048100(unsigned char x);
};
// matches/0x00048170.cpp (stub Obj_48170), size 0x10
struct Obj_48170 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    bool FUN_00048170(int value);
};
// matches/0x00048180.cpp (stub Obj_48180), size 0x14
struct Obj_48180 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_00048180(int x);
};
// matches/0x000481c0.cpp (stub Obj_481c0), size 0x10 (0x18)
struct Obj_481c0 {
    char pad[12]; // +0x00
    void* mObj; // +0x0c (+0x10)
    bool FUN_000481c0(void* p);
};
// matches/0x000481d0.cpp (stub Obj_481d0), size 0x14
struct Obj_481d0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_000481d0(int x);
};
// matches/0x000481e0.cpp (stub Obj_481e0), size 0x14 (0x20)
struct Obj_481e0 {
    char pad[12]; // +0x00
    void* mP; // +0x0c (+0x10)
    int mFlag; // +0x10 (+0x18)
    char FUN_000481e0(void* p);
};
// matches/0x000481f0.cpp (stub X_481f0), size 0x11
struct X_481f0 {
    char FUN_000481f0(char b);
    char pad[0x10]; // +0x00
    char m10; // +0x10
};
// matches/0x0004c790.cpp (stub Thing), size 0x14
struct Thing_4c790 {
    char pad[0x10]; // +0x00
    float angle; // +0x10
    bool FUN_0004c790(float x);
};
// equivalent/0x000592a0.cpp (stub Object), size 0xc
struct Object_592a0 {
    char pad[8]; // +0x00
    int value; // +0x08
    hulk_intptr FUN_000592a0();
};
// matches/0x00059c10.cpp (stub ThisWrap_00059c10), size 0x1
struct ThisWrap_00059c10 {
    void* FUN_00059ba0(void*);
    hulk_uintptr FUN_00059c10(void* p);
};
// matches/0x0005a0d0.cpp (stub O_5a0d0), size 0x10
struct O_5a0d0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0005a0d0(int x);
};
// matches/0x0005a0e0.cpp (stub Obj_5a0e0), size 0x10
struct Obj_5a0e0 {
    char m[0x10]; // +0x00
    char FUN_0005a0e0(int a);
};
// matches/0x0005a0f0.cpp (stub Obj_5a0f0), size 0x74
struct Obj_5a0f0 {
    char pad[0x70]; // +0x00
    int m70; // +0x70
    char FUN_0005a0f0(int x);
};
// matches/0x0005a100.cpp (stub Obj_5a100), size 0x78
struct Obj_5a100 {
    char pad[0x74]; // +0x00
    int value; // +0x74
    char FUN_0005a100(int x);
};
// matches/0x0005a110.cpp (stub Obj_5a110), size 0x7c
struct Obj_5a110 {
    char pad[0x78]; // +0x00
    int m78; // +0x78
    char FUN_0005a110(int v);
};
// matches/0x0005a120.cpp (stub C_5a120), size 0x10
struct C_5a120 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0005a120(int x);
};
// matches/0x0005a130.cpp (stub Obj_5a130), size 0x21
struct Obj_5a130 {
    char m0[32]; // +0x00
    char m20; // +0x20
    char FUN_0005a130(char x);
};
// matches/0x0005a160.cpp (stub Obj_5a160), size 0x30
struct Obj_5a160 {
    char FUN_0005a160(float x);
    char pad[0x30]; // +0x00
};
// matches/0x0005a1d0.cpp (stub Obj_5a1d0), size 0x58
struct Obj_5a1d0 {
    char pad[0x54]; // +0x00
    int mVal; // +0x54
    bool FUN_0005a1d0(int v);
};
// matches/0x0005a1e0.cpp (stub Obj_5a1e0), size 0x5c
struct Obj_5a1e0 {
    char FUN_0005a1e0(int value);
    char pad[0x58]; // +0x00
    int m58; // +0x58
};
// matches/0x0005a1f0.cpp (stub Obj_5a1f0), size 0x5d
struct Obj_5a1f0 {
    char pad[0x5c]; // +0x00
    char m5c; // +0x5c
    char FUN_0005a1f0(unsigned char x);
};
// matches/0x0005a200.cpp (stub Obj_5a200), size 0x64
struct Obj_5a200 {
    char pad[0x60]; // +0x00
    int mFoo; // +0x60
    bool FUN_0005a200(int value);
};
// matches/0x0005a210.cpp (stub Obj_5a210), size 0x68
struct Obj_5a210 {
    char pad[0x64]; // +0x00
    int m64; // +0x64
    char FUN_0005a210(int v);
};
// matches/0x0005a220.cpp (stub C_5a220), size 0x10
struct C_5a220 {
    char FUN_0005a220(int a);
    char pad[12]; // +0x00
    int m; // +0x0c
};
// matches/0x0005a230.cpp (stub O_5a230), size 0x21
struct O_5a230 {
    char pad[0x20]; // +0x00
    char m20; // +0x20
    char FUN_0005a230(char v);
};
// matches/0x0005a260.cpp (stub Thing), size 0x34
struct Thing_5a260 {
    char pad[0x30]; // +0x00
    float angle; // +0x30
    char FUN_0005a260(float a);
};
// matches/0x0005a280.cpp (stub Obj_5a280), size 0x38
struct Obj_5a280 {
    char pad[0x34]; // +0x00
    int mVal; // +0x34
    bool FUN_0005a280(int x);
};
// matches/0x0005a290.cpp (stub Obj_5a290), size 0x3c
struct Obj_5a290 {
    char pad[0x38]; // +0x00
    int m38; // +0x38
    bool FUN_0005a290(int v);
};
// matches/0x0005a2a0.cpp (stub Obj_5a2a0), size 0x40
struct Obj_5a2a0 {
    char pad[0x3c]; // +0x00
    int mField; // +0x3c
    bool FUN_0005a2a0(int value);
};
// matches/0x0005a2b0.cpp (stub Obj_5a2b0), size 0x10
struct Obj_5a2b0 {
    char pad[0xc]; // +0x00
    int mVal; // +0x0c
    bool FUN_0005a2b0(int x);
};
// matches/0x0005a2c0.cpp (stub Target_5a2c0), size 0x14
struct Target_5a2c0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_0005a2c0(int x);
};
// matches/0x0005a2d0.cpp (stub O_5a2d0), size 0x10
struct O_5a2d0 {
    char pad[0x0c]; // +0x00
    int mVal; // +0x0c
    bool FUN_0005a2d0(int x);
};
// matches/0x0005a2e0.cpp (stub Obj_5a2e0), size 0x14
struct Obj_5a2e0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0005a2e0(int x);
};
// matches/0x0005a2f0.cpp (stub Obj_5a2f0), size 0x18
struct Obj_5a2f0 {
    char pad[0x14]; // +0x00
    int mValue; // +0x14
    char FUN_0005a2f0(int v);
};
// matches/0x0005a300.cpp (stub Obj_5a300), size 0x18
struct Obj_5a300 {
    char pad[0x18]; // +0x00
    void* FUN_0005a300();
};
// matches/0x0005a310.cpp (stub Obj_5a310), size 0x28
struct Obj_5a310 {
    char pad[0x24]; // +0x00
    int m24; // +0x24
    bool FUN_0005a310(int value);
};
// matches/0x0005a320.cpp (stub O_5a320), size 0x28
struct O_5a320 {
    char pad[0x28]; // +0x00
    void* FUN_0005a320();
};
// matches/0x0005a360.cpp (stub Obj_5a360), size 0x10
struct Obj_5a360 {
    char Pad[12]; // +0x00
    int mValue; // +0x0c
    char FUN_0005a360(int value);
};
// matches/0x0005a370.cpp (stub Obj_5a370), size 0x14
struct Obj_5a370 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_0005a370(int value);
};
// matches/0x0005a380.cpp (stub Obj_5a380), size 0x18
struct Obj_5a380 {
    char pad[0x18]; // +0x00
    void* FUN_0005a380();
};
// matches/0x0005a3b0.cpp (stub O_5a3b0), size 0x30
struct O_5a3b0 {
    char pad[0x2c]; // +0x00
    int mVal; // +0x2c
    char FUN_0005a3b0(int v);
};
// matches/0x0005a3c0.cpp (stub Obj_5a3c0), size 0x34
struct Obj_5a3c0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    char FUN_0005a3c0(int x);
};
// matches/0x0005a3d0.cpp (stub Obj_5a3d0), size 0x35
struct Obj_5a3d0 {
    char pad[0x34]; // +0x00
    char m34; // +0x34
    char FUN_0005a3d0(int value);
};
// matches/0x0005d120.cpp (stub Obj_5d120), size 0x10
struct Obj_5d120 {
    char pad[0xc]; // +0x00
    int mVal; // +0x0c
    bool FUN_0005d120(int x);
};
// matches/0x0005d140.cpp (stub Obj_5d140), size 0x18
struct Obj_5d140 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    char FUN_0005d140(int value);
};
// matches/0x0005d160.cpp (stub Obj_5d160), size 0x1d
struct Obj_5d160 {
    char pad[0x1c]; // +0x00
    unsigned char b; // +0x1c
    unsigned char FUN_0005d160(unsigned char v);
};
// matches/0x0005d4b0.cpp (stub T_5d4b0), size 0x10
struct T_5d4b0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0005d4b0(int a);
};
// matches/0x0005d4c0.cpp (stub X_5d4c0), size 0x14
struct X_5d4c0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_0005d4c0(int x);
};
// matches/0x0005d4d0.cpp (stub X_5d4d0), size 0x1
struct X_5d4d0 {
    char* FUN_0005d4d0();
};
// matches/0x0005d500.cpp (stub Obj_5d500), size 0x30
struct Obj_5d500 {
    char pad[0x2c]; // +0x00
    int mVal; // +0x2c
    bool FUN_0005d500(int x);
};
// matches/0x0005d510.cpp (stub O_5d510), size 0x34
struct O_5d510 {
    char pad[0x30]; // +0x00
    int value; // +0x30
    bool FUN_0005d510(int v);
};
// matches/0x0005d520.cpp (stub X_5d520), size 0x38
struct X_5d520 {
    char pad[0x34]; // +0x00
    int value; // +0x34
    bool FUN_0005d520(int v);
};
// matches/0x0005d530.cpp (stub Obj_5d530), size 0x39
struct Obj_5d530 {
    char FUN_0005d530(char c);
    char mPad[0x38]; // +0x00
    char mState; // +0x38
};
// matches/0x0005d540.cpp (stub Obj_5d540), size 0x3a
struct Obj_5d540 {
    char FUN_0005d540(char c);
    char pad[0x39]; // +0x00
    char m39; // +0x39
};
// matches/0x0005d550.cpp (stub Obj_5d550), size 0x3b
struct Obj_5d550 {
    char pad[0x3a]; // +0x00
    char mVal; // +0x3a
    char FUN_0005d550(char c);
};
// matches/0x0005d560.cpp (stub X_5d560), size 0x3c
struct X_5d560 {
    char FUN_0005d560(char v);
    char pad[0x3b]; // +0x00
    char m3b; // +0x3b
};
// matches/0x0005d570.cpp (stub C_5d570), size 0x3d
struct C_5d570 {
    char FUN_0005d570(char arg);
    char m[0x3c]; // +0x00
    char m3c; // +0x3c
};
// matches/0x0005d580.cpp (stub C_5d580), size 0x44
struct C_5d580 {
    char pad[0x40]; // +0x00
    int m40; // +0x40
    bool FUN_0005d580(int x);
};
// matches/0x0005d590.cpp (stub X_5d590), size 0x1
struct X_5d590 {
    bool FUN_0005d590(int v);
};
// matches/0x0005d5a0.cpp (stub C_5d5a0), size 0x4c
struct C_5d5a0 {
    char FUN_0005d5a0(int v);
    char pad[0x48]; // +0x00
    int m; // +0x48
};
// matches/0x0005d5b0.cpp (stub Obj_5d5b0), size 0xbc
struct Obj_5d5b0 {
    char pad[0xb8]; // +0x00
    int mValue; // +0xb8
    bool FUN_0005d5b0(int value);
};
// matches/0x0005d5c0.cpp (stub C_5d5c0), size 0xc0
struct C_5d5c0 {
    char pad[0xbc]; // +0x00
    int mValue; // +0xbc
    bool FUN_0005d5c0(int x);
};
// matches/0x0005d5d0.cpp (stub Obj), size 0xcc
struct Obj_5d5d0 {
    char pad[0xc0]; // +0x00
    int a, b, c; // +0xc0
    bool FUN_0005d5d0(int* p);
};
// matches/0x0005d630.cpp (stub Obj_5d630), size 0xdc
struct Obj_5d630 {
    char FUN_0005d630(int x);
    char pad[0xd8]; // +0x00
    int value; // +0xd8
};
// matches/0x0005d640.cpp (stub O_5d640), size 0xe0
struct O_5d640 {
    char pad[0xdc]; // +0x00
    int m; // +0xdc
    bool FUN_0005d640(int x);
};
// matches/0x0005d680.cpp (stub Obj_5d680), size 0xf0
struct Obj_5d680 {
    char FUN_0005d680(int x);
    char mPad[0xec]; // +0x00
    int mField; // +0xec
};
// matches/0x0005d690.cpp (stub Obj_5d690), size 0x10
struct Obj_5d690 {
    char pad[12]; // +0x00
    int mX; // +0x0c
    bool FUN_0005d690(int x);
};
// matches/0x0005d6a0.cpp (stub A_5d6a0), size 0x14
struct A_5d6a0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_0005d6a0(int value);
};
// matches/0x0005d6b0.cpp (stub Obj_5d6b0), size 0x18
struct Obj_5d6b0 {
    char pad[0x18]; // +0x00
    int* FUN_0005d6b0();
};
// matches/0x0005d6e0.cpp (stub C_5d6e0), size 0x30
struct C_5d6e0 {
    bool FUN_0005d6e0(int x);
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
};
// matches/0x0005d6f0.cpp (stub A_5d6f0), size 0x34
struct A_5d6f0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0005d6f0(int v);
};
// matches/0x0005d700.cpp (stub Obj_5d700), size 0x10
struct Obj_5d700 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0005d700(int x);
};
// matches/0x0005d710.cpp (stub Obj), size 0x14
struct Obj_5d710 {
    char pad[16]; // +0x00
    int value; // +0x10
    bool FUN_0005d710(int x);
};
// matches/0x0005d720.cpp (stub Obj_5d720), size 0x18
struct Obj_5d720 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    char FUN_0005d720(int x);
};
// matches/0x0005d730.cpp (stub Obj_5d730), size 0x24
struct Obj_5d730 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_0005d730(int v);
};
// matches/0x0005d740.cpp (stub Obj_5d740), size 0x28
struct Obj_5d740 {
    char FUN_0005d740(int x);
    char pad[0x24]; // +0x00
    int m24; // +0x24
};
// matches/0x0005d750.cpp (stub A_5d750), size 0x2c
struct A_5d750 {
    char FUN_0005d750(int v);
    char pad[0x28]; // +0x00
    int m28; // +0x28
};
// matches/0x0005d760.cpp (stub Obj_5d760), size 0x30
struct Obj_5d760 {
    char Pad[0x2c]; // +0x00
    int Value; // +0x2c
    char FUN_0005d760(int x);
};
// matches/0x0005d770.cpp (stub T_5d770), size 0x34
struct T_5d770 {
    char FUN_0005d770(int a);
    char pad[0x30]; // +0x00
    int m; // +0x30
};
// matches/0x0005d780.cpp (stub Obj_5d780), size 0x44
struct Obj_5d780 {
    char pad[0x40]; // +0x00
    int m40; // +0x40
    char FUN_0005d780(int v);
};
// matches/0x0005d790.cpp (stub Obj_5d790), size 0x48
struct Obj_5d790 {
    char pad[0x44]; // +0x00
    int m44; // +0x44
    bool FUN_0005d790(int v);
};
// matches/0x0005d7a0.cpp (stub Obj_5d7a0), size 0x4c
struct Obj_5d7a0 {
    char pad[0x48]; // +0x00
    int value; // +0x48
    bool FUN_0005d7a0(int v);
};
// matches/0x0005d7b0.cpp (stub Thing_5d7b0), size 0x4e
struct Thing_5d7b0 {
    char mField[0x4d + 1]; // +0x00
    unsigned char FUN_0005d7b0(unsigned char v);
};
// matches/0x0005d7c0.cpp (stub X_5d7c0), size 0x10
struct X_5d7c0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0005d7c0(int x);
};
// matches/0x0005d7d0.cpp (stub Obj_5d7d0), size 0x1c
struct Obj_5d7d0 {
    char FUN_0005d7d0(int v);
    char pad[0x18]; // +0x00
    int mVal; // +0x18
};
// matches/0x0005d7e0.cpp (stub Obj_5d7e0), size 0x20
struct Obj_5d7e0 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    bool FUN_0005d7e0(int value);
};
// matches/0x0005d7f0.cpp (stub C_5d7f0), size 0x24
struct C_5d7f0 {
    char pad[0x20]; // +0x00
    int mValue; // +0x20
    bool FUN_0005d7f0(int x);
};
// matches/0x0005d800.cpp (stub Obj_5d800), size 0x28
struct Obj_5d800 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    bool FUN_0005d800(int x);
};
// matches/0x0005d810.cpp (stub Obj_5d810), size 0x2c
struct Obj_5d810 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    bool FUN_0005d810(int v);
};
// matches/0x0005d820.cpp (stub Obj_5d820), size 0x3c
struct Obj_5d820 {
    char pad[0x38]; // +0x00
    int mField; // +0x38
    bool FUN_0005d820(int value);
};
// matches/0x0005d830.cpp (stub C_5d830), size 0x40
struct C_5d830 {
    char pad[0x3c]; // +0x00
    int value; // +0x3c
    char FUN_0005d830(int x);
};
// matches/0x0005d840.cpp (stub Obj_5d840), size 0x44
struct Obj_5d840 {
    char pad[0x40]; // +0x00
    int member; // +0x40
    bool FUN_0005d840(int v);
};
// matches/0x0005d850.cpp (stub Obj_5d850), size 0x10
struct Obj_5d850 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_0005d850(int v);
};
// matches/0x0005d860.cpp (stub Obj_5d860), size 0x14 (0x18)
struct Obj_5d860 {
    void* vptr; // +0x00
    char pad[12]; // +0x04 (+0x08)
    unsigned int m; // +0x10 (+0x14)
    unsigned char FUN_0005d860(unsigned int x);
};
// matches/0x0005d870.cpp (stub Obj_5d870), size 0x18
struct Obj_5d870 {
    char FUN_0005d870(float a);
    char pad[0x14]; // +0x00
    float mAngle; // +0x14
};
// matches/0x0005d8b0.cpp (stub Obj_5d8b0), size 0x25
struct Obj_5d8b0 {
    char pad[0x24]; // +0x00
    char m24; // +0x24
    unsigned char FUN_0005d8b0(unsigned char x);
};
// matches/0x0005d8c0.cpp (stub Obj_5d8c0), size 0x28
struct Obj_5d8c0 {
    char pad[0x28]; // +0x00
    bool FUN_0005d8c0(int value);
};
// matches/0x0005d8e0.cpp (stub Obj_5d8e0), size 0x34
struct Obj_5d8e0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    char FUN_0005d8e0(int v);
};
// matches/0x0005d8f0.cpp (stub Obj_5d8f0), size 0x10
struct Obj_5d8f0 {
    char FUN_0005d8f0(int a);
    char mPad[0x0c]; // +0x00
    int mVal; // +0x0c
};
// matches/0x0005dad0.cpp (stub C_5dad0), size 0x1
struct C_5dad0 {
    char FUN_0005dad0(int x);
};
// matches/0x000601f0.cpp (stub Obj_601f0), size 0x140
struct Obj_601f0 {
    char pad[0x140]; // +0x00
    Obj_601f0* FUN_000601f0();
    void G();
};
// matches/0x00060210.cpp (stub A_60210), size 0x1
struct A_60210 {
    char FUN_00060210(int x);
};
// matches/0x00060220.cpp (stub Obj_60220), size 0x14
struct Obj_60220 {
    char FUN_00060220(int x);
    char mPad[0x10]; // +0x00
    int m10; // +0x10
};
// matches/0x00060230.cpp (stub Obj_60230), size 0x18
struct Obj_60230 {
    char pad[0x14]; // +0x00
    int m; // +0x14
    char FUN_00060230(int x);
};
// matches/0x00060240.cpp (stub Obj_60240), size 0x1c
struct Obj_60240 {
    char pad[0x18]; // +0x00
    int mVal; // +0x18
    char FUN_00060240(int v);
};
// matches/0x00060250.cpp (stub Obj_60250), size 0x30
struct Obj_60250 {
    char pad[0x30]; // +0x00
    void* FUN_00060250();
};
// matches/0x00060260.cpp (stub Obj_60260), size 0x38
struct Obj_60260 {
    char pad[0x38]; // +0x00
    char* FUN_00060260();
};
// matches/0x00060270.cpp (stub Obj_60270), size 0x40
struct Obj_60270 {
    char pad[0x40]; // +0x00
    char* FUN_00060270() throw();
};
// matches/0x00060280.cpp (stub T_60280), size 0x48
struct T_60280 {
    char pad[0x48]; // +0x00
    void* FUN_00060280();
};
// matches/0x00060290.cpp (stub Obj_60290), size 0x54
struct Obj_60290 {
    char pad[0x50]; // +0x00
    int value; // +0x50
    int* FUN_00060290();
};
// matches/0x000602b0.cpp (stub Obj_602b0), size 0x6c
struct Obj_602b0 {
    char pad[0x60]; // +0x00
    int a; // +0x60
    int b; // +0x64
    int c; // +0x68
    bool FUN_000602b0(const void* src);
};
// matches/0x000602f0.cpp (stub Obj_602f0), size 0x84
struct Obj_602f0 {
    char pad[0x78]; // +0x00
    int a; // +0x78
    int b; // +0x7c
    int c; // +0x80
    bool FUN_000602f0(int* x);
};
// matches/0x00060340.cpp (stub Obj), size 0x9c
struct Obj_60340 {
    char pad[0x90]; // +0x00
    int a, b, c; // +0x90
    char FUN_00060340(void* p);
};
// matches/0x000603d0.cpp (stub X_603d0), size 0xc0
struct X_603d0 {
    char pad[0xbc]; // +0x00
    int m; // +0xbc
    bool FUN_000603d0(int);
};
// matches/0x000603e0.cpp (stub X_603e0), size 0xc4
struct X_603e0 {
    char FUN_000603e0(int v);
    char mPad[0xc0]; // +0x00
    int mVal; // +0xc0
};
// matches/0x000603f0.cpp (stub T_603f0), size 0xc8
struct T_603f0 {
    char pad[0xc4]; // +0x00
    int m; // +0xc4
    bool FUN_000603f0(int x);
};
// matches/0x00060400.cpp (stub Obj_60400), size 0xc8
struct Obj_60400 {
    char pad[0xc8]; // +0x00
    bool FUN_00060400(char c);
};
// matches/0x00060410.cpp (stub Obj_60410), size 0xca
struct Obj_60410 {
    char pad[0xc9]; // +0x00
    unsigned char value; // +0xc9
    bool FUN_00060410(unsigned char v);
};
// matches/0x00060420.cpp (stub Obj_60420), size 0xd0
struct Obj_60420 {
    char pad[0xcc]; // +0x00
    int mValue; // +0xcc
    bool FUN_00060420(int v);
};
// matches/0x00060430.cpp (stub Obj_60430), size 0x10
struct Obj_60430 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_00060430(int v);
};
// matches/0x00060440.cpp (stub Obj_60440), size 0x14
struct Obj_60440 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_00060440(int x);
};
// matches/0x00060470.cpp (stub Obj_60470), size 0x24
struct Obj_60470 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_00060470(int v);
};
// matches/0x00060480.cpp (stub Obj_60480), size 0x28
struct Obj_60480 {
    char pad[0x24]; // +0x00
    int field; // +0x24
    bool FUN_00060480(int x);
};
// matches/0x00060490.cpp (stub Obj_60490), size 0x51
struct Obj_60490 {
    char pad[0x50]; // +0x00
    char m50; // +0x50
    char FUN_00060490(char c);
};
// matches/0x000604a0.cpp (stub Obj_604a0), size 0x52
struct Obj_604a0 {
    char Pad[0x51]; // +0x00
    unsigned char Value; // +0x51
    unsigned char FUN_000604a0(unsigned char x);
};
// matches/0x000604b0.cpp (stub T_604b0), size 0x58
struct T_604b0 {
    char pad[0x54]; // +0x00
    int m54; // +0x54
    bool FUN_000604b0(int v);
};
// matches/0x000604c0.cpp (stub Obj_604c0), size 0x5c
struct Obj_604c0 {
    char pad[0x58]; // +0x00
    int m58; // +0x58
    bool FUN_000604c0(int v);
};
// matches/0x00060b10.cpp (stub Obj), size 0x2c
struct Obj_60b10 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    char FUN_00060b10(int n);
};
// matches/0x00061b40.cpp (stub X_61b40), size 0x10
struct X_61b40 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    char FUN_00061b40(int a);
};
// matches/0x00061b50.cpp (stub C_61b50), size 0x14
struct C_61b50 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_00061b50(int a);
};
// matches/0x00061b60.cpp (stub Obj_61b60), size 0x18
struct Obj_61b60 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    bool FUN_00061b60(int x);
};
// matches/0x00061b70.cpp (stub Obj_61b70), size 0x1c
struct Obj_61b70 {
    char pad[0x18]; // +0x00
    unsigned int mValue; // +0x18
    bool FUN_00061b70(unsigned int x);
};
// matches/0x00061b80.cpp (stub X_61b80), size 0x20
struct X_61b80 {
    char FUN_00061b80(int a);
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
};
// matches/0x00061b90.cpp (stub Obj_61b90), size 0x24
struct Obj_61b90 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    char FUN_00061b90(int x);
};
// matches/0x00061ba0.cpp (stub Obj_61ba0), size 0x25
struct Obj_61ba0 {
    char pad[0x24]; // +0x00
    char mFlag; // +0x24
    char FUN_00061ba0(char v);
};
// matches/0x00061bb0.cpp (stub X_61bb0), size 0x2c
struct X_61bb0 {
    char pad[0x28]; // +0x00
    int m; // +0x28
    char FUN_00061bb0(int);
};
// matches/0x00061bc0.cpp (stub C_61bc0), size 0x94
struct C_61bc0 {
    char pad[0x90]; // +0x00
    int m90; // +0x90
    bool FUN_00061bc0(int x);
};
// matches/0x00061bd0.cpp (stub Obj_61bd0), size 0x98
struct Obj_61bd0 {
    char pad[0x94]; // +0x00
    int value; // +0x94
    bool FUN_00061bd0(int x);
};
// matches/0x00061c40.cpp (stub T_61c40), size 0xb4
struct T_61c40 {
    char pad[0xb0]; // +0x00
    int value; // +0xb0
    bool FUN_00061c40(int v);
};
// matches/0x00061c50.cpp (stub Obj_61c50), size 0xb8
struct Obj_61c50 {
    char Pad[0xb4]; // +0x00
    int Value; // +0xb4
    char FUN_00061c50(int v);
};
// matches/0x00061c90.cpp (stub Obj_61c90), size 0xc8
struct Obj_61c90 {
    char pad[0xc4]; // +0x00
    int m1c4; // +0xc4
    bool FUN_00061c90(int x);
};
// matches/0x00061ca0.cpp (stub X_61ca0), size 0xcc
struct X_61ca0 {
    char FUN_00061ca0(int v);
    char pad[0xc8]; // +0x00
    int value; // +0xc8
};
// matches/0x00061cb0.cpp (stub Obj_61cb0), size 0x10 (0x18)
struct Obj_61cb0 {
    char pad[0xc]; // +0x00
    void* mPtr; // +0x0c (+0x10)
    bool FUN_00061cb0(void* p);
};
// matches/0x00061cc0.cpp (stub Obj_61cc0), size 0x14
struct Obj_61cc0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_00061cc0(int v);
};
// matches/0x00061cd0.cpp (stub C_61cd0), size 0x18
struct C_61cd0 {
    char pad[0x14]; // +0x00
    int m; // +0x14
    char FUN_00061cd0(int x);
};
// matches/0x00061ce0.cpp (stub Obj_61ce0), size 0x29
struct Obj_61ce0 {
    char pad[0x28]; // +0x00
    char m28; // +0x28
    char FUN_00061ce0(char v);
};
// matches/0x00061d10.cpp (stub Obj_61d10), size 0x49
struct Obj_61d10 {
    char pad[0x48]; // +0x00
    char flag; // +0x48
    bool FUN_00061d10(char v);
};
// matches/0x00061d20.cpp (stub C_61d20), size 0x48
struct C_61d20 {
    char pad[0x44]; // +0x00
    int m44; // +0x44
    bool FUN_00061d20(int v);
};
// matches/0x00061d50.cpp (stub Obj_61d50), size 0x10
struct Obj_61d50 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_00061d50(int value);
};
// matches/0x00061d60.cpp (stub Obj_61d60), size 0x14
struct Obj_61d60 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    bool FUN_00061d60(int v);
};
// matches/0x00061d70.cpp (stub C_61d70), size 0x18
struct C_61d70 {
    char pad[0x14]; // +0x00
    volatile int m; // +0x14
    bool FUN_00061d70(int x);
};
// matches/0x00061d80.cpp (stub Obj_61d80), size 0x29
struct Obj_61d80 {
    char pad[0x28]; // +0x00
    char mFlag; // +0x28
    unsigned char FUN_00061d80(unsigned char b);
};
// matches/0x00061db0.cpp (stub X_61db0), size 0x48
struct X_61db0 {
    char pad[0x44]; // +0x00
    int m; // +0x44
    char FUN_00061db0(int arg);
};
// matches/0x00061dc0.cpp (stub O_61dc0), size 0x10
struct O_61dc0 {
    char pad[12]; // +0x00
    int mC; // +0x0c
    char FUN_00061dc0(int a);
};
// matches/0x00061dd0.cpp (stub T_61dd0), size 0xa9
struct T_61dd0 {
    char Pad[0xa8]; // +0x00
    char Value; // +0xa8
    char FUN_00061dd0(char x);
};
// matches/0x00061e10.cpp (stub Obj_61e10), size 0xc8
struct Obj_61e10 {
    char pad[0xc4]; // +0x00
    int m; // +0xc4
    bool FUN_00061e10(int x);
};
// matches/0x00061e20.cpp (stub Obj_61e20), size 0x94
struct Obj_61e20 {
    char pad[0x90]; // +0x00
    int value; // +0x90
    bool FUN_00061e20(int x);
};
// matches/0x00061e30.cpp (stub O_61e30), size 0x10
struct O_61e30 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    char FUN_00061e30(int x);
};
// matches/0x00061e40.cpp (stub O_61e40), size 0x14
struct O_61e40 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    bool FUN_00061e40(int v);
};
// matches/0x00061e50.cpp (stub Obj_61e50), size 0x10
struct Obj_61e50 {
    char Pad[0xc]; // +0x00
    int mValue; // +0x0c
    char FUN_00061e50(int v);
};
// matches/0x00061e60.cpp (stub Obj_61e60), size 0x10
struct Obj_61e60 {
    char FUN_00061e60(int value);
    char pad[12]; // +0x00
    int mField; // +0x0c
};
// matches/0x00061e70.cpp (stub C_61e70), size 0x44
struct C_61e70 {
    char pad[0x40]; // +0x00
    int m; // +0x40
    bool FUN_00061e70(int x);
};
// matches/0x00061ec0.cpp (stub Obj), size 0x2c
struct Obj_61ec0 {
    char pad[0x28]; // +0x00
    float angle; // +0x28
    char FUN_00061ec0(float x);
};
// matches/0x00061ee0.cpp (stub Obj_61ee0), size 0x2c
struct Obj_61ee0 {
    char pad[0x2c]; // +0x00
    bool FUN_00061ee0(int value);
};
// matches/0x00061ef0.cpp (stub O_61ef0), size 0x34
struct O_61ef0 {
    char pad[0x30]; // +0x00
    int value; // +0x30
    char FUN_00061ef0(int x);
};
// matches/0x00061f00.cpp (stub Obj_61f00), size 0x38
struct Obj_61f00 {
    char pad[0x34]; // +0x00
    int m34; // +0x34
    char FUN_00061f00(int x);
};
// matches/0x00061f10.cpp (stub Obj_61f10), size 0x3c (0x40)
struct Obj_61f10 {
    char pad[0x38]; // +0x00
    void* m38; // +0x38
    bool FUN_00061f10(void* v);
};
// matches/0x00061f20.cpp (stub O_61f20), size 0x3d
struct O_61f20 {
    char pad[0x3c]; // +0x00
    char m3c; // +0x3c
    unsigned char FUN_00061f20(unsigned char c);
};
// matches/0x00061f30.cpp (stub O_61f30), size 0x10
struct O_61f30 {
    char pad[12]; // +0x00
    volatile int m; // +0x0c
    char FUN_00061f30(int x);
};
// matches/0x00061f40.cpp (stub Obj), size 0x14
struct Obj_61f40 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_00061f40(int v);
};
// matches/0x00061f50.cpp (stub Obj_61f50), size 0x10
struct Obj_61f50 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    bool FUN_00061f50(int x);
};
// matches/0x00061f60.cpp (stub A_61f60), size 0x14
struct A_61f60 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    bool FUN_00061f60(int v);
};
// matches/0x00061fb0.cpp (stub Obj_61fb0), size 0x10
struct Obj_61fb0 {
    bool FUN_00061fb0(int v);
    char pad[0x0c]; // +0x00
    int mVal; // +0x0c
};
// matches/0x00061fc0.cpp (stub Obj_61fc0), size 0x10
struct Obj_61fc0 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_00061fc0(int x);
};
// matches/0x00061fd0.cpp (stub Obj_61fd0), size 0x14
struct Obj_61fd0 {
    char pad[0x10]; // +0x00
    int field; // +0x10
    char FUN_00061fd0(int value);
};
// matches/0x00062180.cpp (stub Obj_62180), size 0x50
struct Obj_62180 {
    char pad[0x50]; // +0x00
    char FUN_00062180(const char* v);
};
// matches/0x000626c0.cpp (stub X_626c0), size 0x90
struct X_626c0 {
    char FUN_000626c0(const char* s);
    char pad[0x10]; // +0x00
    char buf[0x80]; // +0x10
};
// matches/0x00065aa0.cpp (stub Target_65aa0), size 0x36d
struct Target_65aa0 {
    char pad[0x36c]; // +0x00
    unsigned char field; // +0x36c
    void FUN_00065aa0();
};
// matches/0x00065ab0.cpp (stub C_65ab0), size 0x36d
struct C_65ab0 {
    char pad[0x36c]; // +0x00
    unsigned char value; // +0x36c
    unsigned char FUN_00065ab0();
};
// matches/0x00065f60.cpp (stub C_65f60), size 0x394
struct C_65f60 {
    char pad[0x390]; // +0x00
    unsigned int value; // +0x390
    unsigned int FUN_00065f60();
};
// matches/0x00066280.cpp (stub Obj), size 0x8
struct Obj_66280 {
    int cached; // +0x00
    int enabled; // +0x04
    float FUN_00066280();
};
// matches/0x000670e0.cpp (stub C_670e0), size 0x2f4
struct C_670e0 {
    char pad[0x2f4]; // +0x00
    float FUN_000670e0(hulk_uintptr);
};
// matches/0x00067a20.cpp (stub C_67a20), size 0x920
struct C_67a20 {
    char pad[0x920]; // +0x00
    void FUN_00067a20();
};
// matches/0x00067ad0.cpp (stub C_67ad0), size 0x408
struct C_67ad0 {
    char pad[8]; // +0x00
    unsigned int slots[256]; // +0x08
    void* FUN_00067ad0(unsigned int x);
};
// matches/0x00067f30.cpp (stub Obj_67f30), size 0xc
struct Obj_67f30 {
    char pad[12]; // +0x00
    bool FUN_00067f30(void* p);
};
// matches/0x00067f40.cpp (stub Obj_67f40), size 0x14
struct Obj_67f40 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_00067f40(int x);
};
// matches/0x00067f50.cpp (stub X_67f50), size 0x21
struct X_67f50 {
    char pad[0x20]; // +0x00
    char m20; // +0x20
    char FUN_00067f50(char v);
};
// matches/0x00067f80.cpp (stub Obj_67f80), size 0x31
struct Obj_67f80 {
    char pad[0x30]; // +0x00
    unsigned char m; // +0x30
    unsigned char FUN_00067f80(unsigned char v);
};
// matches/0x00067fa0.cpp (stub Obj_67fa0), size 0x44
struct Obj_67fa0 {
    char m[0x44]; // +0x00
    char FUN_00067fa0(int a);
};
// matches/0x00067fb0.cpp (stub Obj_67fb0), size 0x4c
struct Obj_67fb0 {
    char FUN_00067fb0(int v);
    char mPad[0x48]; // +0x00
    int mVal; // +0x48
};
// matches/0x00067fc0.cpp (stub O_67fc0), size 0x10
struct O_67fc0 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    bool FUN_00067fc0(int x);
};
// matches/0x00067fd0.cpp (stub Obj_67fd0), size 0x14
struct Obj_67fd0 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    char FUN_00067fd0(int x);
};
// matches/0x00067fe0.cpp (stub Obj_67fe0), size 0x10
struct Obj_67fe0 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    bool FUN_00067fe0(int x);
};
// matches/0x00067ff0.cpp (stub Obj_67ff0), size 0x14
struct Obj_67ff0 {
    char Pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_00067ff0(int v);
};
// matches/0x00068000.cpp (stub Obj), size 0x18 (0x20)
struct Obj_68000 {
    char pad[0x14]; // +0x00
    void* value; // +0x14 (+0x18)
    char FUN_00068000(void* p);
};
// matches/0x00068010.cpp (stub Obj_68010), size 0x1c
struct Obj_68010 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    char FUN_00068010(int v);
};
// matches/0x00068020.cpp (stub Obj_68020), size 0x20
struct Obj_68020 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    bool FUN_00068020(int x);
};
// matches/0x00068030.cpp (stub A_68030), size 0x24
struct A_68030 {
    char pad[32]; // +0x00
    int m20; // +0x20
    bool FUN_00068030(int x);
};
// matches/0x00068040.cpp (stub X_68040), size 0x28
struct X_68040 {
    char pad[0x24]; // +0x00
    int mField; // +0x24
    char FUN_00068040(int x);
};
// matches/0x00068050.cpp (stub Obj_68050), size 0x2c
struct Obj_68050 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    unsigned char FUN_00068050(int a);
};
// matches/0x00068060.cpp (stub A_68060), size 0x30
struct A_68060 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    bool FUN_00068060(int x);
};
// matches/0x00068070.cpp (stub Obj_68070), size 0x38
struct Obj_68070 {
    char pad[0x34]; // +0x00
    int mField; // +0x34
    bool FUN_00068070(int value);
};
// matches/0x00068080.cpp (stub Obj_68080), size 0x40
struct Obj_68080 {
    char pad[0x3c]; // +0x00
    int value; // +0x3c
    bool FUN_00068080(int x);
};
// matches/0x00068090.cpp (stub Obj_68090), size 0x44
struct Obj_68090 {
    char pad[0x40]; // +0x00
    int value; // +0x40
    bool FUN_00068090(int x);
};
// matches/0x000680a0.cpp (stub Obj_680a0), size 0x4c
struct Obj_680a0 {
    char pad[0x48]; // +0x00
    int mValue; // +0x48
    char FUN_000680a0(int v);
};
// matches/0x000680b0.cpp (stub X_680b0), size 0x50
struct X_680b0 {
    char pad[0x4c]; // +0x00
    int m; // +0x4c
    bool FUN_000680b0(int v);
};
// matches/0x000680c0.cpp (stub Target_680c0), size 0x51
struct Target_680c0 {
    char data[0x51]; // +0x00
    char FUN_000680c0(char v);
};
// matches/0x000680d0.cpp (stub Obj_680d0), size 0x52
struct Obj_680d0 {
    char FUN_000680d0(char v);
    char pad[0x51]; // +0x00
    char value; // +0x51
};
// matches/0x000680e0.cpp (stub Obj_680e0), size 0x34
struct Obj_680e0 {
    char pad[0x30]; // +0x00
    float value; // +0x30
    char FUN_000680e0(float x);
};
// matches/0x00068100.cpp (stub Obj), size 0x3c
struct Obj_68100 {
    char pad[0x38]; // +0x00
    float angle; // +0x38
    bool FUN_00068100(float x);
};
// matches/0x00068120.cpp (stub O_68120), size 0x14
struct O_68120 {
    char p[12]; // +0x00
    int mF12; // +0x0c
    char y[4]; // +0x10
    bool FUN_00068120(int);
};
// matches/0x00068130.cpp (stub Obj_68130), size 0x14
struct Obj_68130 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_00068130(int x);
};
// matches/0x00068140.cpp (stub C_68140), size 0x18
struct C_68140 {
    char Pad[20]; // +0x00
    float f; // +0x14
    char FUN_00068140(float x);
};
// matches/0x00068160.cpp (stub Obj_68160), size 0x1c
struct Obj_68160 {
    char pad[0x18]; // +0x00
    float angle; // +0x18
    char FUN_00068160(float deg);
};
// matches/0x00068180.cpp (stub Obj_68180), size 0x20
struct Obj_68180 {
    char pad[0x1c]; // +0x00
    float value; // +0x1c
    bool FUN_00068180(float x);
};
// matches/0x000681a0.cpp (stub Obj_681a0), size 0x21
struct Obj_681a0 {
    char pad[0x20]; // +0x00
    unsigned char m; // +0x20
    unsigned char FUN_000681a0(unsigned char value);
};
// matches/0x000681b0.cpp (stub Target_681b0), size 0x28
struct Target_681b0 {
    char Pad[0x24]; // +0x00
    int m24; // +0x24
    char FUN_000681b0(int arg);
};
// matches/0x000681c0.cpp (stub Obj_681c0), size 0x2c
struct Obj_681c0 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    char FUN_000681c0(int v);
};
// matches/0x000681d0.cpp (stub Obj_681d0), size 0x30 (0x38)
struct Obj_681d0 {
    char pad[0x2c]; // +0x00
    void* m2c; // +0x2c (+0x30)
    bool FUN_000681d0(void* p);
};
// matches/0x000681e0.cpp (stub Obj_681e0), size 0x34
struct Obj_681e0 {
    bool FUN_000681e0(int value);
    char pad[0x30]; // +0x00
    int mValue; // +0x30
};
// matches/0x000681f0.cpp (stub Obj_681f0), size 0x38
struct Obj_681f0 {
    char pad[0x34]; // +0x00
    int m34; // +0x34
    bool FUN_000681f0(int v);
};
// matches/0x00068200.cpp (stub Obj_68200), size 0x3c
struct Obj_68200 {
    char pad[0x38]; // +0x00
    int m; // +0x38
    bool FUN_00068200(int v);
};
// matches/0x00068210.cpp (stub O_68210), size 0x59
struct O_68210 {
    char pad[0x58]; // +0x00
    unsigned char m58; // +0x58
    char FUN_00068210(unsigned char x);
};
// matches/0x00068220.cpp (stub Obj_68220), size 0x6c
struct Obj_68220 {
    char pad[0x68]; // +0x00
    int field; // +0x68
    char FUN_00068220(int value);
};
// matches/0x00068230.cpp (stub Obj_68230), size 0x70
struct Obj_68230 {
    char pad[0x6c]; // +0x00
    int value; // +0x6c
    bool FUN_00068230(int x);
};
// matches/0x00068240.cpp (stub Obj_68240), size 0x74
struct Obj_68240 {
    char pad[0x70]; // +0x00
    int value; // +0x70
    bool FUN_00068240(int x);
};
// matches/0x00068280.cpp (stub Obj_68280), size 0x10
struct Obj_68280 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    bool FUN_00068280(int arg);
};
// matches/0x00068290.cpp (stub Obj_68290), size 0x14
struct Obj_68290 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_00068290(int v);
};
// matches/0x000682a0.cpp (stub Obj_682a0), size 0x18
struct Obj_682a0 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    char FUN_000682a0(int value);
};
// matches/0x000682b0.cpp (stub X_682b0), size 0x20
struct X_682b0 {
    char pad[0x1c]; // +0x00
    int mVal; // +0x1c
    bool FUN_000682b0(int v);
};
// matches/0x000682c0.cpp (stub X_682c0), size 0x24
struct X_682c0 {
    char pad[0x20]; // +0x00
    int mValue; // +0x20
    bool FUN_000682c0(int v);
};
// matches/0x000682d0.cpp (stub Obj_682d0), size 0x28
struct Obj_682d0 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    bool FUN_000682d0(int x);
};
// matches/0x00068340.cpp (stub Obj_68340), size 0x10
struct Obj_68340 {
    char FUN_00068340(int v);
    char mPad[12]; // +0x00
    int mVal; // +0x0c
};
// matches/0x00068350.cpp (stub Obj_68350), size 0x14
struct Obj_68350 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_00068350(int value);
};
// matches/0x00068360.cpp (stub Thing_68360), size 0x18
struct Thing_68360 {
    char pad[0x14]; // +0x00
    float angle; // +0x14
    bool FUN_00068360(float v);
};
// matches/0x00068380.cpp (stub Obj_68380), size 0x1c
struct Obj_68380 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    bool FUN_00068380(int v);
};
// matches/0x00068390.cpp (stub Obj_68390), size 0x20
struct Obj_68390 {
    char pad[0x1c]; // +0x00
    int mValue; // +0x1c
    char FUN_00068390(int x);
};
// matches/0x000683a0.cpp (stub Obj_683a0), size 0x24
struct Obj_683a0 {
    char pad[0x20]; // +0x00
    int m; // +0x20
    char FUN_000683a0(int value) throw();
};
// matches/0x000685b0.cpp (stub X_685b0), size 0x10
struct X_685b0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_000685b0(int value);
};
// matches/0x000685c0.cpp (stub Obj_685c0), size 0x14
struct Obj_685c0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_000685c0(int v);
};
// matches/0x000685d0.cpp (stub Obj_685d0), size 0x10
struct Obj_685d0 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    bool FUN_000685d0(int v);
};
// matches/0x000685e0.cpp (stub Obj_685e0), size 0x14
struct Obj_685e0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_000685e0(int value);
};
// matches/0x00068630.cpp (stub Obj_68630), size 0x10
struct Obj_68630 {
    char pad[0xc]; // +0x00
    int mField; // +0x0c
    char FUN_00068630(int value);
};
// matches/0x00068640.cpp (stub Obj_68640), size 0x14
struct Obj_68640 {
    char Pad[0x10]; // +0x00
    int Value; // +0x10
    char FUN_00068640(int v);
};
// matches/0x00068670.cpp (stub Obj_68670), size 0x64 (0x68)
struct Obj_68670 {
    char FUN_00068670(void* p);
    char pad[0x60]; // +0x00
    void* mValue; // +0x60
};
// matches/0x00068680.cpp (stub C_68680), size 0x1
struct C_68680 {
    char FUN_00068680(int a);
};
// matches/0x00068690.cpp (stub Obj_68690), size 0x6c
struct Obj_68690 {
    char pad[0x68]; // +0x00
    int value; // +0x68
    char FUN_00068690(int x);
};
// matches/0x000686a0.cpp (stub Obj_686a0), size 0x70
struct Obj_686a0 {
    char pad[0x6c]; // +0x00
    int field; // +0x6c
    bool FUN_000686a0(int v);
};
// matches/0x000686b0.cpp (stub Obj_686b0), size 0x74
struct Obj_686b0 {
    char pad[0x70]; // +0x00
    int field; // +0x70
    bool FUN_000686b0(int x);
};
// matches/0x000686c0.cpp (stub Obj_686c0), size 0x78
struct Obj_686c0 {
    char pad[0x74]; // +0x00
    int field; // +0x74
    bool FUN_000686c0(int x);
};
// matches/0x000686d0.cpp (stub Obj_686d0), size 0x78
struct Obj_686d0 {
    char FUN_000686d0(int x);
    char pad[0x78]; // +0x00
};
// matches/0x000686e0.cpp (stub Obj_686e0), size 0x80
struct Obj_686e0 {
    char pad[0x7c]; // +0x00
    int m7c; // +0x7c
    bool FUN_000686e0(int arg);
};
// matches/0x000686f0.cpp (stub A_686f0), size 0x84
struct A_686f0 {
    char pad[0x80]; // +0x00
    int m80; // +0x80
    bool FUN_000686f0(int x);
};
// matches/0x00068700.cpp (stub O_68700), size 0x85
struct O_68700 {
    char pad[0x84]; // +0x00
    char mFlag; // +0x84
    bool FUN_00068700(char value);
};
// matches/0x00068710.cpp (stub Target_68710), size 0x8c
struct Target_68710 {
    char pad[0x88]; // +0x00
    int value; // +0x88
    bool FUN_00068710(int x);
};
// matches/0x00068720.cpp (stub Obj_68720), size 0x90
struct Obj_68720 {
    char pad[0x8c]; // +0x00
    int value; // +0x8c
    char FUN_00068720(int v);
};
// matches/0x00068730.cpp (stub Obj_68730), size 0x94
struct Obj_68730 {
    char pad[0x90]; // +0x00
    int field; // +0x90
    bool FUN_00068730(int value);
};
// matches/0x00068740.cpp (stub Obj_68740), size 0x98
struct Obj_68740 {
    char pad[0x94]; // +0x00
    int m; // +0x94
    bool FUN_00068740(int x);
};
// matches/0x00068750.cpp (stub Obj_68750), size 0x9c
struct Obj_68750 {
    char pad[0x98]; // +0x00
    int m98; // +0x98
    bool FUN_00068750(int v);
};
// matches/0x00068760.cpp (stub Target_68760), size 0xa0
struct Target_68760 {
    char pad[0x9c]; // +0x00
    int value; // +0x9c
    bool FUN_00068760(int v);
};
// matches/0x000687a0.cpp (stub A_687a0), size 0x10
struct A_687a0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_000687a0(int v);
};
// matches/0x000687b0.cpp (stub A_687b0), size 0x14
struct A_687b0 {
    char Pad[0x10]; // +0x00
    int Value; // +0x10
    bool FUN_000687b0(int x);
};
// matches/0x000687e0.cpp (stub Sub_687e0), size 0x24
struct Sub_687e0 {
    char pad[0x20]; // +0x00
    float mAngle; // +0x20
    unsigned char FUN_000687e0(float v);
};
// matches/0x00068800.cpp (stub Obj_68800), size 0x28
struct Obj_68800 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    unsigned char FUN_00068800(int x);
};
// matches/0x00068810.cpp (stub Obj_68810), size 0x2c
struct Obj_68810 {
    char pad[0x28]; // +0x00
    int mValue; // +0x28
    bool FUN_00068810(int v);
};
// matches/0x00068820.cpp (stub C_68820), size 0x1
struct C_68820 {
    bool FUN_00068820(int x);
};
// matches/0x00068830.cpp (stub Obj_68830), size 0x34
struct Obj_68830 {
    char Pad[0x30]; // +0x00
    int Value; // +0x30
    char FUN_00068830(int v);
};
// matches/0x00068840.cpp (stub Obj_68840), size 0x38
struct Obj_68840 {
    char pad[0x34]; // +0x00
    int m34; // +0x34
    bool FUN_00068840(int v);
};
// matches/0x00068850.cpp (stub Obj_68850), size 0x10
struct Obj_68850 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_00068850(int value);
};
// matches/0x00068860.cpp (stub Obj_68860), size 0x14
struct Obj_68860 {
    char pad[0x10]; // +0x00
    unsigned int m10; // +0x10
    unsigned char FUN_00068860(unsigned int v);
};
// matches/0x00068870.cpp (stub Obj), size 0x18
struct Obj_68870 {
    char pad[0x14]; // +0x00
    float angle; // +0x14
    bool FUN_00068870(float degrees);
};
// matches/0x00068890.cpp (stub Obj), size 0x1c
struct Obj_68890 {
    char pad[24]; // +0x00
    float angle; // +0x18
    char FUN_00068890(float x);
};
// matches/0x000688b0.cpp (stub Obj_688b0), size 0x1d
struct Obj_688b0 {
    char pad[0x1c]; // +0x00
    char mVal; // +0x1c
    unsigned char FUN_000688b0(char x);
};
// matches/0x000688c0.cpp (stub X_688c0), size 0x24
struct X_688c0 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_000688c0(int v);
};
// matches/0x000688d0.cpp (stub C_688d0), size 0x28
struct C_688d0 {
    bool FUN_000688d0(int value);
    char pad[0x24]; // +0x00
    int m24; // +0x24
};
// matches/0x000688e0.cpp (stub Target_688e0), size 0x2c
struct Target_688e0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    char FUN_000688e0(int value);
};
// matches/0x00068990.cpp (stub Obj_68990), size 0x10
struct Obj_68990 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    char FUN_00068990(int v);
};
// matches/0x000689a0.cpp (stub X_689a0), size 0x10
struct X_689a0 {
    char pad[0x10]; // +0x00
    char FUN_000689a0(int v);
};
// matches/0x000689b0.cpp (stub X_689b0), size 0x10
struct X_689b0 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    bool FUN_000689b0(int v);
};
// matches/0x000689c0.cpp (stub Obj_689c0), size 0x14
struct Obj_689c0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_000689c0(int value);
};
// matches/0x000689d0.cpp (stub Obj_689d0), size 0x10
struct Obj_689d0 {
    char pad[0xc]; // +0x00
    int m1c; // +0x0c
    bool FUN_000689d0(int v);
};
// matches/0x000689e0.cpp (stub Obj_689e0), size 0x14
struct Obj_689e0 {
    char FUN_000689e0(int x);
    char pad[0x10]; // +0x00
    int m10; // +0x10
};
// matches/0x00068a50.cpp (stub Obj_68a50), size 0x40
struct Obj_68a50 {
    char Pad[0x3c]; // +0x00
    float Value; // +0x3c
    char FUN_00068a50(float a);
};
// matches/0x00068a70.cpp (stub C_68a70), size 0x1
struct C_68a70 {
    char FUN_00068a70(float x);
};
// matches/0x00068a90.cpp (stub Obj_68a90), size 0x48
struct Obj_68a90 {
    char pad[0x44]; // +0x00
    float value; // +0x44
    char FUN_00068a90(float angle);
};
// matches/0x00068ab0.cpp (stub T_68ab0), size 0x4c
struct T_68ab0 {
    char FUN_00068ab0(float x);
    char pad[0x48]; // +0x00
    float m48; // +0x48
};
// matches/0x00068ad0.cpp (stub O_68ad0), size 0x54
struct O_68ad0 {
    char pad[0x50]; // +0x00
    int m50; // +0x50
    bool FUN_00068ad0(int v);
};
// matches/0x00068ae0.cpp (stub Obj_68ae0), size 0x58
struct Obj_68ae0 {
    char pad[0x54]; // +0x00
    int mValue; // +0x54
    char FUN_00068ae0(int value);
};
// matches/0x00068af0.cpp (stub Obj_68af0), size 0x5c
struct Obj_68af0 {
    char pad[0x58]; // +0x00
    int value; // +0x58
    bool FUN_00068af0(int x);
};
// matches/0x00068b00.cpp (stub Obj_68b00), size 0x60
struct Obj_68b00 {
    char pad[0x5c]; // +0x00
    int m5c; // +0x5c
    bool FUN_00068b00(int v);
};
// matches/0x00068b10.cpp (stub Obj_68b10), size 0x10
struct Obj_68b10 {
    char pad[12]; // +0x00
    int value; // +0x0c
    char FUN_00068b10(int v);
};
// matches/0x00068b20.cpp (stub Obj_68b20), size 0x18 (0x20)
struct Obj_68b20 {
    char pad[0x10]; // +0x00
    void* mValue; // +0x10
    char mFlag; // +0x14 (+0x18)
    char FUN_00068b20(void* p);
};
// matches/0x00068b30.cpp (stub Obj_68b30), size 0x10
struct Obj_68b30 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_00068b30(int x);
};
// matches/0x00068b70.cpp (stub Obj_68b70), size 0x10
struct Obj_68b70 {
    char pad[12]; // +0x00
    int m; // +0x0c
    char FUN_00068b70(int arg);
};
// matches/0x00068b80.cpp (stub Obj_68b80), size 0x14
struct Obj_68b80 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_00068b80(int v);
};
// matches/0x00068bc0.cpp (stub X_68bc0), size 0x14
struct X_68bc0 {
    bool FUN_00068bc0(int a);
    char mPad[12]; // +0x00
    int mValue; // +0x0c
    bool mFlag; // +0x10
};
// matches/0x00068bd0.cpp (stub A_68bd0), size 0x14
struct A_68bd0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_00068bd0(int x);
};
// matches/0x00068be0.cpp (stub C_68be0), size 0x18
struct C_68be0 {
    char FUN_00068be0(int x);
    char pad[0x14]; // +0x00
    int m14; // +0x14
};
// matches/0x00068bf0.cpp (stub Obj_68bf0), size 0x1c
struct Obj_68bf0 {
    char pad[0x18]; // +0x00
    int field; // +0x18
    bool FUN_00068bf0(int v);
};
// matches/0x00068c00.cpp (stub Obj_68c00), size 0x20
struct Obj_68c00 {
    char pad[0x1c]; // +0x00
    int mValue; // +0x1c
    bool FUN_00068c00(int v);
};
// matches/0x00068c10.cpp (stub Obj_68c10), size 0x24
struct Obj_68c10 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_00068c10(int x);
};
// matches/0x00068c20.cpp (stub Obj_68c20), size 0x24
struct Obj_68c20 {
    char pad[0x24]; // +0x00
    char FUN_00068c20(int value);
};
// matches/0x00068c30.cpp (stub X_68c30), size 0x2c
struct X_68c30 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    char FUN_00068c30(int a);
};
// matches/0x00068c40.cpp (stub Obj_68c40), size 0x2c
struct Obj_68c40 {
    char pad[0x2c]; // +0x00
    unsigned char FUN_00068c40(int x);
};
// matches/0x00068c50.cpp (stub Obj_68c50), size 0xc
struct Obj_68c50 {
    char m[12]; // +0x00
    char FUN_00068c50(int v);
};
// matches/0x00068c60.cpp (stub Obj_68c60), size 0x14
struct Obj_68c60 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    unsigned char FUN_00068c60(int v);
};
// matches/0x000695e0.cpp (stub A_695e0), size 0x38
struct A_695e0 {
    char pad[0x18]; // +0x00
    float values[8]; // +0x18
    float FUN_000695e0(int i);
};
// matches/0x00069620.cpp (stub Thing_69620), size 0x38
struct Thing_69620 {
    char pad[0x38]; // +0x00
    float FUN_00069620(int i);
};
// matches/0x0006ad10.cpp (stub Thing_6ad10), size 0x50
struct Thing_6ad10 {
    char pad[0x4c]; // +0x00
    float value; // +0x4c
    bool FUN_0006ad10(float degrees);
};
// matches/0x0006b310.cpp (stub Obj_6b310), size 0x1c
struct Obj_6b310 {
    char Pad[0x18]; // +0x00
    int mVal; // +0x18
    char FUN_0006b310(int v);
};
// matches/0x0006b320.cpp (stub X_6b320), size 0x3c
struct X_6b320 {
    char pad[0x38]; // +0x00
    int mThing; // +0x38
    bool FUN_0006b320(int v);
};
// matches/0x0006b330.cpp (stub X_6b330), size 0x20
struct X_6b330 {
    char Pad[0x1c]; // +0x00
    int mValue; // +0x1c
    char FUN_0006b330(int v);
};
// matches/0x0006b340.cpp (stub Obj_6b340), size 0x40
struct Obj_6b340 {
    char pad[0x3c]; // +0x00
    int field; // +0x3c
    bool FUN_0006b340(int v);
};
// matches/0x0006b350.cpp (stub Obj_6b350), size 0x24
struct Obj_6b350 {
    char pad[0x20]; // +0x00
    int mValue; // +0x20
    bool FUN_0006b350(int x);
};
// matches/0x0006b360.cpp (stub Obj_6b360), size 0x44
struct Obj_6b360 {
    char pad[0x40]; // +0x00
    int value; // +0x40
    bool FUN_0006b360(int v);
};
// matches/0x0006b370.cpp (stub Obj_6b370), size 0x28
struct Obj_6b370 {
    char pad[0x24]; // +0x00
    int mVal; // +0x24
    bool FUN_0006b370(int v);
};
// matches/0x0006b380.cpp (stub Obj_6b380), size 0x48
struct Obj_6b380 {
    char pad[0x44]; // +0x00
    int field; // +0x44
    bool FUN_0006b380(int v);
};
// matches/0x0006b390.cpp (stub C_6b390), size 0x28
struct C_6b390 {
    char FUN_0006b390(int v);
    char pad[0x28]; // +0x00
};
// matches/0x0006b3a0.cpp (stub Obj_6b3a0), size 0x4c
struct Obj_6b3a0 {
    char pad[0x48]; // +0x00
    int mValue; // +0x48
    bool FUN_0006b3a0(int v);
};
// matches/0x0006b3b0.cpp (stub Obj_6b3b0), size 0x30
struct Obj_6b3b0 {
    char pad[0x2c]; // +0x00
    int field; // +0x2c
    bool FUN_0006b3b0(int v);
};
// matches/0x0006b3c0.cpp (stub Obj_6b3c0), size 0x50
struct Obj_6b3c0 {
    char pad[0x4c]; // +0x00
    int mValue; // +0x4c
    bool FUN_0006b3c0(int value);
};
// matches/0x0006b3d0.cpp (stub Obj_6b3d0), size 0x34
struct Obj_6b3d0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0006b3d0(int x);
};
// matches/0x0006b3e0.cpp (stub Obj_6b3e0), size 0x54
struct Obj_6b3e0 {
    char pad[0x50]; // +0x00
    int mVal; // +0x50
    bool FUN_0006b3e0(int v);
};
// matches/0x0006b3f0.cpp (stub A_6b3f0), size 0x34
struct A_6b3f0 {
    char pad[0x34]; // +0x00
    bool FUN_0006b3f0(int x);
};
// matches/0x0006b400.cpp (stub X_6b400), size 0x58
struct X_6b400 {
    char FUN_0006b400(int v);
    char pad[0x54]; // +0x00
    int m54; // +0x54
};
// matches/0x0006b6f0.cpp (stub C), size 0x1c
struct C_6b6f0 {
    char pad[0x18]; // +0x00
    float angle; // +0x18
    bool FUN_0006b6f0(float x);
};
// matches/0x00077df0.cpp (stub Obj_77df0), size 0x10
struct Obj_77df0 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    bool FUN_00077df0(int x);
};
// matches/0x00077e00.cpp (stub C_77e00), size 0x14
struct C_77e00 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_00077e00(int v);
};
// matches/0x00077e10.cpp (stub X_77e10), size 0x18
struct X_77e10 {
    char pad[0x14]; // +0x00
    int m; // +0x14
    char FUN_00077e10(int v);
};
// matches/0x00077e20.cpp (stub X_77e20), size 0x1c
struct X_77e20 {
    char FUN_00077e20(float v);
    char mPad[0x18]; // +0x00
    float mVal; // +0x18
};
// matches/0x00077e40.cpp (stub Obj), size 0x20
struct Obj_77e40 {
    char pad[0x1c]; // +0x00
    float angle; // +0x1c
    char FUN_00077e40(float x);
};
// matches/0x00077e60.cpp (stub X_77e60), size 0x24
struct X_77e60 {
    char pad[32]; // +0x00
    int m; // +0x20
    bool FUN_00077e60(int v);
};
// matches/0x00077e70.cpp (stub A_77e70), size 0x28
struct A_77e70 {
    char pad[0x24]; // +0x00
    int mField; // +0x24
    bool FUN_00077e70(int x);
};
// matches/0x00077e80.cpp (stub Target_77e80), size 0x2c
struct Target_77e80 {
    char pad[0x28]; // +0x00
    float mAngle; // +0x28
    char FUN_00077e80(float x);
};
// matches/0x00077ea0.cpp (stub Obj_77ea0), size 0x30
struct Obj_77ea0 {
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
    char FUN_00077ea0(int v);
};
// matches/0x00077eb0.cpp (stub X_77eb0), size 0x34
struct X_77eb0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_00077eb0(int v);
};
// matches/0x00077ec0.cpp (stub Obj_77ec0), size 0x38
struct Obj_77ec0 {
    char pad[0x34]; // +0x00
    int value; // +0x34
    bool FUN_00077ec0(int x);
};
// matches/0x00078750.cpp (stub Vec3_78750), size 0xc
struct Vec3_78750 {
    float x, y, z; // +0x00
    Vec3_78750* FUN_00078750(Vec3_78750* out, Vec3_78750* other);
};
// matches/0x00078850.cpp (stub X_78850), size 0x1
struct X_78850 {
    X_78850* FUN_00078850();
};
// matches/0x00078b40.cpp (stub A_78b40), size 0x5a0 (0x5a8)
struct A_78b40 {
    char pad[0x59c]; // +0x00
    void* m59c; // +0x59c (+0x5a0)
    void* FUN_00078b40();
};
// matches/0x00078c50.cpp (stub C_78c50), size 0x3830
struct C_78c50 {
    char pad[0x382c]; // +0x00
    int value; // +0x382c
    void FUN_00078c50(hulk_intptr x);
};
// matches/0x00079280.cpp (stub Target_79280), size 0x3550
struct Target_79280 {
    char pad[0x354c]; // +0x00
    int values[1]; // +0x354c
    hulk_intptr FUN_00079280(int index);
};
// matches/0x00079530.cpp (stub Obj_79530), size 0x3650
struct Obj_79530 {
    char pad[0x3650]; // +0x00
    unsigned __int64 FUN_00079530(int index);
};
// matches/0x00079950.cpp (stub C_79950), size 0x3750 (0x3758)
struct C_79950 {
    char pad[0x374c]; // +0x00
    void* arr[1]; // +0x374c (+0x3750)
    int lookup(int);
    bool FUN_00079950(hulk_intptr);
};
// matches/0x0007a820.cpp (stub Thing_7a820), size 0x3750 (0x3758)
struct Thing_7a820 {
    char pad[0x374c]; // +0x00
    void* entries[1]; // +0x374c (+0x3750)
    float FUN_0007a820(int index);
};
// matches/0x0007ad00.cpp (stub Obj_7ad00), size 0x3804
struct Obj_7ad00 {
    char pad[0x3800]; // +0x00
    int vals[1]; // +0x3800
    int helper(int);
    hulk_intptr FUN_0007ad00(hulk_intptr);
};
// matches/0x0007def0.cpp (stub C_7def0), size 0x1
struct C_7def0 {
    int ac30(int);
    void ccf0(int);
    void FUN_0007def0(hulk_intptr);
};
// equivalent/0x0007e680.cpp (stub VehicleManager), size 0x37a4
struct VehicleManager_7e680 {
    char pad[0x36f0]; // +0x00
    int limits[10]; // +0x36f0
    int counts[10]; // +0x3718
    int count; // +0x3740
    char pad2[0x5c]; // +0x3744
    int vehicle; // +0x37a0
    void FUN_0007db80(int*, int*);
    void FUN_0007d700(const char*, int, int, int);
    void FUN_0007e680();
};
// equivalent/0x00080820.cpp (stub Actor_80820), size 0x1
struct Actor_80820 {
    bool FUN_0007a420(int*, int*, int*, int*);
    int FUN_0007a8f0(int*, int*);
    int FUN_0007f560(const char*, int, int, int, int);
    int FUN_0007f690(const char*, int, int, int);
    int FUN_00080820();
};
// matches/0x00080b70.cpp (stub C_80b70), size 0x1
struct C_80b70 {
    void FUN_00080b70(hulk_uintptr, hulk_uintptr);
    void A(unsigned int);
    void B(unsigned int);
    void D(unsigned int);
};
// matches/0x00080c60.cpp (stub Obj_80c60), size 0x2c
struct Obj_80c60 {
    char pad[0x28]; // +0x00
    unsigned int flags; // +0x28
    void FUN_00080c60(char value);
};
// matches/0x00080c80.cpp (stub Obj_80c80), size 0x2c
struct Obj_80c80 {
    char pad[0x28]; // +0x00
    unsigned int flags; // +0x28
    void FUN_00080c80(char value);
};
// matches/0x00080cb0.cpp (stub C_80cb0), size 0x2c
struct C_80cb0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char pad2[0x14]; // +0x14
    unsigned int flags; // +0x28
    void FUN_00080cb0(int);
};
// matches/0x00080e30.cpp (stub C_80e30), size 0x70
struct C_80e30 {
    char pad[0x64]; // +0x00
    int a, b, c; // +0x64
    void FUN_00080e30(int* p);
};
// matches/0x00080e70.cpp (stub Target_80e70), size 0xf0 (0xf8)
struct Target_80e70 {
    char pad[0xec]; // +0x00
    hulk_intptr member; // +0xec (+0xf0)
    void FUN_00080e70(char* p);
};
// matches/0x00080ef0.cpp (stub C_80ef0), size 0xbc
struct C_80ef0 {
    char pad[0xbc]; // +0x00
    void FUN_00080ef0(int);
};
// matches/0x00080f00.cpp (stub C_80f00), size 0xc4
struct C_80f00 {
    char pad[0xc0]; // +0x00
    int field; // +0xc0
    void FUN_00080f00(int x);
};
// matches/0x00080f10.cpp (stub C_80f10), size 0xc8
struct C_80f10 {
    char pad[0xc4]; // +0x00
    int value; // +0xc4
    void FUN_00080f10(int x);
};
// matches/0x00080f20.cpp (stub C_80f20), size 0xcc
struct C_80f20 {
    char pad[0xc8]; // +0x00
    int m; // +0xc8
    void FUN_00080f20(int);
};
// matches/0x00080f30.cpp (stub Thing_80f30), size 0xd0
struct Thing_80f30 {
    char pad[0xcc]; // +0x00
    int value; // +0xcc
    void FUN_00080f30(int);
};
// matches/0x00080f40.cpp (stub C_80f40), size 0x2c
struct C_80f40 {
    char pad[0x28]; // +0x00
    unsigned int flags; // +0x28
    void FUN_00080f40(bool b);
};
// matches/0x00082cd0.cpp (stub Target_82cd0), size 0x28
struct Target_82cd0 {
    char pad0[0x14]; // +0x00
    int a; // +0x14
    char pad1[0x0c]; // +0x18
    int b; // +0x24
    void FUN_00082cd0(int);
};
// equivalent/0x00082cf0.cpp (stub Owner), size 0x14
struct Owner_82cf0 {
    char pad[16]; // +0x00
    int value; // +0x10
    hulk_intptr FUN_00082cf0();
};
// matches/0x00083ba0.cpp (stub Vec), size 0xc
struct Vec_83ba0 {
    float x, y, z; // +0x00
    void FUN_00083ba0(const Vec_83ba0* a);
};
// matches/0x00083d20.cpp (stub Thing_83d20), size 0x14
struct Thing_83d20 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    void FUN_00083d20(int x);
};
// matches/0x00083d50.cpp (stub C_83d50), size 0x24
struct C_83d50 {
    char pad[0x20]; // +0x00
    int value; // +0x20
    void FUN_00083d50(int x);
};
// matches/0x00083d60.cpp (stub Target_83d60), size 0x28
struct Target_83d60 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    void FUN_00083d60(int v);
};
// matches/0x00083d70.cpp (stub C_83d70), size 0x2c
struct C_83d70 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    void FUN_00083d70(int x);
};
// matches/0x00085f50.cpp (stub Thing_85f50), size 0x49
struct Thing_85f50 {
    char pad[0x48]; // +0x00
    unsigned char field; // +0x48
    void FUN_00085f50(unsigned char value);
};
// matches/0x00085f80.cpp (stub Counter), size 0x28
struct Counter_85f80 {
    char pad[0x20]; // +0x00
    unsigned __int64 value; // +0x20
    double FUN_00085f80();
};
// matches/0x00085fc0.cpp (stub Timer), size 0x30
struct Timer_85fc0 {
    char pad[0x28]; // +0x00
    unsigned __int64 ticks; // +0x28
    double FUN_00085fc0();
};
// matches/0x00086040.cpp (stub Clock), size 0x18
struct Clock_86040 {
    char pad[16]; // +0x00
    unsigned __int64 count; // +0x10
    double FUN_00086040();
};
// matches/0x00086080.cpp (stub Obj), size 0x20
struct Obj_86080 {
    char pad[24]; // +0x00
    unsigned __int64 ticks; // +0x18
    double FUN_00086080();
};
// matches/0x00086100.cpp (stub Thing_86100), size 0x40
struct Thing_86100 {
    char pad[0x38]; // +0x00
    __int64 value; // +0x38
    void FUN_00086100(float);
};
// matches/0x00086290.cpp (stub Obj_86290), size 0x28
struct Obj_86290 {
    char pad[0x24]; // +0x00
    int mValue; // +0x24
    hulk_intptr FUN_00086290();
};
// matches/0x000862a0.cpp (stub Target_862a0), size 0x2c
struct Target_862a0 {
    char pad[0x28]; // +0x00
    unsigned int value; // +0x28
    hulk_uintptr FUN_000862a0();
};
// matches/0x000862b0.cpp (stub C_862b0), size 0x2c
struct C_862b0 {
    char pad[0x2c]; // +0x00
    hulk_uintptr FUN_000862b0();
};
// matches/0x00086310.cpp (stub C_86310), size 0x3c
struct C_86310 {
    char pad[0x38]; // +0x00
    unsigned int value; // +0x38
    hulk_uintptr FUN_00086310();
};
// matches/0x00086340.cpp (stub A_86340), size 0x40
struct A_86340 {
    char pad[0x3c]; // +0x00
    unsigned int value; // +0x3c
    hulk_uintptr FUN_00086340();
};
// matches/0x00086370.cpp (stub A_86370), size 0x4c
struct A_86370 {
    char pad[0x48]; // +0x00
    int x; // +0x48
    hulk_intptr FUN_00086370();
};
// matches/0x000863e0.cpp (stub Target_863e0), size 0xc
struct Target_863e0 {
    unsigned int a; // +0x00
    char pad[4]; // +0x04
    unsigned int b; // +0x08
    void FUN_000863e0(unsigned int x);
};
// matches/0x00086420.cpp (stub Target_86420), size 0x4
struct Target_86420 {
    int value; // +0x00
    void FUN_00086420(int);
};
// matches/0x00087940.cpp (stub Thing_87940), size 0x8 (0x10)
struct Thing_87940 {
    char pad[4]; // +0x00
    int* state; // +0x04 (+0x08)
    void Set(int);
    void StepA();
    void StepB();
    void FUN_00087940();
};
// matches/0x00088530.cpp (stub Obj_88530), size 0x1
struct Obj_88530 {
    void FUN_00088020();
    void FUN_000879c0();
    void FUN_00088530();
    void FUN_00087940();
};
// matches/0x00088e40.cpp (stub A_88e40), size 0x9d
struct A_88e40 {
    char pad[0x9c]; // +0x00
    char flag; // +0x9c
    void* FUN_00088e40();
};
// matches/0x00088ea0.cpp (stub A_88ea0), size 0x1
struct A_88ea0 {
    int f(unsigned int);
    hulk_intptr FUN_00088ea0(hulk_uintptr);
};
// matches/0x00088fe0.cpp (stub Obj_88fe0), size 0x28
struct Obj_88fe0 {
    int a; // +0x00
    int b; // +0x04
    char buf[32]; // +0x08
    void FUN_00088fe0(unsigned int);
};
// matches/0x000893c0.cpp (stub Target_893c0), size 0xac0
struct Target_893c0 {
    char pad[0xabf]; // +0x00
    unsigned char value; // +0xabf
    unsigned char FUN_000893c0();
};
// matches/0x000895c0.cpp (stub C_895c0), size 0xabc
struct C_895c0 {
    char pad[0xab8]; // +0x00
    int value; // +0xab8
    void FUN_000895c0(int);
};
// equivalent/0x000895e0.cpp (stub LevelName), size 0x80
struct LevelName_895e0 {
    char pad0[0x20]; // +0x00
    char name[0x20]; // +0x20
    char shortName[0x20]; // +0x40
    char displayName[0x20]; // +0x60
    void FUN_000895e0(const char* levelName);
};
// matches/0x00089880.cpp (stub C_89880), size 0xd8
struct C_89880 {
    char pad[0xd0]; // +0x00
    unsigned a, b; // +0xd0
    void FUN_00089880(unsigned* x, unsigned* y);
};
// matches/0x000898a0.cpp (stub Obj_898a0), size 0x104
struct Obj_898a0 {
    char pad[0xf8]; // +0x00
    unsigned int a, b, c; // +0xf8
    void FUN_000898a0(unsigned int x, unsigned int y, unsigned int z);
};
// matches/0x00089900.cpp (stub Target_89900), size 0x108
struct Target_89900 {
    char pad[0x104]; // +0x00
    int value; // +0x104
    void FUN_00089900(int x);
};
// matches/0x00089950.cpp (stub C_89950), size 0x110
struct C_89950 {
    char pad[0x10c]; // +0x00
    unsigned int value; // +0x10c
    unsigned int FUN_00089950();
};
// matches/0x00089960.cpp (stub C_89960), size 0x138
struct C_89960 {
    char pad[0x110]; // +0x00
    int values[10]; // +0x110
    int FUN_00089960(int index);
};
// matches/0x00089980.cpp (stub Obj_89980), size 0x138
struct Obj_89980 {
    char pad[0x10c]; // +0x00
    int field10c; // +0x10c
    int fields[10]; // +0x110
    void FUN_00089980();
};
// matches/0x000899d0.cpp (stub Obj_899d0), size 0x158
struct Obj_899d0 {
    char before[0x138]; // +0x00
    char pad[0x20]; // +0x138
    void FUN_000899d0(const char*);
};
// matches/0x00089a10.cpp (stub C_89a10), size 0xabd
struct C_89a10 {
    char pad[0xabc]; // +0x00
    unsigned char x; // +0xabc
    unsigned char FUN_00089a10();
};
// matches/0x00089a20.cpp (stub C_89a20), size 0xabd
struct C_89a20 {
    char pad[0xabc]; // +0x00
    unsigned char value; // +0xabc
    void FUN_00089a20(unsigned char x);
};
// matches/0x00089a30.cpp (stub Target_89a30), size 0xabd
struct Target_89a30 {
    char pad[0xabd]; // +0x00
    void FUN_00089a30(unsigned char value);
};
// matches/0x00089a40.cpp (stub Target_89a40), size 0xabe
struct Target_89a40 {
    char pad[0xABD]; // +0x00
    unsigned char value; // +0xabd
    unsigned char FUN_00089a40();
};
// matches/0x00089a50.cpp (stub Obj_89a50), size 0xac8
struct Obj_89a50 {
    char pad[0xac4]; // +0x00
    int value; // +0xac4
    hulk_intptr FUN_00089a50();
};
// matches/0x00089e10.cpp (stub W_89e10), size 0xf8
struct W_89e10 {
    char pad[0x80]; // +0x00
    int i80, i84; // +0x80
    char pad2[0xa8 - 0x88]; // +0x88
    int ia8, iac; // +0xa8
    char pad3[0xd0 - 0xb0]; // +0xb0
    int d0, d4; // +0xd0
    char d8[0x20]; // +0xd8
    void FUN_00089e10();
    void P();
};
// matches/0x0008a060.cpp (stub Obj_8a060), size 0x160
struct Obj_8a060 {
    char pad[0x160]; // +0x00
    int Find(int);
    char* FUN_0008a060(hulk_intptr);
};
// matches/0x0008a310.cpp (stub C_8a310), size 0xd8
struct C_8a310 {
    char pad[0xd0]; // +0x00
    int a; // +0xd0
    int b; // +0xd4
    int* FUN_0008a310();
};
// equivalent/0x0008baf0.cpp (stub ThisWrap_0008baf0), size 0x1
struct ThisWrap_0008baf0 {
    const char* FUN_0008abc0();
    void FUN_0008baf0(int* column, int* mode);
};
// equivalent/0x0008dec0.cpp (stub Target_8dec0), size 0x10 (0x18)
struct Target_8dec0 {
    char pad[8]; // +0x00
    void* name; // +0x08
    void* handle; // +0x0c (+0x10)
    void FUN_0008dec0();
};
// matches/0x0008ef90.cpp (stub Obj_8ef90), size 0x14 (0x20)
struct Obj_8ef90 {
    char pad[8]; // +0x00
    unsigned int* a; // +0x08
    char pad2[4]; // +0x0c (+0x10)
    unsigned int* b; // +0x10 (+0x18)
    void CopyTail();
    void FUN_0008ef90(unsigned int* src, unsigned int val);
};
// equivalent/0x0008fe90.cpp (stub BitPool), size 0x1c (0x28)
struct BitPool_8fe90 {
    char pad00[4]; // +0x00
    unsigned int elemSize; // +0x04
    unsigned int count; // +0x08
    char pad0c[4]; // +0x0c
    int base; // +0x10
    unsigned int *bitmap; // +0x14 (+0x18)
    unsigned int cursor; // +0x18 (+0x20)
    hulk_intptr FUN_0008fe90(int unused);
};
// matches/0x0008ff00.cpp (stub Thing_8ff00), size 0x1c (0x28)
struct Thing_8ff00 {
    char pad0[4]; // +0x00
    unsigned int divisor; // +0x04
    char pad8[8]; // +0x08
    unsigned int base; // +0x10
    unsigned int* bits; // +0x14 (+0x18)
    unsigned int limit; // +0x18 (+0x20)
    void FUN_0008ff00(hulk_intptr value, int unused);
};
// matches/0x00090050.cpp (stub Table_90050), size 0x8
struct Table_90050 {
    int FUN_00090050(char* s);
    unsigned int mLow; // +0x00
    unsigned int mHigh; // +0x04
};
// matches/0x00090130.cpp (stub Stats_90130), size 0x38
struct Stats_90130 {
    int Find(const char* n);
    void FUN_00090130(int v);
    char p[0x38]; // +0x00
};
// matches/0x000901d0.cpp (stub C_901d0), size 0x38
struct C_901d0 {
    char pad[0x38]; // +0x00
    void FUN_000901d0(int index, unsigned int value);
};
// matches/0x000906f0.cpp (stub C_906f0), size 0x1
struct C_906f0 {
    int Find(int);
    void FUN_000906f0(int);
};
// matches/0x00090720.cpp (stub C_90720), size 0x1
struct C_90720 {
    void FUN_00090720(const char* s, int n);
    int Find(const char* s);
    void Other(int n);
    char pad[0]; // +0x00
};
// equivalent/0x00090790.cpp (stub Measure), size 0x40
struct Measure_90790 {
    char pad00[0x10]; // +0x00
    int kind; // +0x10
    int mode; // +0x14
    char active; // +0x18
    char pad19[3]; // +0x19
    float startX; // +0x1c
    float startY; // +0x20
    float startZ; // +0x24
    char pad28[0x38 - 0x28]; // +0x28
    int value; // +0x38
    int best; // +0x3c
    void FUN_00090790();
};
// matches/0x00090db0.cpp (stub Obj_90db0), size 0xc84
struct Obj_90db0 {
    char pad[0xc80]; // +0x00
    int count; // +0xc80
    void FUN_00090db0(int a, int b);
};
// matches/0x00090df0.cpp (stub C_90df0), size 0x1
struct C_90df0 {
    int Find(int);
    void FUN_00090df0(int);
};
// matches/0x00091d20.cpp (stub C_91d20), size 0x28
struct C_91d20 {
    char pad[0x28]; // +0x00
    char* FUN_00091d20();
};
// matches/0x00091d50.cpp (stub Obj_91d50), size 0x68
struct Obj_91d50 {
    char pad[0x68]; // +0x00
    Obj_91d50* FUN_00091d50();
};
// matches/0x00091f30.cpp (stub C_91f30), size 0x21
struct C_91f30 {
    char pad[0x20]; // +0x00
    unsigned char value; // +0x20
    void FUN_00091f30(unsigned char x);
};
// matches/0x00091f70.cpp (stub Obj_91f70), size 0x28
struct Obj_91f70 {
    char pad[0x24]; // +0x00
    int mValue; // +0x24
    int FUN_00091f70();
};
// matches/0x00091f90.cpp (stub Target_91f90), size 0x2c
struct Target_91f90 {
    char pad[0x28]; // +0x00
    unsigned int value; // +0x28
    unsigned int FUN_00091f90();
};
// matches/0x00091fb0.cpp (stub A_91fb0), size 0x2c
struct A_91fb0 {
    char pad[0x2c]; // +0x00
    unsigned char FUN_00091fb0();
};
// equivalent/0x00091fe0.cpp (stub Object), size 0x34 (0x38)
struct Object_91fe0 {
    char pad[0x30]; // +0x00
    char *text; // +0x30
    void FUN_00091fe0(const char *value);
};
// equivalent/0x00092120.cpp (stub TextOwner), size 0x24 (0x28)
struct TextOwner_92120 {
    char padding[0x20]; // +0x00
    char *text; // +0x20
    void FUN_00092120(const char *source);
};
// matches/0x00092360.cpp (stub Target_92360), size 0xb1
struct Target_92360 {
    char pad[0xb0]; // +0x00
    unsigned char value; // +0xb0
    void FUN_00092360(unsigned char x);
};
// matches/0x00092370.cpp (stub C_92370), size 0xb1
struct C_92370 {
    char pad[0xb0]; // +0x00
    unsigned char value; // +0xb0
    unsigned char FUN_00092370();
};
// matches/0x00092860.cpp (stub C_92860), size 0x1
struct C_92860 {
    unsigned char FUN_00092860(hulk_intptr i);
};
// matches/0x000929a0.cpp (stub Owner_929a0), size 0x4 (0x8)
struct Owner_929a0 {
    void* items[1]; // +0x00
    void FUN_000929a0(int index, char value);
};
// matches/0x00092a40.cpp (stub C_92a40), size 0x4 (0x8)
struct C_92a40 {
    void* items[1]; // +0x00
    unsigned char FUN_00092a40(int index);
};
// matches/0x00092ad0.cpp (stub C_92ad0), size 0x4
struct C_92ad0 {
    hulk_intptr FUN_00092ad0(hulk_intptr);
    int m[1]; // +0x00
};
// matches/0x00092bb0.cpp (stub C_92bb0), size 0x1
struct C_92bb0 {
    hulk_intptr FUN_00092bb0(int index);
};
// matches/0x00092bd0.cpp (stub C_92bd0), size 0xd88
struct C_92bd0 {
    char pad[0xd88]; // +0x00
    void FUN_00092bd0(hulk_intptr value);
};
// matches/0x00092be0.cpp (stub C_92be0), size 0xd8c
struct C_92be0 {
    char pad[0xd88]; // +0x00
    int value; // +0xd88
    void FUN_00092be0();
};
// matches/0x00092de0.cpp (stub ThisWrap_00092de0), size 0x1
struct ThisWrap_00092de0 {
    unsigned int FUN_00092940(unsigned int);
    unsigned char FUN_00092de0(unsigned int x);
};
// matches/0x000932a0.cpp (stub C_932a0), size 0xd88
struct C_932a0 {
    char pad[0xbf8]; // +0x00
    int values[100]; // +0xbf8
    int FUN_000932a0(int index);
};
// matches/0x00094590.cpp (stub Obj_94590), size 0x1
struct Obj_94590 {
    void Do(int, int);
    void FUN_00094590();
};
// matches/0x00095e80.cpp (stub Vec3_95e80), size 0xc
struct Vec3_95e80 {
    float x, y, z; // +0x00
    void FUN_00095e80(float s, float const* v);
};
// matches/0x00098380.cpp (stub Obj_98380), size 0x40
struct Obj_98380 {
    unsigned int x[16]; // +0x00
    void FUN_00098380(hulk_uintptr);
};
// matches/0x00098460.cpp (stub C_98460), size 0x1b4
struct C_98460 {
    char pad[0x17c]; // +0x00
    float a; // +0x17c
    char pad2[0x30]; // +0x180
    float b; // +0x1b0
    int FUN_00098460(int);
};
// matches/0x00098e20.cpp (stub A_98e20), size 0x10
struct A_98e20 {
    char pad[12]; // +0x00
    int value; // +0x0c
    void FUN_00098e20(hulk_intptr x);
};
// equivalent/0x0009a1e0.cpp (stub Obj), size 0x18
struct Obj_9a1e0 {
    char pad0[4]; // +0x00
    unsigned flags; // +0x04
    char pad8[8]; // +0x08
    unsigned value10; // +0x10
    unsigned value14; // +0x14
    void FUN_000991b0(unsigned, unsigned, unsigned, unsigned, unsigned);
    void FUN_0009a1e0(hulk_uintptr);
};
// equivalent/0x000a06d0.cpp (stub Obj000a06d0), size 0xd8
struct Obj000a06d0_a06d0 {
    unsigned int words[0x35]; // +0x00
    char b0; // +0xd4
    char b1; // +0xd5
    Obj000a06d0_a06d0* FUN_000a06d0(const Obj000a06d0_a06d0* src);
};
// matches/0x000a0b70.cpp (stub C_a0b70), size 0x354
struct C_a0b70 {
    char pad[0x350]; // +0x00
    unsigned int value; // +0x350
    hulk_uintptr FUN_000a0b70();
};
// matches/0x000a0bc0.cpp (stub Target_a0bc0), size 0x444
struct Target_a0bc0 {
    char pad[0x440]; // +0x00
    int value; // +0x440
    void FUN_000a0bc0(int x);
};
// matches/0x000a0c10.cpp (stub Thing_a0c10), size 0x49c
struct Thing_a0c10 {
    char pad[0x498]; // +0x00
    int value; // +0x498
    void FUN_000a0c10(int x);
};
// matches/0x000a0c30.cpp (stub C_a0c30), size 0x4a0
struct C_a0c30 {
    char pad[0x49c]; // +0x00
    int value; // +0x49c
    void FUN_000a0c30(int);
};
// matches/0x000a2370.cpp (stub Obj_a2370), size 0x18
struct Obj_a2370 {
    char pad[8]; // +0x00
    float a, b, c; // +0x08
    unsigned char flag; // +0x14
    unsigned char FUN_000a2370(float, float*, float*, unsigned char*);
};
// matches/0x000a87f0.cpp (stub V), size 0x18
struct V_a87f0 {
    float v[6]; // +0x00
    void FUN_000a87f0(V_a87f0*);
};
// matches/0x000a90f0.cpp (stub Thing_a90f0), size 0x160
struct Thing_a90f0 {
    char pad[0x154]; // +0x00
    int values[3]; // +0x154
    void FUN_000a90f0(int index, int value);
};
// matches/0x000a9110.cpp (stub C_a9110), size 0x4
struct C_a9110 {
    float arr[1]; // +0x00
    void FUN_000a9110(int i, float v);
};
// matches/0x000a9130.cpp (stub C_a9130), size 0x164
struct C_a9130 {
    char pad[0x158]; // +0x00
    int values[3]; // +0x158
    void FUN_000a9130(int index, int value);
};
// matches/0x000ac610.cpp (stub Thing_ac610), size 0x38
struct Thing_ac610 {
    char pad[0x14]; // +0x00
    float a; // +0x14
    float b; // +0x18
    char gap[4]; // +0x1c
    float c; // +0x20
    float d; // +0x24
    float out1; // +0x28
    float out2; // +0x2c
    int copy1; // +0x30
    int copy2; // +0x34
    void FUN_000ac610();
};
// matches/0x000ac780.cpp (stub Target_ac780), size 0x20
struct Target_ac780 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    char pad2[4]; // +0x18
    unsigned char flag; // +0x1c
    void FUN_000ac780(int x);
};
// matches/0x000ac790.cpp (stub Target_ac790), size 0x20
struct Target_ac790 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    unsigned char flag; // +0x1c
    void FUN_000ac790(int x);
};
// matches/0x000ac7a0.cpp (stub Thing_ac7a0), size 0x28
struct Thing_ac7a0 {
    char pad14[0x14]; // +0x00
    float mA; // +0x14
    float mB; // +0x18
    unsigned char flag; // +0x1c
    char pad1d[3]; // +0x1d
    float x; // +0x20
    float y; // +0x24
    void FUN_000ac7a0(float a, float b);
};
// matches/0x000ac9c0.cpp (stub Obj_ac9c0), size 0x2c4
struct Obj_ac9c0 {
    char pad[0x170]; // +0x00
    unsigned char v170; // +0x170
    char p171[0x37]; // +0x171
    unsigned char v1a8; // +0x1a8
    char p1a9[0x37]; // +0x1a9
    unsigned char v1e0; // +0x1e0
    char p1e1[0x37]; // +0x1e1
    unsigned char v218; // +0x218
    char p219[0x37]; // +0x219
    unsigned char v250; // +0x250
    char p251[0x5b]; // +0x251
    unsigned char v2ac; // +0x2ac
    char p2ad[0x13]; // +0x2ad
    int v2c0; // +0x2c0
    void FUN_000ac9c0(unsigned char p1, unsigned char p2, unsigned char p3, unsigned char p4, unsigned char p5, unsigned char p6);
};
// matches/0x000ace20.cpp (stub C_ace20), size 0x18 (0x20)
struct C_ace20 {
    char pad[0x14]; // +0x00
    int* items; // +0x14 (+0x18)
    hulk_intptr FUN_000ace20(int i);
};
// matches/0x000ada30.cpp (stub C_ada30), size 0x90
struct C_ada30 {
    char pad[0x5c]; // +0x00
    int a[13]; // +0x5c
    void FUN_000ada30(int);
};
// matches/0x000ada50.cpp (stub X_ada50), size 0xa0
struct X_ada50 {
    char pad[0x90]; // +0x00
    int a[4]; // +0x90
    void FUN_000ada50(int);
};
// matches/0x000ada70.cpp (stub Obj_ada70), size 0x5c
struct Obj_ada70 {
    char pad[0x18]; // +0x00
    int data[17]; // +0x18
    void FUN_000ada70(void* out);
};
// matches/0x000ae640.cpp (stub C_ae640), size 0x8
struct C_ae640 {
    int pad; // +0x00
    int a; // +0x04
    hulk_intptr FUN_000ae640(int i);
};
// matches/0x000af0f0.cpp (stub C_af0f0), size 0xd
struct C_af0f0 {
    char pad[12]; // +0x00
    char data[1]; // +0x0c
    void FUN_000af0f0(void* p);
};
// matches/0x000af3a0.cpp (stub C_af3a0), size 0x8
struct C_af3a0 {
    int pad; // +0x00
    int a; // +0x04
    hulk_intptr FUN_000af3a0(int i);
};
// matches/0x000af650.cpp (stub Obj_af650), size 0x18 (0x20)
struct Obj_af650 {
    char pad0[8]; // +0x00
    unsigned char enabled; // +0x08
    char pad9[0x14 - 9]; // +0x09
    int* data; // +0x14 (+0x18)
    void FUN_000af650(int, unsigned int, float);
};
// matches/0x000afb80.cpp (stub Thing_afb80), size 0x9
struct Thing_afb80 {
    char pad[8]; // +0x00
    char value; // +0x08
    void FUN_000afb80(char);
};
// matches/0x000afdf0.cpp (stub A_afdf0), size 0x5
struct A_afdf0 {
    char pad[4]; // +0x00
    unsigned char flag; // +0x04
    void FUN_000afdf0();
};
// matches/0x000afe40.cpp (stub C_afe40), size 0x8
struct C_afe40 {
    int pad[2]; // +0x00
    hulk_intptr FUN_000afe40(int i);
};
// matches/0x000b0740.cpp (stub Dev_b0740), size 0x58
struct Dev_b0740 {
    char p[0x14]; // +0x00
    char name[0x40]; // +0x14
    int type; // +0x54
    void FUN_000b0740(const char* s);
};
// matches/0x000b07b0.cpp (stub Object), size 0x494
struct Object_b07b0 {
    char pad[0x490]; // +0x00
    int value; // +0x490
    unsigned char FUN_000b07b0(int x);
};
// matches/0x000b07c0.cpp (stub Obj_b07c0), size 0x498
struct Obj_b07c0 {
    char pad[0x494]; // +0x00
    int value; // +0x494
    unsigned char FUN_000b07c0(int x);
};
// matches/0x000b07d0.cpp (stub Target_b07d0), size 0x49c
struct Target_b07d0 {
    char pad[0x498]; // +0x00
    int value; // +0x498
    bool FUN_000b07d0(int x);
};
// matches/0x000b07e0.cpp (stub Target_b07e0), size 0x4a0
struct Target_b07e0 {
    char pad[0x49c]; // +0x00
    unsigned int value; // +0x49c
    bool FUN_000b07e0(unsigned int);
};
// matches/0x000b07f0.cpp (stub Target_b07f0), size 0x4a4
struct Target_b07f0 {
    char pad[0x4a0]; // +0x00
    int value; // +0x4a0
    unsigned char FUN_000b07f0(int x);
};
// matches/0x000b0800.cpp (stub Target_b0800), size 0x4a8
struct Target_b0800 {
    char pad[0x4a4]; // +0x00
    int value; // +0x4a4
    bool FUN_000b0800(int x);
};
// matches/0x000b0ef0.cpp (stub C_b0ef0), size 0x4b0
struct C_b0ef0 {
    char pad[0x4ac]; // +0x00
    unsigned int value; // +0x4ac
    unsigned int FUN_000b0ef0();
};
// equivalent/0x000b1020.cpp (stub StringTable_b1020), size 0x8 (0x10)
struct StringTable_b1020 {
    int count; // +0x00
    char (*data)[32];
    void FUN_000b1020(int n);
};
// matches/0x000b10a0.cpp (stub Target_b10a0), size 0x8 (0x10)
struct Target_b10a0 {
    int count; // +0x00
    char* data; // +0x04 (+0x08)
    void Check(int);
    void FUN_000b10a0(int index, const void* source);
};
// matches/0x000b3b50.cpp (stub Obj_b3b50), size 0x118
struct Obj_b3b50 {
    char pad[0x118]; // +0x00
    void Copy(void* p, unsigned int v);
    void FUN_000b3b50(unsigned int v);
};
// matches/0x000b3d20.cpp (stub C_b3d20), size 0x8
struct C_b3d20 {
    int pad; // +0x00
    int a; // +0x04
    hulk_intptr FUN_000b3d20(int i);
};
// matches/0x000b3ec0.cpp (stub C_b3ec0), size 0x8
struct C_b3ec0 {
    int pad; // +0x00
    int m[1]; // +0x04
    hulk_intptr FUN_000b3ec0(int i);
};
// equivalent/0x000b4b00.cpp (stub Obj), size 0x1c8c
struct Obj_b4b00 {
    char pad[0x1c0c]; // +0x00
    char first[0x40]; // +0x1c0c
    char second[0x40]; // +0x1c4c
    void FUN_000b4b00(int);
};
// equivalent/0x000b4b60.cpp (stub Registry_b4b60), size 0x46c (0x870)
struct Registry_b4b60 {
    char pad[0x6c]; // +0x00
    char* values[128]; // +0x6c (+0x70)
    char* keys[128]; // +0x26c (+0x470)
    void FUN_000b4b60(const char* key, const char* value);
};
// matches/0x000b4c10.cpp (stub K_b4c10), size 0x46c (0x670)
struct K_b4c10 {
    char pad[0x26c]; // +0x00
    const char* names[128]; // +0x26c (+0x270)
    bool FUN_000b4c10(const char* s);
};
// matches/0x000b4c80.cpp (stub Table_b4c80), size 0x26c (0x470)
struct Table_b4c80 {
    bool FUN_000b4c80(const char* name);
    char pad[0x6c]; // +0x00
    const char* names[0x80]; // +0x6c (+0x70)
};
// equivalent/0x000b4cf0.cpp (stub NameTable_b4cf0), size 0x46c (0x670)
struct NameTable_b4cf0 {
    hulk_uintptr FUN_000b4cf0(const char *name);
    char pad0[0x6c]; // +0x00
    unsigned int values[128]; // +0x6c
    const char *names[128]; // +0x26c (+0x270)
};
// matches/0x000b54d0.cpp (stub Owner), size 0x1
struct Owner_b54d0 {
    void Apply(void*, int, int, int, int, int, int, int);
    void FUN_000b54d0(int, int, int, int, int, int, int);
};
// matches/0x000b5530.cpp (stub Owner), size 0x1
struct Owner_b5530 {
    void process(void*, int, int, int, int, int, int, int);
    void FUN_000b5530(int a, int b, int c, int d, int e, int f, int g);
};
// matches/0x000b5810.cpp (stub Handler), size 0x1
struct Handler_b5810 {
    void write(void*, float, float, float, float, float, float, float);
    void FUN_000b5810(float a, float b, float c, float d, float e, float f, float g);
};
// matches/0x000b5a30.cpp (stub Owner), size 0x48 (0x50)
struct Owner_b5a30 {
    char pad[0x44]; // +0x00
    char* state; // +0x44 (+0x48)
    void FUN_000b5a30();
};
// equivalent/0x000b7ff0.cpp (stub HintMenu_b7ff0), size 0x1a10
struct HintMenu_b7ff0 {
    void FUN_000b7ff0();
    char pad00[0x1a0c]; // +0x00
    int hintIds[1]; // +0x1a0c
};
// equivalent/0x000b8430.cpp (stub HintMenu_b8430), size 0x1bd0
struct HintMenu_b8430 {
    char pad00[0x1b50]; // +0x00
    int shown[32]; // +0x1b50
    void FUN_000b8430();
};
// matches/0x000b8c90.cpp (stub Foo_b8c90), size 0x1d00
struct Foo_b8c90 {
    char pad[0x1cfc]; // +0x00
    float v; // +0x1cfc
    bool FUN_000b8c90();
};
// matches/0x000b9090.cpp (stub Target_b9090), size 0x14
struct Target_b9090 {
    char pad[0x10]; // +0x00
    int state; // +0x10
    void FUN_000b9090(int value);
};
// matches/0x000bc9f0.cpp (stub MenuScreen_bc9f0), size 0x1
struct MenuScreen_bc9f0 {
    int FUN_000bc900(unsigned short* out, int pos, const char* name, int flag);
    void FUN_000bc9f0(hulk_intptr id, int code);
};
// equivalent/0x000bd050.cpp (stub MenuScreen_bd050), size 0x1
struct MenuScreen_bd050 {
    void FUN_000bc900(char* out, int a, const char* name, int b);
    void FUN_000bd050();
};
// equivalent/0x000bdf50.cpp (stub Target_bdf50), size 0x1a06
struct Target_bdf50 {
    char pad[0x1a04]; // +0x00
    unsigned char flag; // +0x1a04
    unsigned char latched; // +0x1a05
    bool FUN_000bdf50(bool mode, bool analog);
};
// matches/0x000be100.cpp (stub Menu_be100), size 0x1cf4
struct Menu_be100 {
    char pad0[0x10]; // +0x00
    int state; // +0x10
    char pad1[0x1cec - 0x14]; // +0x14
    int pending; // +0x1cec
    int index; // +0x1cf0
    void FUN_000bc5c0(const char* kind, const char* level, int difficulty, int flag);
    void FUN_000be100();
};
// matches/0x000befc0.cpp (stub Loader), size 0x1
struct Loader_befc0 {
    void FUN_000bd1b0(int arg);
    void FUN_000befc0(const char* name, int param, bool pump);
};
// matches/0x000bfbe0.cpp (stub Game_bfbe0), size 0x1884
struct Game_bfbe0 {
    char pad[0x1880]; // +0x00
    float timer; // +0x1880
    bool Check(int, int);
    void FUN_000bfbe0(void*, float);
};
// matches/0x000c3ce0.cpp (stub Object), size 0x50
struct Object_c3ce0 {
    char padding[0x4c]; // +0x00
    unsigned int enabled; // +0x4c
    void FUN_000c21b0(int id);
    void FUN_000c3ce0();
};
// matches/0x000c6fa0.cpp (stub C_c6fa0), size 0x64
struct C_c6fa0 {
    int pad[25]; // +0x00
    void FUN_000c6fa0(int index, int a, int b, int c);
};
// matches/0x000c7ad0.cpp (stub Target_c7ad0), size 0x21
struct Target_c7ad0 {
    char pad[0x20]; // +0x00
    unsigned char field; // +0x20
    void FUN_000c7ad0();
};
// matches/0x000c7ae0.cpp (stub C_c7ae0), size 0x22c
struct C_c7ae0 {
    char pad[0x228]; // +0x00
    int value; // +0x228
    void FUN_000c7ae0(int x);
};
// matches/0x000c7af0.cpp (stub C_c7af0), size 0x295a
struct C_c7af0 {
    char pad[0x2958]; // +0x00
    unsigned char a; // +0x2958
    unsigned char b; // +0x2959
    void FUN_000c7af0();
};
// matches/0x000c8190.cpp (stub X_c8190), size 0x2258
struct X_c8190 {
    char pad[0x258]; // +0x00
    int vals[128][16]; // +0x258
    int* FUN_000c8190(int i);
};
// equivalent/0x000c8f50.cpp (stub Obj), size 0x295c
struct Obj_c8f50 {
    void FUN_000c8f50(float target);
    char p0[0x210]; // +0x00
    float f210; // +0x210
    char p1[4]; // +0x214
    float f218; // +0x218
    char p2[0x224 - 0x21c]; // +0x21c
    char c224; // +0x224
    char p3[0x2959 - 0x225]; // +0x225
    char c2959; // +0x2959
};
// matches/0x000cac60.cpp (stub Obj_cac60), size 0x4a0
struct Obj_cac60 {
    char pad0[0x264]; // +0x00
    char a[8][0x40]; // +0x264
    char pad1[0x14]; // +0x464
    int x478; // +0x478
    int x47c; // +0x47c
    int x480; // +0x480
    int x484; // +0x484
    int x488; // +0x488
    int x48c; // +0x48c
    char pad2[4]; // +0x490
    int x494; // +0x494
    int x498; // +0x498
    int x49c; // +0x49c
    void FUN_000cac60();
};
// matches/0x000cae40.cpp (stub Target_cae40), size 0xb8
struct Target_cae40 {
    char pad[0xb8]; // +0x00
    void FUN_000cae40(int value);
};
// matches/0x000cae70.cpp (stub C_cae70), size 0x8c
struct C_cae70 {
    char pad[0x88]; // +0x00
    int value; // +0x88
    hulk_intptr FUN_000cae70();
};
// equivalent/0x000d3ef0.cpp (stub Thing), size 0x8
struct Thing_d3ef0 {
    int first; // +0x00
    int second; // +0x04
    void FUN_000d3ef0(hulk_intptr a, hulk_intptr b);
    void FUN_000f7050(Thing_d3ef0*);
};
// matches/0x000d4370.cpp (stub Obj_d4370), size 0x810
struct Obj_d4370 {
    char pad[0x10]; // +0x00
    int a; // +0x10
    char rest[0x7f8]; // +0x14
    unsigned char b; // +0x80c
    void FUN_000d4370(hulk_intptr);
};
// equivalent/0x000d4400.cpp (stub Accum), size 0x488
struct Accum_d4400 {
    char pad0[0x220]; // +0x00
    float sum0; // +0x220
    float sum1; // +0x224
    float sum2; // +0x228
    char pad22c[0x8]; // +0x22c
    float damp0; // +0x234
    char pad238[8]; // +0x238
    int id0; // +0x240
    int count0; // +0x244
    char flag0; // +0x248
    char pad249[0x213]; // +0x249
    float sum3; // +0x45c
    float sum4; // +0x460
    float sum5; // +0x464
    char pad468[8]; // +0x468
    float damp1; // +0x470
    char pad474[8]; // +0x474
    int id1; // +0x47c
    int count1; // +0x480
    char flag1; // +0x484
    void FUN_000d4400(int id, float amount);
};
// matches/0x000d4820.cpp (stub Obj_d4820), size 0x8b8
struct Obj_d4820 {
    char pad[0x594]; // +0x00
    float items[3][67]; // +0x594
    void FUN_000d4820(int index, float value);
};
// matches/0x000d6dd0.cpp (stub Slots_d6dd0), size 0x2c
struct Slots_d6dd0 {
    char pad[0xc]; // +0x00
    int values[8]; // +0x0c
    void FUN_000d6dd0(hulk_intptr);
};
// matches/0x000d6f00.cpp (stub A_d6f00), size 0x10
struct A_d6f00 {
    char pad[12]; // +0x00
    int value; // +0x0c
    void FUN_000d6f00(int x);
};
// matches/0x000d6fd0.cpp (stub Thing_d6fd0), size 0xc (0x10)
struct Thing_d6fd0 {
    char pad[8]; // +0x00
    char* p; // +0x08
    char FUN_000d6fd0();
};
// equivalent/0x000d7be0.cpp (stub Object), size 0x2c
struct Object_d7be0 {
    char unused[8]; // +0x00
    unsigned int first; // +0x08
    unsigned int second; // +0x0c
    unsigned int third; // +0x10
    unsigned int fourth; // +0x14
    unsigned int zero1; // +0x18
    unsigned int zero2; // +0x1c
    unsigned int zero3; // +0x20
    unsigned int sentinel; // +0x24
    unsigned int last; // +0x28
    void FUN_000d7be0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
};
// equivalent/0x000d7c30.cpp (stub Object), size 0x30
struct Object_d7c30 {
    char reserved[8]; // +0x00
    unsigned int state0; // +0x08
    unsigned int state1; // +0x0c
    unsigned int state2; // +0x10
    unsigned int state3; // +0x14
    unsigned int value0; // +0x18
    unsigned int value1; // +0x1c
    unsigned int value2; // +0x20
    unsigned int value3; // +0x24
    unsigned int value4; // +0x28
    unsigned int value5; // +0x2c
    void FUN_000d7c30(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f);
};
// matches/0x000de1d0.cpp (stub Obj_de1d0), size 0x38
struct Obj_de1d0 {
    char pad[0x2c]; // +0x00
    float second; // +0x2c
    char pad2[4]; // +0x30
    float first; // +0x34
    void FUN_000de1d0();
};
// matches/0x000e0100.cpp (stub Obj), size 0x54
struct Obj_e0100 {
    char pad[0x3c]; // +0x00
    float a; // +0x3c
    char pad2[4]; // +0x40
    float b; // +0x44
    char pad3[8]; // +0x48
    unsigned char flag; // +0x50
    void FUN_000e0100();
};
// matches/0x000e0170.cpp (stub C_e0170), size 0x18
struct C_e0170 {
    char pad[0x10]; // +0x00
    unsigned __int64 value; // +0x10
    void FUN_000e0170(unsigned long);
};
// matches/0x000e0300.cpp (stub C_e0300), size 0x180c
struct C_e0300 {
    char pad[0x1800]; // +0x00
    int a; // +0x1800
    int b; // +0x1804
    int c; // +0x1808
    void FUN_000e0300(int x, int y, int z);
};
// matches/0x000e0360.cpp (stub C_e0360), size 0x1818
struct C_e0360 {
    char pad[0x180c]; // +0x00
    int a; // +0x180c
    int b; // +0x1810
    int c; // +0x1814
    void FUN_000e0360(int x, int y, int z);
};
// matches/0x000e03c0.cpp (stub Obj_e03c0), size 0x1850
struct Obj_e03c0 {
    char pad[0x1840]; // +0x00
    unsigned a; // +0x1840
    unsigned b; // +0x1844
    unsigned c; // +0x1848
    unsigned char flag; // +0x184c
    void FUN_000e03c0(unsigned x, unsigned y, unsigned z, unsigned w, unsigned v);
};
// matches/0x000e04f0.cpp (stub Obj_e04f0), size 0x90
struct Obj_e04f0 {
    char pad[0x88]; // +0x00
    unsigned long long value; // +0x88
    void FUN_000e04f0(hulk_uintptr x);
};
// matches/0x000e2ac0.cpp (stub Obj_e2ac0), size 0xb0
struct Obj_e2ac0 {
    char pad[0xac]; // +0x00
    volatile int field; // +0xac
    void FUN_000e2ac0(hulk_intptr);
};
// matches/0x000e2c60.cpp (stub C_e2c60), size 0x140
struct C_e2c60 {
    char pad[0x118]; // +0x00
    int slots[10]; // +0x118
    void FUN_000e2c60(hulk_intptr x);
};
// matches/0x000e2ec0.cpp (stub Obj_e2ec0), size 0x180
struct Obj_e2ec0 {
    char p0[0x78]; // +0x00
    unsigned int f78, f7c, f80; // +0x78
    char p84[0x94]; // +0x84
    unsigned int f118[10]; // +0x118
    unsigned int f140, f144, f148, f14c, f150, f154, f158, f15c, f160, f164, f168; // +0x140
    char p16c[0x10]; // +0x16c
    unsigned int f17c; // +0x17c
    void Init(Obj_e2ec0*);
    void FUN_000e2ec0(Obj_e2ec0*);
};
// matches/0x000e3750.cpp (stub C_e3750), size 0x1d9c (0x1da0)
struct C_e3750 {
    char pad[0x1d98]; // +0x00
    void* p; // +0x1d98
    void FUN_000e3750(void* x);
};
// matches/0x000e3ac0.cpp (stub Thing_e3ac0), size 0x118
struct Thing_e3ac0 {
    char pad[0x118]; // +0x00
    void Init(Thing_e3ac0*);
    void FUN_000e3ac0(Thing_e3ac0*);
};
// matches/0x000e3c70.cpp (stub Obj_e3c70), size 0x4990
struct Obj_e3c70 {
    char pad[0x118]; // +0x00
    int block[10]; // +0x118
    char pad2[0x495c - 0x140]; // +0x140
    int vals[13]; // +0x495c
    void Base(Obj_e3c70*);
    void FUN_000e3c70(Obj_e3c70*);
};
// matches/0x000e3f20.cpp (stub Obj_e3f20), size 0x2ac
struct Obj_e3f20 {
    char pad[0x2aC]; // +0x00
    void Base(Obj_e3f20*);
    void FUN_000e3f20(Obj_e3f20*);
};
// matches/0x000e4000.cpp (stub A_e4000), size 0x29c
struct A_e4000 {
    char pad[0x298]; // +0x00
    unsigned int x; // +0x298
    unsigned int FUN_000e4000();
};
// equivalent/0x000e4610.cpp (stub Object), size 0x859
struct Object_e4610 {
    char pad[0x858]; // +0x00
    char text[1]; // +0x858
    void FUN_000e4610(const char *source);
};
// matches/0x000e5440.cpp (stub Fader_e5440), size 0xaa4
struct Fader_e5440 {
    char pad00[0xa74]; // +0x00
    float level; // +0xa74
    int state; // +0xa78
    int stateTime; // +0xa7c
    char padA80[0x10]; // +0xa80
    float base; // +0xa90
    char padA94[0xc]; // +0xa94
    float output; // +0xaa0
    void FUN_000e5330();
    void FUN_000e53e0(int oldState);
    void FUN_000e5440(int newState);
};
// matches/0x000e5510.cpp (stub C_e5510), size 0xb40
struct C_e5510 {
    char pad[0xb40]; // +0x00
    void FUN_000e5510(const char* p);
};
// matches/0x000e5540.cpp (stub C_e5540), size 0xb80
struct C_e5540 {
    char pad[0xb80]; // +0x00
    void FUN_000e5540(const char* p);
};
// matches/0x000e5570.cpp (stub C_e5570), size 0xab4
struct C_e5570 {
    char pad[0xaa4]; // +0x00
    unsigned a, b, c; // +0xaa4
    unsigned char flag; // +0xab0
    void FUN_000e5570(unsigned x, unsigned y, unsigned z, unsigned q, unsigned r);
};
// matches/0x000e55b0.cpp (stub X_e55b0), size 0xab8
struct X_e55b0 {
    char pad[0xab4]; // +0x00
    unsigned int value; // +0xab4
    void FUN_000e55b0(unsigned int a, unsigned int b, unsigned int c);
};
// matches/0x000e55e0.cpp (stub C_e55e0), size 0xb40
struct C_e55e0 {
    char pad[0xabc]; // +0x00
    int values[32]; // +0xabc
    int count; // +0xb3c
    void FUN_000e55e0(hulk_intptr);
};
// matches/0x000e7460.cpp (stub ThisWrap_000e7460), size 0x1
struct ThisWrap_000e7460 {
    void* FUN_000e7260(void*);
    void* FUN_000e7460(void* p);
};
// matches/0x000e74a0.cpp (stub ThisWrap_000e74a0), size 0x1
struct ThisWrap_000e74a0 {
    int inner(int);
    hulk_intptr FUN_000e74a0(hulk_intptr x);
};
// matches/0x000e74e0.cpp (stub ThisWrap_000e74e0), size 0x1
struct ThisWrap_000e74e0 {
    int Inner(int);
    int FUN_000e74e0(int x);
};
// matches/0x000e7520.cpp (stub ThisWrap_000e7520), size 0x1
struct ThisWrap_000e7520 {
    int FUN_000e7260(int);
    hulk_intptr FUN_000e7520(int x);
};
// matches/0x000e7560.cpp (stub ThisWrap_000e7560), size 0x1
struct ThisWrap_000e7560 {
    int helper(int);
    int FUN_000e7560(int x);
};
// matches/0x000e75a0.cpp (stub ThisWrap_000e75a0), size 0x1
struct ThisWrap_000e75a0 {
    int inner(int);
    int FUN_000e75a0(int x);
};
// matches/0x000e75e0.cpp (stub ThisWrap_000e75e0), size 0x1
struct ThisWrap_000e75e0 {
    int FUN_000e7260(int);
    hulk_intptr FUN_000e75e0(int x);
};
// matches/0x000e76a0.cpp (stub Obj_e76a0), size 0x1614
struct Obj_e76a0 {
    char pad[0x610]; // +0x00
    int entries[0x401]; // +0x610
    void FUN_000e76a0(hulk_intptr value);
};
// matches/0x000e8490.cpp (stub T_e8490), size 0x2075
struct T_e8490 {
    void FUN_000e8490(unsigned char x);
    char pad[0x2074]; // +0x00
    unsigned char mX; // +0x2074
};
// matches/0x000e8650.cpp (stub Obj), size 0x54
struct Obj_e8650 {
    char pad[0x3c]; // +0x00
    float a; // +0x3c
    char pad2[4]; // +0x40
    float b; // +0x44
    char pad3[8]; // +0x48
    char flag; // +0x50
    void FUN_000e8650(float x);
};
// matches/0x000e86a0.cpp (stub Obj_e86a0), size 0x54
struct Obj_e86a0 {
    char pad0[0x3c]; // +0x00
    float value; // +0x3c
    char pad40[4]; // +0x40
    float input; // +0x44
    char pad48[8]; // +0x48
    unsigned char flag; // +0x50
    void FUN_000e86a0(float);
};
// matches/0x000f1a70.cpp (stub Obj), size 0x164
struct Obj_f1a70 {
    char pad[0x150]; // +0x00
    float value; // +0x150
    char pad2[8]; // +0x154
    float low; // +0x15c
    float high; // +0x160
    void update();
    void FUN_000f1a70(float x);
};
// matches/0x000f2740.cpp (stub Y_f2740), size 0x88 (0x110)
struct Y_f2740 {
    int pad; // +0x00
    void* field; // +0x04 (+0x08)
    void* slots[32]; // +0x08 (+0x10)
    hulk_intptr FUN_000f2740(void*);
};
// matches/0x000f27a0.cpp (stub Holder_f27a0), size 0x88
struct Holder_f27a0 {
    int field; // +0x00
    int data; // +0x04
    int slots[32]; // +0x08
    hulk_intptr FUN_000f27a0(hulk_intptr arg);
};
// matches/0x000f2800.cpp (stub Thing_f2800), size 0x88
struct Thing_f2800 {
    int value; // +0x00
    int ref; // +0x04
    volatile int slots[32]; // +0x08
    hulk_intptr FUN_000f2800(hulk_intptr, hulk_intptr);
};
// matches/0x000f2860.cpp (stub Y_f2860), size 0x88 (0x110)
struct Y_f2860 {
    int pad; // +0x00
    void* field; // +0x04 (+0x08)
    void* slots[32]; // +0x08 (+0x10)
    hulk_intptr FUN_000f2860(void*);
};
// matches/0x000f28c0.cpp (stub Y_f28c0), size 0x88 (0x110)
struct Y_f28c0 {
    int pad; // +0x00
    void* field; // +0x04 (+0x08)
    void* slots[32]; // +0x08 (+0x10)
    hulk_intptr FUN_000f28c0(void*);
};
// matches/0x000f2920.cpp (stub Holder_f2920), size 0x88
struct Holder_f2920 {
    int field; // +0x00
    int data; // +0x04
    int slots[32]; // +0x08
    hulk_intptr FUN_000f2920(hulk_intptr arg);
};
// matches/0x000f6fe0.cpp (stub C_f6fe0), size 0x110
struct C_f6fe0 {
    char pad[0x10c]; // +0x00
    int value; // +0x10c
    void FUN_000f6fe0(int);
};
// matches/0x000f7050.cpp (stub C_f7050), size 0x118
struct C_f7050 {
    char pad[0x114]; // +0x00
    int field; // +0x114
    void FUN_000f7050(hulk_intptr value);
};
// matches/0x000f7220.cpp (stub C_f7220), size 0x14 (0x20)
struct C_f7220 {
    char pad0[0x0c]; // +0x00
    int* items; // +0x0c (+0x10)
    int max; // +0x10 (+0x18)
    hulk_intptr FUN_000f7220(hulk_intptr index);
};
// matches/0x000f72c0.cpp (stub Obj_f72c0), size 0x1c (0x20)
struct Obj_f72c0 {
    char pad[0x18]; // +0x00
    unsigned long* data; // +0x18
    unsigned long long FUN_000f72c0(int index);
};
// matches/0x000f78f0.cpp (stub X_f78f0), size 0x84
struct X_f78f0 {
    char pad[0x80]; // +0x00
    int count; // +0x80
    void FUN_000f78f0();
};
// equivalent/0x000f7930.cpp (stub State), size 0x24
struct State_f7930 {
    int value; // +0x00
    bool flag; // +0x04
    char pad5[3]; // +0x05
    float scale; // +0x08
    int fieldC; // +0x0c
    int field10; // +0x10
    int field14; // +0x14
    bool flag18; // +0x18
    char pad19[3]; // +0x19
    float amount; // +0x1c
    int field20; // +0x20
    State_f7930* FUN_000f7930();
};
// matches/0x000f7960.cpp (stub Thing_f7960), size 0x14
struct Thing_f7960 {
    char pad[0x0c]; // +0x00
    unsigned int mSecond; // +0x0c
    unsigned int mFirst; // +0x10
    void FUN_000f7960();
};
// matches/0x000f79a0.cpp (stub Obj_f79a0), size 0x24 (0x28)
struct Obj_f79a0 {
    char pad0[0x10]; // +0x00
    void* mData; // +0x10
    int mOther; // +0x14 (+0x18)
    char pad18[8]; // +0x18 (+0x1c)
    int mState; // +0x20 (+0x24)
    void FUN_000f79a0(const short* text, hulk_intptr unused);
};
// matches/0x000f7a10.cpp (stub Obj_f7a10), size 0x24
struct Obj_f7a10 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    int m14; // +0x14
    char pad18[8]; // +0x18
    int m20; // +0x20
    void FUN_000f7a10(hulk_intptr value, int unused);
};
// matches/0x000f7d30.cpp (stub A_f7d30), size 0x1
struct A_f7d30 {
    int f(unsigned long long);
    hulk_intptr FUN_000f7d30(hulk_intptr p);
};
// matches/0x000f7f60.cpp (stub Printer_f7f60), size 0x1
struct Printer_f7f60 {
    void FUN_000f7d60(const char* text, int a2, int a3, int a4, int a5, int a6);
    void FUN_000f7f60(int src, int a2, int a3, int a4, int a5, int a6);
};
// matches/0x000f86f0.cpp (stub Obj_f86f0), size 0x120 (0x130)
struct Obj_f86f0 {
    void FUN_000f86f0(int a, hulk_intptr b);
    char* m0; // +0x00
    unsigned m4; // +0x04 (+0x08)
    char pad8[4]; // +0x08 (+0x0c)
    int* mC; // +0x0c (+0x10)
    unsigned m10; // +0x10 (+0x18)
    char pad14[4]; // +0x14 (+0x1c)
    void* m18; // +0x18 (+0x20)
    int m1c; // +0x1c (+0x28)
    char pad20[0x110 - 0x20]; // +0x20 (+0x2c)
    char m110; // +0x110 (+0x11c)
    char pad111[0x11c - 0x111]; // +0x111 (+0x11d)
    unsigned* m11c; // +0x11c (+0x128)
};
// matches/0x000f8bb0.cpp (stub Obj_f8bb0), size 0x204 (0x208)
struct Obj_f8bb0 {
    void* vptr; // +0x00
    int data[0x80]; // +0x04 (+0x08)
    Obj_f8bb0* FUN_000f8bb0(hulk_intptr a);
};
// matches/0x000f8c00.cpp (stub C_f8c00), size 0x204
struct C_f8c00 {
    int pad; // +0x00
    int a[128]; // +0x04
    int FUN_000f8c00(hulk_intptr x);
};
// matches/0x000f8c30.cpp (stub Obj_f8c30), size 0x208 (0x410)
struct Obj_f8c30 {
    char pad[4]; // +0x00
    void* items[129]; // +0x04 (+0x08)
    void FUN_000f8c30(const char* name);
};
// matches/0x000f8cc0.cpp (stub Table_f8cc0), size 0x208
struct Table_f8cc0 {
    int pad; // +0x00
    int items[129]; // +0x04
    int FUN_000f8cc0(const char* s);
};
// matches/0x000f8d40.cpp (stub ThisWrap_000f8d40), size 0x1
struct ThisWrap_000f8d40 {
    int FUN_000f8cc0(int a);
    hulk_intptr FUN_000f8d40(int a);
};
// matches/0x000f8d70.cpp (stub Obj), size 0x1
struct Obj_f8d70 {
    hulk_intptr FUN_000f8d70(hulk_intptr);
};
// matches/0x000f92b0.cpp (stub Obj_f92b0), size 0x458
struct Obj_f92b0 {
    char pad[0x458]; // +0x00
    bool FUN_000f92b0(unsigned int, unsigned int, unsigned char*);
};
// matches/0x000f9670.cpp (stub Table_f9670), size 0x1
struct Table_f9670 {
    hulk_intptr FUN_000f9670(int a, int b);
};
// matches/0x000f9700.cpp (stub X_f9700), size 0x14
struct X_f9700 {
    char pad[0x10]; // +0x00
    int count; // +0x10
    void FUN_000f9700(int x);
};
// matches/0x000f9720.cpp (stub Stack_f9720), size 0x14
struct Stack_f9720 {
    char pad[0x10]; // +0x00
    int count; // +0x10
    int FUN_000f9720();
};
// matches/0x000f9b40.cpp (stub Node), size 0x8 (0x10)
struct Node_f9b40 {
    int pad; // +0x00
    Node_f9b40* next; // +0x04 (+0x08)
    void FUN_000f9b40(Node_f9b40* p);
};
// matches/0x000f9e50.cpp (stub ThisWrap_000f9e50), size 0x1
struct ThisWrap_000f9e50 {
    int FUN_000f9d70();
    bool FUN_000f9e50();
};
// equivalent/0x000fb240.cpp (stub Inventory), size 0x1
struct Inventory_fb240 {
    int FUN_000fa4b0(void *item);
    void *FUN_000faf80(int result);
    void * FUN_000fb240(void *item);
};
// matches/0x000fb470.cpp (stub Thing_fb470), size 0x38
struct Thing_fb470 {
    int a[5]; // +0x00
    float value; // +0x14
    char text[32]; // +0x18
    Thing_fb470* FUN_000fb470(const char* s);
};
// matches/0x000fc800.cpp (stub Obj_fc800), size 0x18
struct Obj_fc800 {
    char pad[0x10]; // +0x00
    unsigned char flag10; // +0x10
    char pad11; // +0x11
    unsigned char flag12; // +0x12
    char pad13; // +0x13
    float value; // +0x14
    bool FUN_000fc800();
};
// matches/0x000fc830.cpp (stub C_fc830), size 0x18
struct C_fc830 {
    char pad[0x12]; // +0x00
    unsigned char flag; // +0x12
    char pad2; // +0x13
    float value; // +0x14
    float FUN_000fc830();
};
// matches/0x000fc850.cpp (stub Obj), size 0x18
struct Obj_fc850 {
    char pad[16]; // +0x00
    char a, b, c, d; // +0x10
    float x; // +0x14
    int FUN_000fc850();
};
// matches/0x000fc890.cpp (stub Obj_fc890), size 0x1c
struct Obj_fc890 {
    char pad0[0x10]; // +0x00
    bool flag10; // +0x10
    bool flag11; // +0x11
    bool flag12; // +0x12
    bool flag13; // +0x13
    float threshold; // +0x14
    float value; // +0x18
    float FUN_000fc890();
};
// matches/0x000fc900.cpp (stub X_fc900), size 0x72
struct X_fc900 {
    char pad[0x70]; // +0x00
    unsigned char a; // +0x70
    unsigned char b; // +0x71
    int FUN_000fc900();
};
// matches/0x000fdc80.cpp (stub C_fdc80), size 0x50
struct C_fdc80 {
    char pad[8]; // +0x00
    int count; // +0x08
    char pad2[0x40]; // +0x0c
    int index; // +0x4c
    int FUN_000fdc80();
};
// matches/0x000fdca0.cpp (stub Obj_fdca0), size 0xf0
struct Obj_fdca0 {
    char pad[0xec]; // +0x00
    int value; // +0xec
    int FUN_000fdca0();
};
// matches/0x000fdd30.cpp (stub Container_fdd30), size 0x10
struct Container_fdd30 {
    hulk_intptr FUN_000fdd30(hulk_intptr arg);
    char pad[8]; // +0x00
    int mCount; // +0x08
    int mArray[1]; // +0x0c
};
// matches/0x000fddb0.cpp (stub Obj_fddb0), size 0x44
struct Obj_fddb0 {
    char pad[0x34]; // +0x00
    int zero, a, b, c; // +0x34
    void FUN_000fddb0(int* p);
};
// matches/0x000fddf0.cpp (stub C_fddf0), size 0x74
struct C_fddf0 {
    char pad[0x74]; // +0x00
    void FUN_000fddf0(void* a, unsigned* b);
};
// matches/0x000fde20.cpp (stub C_fde20), size 0x84
struct C_fde20 {
    char pad[0x74]; // +0x00
    int value; // +0x74
    int a; // +0x78
    int b; // +0x7c
    int c; // +0x80
    hulk_intptr FUN_000fde20(int* out);
};
// matches/0x000fde40.cpp (stub C_fde40), size 0x28
struct C_fde40 {
    char pad[0x1c]; // +0x00
    int a; // +0x1c
    int b; // +0x20
    int c; // +0x24
    bool FUN_000fde40(int* out);
};
// matches/0x000fde60.cpp (stub C_fde60), size 0x44
struct C_fde60 {
    char pad[0x38]; // +0x00
    int a, b, c; // +0x38
    bool FUN_000fde60(int* out);
};
// matches/0x000fefa0.cpp (stub C_fefa0), size 0x110
struct C_fefa0 {
    char pad[0x10c]; // +0x00
    int value; // +0x10c
    hulk_intptr FUN_000fefa0();
};
// matches/0x000fefc0.cpp (stub Obj_fefc0), size 0x114
struct Obj_fefc0 {
    char pad[0x110]; // +0x00
    int value; // +0x110
    hulk_intptr FUN_000fefc0();
};
// matches/0x001034b0.cpp (stub Obj_1034b0), size 0x60 (0x68)
struct Obj_1034b0 {
    char pad[0x5c]; // +0x00
    char* p; // +0x5c (+0x60)
    void FUN_001034b0(unsigned char);
};
// matches/0x00106160.cpp (stub Target_106160), size 0x14
struct Target_106160 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    hulk_intptr FUN_00106160(int index);
};
// matches/0x00106170.cpp (stub C_106170), size 0x18 (0x20)
struct C_106170 {
    char pad0[0x10]; // +0x00
    void* items; // +0x10
    int count; // +0x14 (+0x18)
    bool FUN_00106170(int index, int a, int b, int c);
};
// matches/0x00106210.cpp (stub C_106210), size 0x10 (0x18)
struct C_106210 {
    char pad[8]; // +0x00
    int count; // +0x08
    int* values; // +0x0c (+0x10)
    hulk_intptr FUN_00106210(int index);
};
// matches/0x0010b3d0.cpp (stub Obj_10b3d0), size 0x10
struct Obj_10b3d0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_0010b3d0(int v);
};
// matches/0x0010b3e0.cpp (stub A_10b3e0), size 0x10
struct A_10b3e0 {
    char FUN_0010b3e0(int x);
    char m[0x10]; // +0x00
};
// matches/0x0010b3f0.cpp (stub X_10b3f0), size 0x10
struct X_10b3f0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0010b3f0(int v);
};
// matches/0x0010b400.cpp (stub Obj_10b400), size 0x14
struct Obj_10b400 {
    char pad[16]; // +0x00
    int m10; // +0x10
    char FUN_0010b400(int value);
};
// matches/0x0010b580.cpp (stub C_10b580), size 0x1b78
struct C_10b580 {
    char pad[0x1b78]; // +0x00
    void FUN_0010b580(const unsigned int* p);
};
// matches/0x0010c130.cpp (stub Obj_10c130), size 0xd
struct Obj_10c130 {
    char pad[12]; // +0x00
    char value; // +0x0c
    bool FUN_0010c130(char c);
};
// matches/0x0010c180.cpp (stub A_10c180), size 0x10
struct A_10c180 {
    char Pad[12]; // +0x00
    int mVal; // +0x0c
    char FUN_0010c180(int x);
};
// matches/0x0010c1a0.cpp (stub Obj_10c1a0), size 0x10
struct Obj_10c1a0 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    char FUN_0010c1a0(int v);
};
// matches/0x0010c1c0.cpp (stub O_10c1c0), size 0x14
struct O_10c1c0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_0010c1c0(int x);
};
// matches/0x0010c1d0.cpp (stub O_10c1d0), size 0x10
struct O_10c1d0 {
    char FUN_0010c1d0(int v);
    char pad[0xc]; // +0x00
    int m; // +0x0c
};
// matches/0x0010c1f0.cpp (stub Obj_10c1f0), size 0xd
struct Obj_10c1f0 {
    char pad[12]; // +0x00
    char mByte; // +0x0c
    char FUN_0010c1f0(char b);
};
// matches/0x0010c240.cpp (stub O_10c240), size 0xc
struct O_10c240 {
    char m[0xc]; // +0x00
    char FUN_0010c240(int x);
};
// matches/0x0010c250.cpp (stub Obj_10c250), size 0xc
struct Obj_10c250 {
    char m[12]; // +0x00
    char FUN_0010c250(int x);
};
// matches/0x0010c270.cpp (stub X_10c270), size 0x11
struct X_10c270 {
    char pad[0x10]; // +0x00
    unsigned char mX; // +0x10
    unsigned char FUN_0010c270(unsigned char x);
};
// matches/0x0010c330.cpp (stub Obj_10c330), size 0xc
struct Obj_10c330 {
    char FUN_0010c330(int x);
    char pad[12]; // +0x00
};
// matches/0x0010c350.cpp (stub Obj_10c350), size 0x14
struct Obj_10c350 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0010c350(int x);
};
// matches/0x0010c370.cpp (stub Obj_10c370), size 0xd
struct Obj_10c370 {
    char pad[12]; // +0x00
    char mValue; // +0x0c
    char FUN_0010c370(unsigned char x);
};
// matches/0x0010c390.cpp (stub Obj_10c390), size 0xe
struct Obj_10c390 {
    char pad[0xd]; // +0x00
    char v; // +0x0d
    char FUN_0010c390(unsigned char x);
};
// matches/0x0010c3a0.cpp (stub Obj_10c3a0), size 0x10
struct Obj_10c3a0 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    bool FUN_0010c3a0(int v);
};
// matches/0x0010c3b0.cpp (stub Obj_10c3b0), size 0x10
struct Obj_10c3b0 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    unsigned char FUN_0010c3b0(int x);
};
// matches/0x0010c3c0.cpp (stub Obj_10c3c0), size 0x14
struct Obj_10c3c0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0010c3c0(int x);
};
// matches/0x0010c3f0.cpp (stub Obj_10c3f0), size 0x21
struct Obj_10c3f0 {
    char pad[0x20]; // +0x00
    char m20; // +0x20
    char FUN_0010c3f0(char x);
};
// matches/0x0010c410.cpp (stub Obj_10c410), size 0x22
struct Obj_10c410 {
    char pad[0x21]; // +0x00
    char m; // +0x21
    unsigned char FUN_0010c410(unsigned char x);
};
// matches/0x0010c420.cpp (stub X_10c420), size 0x10
struct X_10c420 {
    char m[0xc]; // +0x00
    int value; // +0x0c
    char FUN_0010c420(int v);
};
// matches/0x0010c430.cpp (stub O_10c430), size 0x14
struct O_10c430 {
    char pad[16]; // +0x00
    int m; // +0x10
    char FUN_0010c430(int x);
};
// matches/0x0010c450.cpp (stub Obj_10c450), size 0x15
struct Obj_10c450 {
    char Pad[0x14]; // +0x00
    char m14; // +0x14
    char FUN_0010c450(char x);
};
// matches/0x0010c470.cpp (stub X_10c470), size 0x1c
struct X_10c470 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    bool FUN_0010c470(int v);
};
// matches/0x0010c490.cpp (stub Obj_10c490), size 0x1d
struct Obj_10c490 {
    char pad[0x1c]; // +0x00
    char mVal; // +0x1c
    char FUN_0010c490(char c);
};
// matches/0x0010c4b0.cpp (stub Obj_10c4b0), size 0x1e
struct Obj_10c4b0 {
    char pad[0x1d]; // +0x00
    char value; // +0x1d
    bool FUN_0010c4b0(unsigned char x);
};
// matches/0x0010c4c0.cpp (stub C_10c4c0), size 0x10
struct C_10c4c0 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    char FUN_0010c4c0(int x);
};
// matches/0x0010c560.cpp (stub O_10c560), size 0x10
struct O_10c560 {
    bool FUN_0010c560(int v);
    char pad[0xc]; // +0x00
    int m; // +0x0c
};
// matches/0x0010c590.cpp (stub Obj_10c590), size 0x18
struct Obj_10c590 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    bool FUN_0010c590(int x);
};
// matches/0x0010c5b0.cpp (stub Obj_10c5b0), size 0x1c
struct Obj_10c5b0 {
    char FUN_0010c5b0(int x);
    char pad[0x18]; // +0x00
    int mValue; // +0x18
};
// matches/0x0010c5d0.cpp (stub O_10c5d0), size 0x20
struct O_10c5d0 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    char FUN_0010c5d0(int v);
};
// matches/0x0010c5f0.cpp (stub Obj_10c5f0), size 0x24
struct Obj_10c5f0 {
    char Pad[0x20]; // +0x00
    int value; // +0x20
    char FUN_0010c5f0(int v);
};
// matches/0x0010c680.cpp (stub T_10c680), size 0x10
struct T_10c680 {
    char pad[8]; // +0x00
    char gap[4]; // +0x08
    int m_c; // +0x0c
    bool FUN_0010c680(int a);
};
// matches/0x0010c690.cpp (stub Obj_10c690), size 0x14
struct Obj_10c690 {
    char pad[16]; // +0x00
    int value; // +0x10
    char FUN_0010c690(int x);
};
// matches/0x0010c6a0.cpp (stub Obj_10c6a0), size 0x18
struct Obj_10c6a0 {
    char pad[0x18]; // +0x00
    char* FUN_0010c6a0();
};
// matches/0x0010c6c0.cpp (stub Obj_10c6c0), size 0x21
struct Obj_10c6c0 {
    char pad[0x20]; // +0x00
    char m20; // +0x20
    bool FUN_0010c6c0(char v);
};
// matches/0x0010c6e0.cpp (stub Obj_10c6e0), size 0x22
struct Obj_10c6e0 {
    char pad[0x21]; // +0x00
    char m21; // +0x21
    char FUN_0010c6e0(char c);
};
// matches/0x0010c700.cpp (stub O_10c700), size 0x28
struct O_10c700 {
    char FUN_0010c700(int v);
    char pad[0x24]; // +0x00
    int m24; // +0x24
};
// equivalent/0x0010c9b0.cpp (stub Obj), size 0x14 (0x18)
struct Obj_10c9b0 {
    char pad[0x10]; // +0x00
    char* text; // +0x10
    unsigned int FUN_0010c9b0(const char* value);
};
// matches/0x0010cb00.cpp (stub Obj), size 0x14 (0x18)
struct Obj_10cb00 {
    char pad[16]; // +0x00
    char* s; // +0x10
    char FUN_0010cb00(const char* p);
};
// equivalent/0x0010cd20.cpp (stub Obj), size 0x14 (0x18)
struct Obj_10cd20 {
    char pad[16]; // +0x00
    char* text; // +0x10
    bool FUN_0010cd20(const char* value);
};
// matches/0x00114eb0.cpp (stub Obj_114eb0), size 0xd
struct Obj_114eb0 {
    char pad[12]; // +0x00
    char mVal; // +0x0c
    char FUN_00114eb0(char v);
};
// matches/0x00114ed0.cpp (stub T_114ed0), size 0xe
struct T_114ed0 {
    char pad[13]; // +0x00
    char m; // +0x0d
    char FUN_00114ed0(unsigned char x);
};
// matches/0x00114ee0.cpp (stub Obj), size 0x10
struct Obj_114ee0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    char FUN_00114ee0(int x);
};
// matches/0x00114ef0.cpp (stub A_114ef0), size 0x14
struct A_114ef0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_00114ef0(int value);
};
// matches/0x00114f10.cpp (stub Obj_114f10), size 0x10
struct Obj_114f10 {
    char FUN_00114f10(int v);
    char pad[12]; // +0x00
    int m; // +0x0c
};
// matches/0x00114f30.cpp (stub Obj_114f30), size 0x14 (0x18)
struct Obj_114f30 {
    char pad[0x10]; // +0x00
    void* m; // +0x10
    bool FUN_00114f30(void* p);
};
// matches/0x00114f50.cpp (stub Obj_114f50), size 0x18
struct Obj_114f50 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    char FUN_00114f50(int x);
};
// matches/0x00114f60.cpp (stub Obj_114f60), size 0x1c
struct Obj_114f60 {
    char pad[0x18]; // +0x00
    int mFlag; // +0x18
    bool FUN_00114f60(int v);
};
// matches/0x00114f80.cpp (stub Obj), size 0x1d
struct Obj_114f80 {
    char pad[0x1c]; // +0x00
    unsigned char value; // +0x1c
    unsigned char FUN_00114f80(unsigned char x);
};
// matches/0x00114fa0.cpp (stub Obj_114fa0), size 0x24
struct Obj_114fa0 {
    char pad[0x20]; // +0x00
    int value; // +0x20
    unsigned char FUN_00114fa0(int x);
};
// matches/0x00114fb0.cpp (stub Obj_114fb0), size 0xd
struct Obj_114fb0 {
    char pad[0xc]; // +0x00
    char mValue; // +0x0c
    unsigned char FUN_00114fb0(char value);
};
// matches/0x00114fd0.cpp (stub X_114fd0), size 0xe
struct X_114fd0 {
    char pad[0xd]; // +0x00
    char m; // +0x0d
    char FUN_00114fd0(char arg);
};
// matches/0x00114fe0.cpp (stub X_114fe0), size 0xe
struct X_114fe0 {
    char pad[0xe]; // +0x00
    bool FUN_00114fe0(char c);
};
// matches/0x00115000.cpp (stub Obj_115000), size 0xf
struct Obj_115000 {
    char m[0x0f]; // +0x00
    char FUN_00115000(char v);
};
// matches/0x00115020.cpp (stub Obj_115020), size 0x11
struct Obj_115020 {
    char pad[0x10]; // +0x00
    unsigned char mVal; // +0x10
    unsigned char FUN_00115020(unsigned char arg);
};
// matches/0x00115040.cpp (stub Obj_115040), size 0x11
struct Obj_115040 {
    char m[0x11]; // +0x00
    unsigned char FUN_00115040(char v);
};
// matches/0x00115060.cpp (stub X_115060), size 0x18
struct X_115060 {
    char pad[0x14]; // +0x00
    int m; // +0x14
    bool FUN_00115060(int x);
};
// matches/0x00115080.cpp (stub O_115080), size 0x1c
struct O_115080 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    bool FUN_00115080(int a);
};
// matches/0x00115110.cpp (stub Body_115110), size 0x10
struct Body_115110 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_00115110(int x);
};
// matches/0x00115120.cpp (stub Obj_115120), size 0x14
struct Obj_115120 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_00115120(int value);
};
// matches/0x00115130.cpp (stub Obj_115130), size 0x10
struct Obj_115130 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    char FUN_00115130(int x);
};
// matches/0x00115140.cpp (stub X_115140), size 0x14
struct X_115140 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_00115140(int x);
};
// matches/0x00115160.cpp (stub Obj_115160), size 0x18
struct Obj_115160 {
    char FUN_00115160(float x);
    char pad[0x14]; // +0x00
    float value; // +0x14
};
// matches/0x001151d0.cpp (stub O_1151d0), size 0x28
struct O_1151d0 {
    char Pad[0x24]; // +0x00
    int m24; // +0x24
    char FUN_001151d0(int v);
};
// matches/0x001151e0.cpp (stub Obj_1151e0), size 0x10
struct Obj_1151e0 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    bool FUN_001151e0(int x);
};
// matches/0x001151f0.cpp (stub Obj_1151f0), size 0x14
struct Obj_1151f0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_001151f0(int x);
};
// matches/0x00115210.cpp (stub Obj), size 0x18
struct Obj_115210 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    bool FUN_00115210(int x);
};
// matches/0x00115230.cpp (stub Obj_115230), size 0x1c
struct Obj_115230 {
    char pad[0x18]; // +0x00
    int mVal; // +0x18
    bool FUN_00115230(int v);
};
// matches/0x00115240.cpp (stub X_115240), size 0x20
struct X_115240 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    char FUN_00115240(int);
};
// matches/0x00115250.cpp (stub Obj_115250), size 0x24
struct Obj_115250 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_00115250(int x);
};
// matches/0x00115270.cpp (stub Target_115270), size 0x28
struct Target_115270 {
    char pad[0x24]; // +0x00
    int mValue; // +0x24
    bool FUN_00115270(int x);
};
// matches/0x00115280.cpp (stub C_115280), size 0x2c
struct C_115280 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    bool FUN_00115280(int x);
};
// matches/0x00115290.cpp (stub Obj_115290), size 0x10
struct Obj_115290 {
    char pad[0xc]; // +0x00
    int mVal; // +0x0c
    bool FUN_00115290(int x);
};
// matches/0x001152a0.cpp (stub Obj_1152a0), size 0x14
struct Obj_1152a0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_001152a0(int x);
};
// matches/0x001152c0.cpp (stub C_1152c0), size 0x18
struct C_1152c0 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    char FUN_001152c0(int x);
};
// matches/0x001152e0.cpp (stub O_1152e0), size 0x1c
struct O_1152e0 {
    char m[0x18]; // +0x00
    int m18; // +0x18
    unsigned char FUN_001152e0(int x);
};
// matches/0x00115320.cpp (stub Obj_115320), size 0x24
struct Obj_115320 {
    char Pad[0x20]; // +0x00
    int m20; // +0x20
    char FUN_00115320(int v);
};
// matches/0x00115340.cpp (stub Obj_115340), size 0x28
struct Obj_115340 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    bool FUN_00115340(int v);
};
// matches/0x00115360.cpp (stub X_115360), size 0x29
struct X_115360 {
    char pad[0x28]; // +0x00
    char m; // +0x28
    bool FUN_00115360(char c);
};
// matches/0x00115380.cpp (stub X_115380), size 0x2a
struct X_115380 {
    char m[0x29]; // +0x00
    char m29; // +0x29
    char FUN_00115380(int a);
};
// matches/0x001153a0.cpp (stub X_1153a0), size 0x2b
struct X_1153a0 {
    char pad[0x2a]; // +0x00
    char m2a; // +0x2a
    char FUN_001153a0(char v);
};
// matches/0x001153c0.cpp (stub Obj_1153c0), size 0x2b
struct Obj_1153c0 {
    char m[0x2b]; // +0x00
    char FUN_001153c0(unsigned char value);
};
// matches/0x001153d0.cpp (stub Obj_1153d0), size 0x30
struct Obj_1153d0 {
    char pad[0x30]; // +0x00
    char* FUN_001153d0();
};
// matches/0x001153e0.cpp (stub X_1153e0), size 0x10
struct X_1153e0 {
    char pad[0xc]; // +0x00
    int m1c; // +0x0c
    bool FUN_001153e0(int a);
};
// matches/0x001153f0.cpp (stub X_1153f0), size 0x14
struct X_1153f0 {
    char FUN_001153f0(int v);
    char pad[0x10]; // +0x00
    int mValue; // +0x10
};
// matches/0x00115410.cpp (stub X_115410), size 0x18
struct X_115410 {
    char flag; // +0x00
    char pad[19]; // +0x01
    float radians; // +0x14
    char FUN_00115410(float degrees);
};
// matches/0x00115480.cpp (stub Obj_115480), size 0x28
struct Obj_115480 {
    char pad[0x24]; // +0x00
    int mVal; // +0x24
    bool FUN_00115480(int x);
};
// matches/0x00115490.cpp (stub X_115490), size 0x10
struct X_115490 {
    char FUN_00115490(int x);
    char pad[12]; // +0x00
    int m; // +0x0c
};
// matches/0x001154a0.cpp (stub A_1154a0), size 0x14
struct A_1154a0 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    bool FUN_001154a0(int x);
};
// matches/0x001154c0.cpp (stub X_1154c0), size 0x18
struct X_1154c0 {
    char pad[0x14]; // +0x00
    int member; // +0x14
    bool FUN_001154c0(int x);
};
// matches/0x001154e0.cpp (stub C_1154e0), size 0x1c (0x20)
struct C_1154e0 {
    char pad[0x18]; // +0x00
    void* mPtr; // +0x18
    bool FUN_001154e0(void* p);
};
// matches/0x00115500.cpp (stub Obj_115500), size 0x20
struct Obj_115500 {
    char pad[0x1c]; // +0x00
    int mValue; // +0x1c
    bool FUN_00115500(int v);
};
// matches/0x00115520.cpp (stub Obj_115520), size 0x24
struct Obj_115520 {
    char pad[0x20]; // +0x00
    int mValue; // +0x20
    bool FUN_00115520(int value);
};
// matches/0x00115540.cpp (stub Obj_115540), size 0x28
struct Obj_115540 {
    char pad[0x24]; // +0x00
    int mVal; // +0x24
    bool FUN_00115540(int v);
};
// matches/0x00115550.cpp (stub X_115550), size 0x2c
struct X_115550 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    char FUN_00115550(int v);
};
// matches/0x00115560.cpp (stub X_115560), size 0x10
struct X_115560 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_00115560(int v);
};
// matches/0x00115570.cpp (stub Obj_115570), size 0x14
struct Obj_115570 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_00115570(int a);
};
// matches/0x00115590.cpp (stub C_115590), size 0x18
struct C_115590 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    bool FUN_00115590(int x);
};
// matches/0x001155b0.cpp (stub X_1155b0), size 0x1c
struct X_1155b0 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    char FUN_001155b0(int arg);
};
// matches/0x001155d0.cpp (stub Obj_1155d0), size 0x20
struct Obj_1155d0 {
    bool FUN_001155d0(int v);
    char pad[0x1c]; // +0x00
    int field; // +0x1c
};
// matches/0x001155f0.cpp (stub Obj_1155f0), size 0x24
struct Obj_1155f0 {
    char pad[0x20]; // +0x00
    int value; // +0x20
    bool FUN_001155f0(int v);
};
// matches/0x00115610.cpp (stub Obj_115610), size 0x28
struct Obj_115610 {
    char pad[0x24]; // +0x00
    int m24; // +0x24
    bool FUN_00115610(int v);
};
// matches/0x00115630.cpp (stub C_115630), size 0x29
struct C_115630 {
    char pad[0x28]; // +0x00
    unsigned char m; // +0x28
    unsigned char FUN_00115630(unsigned char x);
};
// matches/0x00115650.cpp (stub Obj_115650), size 0x29
struct Obj_115650 {
    char m[0x29]; // +0x00
    char FUN_00115650(char a);
};
// matches/0x00115670.cpp (stub Obj_115670), size 0x30
struct Obj_115670 {
    char pad[0x2c]; // +0x00
    int mValue; // +0x2c
    bool FUN_00115670(int value);
};
// matches/0x00115690.cpp (stub Obj_115690), size 0x34
struct Obj_115690 {
    char pad[0x30]; // +0x00
    int m; // +0x30
    bool FUN_00115690(int x);
};
// matches/0x0011b810.cpp (stub Obj_11b810), size 0x14
struct Obj_11b810 {
    char pad[0x10]; // +0x00
    int field; // +0x10
    char FUN_0011b810(int x);
};
// matches/0x0011b830.cpp (stub Obj_11b830), size 0x18
struct Obj_11b830 {
    char pad[0x14]; // +0x00
    int mVal; // +0x14
    char FUN_0011b830(int v);
};
// matches/0x0011b850.cpp (stub Obj_11b850), size 0x19
struct Obj_11b850 {
    char pad[0x18]; // +0x00
    char m18; // +0x18
    char FUN_0011b850(unsigned char value);
};
// matches/0x0011b870.cpp (stub C_11b870), size 0x19
struct C_11b870 {
    char m[0x19]; // +0x00
    char FUN_0011b870(char c);
};
// matches/0x0011b890.cpp (stub X_11b890), size 0x1b
struct X_11b890 {
    char pad[0x1a]; // +0x00
    char mValue; // +0x1a
    char FUN_0011b890(char v);
};
// matches/0x0011b8b0.cpp (stub O_11b8b0), size 0x1b
struct O_11b8b0 {
    char p[0x1b]; // +0x00
    unsigned char FUN_0011b8b0(unsigned char x);
};
// matches/0x0011b8d0.cpp (stub X_11b8d0), size 0x1d
struct X_11b8d0 {
    char pad[0x1c]; // +0x00
    char m; // +0x1c
    char FUN_0011b8d0(char c);
};
// matches/0x0011b8f0.cpp (stub X_11b8f0), size 0x1e
struct X_11b8f0 {
    char pad[0x1d]; // +0x00
    unsigned char m1d; // +0x1d
    unsigned char FUN_0011b8f0(unsigned char v);
};
// matches/0x0011b910.cpp (stub X_11b910), size 0x1e
struct X_11b910 {
    char FUN_0011b910(char v);
    char m[0x1e]; // +0x00
};
// matches/0x0011b930.cpp (stub Obj_11b930), size 0x20
struct Obj_11b930 {
    char pad[0x1f]; // +0x00
    char mFlag; // +0x1f
    bool FUN_0011b930(bool x);
};
// matches/0x0011b980.cpp (stub Obj_11b980), size 0x10
struct Obj_11b980 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_0011b980(int v);
};
// matches/0x0011b990.cpp (stub Obj_11b990), size 0x14
struct Obj_11b990 {
    char FUN_0011b990(int value);
    char pad[0x10]; // +0x00
    int m10; // +0x10
};
// matches/0x0011b9a0.cpp (stub Obj), size 0x18
struct Obj_11b9a0 {
    char pad[0x14]; // +0x00
    float angle; // +0x14
    char FUN_0011b9a0(float x);
};
// matches/0x0011b9d0.cpp (stub Obj_11b9d0), size 0x1c
struct Obj_11b9d0 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    bool FUN_0011b9d0(int x);
};
// matches/0x0011b9f0.cpp (stub Obj_11b9f0), size 0x20
struct Obj_11b9f0 {
    char FUN_0011b9f0(int value);
    char pad[0x1c]; // +0x00
    int mValue; // +0x1c
};
// matches/0x0011ba10.cpp (stub Obj_11ba10), size 0x24
struct Obj_11ba10 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_0011ba10(int value);
};
// matches/0x0011ba30.cpp (stub Obj_11ba30), size 0x28
struct Obj_11ba30 {
    char pad[0x24]; // +0x00
    int mVal; // +0x24
    bool FUN_0011ba30(int v);
};
// matches/0x0011ba50.cpp (stub Obj_11ba50), size 0x28
struct Obj_11ba50 {
    char m[0x28]; // +0x00
    char FUN_0011ba50(char a);
};
// matches/0x0011ba70.cpp (stub C_11ba70), size 0x30
struct C_11ba70 {
    char FUN_0011ba70(int x);
    char pad[0x2c]; // +0x00
    int m; // +0x2c
};
// matches/0x0011ba90.cpp (stub Obj_11ba90), size 0x34
struct Obj_11ba90 {
    char Pad[0x30]; // +0x00
    int m30; // +0x30
    char FUN_0011ba90(int x);
};
// matches/0x0011bab0.cpp (stub Obj_11bab0), size 0x38
struct Obj_11bab0 {
    char pad[0x34]; // +0x00
    int value; // +0x34
    bool FUN_0011bab0(int x);
};
// matches/0x0011bac0.cpp (stub X_11bac0), size 0x3c
struct X_11bac0 {
    bool FUN_0011bac0(int value);
    char pad[0x38]; // +0x00
    int m38; // +0x38
};
// matches/0x0011bad0.cpp (stub Obj_11bad0), size 0x10
struct Obj_11bad0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    char FUN_0011bad0(int a);
};
// matches/0x0011bae0.cpp (stub T_11bae0), size 0x14
struct T_11bae0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_0011bae0(int v);
};
// matches/0x0011baf0.cpp (stub X_11baf0), size 0x18
struct X_11baf0 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    bool FUN_0011baf0(int v);
};
// matches/0x0011bb00.cpp (stub X_11bb00), size 0x1c
struct X_11bb00 {
    char pad[0x18]; // +0x00
    float value; // +0x18
    bool FUN_0011bb00(float degrees);
};
// matches/0x0011bb20.cpp (stub Obj_11bb20), size 0x20
struct Obj_11bb20 {
    char pad[0x1c]; // +0x00
    int mValue; // +0x1c
    bool FUN_0011bb20(int v);
};
// matches/0x0011bb30.cpp (stub Obj_11bb30), size 0x24
struct Obj_11bb30 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_0011bb30(int v);
};
// matches/0x0011bb40.cpp (stub Obj_11bb40), size 0x28
struct Obj_11bb40 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    bool FUN_0011bb40(int v);
};
// matches/0x0011bb60.cpp (stub X_11bb60), size 0x2c
struct X_11bb60 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    bool FUN_0011bb60(int v);
};
// matches/0x0011bb80.cpp (stub Obj_11bb80), size 0x30
struct Obj_11bb80 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    bool FUN_0011bb80(int x);
};
// matches/0x0011bba0.cpp (stub Target_11bba0), size 0x34
struct Target_11bba0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0011bba0(int value);
};
// matches/0x0011bbc0.cpp (stub X_11bbc0), size 0x10
struct X_11bbc0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0011bbc0(int arg);
};
// matches/0x0011bbd0.cpp (stub Obj_11bbd0), size 0x14
struct Obj_11bbd0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_0011bbd0(int v);
};
// matches/0x0011bbf0.cpp (stub Obj_11bbf0), size 0x18
struct Obj_11bbf0 {
    char pad[0x14]; // +0x00
    int mVal; // +0x14
    char FUN_0011bbf0(int v);
};
// matches/0x0011bc10.cpp (stub Obj_11bc10), size 0x1c
struct Obj_11bc10 {
    char FUN_0011bc10(float v);
    char pad[0x18]; // +0x00
    float mValue; // +0x18
};
// matches/0x0011bc40.cpp (stub Obj_11bc40), size 0x20
struct Obj_11bc40 {
    char FUN_0011bc40(int x);
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
};
// matches/0x0011bc60.cpp (stub X_11bc60), size 0x24
struct X_11bc60 {
    char pad[0x20]; // +0x00
    int m; // +0x20
    char FUN_0011bc60(int v);
};
// matches/0x0011bc80.cpp (stub Obj_11bc80), size 0x2c
struct Obj_11bc80 {
    char pad[0x24]; // +0x00
    int mValue; // +0x24
    char mFlag; // +0x28
    char FUN_0011bc80(int v);
};
// matches/0x0011bca0.cpp (stub Obj_11bca0), size 0x2c
struct Obj_11bca0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    char FUN_0011bca0(int v);
};
// matches/0x0011bcc0.cpp (stub Obj_11bcc0), size 0x2d
struct Obj_11bcc0 {
    char pad[0x2c]; // +0x00
    char value; // +0x2c
    unsigned char FUN_0011bcc0(unsigned char x);
};
// matches/0x0011bce0.cpp (stub Obj_11bce0), size 0x2e
struct Obj_11bce0 {
    char pad[0x2d]; // +0x00
    char m2d; // +0x2d
    char FUN_0011bce0(char v);
};
// matches/0x0011bd00.cpp (stub Obj_11bd00), size 0x34
struct Obj_11bd00 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0011bd00(int arg);
};
// matches/0x0011bd20.cpp (stub A_11bd20), size 0x38
struct A_11bd20 {
    char FUN_0011bd20(int v);
    char pad[0x33]; // +0x00
    int m34; // +0x34
};
// matches/0x0011bde0.cpp (stub Obj_11bde0), size 0x10
struct Obj_11bde0 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    bool FUN_0011bde0(int v);
};
// matches/0x0011bdf0.cpp (stub Obj_11bdf0), size 0x14
struct Obj_11bdf0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0011bdf0(int v);
};
// matches/0x0011be10.cpp (stub Obj_11be10), size 0x18
struct Obj_11be10 {
    char pad[0x14]; // +0x00
    int mValue; // +0x14
    char FUN_0011be10(int x);
};
// matches/0x0011be30.cpp (stub Obj_11be30), size 0x1c
struct Obj_11be30 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    bool FUN_0011be30(int x);
};
// matches/0x0011be50.cpp (stub Obj_11be50), size 0x20
struct Obj_11be50 {
    char FUN_0011be50(int value);
    char pad[0x1c]; // +0x00
    int mValue; // +0x1c
};
// matches/0x0011be70.cpp (stub Obj_11be70), size 0x24
struct Obj_11be70 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_0011be70(int x);
};
// matches/0x0011be90.cpp (stub X_11be90), size 0x24
struct X_11be90 {
    char pad[0x24]; // +0x00
    char FUN_0011be90(int a);
};
// matches/0x0011bea0.cpp (stub Obj_11bea0), size 0x10
struct Obj_11bea0 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    char FUN_0011bea0(int x);
};
// matches/0x0011beb0.cpp (stub Obj_11beb0), size 0x14
struct Obj_11beb0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_0011beb0(int v);
};
// matches/0x0011bed0.cpp (stub X_11bed0), size 0x18
struct X_11bed0 {
    char FUN_0011bed0(int a);
    char mPad[0x14]; // +0x00
    int m14; // +0x14
};
// matches/0x0011bef0.cpp (stub Obj_11bef0), size 0x1c
struct Obj_11bef0 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    bool FUN_0011bef0(int x);
};
// matches/0x0011bf10.cpp (stub Obj_11bf10), size 0x20
struct Obj_11bf10 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    char FUN_0011bf10(int v);
};
// matches/0x0011bf30.cpp (stub Obj_11bf30), size 0x24
struct Obj_11bf30 {
    char pad[0x20]; // +0x00
    int mX; // +0x20
    char FUN_0011bf30(int v);
};
// matches/0x0011bf50.cpp (stub Obj_11bf50), size 0x28
struct Obj_11bf50 {
    char pad[0x24]; // +0x00
    int mX; // +0x24
    bool FUN_0011bf50(int x);
};
// matches/0x0011bf70.cpp (stub Obj), size 0x2c
struct Obj_11bf70 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    bool FUN_0011bf70(int x);
};
// matches/0x0011bf90.cpp (stub Obj_11bf90), size 0x2d
struct Obj_11bf90 {
    char pad[0x2c]; // +0x00
    char mFlag; // +0x2c
    char FUN_0011bf90(char value);
};
// matches/0x0011bfb0.cpp (stub Obj_11bfb0), size 0x34
struct Obj_11bfb0 {
    char pad[0x30]; // +0x00
    int value; // +0x30
    unsigned char FUN_0011bfb0(int x);
};
// matches/0x0011bfc0.cpp (stub Obj_11bfc0), size 0x35
struct Obj_11bfc0 {
    char pad[0x34]; // +0x00
    char m34; // +0x34
    char FUN_0011bfc0(char c);
};
// matches/0x0011bfd0.cpp (stub X_11bfd0), size 0x10
struct X_11bfd0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    char FUN_0011bfd0(int a);
};
// matches/0x0011bfe0.cpp (stub Obj_11bfe0), size 0x14
struct Obj_11bfe0 {
    char pad[0x10]; // +0x00
    int mVal; // +0x10
    char FUN_0011bfe0(int x);
};
// matches/0x0011c000.cpp (stub Obj_11c000), size 0x18
struct Obj_11c000 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    char FUN_0011c000(int v);
};
// matches/0x0011c010.cpp (stub Obj_11c010), size 0x1c
struct Obj_11c010 {
    char pad[0x18]; // +0x00
    float mValue; // +0x18
    char FUN_0011c010(float f);
};
// matches/0x0011c030.cpp (stub X_11c030), size 0x20
struct X_11c030 {
    char pad[0x1c]; // +0x00
    int value; // +0x1c
    bool FUN_0011c030(int v);
};
// matches/0x0011c040.cpp (stub Obj_11c040), size 0x20
struct Obj_11c040 {
    char pad[0x20]; // +0x00
    char FUN_0011c040(int value);
};
// matches/0x0011c050.cpp (stub Obj_11c050), size 0x28
struct Obj_11c050 {
    char FUN_0011c050(int value);
    char pad[0x24]; // +0x00
    int m24; // +0x24
};
// matches/0x0011c060.cpp (stub Obj_11c060), size 0x2c (0x30)
struct Obj_11c060 {
    char pad[0x28]; // +0x00
    void* mVal; // +0x28
    bool FUN_0011c060(void* v);
};
// matches/0x0011c070.cpp (stub Obj_11c070), size 0x30
struct Obj_11c070 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    bool FUN_0011c070(int x);
};
// matches/0x0011c080.cpp (stub Obj_11c080), size 0x34
struct Obj_11c080 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0011c080(int x);
};
// matches/0x0011c0a0.cpp (stub Obj_11c0a0), size 0x38
struct Obj_11c0a0 {
    char pad[0x34]; // +0x00
    int mVal; // +0x34
    char FUN_0011c0a0(int v);
};
// matches/0x0011c0d0.cpp (stub Obj_11c0d0), size 0x3d
struct Obj_11c0d0 {
    char pad[0x3c]; // +0x00
    char m3c; // +0x3c
    char FUN_0011c0d0(char c);
};
// matches/0x0011c0f0.cpp (stub X_11c0f0), size 0x3e
struct X_11c0f0 {
    char pad[0x3d]; // +0x00
    char field; // +0x3d
    char FUN_0011c0f0(int v);
};
// matches/0x0011c120.cpp (stub Obj_11c120), size 0x49
struct Obj_11c120 {
    char pad[0x48]; // +0x00
    unsigned char field; // +0x48
    unsigned char FUN_0011c120(unsigned char value);
};
// matches/0x0011c140.cpp (stub O_11c140), size 0x4a
struct O_11c140 {
    char pad[0x49]; // +0x00
    char value; // +0x49
    char FUN_0011c140(char v);
};
// matches/0x0011c160.cpp (stub Obj_11c160), size 0x50
struct Obj_11c160 {
    char pad[0x4c]; // +0x00
    int value; // +0x4c
    bool FUN_0011c160(int x);
};
// matches/0x0011c180.cpp (stub A_11c180), size 0x54
struct A_11c180 {
    char pad[0x50]; // +0x00
    int mValue; // +0x50
    bool FUN_0011c180(int v) throw();
};
// matches/0x0011c1a0.cpp (stub Obj_11c1a0), size 0x58
struct Obj_11c1a0 {
    char pad[0x54]; // +0x00
    int field; // +0x54
    char FUN_0011c1a0(int v);
};
// matches/0x0011c1c0.cpp (stub Obj_11c1c0), size 0x5c
struct Obj_11c1c0 {
    char pad[0x58]; // +0x00
    int value; // +0x58
    bool FUN_0011c1c0(int v);
};
// matches/0x0011c1e0.cpp (stub X_11c1e0), size 0x5c
struct X_11c1e0 {
    char m[0x5c]; // +0x00
    bool FUN_0011c1e0(int v);
};
// equivalent/0x0011c290.cpp (stub Object), size 0x10 (0x18)
struct Object_11c290 {
    char pad[12]; // +0x00
    char *text; // +0x0c (+0x10)
    int FUN_0011c290(const char *source);
};
// matches/0x0011c470.cpp (stub Obj), size 0x38 (0x40)
struct Obj_11c470 {
    char pad[0x34]; // +0x00
    char* str; // +0x34 (+0x38)
    char FUN_0011c470(const char* s);
};
// matches/0x0011c870.cpp (stub Obj), size 0x3c (0x40)
struct Obj_11c870 {
    char pad[0x38]; // +0x00
    char* str; // +0x38
    char FUN_0011c870(const char* s);
};
// matches/0x00123510.cpp (stub T_123510), size 0xd
struct T_123510 {
    char pad[12]; // +0x00
    unsigned char flag; // +0x0c
    unsigned char FUN_00123510(void* p);
};
// matches/0x00123520.cpp (stub X_123520), size 0x14
struct X_123520 {
    char FUN_00123520(int a);
    char pad[0x10]; // +0x00
    int m_10; // +0x10
};
// matches/0x00123530.cpp (stub O_123530), size 0x10
struct O_123530 {
    char m[0xc]; // +0x00
    float mValue; // +0x0c
    char FUN_00123530(float v);
};
// matches/0x00123550.cpp (stub Obj_123550), size 0x14
struct Obj_123550 {
    char pad[0x10]; // +0x00
    float mAngle; // +0x10
    char FUN_00123550(float deg);
};
// matches/0x00123580.cpp (stub Obj_123580), size 0x15
struct Obj_123580 {
    char FUN_00123580(char value);
    char mPad[0x14]; // +0x00
    char mValue; // +0x14
};
// matches/0x00123590.cpp (stub X_123590), size 0x18
struct X_123590 {
    char pad[0x18]; // +0x00
    void* FUN_00123590();
};
// matches/0x001235f0.cpp (stub X_1235f0), size 0x2d
struct X_1235f0 {
    char pad[0x2c]; // +0x00
    unsigned char m2c; // +0x2c
    unsigned char FUN_001235f0(unsigned char v);
};
// matches/0x00123680.cpp (stub C_123680), size 0x10
struct C_123680 {
    char pad[0xc]; // +0x00
    int m12; // +0x0c
    char FUN_00123680(int a);
};
// matches/0x00123690.cpp (stub Thing), size 0x14
struct Thing_123690 {
    char pad[16]; // +0x00
    float radians; // +0x10
    char FUN_00123690(float a);
};
// matches/0x001236b0.cpp (stub Obj_1236b0), size 0x10
struct Obj_1236b0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    unsigned char FUN_001236b0(int x);
};
// matches/0x001236c0.cpp (stub Obj_1236c0), size 0x14
struct Obj_1236c0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_001236c0(int x);
};
// matches/0x001236d0.cpp (stub O_1236d0), size 0x10
struct O_1236d0 {
    char pad[0xc]; // +0x00
    int m1c; // +0x0c
    bool FUN_001236d0(int x);
};
// matches/0x001236e0.cpp (stub Obj_1236e0), size 0x14
struct Obj_1236e0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_001236e0(int a);
};
// matches/0x001236f0.cpp (stub Obj_1236f0), size 0x15
struct Obj_1236f0 {
    char pad[20]; // +0x00
    char m14; // +0x14
    unsigned char FUN_001236f0(unsigned char a);
};
// matches/0x00123710.cpp (stub Obj_123710), size 0x16
struct Obj_123710 {
    char pad[0x15]; // +0x00
    char m15; // +0x15
    char FUN_00123710(unsigned char value);
};
// matches/0x00123730.cpp (stub X_123730), size 0x16
struct X_123730 {
    char pad[0x16]; // +0x00
    char FUN_00123730(char c);
};
// matches/0x00123740.cpp (stub Obj_123740), size 0xc
struct Obj_123740 {
    char Pad[0xc]; // +0x00
    char FUN_00123740(float x);
};
// matches/0x00123760.cpp (stub X), size 0x14
struct X_123760 {
    char pad[16]; // +0x00
    float angle; // +0x10
    char FUN_00123760(float x);
};
// matches/0x001237e0.cpp (stub Obj_1237e0), size 0xd
struct Obj_1237e0 {
    char pad[12]; // +0x00
    char mValue; // +0x0c
    bool FUN_001237e0(char v);
};
// matches/0x001237f0.cpp (stub X_1237f0), size 0x1
struct X_1237f0 {
    bool FUN_001237f0(int a);
};
// matches/0x00123800.cpp (stub Obj_123800), size 0x14
struct Obj_123800 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_00123800(int v);
};
// matches/0x00123810.cpp (stub Obj_123810), size 0x10
struct Obj_123810 {
    char m_pad[12]; // +0x00
    int mValue; // +0x0c
    char FUN_00123810(int v);
};
// matches/0x00123820.cpp (stub X_123820), size 0x14
struct X_123820 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_00123820(int v);
};
// matches/0x001238d0.cpp (stub Obj_1238d0), size 0x10
struct Obj_1238d0 {
    char pad[12]; // +0x00
    unsigned int value; // +0x0c
    bool FUN_001238d0(unsigned int v);
};
// matches/0x001238e0.cpp (stub Obj_1238e0), size 0x14
struct Obj_1238e0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_001238e0(int v);
};
// matches/0x001238f0.cpp (stub Obj_1238f0), size 0x10
struct Obj_1238f0 {
    char pad[0xc]; // +0x00
    int mVal; // +0x0c
    bool FUN_001238f0(int v);
};
// matches/0x00123900.cpp (stub X_123900), size 0x14
struct X_123900 {
    char pad[16]; // +0x00
    int m10; // +0x10
    bool FUN_00123900(int value);
};
// matches/0x00123910.cpp (stub Obj_123910), size 0xd
struct Obj_123910 {
    char pad[0xc]; // +0x00
    unsigned char m; // +0x0c
    unsigned char FUN_00123910(unsigned char x);
};
// matches/0x00123920.cpp (stub Thing_123920), size 0xd
struct Thing_123920 {
    char Pad[12]; // +0x00
    char mVal; // +0x0c
    char FUN_00123920(char c);
};
// matches/0x00123930.cpp (stub Obj_123930), size 0xd
struct Obj_123930 {
    char pad[0xc]; // +0x00
    unsigned char value; // +0x0c
    char FUN_00123930(unsigned char v);
};
// matches/0x00123950.cpp (stub O_123950), size 0xe
struct O_123950 {
    char pad[13]; // +0x00
    char m; // +0x0d
    bool FUN_00123950(unsigned char b);
};
// matches/0x00123960.cpp (stub Obj), size 0x10
struct Obj_123960 {
    char pad[12]; // +0x00
    int value; // +0x0c
    char FUN_00123960(int x);
};
// matches/0x00123980.cpp (stub Obj_123980), size 0x11
struct Obj_123980 {
    char pad[0x10]; // +0x00
    char m; // +0x10
    unsigned char FUN_00123980(unsigned char x);
};
// matches/0x00123990.cpp (stub Obj_123990), size 0x10
struct Obj_123990 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    char FUN_00123990(int x);
};
// matches/0x001239a0.cpp (stub O_1239a0), size 0x14
struct O_1239a0 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    bool FUN_001239a0(int a);
};
// matches/0x001239c0.cpp (stub Obj_1239c0), size 0x18
struct Obj_1239c0 {
    char pad[0x14]; // +0x00
    float mAngle; // +0x14
    char FUN_001239c0(float value);
};
// matches/0x001239f0.cpp (stub Obj_1239f0), size 0x1c
struct Obj_1239f0 {
    char pad[0x18]; // +0x00
    int mVal; // +0x18
    bool FUN_001239f0(int x);
};
// matches/0x00123a10.cpp (stub Obj_123a10), size 0x1d
struct Obj_123a10 {
    char pad[0x1c]; // +0x00
    unsigned char m1c; // +0x1c
    unsigned char FUN_00123a10(unsigned char v);
};
// matches/0x00124500.cpp (stub X_124500), size 0x1d60
struct X_124500 {
    char pad[0x1d54]; // +0x00
    int a; // +0x1d54
    int b; // +0x1d58
    int c; // +0x1d5c
    void FUN_00124500(int* out);
};
// matches/0x0012b260.cpp (stub T_12b260), size 0x10
struct T_12b260 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0012b260(int x);
};
// matches/0x0012b270.cpp (stub X_12b270), size 0x14
struct X_12b270 {
    char pad[0x10]; // +0x00
    int mThing; // +0x10
    bool FUN_0012b270(int value);
};
// matches/0x0012b280.cpp (stub Obj_12b280), size 0x10
struct Obj_12b280 {
    char pad[0xc]; // +0x00
    int mVal; // +0x0c
    bool FUN_0012b280(int x);
};
// matches/0x0012b290.cpp (stub X_12b290), size 0x14
struct X_12b290 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    char FUN_0012b290(int v);
};
// matches/0x0012b2b0.cpp (stub Obj_12b2b0), size 0x18
struct Obj_12b2b0 {
    char FUN_0012b2b0(int x);
    char pad[0x14]; // +0x00
    int m14; // +0x14
};
// matches/0x0012b320.cpp (stub Target_12b320), size 0x30
struct Target_12b320 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    unsigned char FUN_0012b320(int v);
};
// matches/0x0012b330.cpp (stub Obj_12b330), size 0x30
struct Obj_12b330 {
    char pad[0x30]; // +0x00
    char* FUN_0012b330();
};
// matches/0x0012b340.cpp (stub Obj_12b340), size 0x10
struct Obj_12b340 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    bool FUN_0012b340(int x);
};
// matches/0x0012b350.cpp (stub X_12b350), size 0x14
struct X_12b350 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_0012b350(int v);
};
// matches/0x0012b370.cpp (stub O_12b370), size 0x18
struct O_12b370 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    bool FUN_0012b370(int x);
};
// matches/0x0012b390.cpp (stub Obj_12b390), size 0x19
struct Obj_12b390 {
    char pad[0x18]; // +0x00
    char m; // +0x18
    bool FUN_0012b390(char c);
};
// matches/0x0012b3a0.cpp (stub X_12b3a0), size 0x20
struct X_12b3a0 {
    char pad[0x20]; // +0x00
    void* FUN_0012b3a0();
};
// matches/0x0012e0a0.cpp (stub A_12e0a0), size 0x10
struct A_12e0a0 {
    bool FUN_0012e0a0(int value);
    char pad[12]; // +0x00
    int mValue; // +0x0c
};
// matches/0x0012e100.cpp (stub Obj_12e100), size 0x10
struct Obj_12e100 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    char FUN_0012e100(int v);
};
// matches/0x0012e130.cpp (stub X_12e130), size 0x18
struct X_12e130 {
    char FUN_0012e130(int v);
    char pad[0x18]; // +0x00
};
// matches/0x0012e170.cpp (stub Obj_12e170), size 0x25
struct Obj_12e170 {
    char FUN_0012e170(char c);
    char pad[0x24]; // +0x00
    char m24; // +0x24
};
// matches/0x0012e1c0.cpp (stub Obj_12e1c0), size 0x10
struct Obj_12e1c0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    char FUN_0012e1c0(int v);
};
// matches/0x0012e1e0.cpp (stub Obj_12e1e0), size 0x10
struct Obj_12e1e0 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    bool FUN_0012e1e0(int v);
};
// matches/0x0012e220.cpp (stub C_12e220), size 0x14
struct C_12e220 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0012e220(int v);
};
// equivalent/0x0012e5c0.cpp (stub Object), size 0x10 (0x18)
struct Object_12e5c0 {
    char pad[12]; // +0x00
    char* name; // +0x0c (+0x10)
    bool FUN_0012e5c0(const char* text);
};
// equivalent/0x0012e620.cpp (stub C), size 0x14 (0x18)
struct C_12e620 {
    char pad[0x10]; // +0x00
    char* text; // +0x10
    bool FUN_0012e620(const char* value);
};
// equivalent/0x0012ec20.cpp (stub Object), size 0x18 (0x20)
struct Object_12ec20 {
    char pad[0x14]; // +0x00
    char* text; // +0x14 (+0x18)
    bool FUN_0012ec20(const char* input);
};
// equivalent/0x0012ec80.cpp (stub Item), size 0x20 (0x28)
struct Item_12ec80 {
    char pad[0x1c]; // +0x00
    char *text; // +0x1c (+0x20)
    hulk_intptr FUN_0012ec80(const char *source);
};
// equivalent/0x0012ece0.cpp (stub Thing), size 0x24 (0x28)
struct Thing_12ece0 {
    char pad[0x20]; // +0x00
    char* text; // +0x20
    unsigned char FUN_0012ece0(const char* value);
};
// equivalent/0x0012ef40.cpp (stub Object), size 0x14 (0x18)
struct Object_12ef40 {
    char pad[16]; // +0x00
    char* value; // +0x10
    unsigned int FUN_0012ef40(const char* text);
};
// matches/0x00133010.cpp (stub Obj_133010), size 0x10
struct Obj_133010 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    char FUN_00133010(int v);
};
// matches/0x00133020.cpp (stub Obj_133020), size 0x14
struct Obj_133020 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_00133020(int v);
};
// matches/0x00133040.cpp (stub Obj_133040), size 0x18
struct Obj_133040 {
    char pad[0x14]; // +0x00
    int mValue; // +0x14
    bool FUN_00133040(int v);
};
// matches/0x00133060.cpp (stub Obj_133060), size 0x1c
struct Obj_133060 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    bool FUN_00133060(int v);
};
// matches/0x00133080.cpp (stub X_133080), size 0x20
struct X_133080 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    unsigned char FUN_00133080(int value);
};
// matches/0x001330a0.cpp (stub X_1330a0), size 0x24
struct X_1330a0 {
    char pad[0x20]; // +0x00
    int mVal; // +0x20
    char FUN_001330a0(int p);
};
// matches/0x001330f0.cpp (stub Obj_1330f0), size 0x10
struct Obj_1330f0 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    char FUN_001330f0(int x);
};
// matches/0x00133100.cpp (stub Obj_133100), size 0x14
struct Obj_133100 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_00133100(int v);
};
// matches/0x00133120.cpp (stub Obj_133120), size 0x18
struct Obj_133120 {
    char FUN_00133120(int v);
    char pad[0x14]; // +0x00
    int m14; // +0x14
};
// matches/0x00133140.cpp (stub C_133140), size 0x18
struct C_133140 {
    char FUN_00133140(int x);
    char pad[0x18]; // +0x00
};
// matches/0x00133180.cpp (stub Obj_133180), size 0x20
struct Obj_133180 {
    char pad[0x20]; // +0x00
    char FUN_00133180(int v);
};
// matches/0x001331a0.cpp (stub Obj_1331a0), size 0x24
struct Obj_1331a0 {
    char pad[0x24]; // +0x00
    bool FUN_001331a0(int v);
};
// matches/0x001331c0.cpp (stub Obj_1331c0), size 0x2c
struct Obj_1331c0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    char FUN_001331c0(int v);
};
// matches/0x001331e0.cpp (stub Obj_1331e0), size 0x30
struct Obj_1331e0 {
    char pad[0x2c]; // +0x00
    int mVal; // +0x2c
    bool FUN_001331e0(int v);
};
// matches/0x001331f0.cpp (stub Obj_1331f0), size 0x10
struct Obj_1331f0 {
    char Pad[12]; // +0x00
    int mField; // +0x0c
    char FUN_001331f0(int value);
};
// matches/0x00133200.cpp (stub Obj_133200), size 0x14
struct Obj_133200 {
    char Pad[0x10]; // +0x00
    int Value; // +0x10
    char FUN_00133200(int v);
};
// matches/0x00133220.cpp (stub Obj_133220), size 0x18
struct Obj_133220 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    bool FUN_00133220(int x);
};
// matches/0x00133240.cpp (stub Obj_133240), size 0x1c
struct Obj_133240 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    bool FUN_00133240(int x);
};
// matches/0x00133260.cpp (stub X_133260), size 0x20
struct X_133260 {
    char FUN_00133260(int value);
    char mPad[0x1c]; // +0x00
    int mValue; // +0x1c
};
// matches/0x00133280.cpp (stub Obj_133280), size 0x24
struct Obj_133280 {
    char pad[0x20]; // +0x00
    int mVal; // +0x20
    bool FUN_00133280(int x);
};
// matches/0x001332a0.cpp (stub Thing_1332a0), size 0x28
struct Thing_1332a0 {
    char Pad[0x24]; // +0x00
    float mAngle; // +0x24
    char FUN_001332a0(float a);
};
// matches/0x001332d0.cpp (stub Obj_1332d0), size 0x2c
struct Obj_1332d0 {
    char pad[0x28]; // +0x00
    int mVal; // +0x28
    char FUN_001332d0(int v);
};
// matches/0x001332f0.cpp (stub Obj_1332f0), size 0x30
struct Obj_1332f0 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    bool FUN_001332f0(int v);
};
// matches/0x00133310.cpp (stub X_133310), size 0x34
struct X_133310 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    char FUN_00133310(int v);
};
// matches/0x00133320.cpp (stub Obj_133320), size 0x10
struct Obj_133320 {
    char FUN_00133320(int v);
    char pad[12]; // +0x00
    int value; // +0x0c
};
// matches/0x00133330.cpp (stub Obj_133330), size 0x14
struct Obj_133330 {
    char pad[16]; // +0x00
    int m; // +0x10
    char FUN_00133330(int v);
};
// matches/0x00133350.cpp (stub X_133350), size 0x18
struct X_133350 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    unsigned char FUN_00133350(int x);
};
// matches/0x00133370.cpp (stub Obj_133370), size 0x1c
struct Obj_133370 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    bool FUN_00133370(int x);
};
// matches/0x00133390.cpp (stub Obj_133390), size 0x20
struct Obj_133390 {
    char pad[0x1c]; // +0x00
    int value; // +0x1c
    unsigned char FUN_00133390(int x);
};
// matches/0x001333b0.cpp (stub Obj_1333b0), size 0x24
struct Obj_1333b0 {
    char pad[0x20]; // +0x00
    int mValue; // +0x20
    bool FUN_001333b0(int x);
};
// matches/0x001333d0.cpp (stub Obj), size 0x28
struct Obj_1333d0 {
    char pad[0x24]; // +0x00
    float angle; // +0x24
    bool FUN_001333d0(float x);
};
// matches/0x00133400.cpp (stub X_133400), size 0x2c
struct X_133400 {
    char pad[0x28]; // +0x00
    int m; // +0x28
    bool FUN_00133400(int);
};
// matches/0x00133420.cpp (stub Obj_133420), size 0x30
struct Obj_133420 {
    char pad[0x2c]; // +0x00
    int mFlag; // +0x2c
    bool FUN_00133420(int x) throw();
};
// matches/0x00133440.cpp (stub Obj_133440), size 0x34
struct Obj_133440 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    char FUN_00133440(int v);
};
// matches/0x00133460.cpp (stub Obj_133460), size 0x38
struct Obj_133460 {
    char pad[0x34]; // +0x00
    int value; // +0x34
    bool FUN_00133460(int x);
};
// matches/0x001334b0.cpp (stub Obj_1334b0), size 0x10
struct Obj_1334b0 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    bool FUN_001334b0(int value);
};
// matches/0x001334c0.cpp (stub Obj_1334c0), size 0x14
struct Obj_1334c0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_001334c0(int a);
};
// matches/0x001334e0.cpp (stub Obj_1334e0), size 0x1
struct Obj_1334e0 {
    char FUN_001334e0(float x);
};
// matches/0x00133510.cpp (stub Obj_133510), size 0x1c
struct Obj_133510 {
    char FUN_00133510(int v);
    char pad[24]; // +0x00
    int m18; // +0x18
};
// matches/0x00133530.cpp (stub Obj_133530), size 0x20
struct Obj_133530 {
    char pad[0x1c]; // +0x00
    float f; // +0x1c
    char FUN_00133530(float x);
};
// matches/0x00133560.cpp (stub Obj_133560), size 0x24
struct Obj_133560 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    char FUN_00133560(int v);
};
// matches/0x00133580.cpp (stub Obj_133580), size 0x26
struct Obj_133580 {
    char pad[0x24]; // +0x00
    char m24; // +0x24
    unsigned char m25; // +0x25
    char FUN_00133580(unsigned char v);
};
// matches/0x001335e0.cpp (stub Obj_1335e0), size 0x38
struct Obj_1335e0 {
    char Pad[0x34]; // +0x00
    int m34; // +0x34
    char FUN_001335e0(int value);
};
// matches/0x00133620.cpp (stub T_133620), size 0x3d
struct T_133620 {
    char pad[0x3c]; // +0x00
    char m3c; // +0x3c
    char FUN_00133620(char c);
};
// matches/0x00133640.cpp (stub Obj_133640), size 0x44
struct Obj_133640 {
    char pad[0x40]; // +0x00
    int mValue; // +0x40
    bool FUN_00133640(int v);
};
// matches/0x00133660.cpp (stub Obj_133660), size 0x1
struct Obj_133660 {
    char FUN_00133660(int a);
};
// matches/0x00133680.cpp (stub O_133680), size 0x4c
struct O_133680 {
    char pad[0x48]; // +0x00
    int m; // +0x48
    bool FUN_00133680(int x);
};
// matches/0x00133690.cpp (stub X_133690), size 0x10 (0x18)
struct X_133690 {
    char pad[12]; // +0x00
    void* m1c; // +0x0c (+0x10)
    bool FUN_00133690(void* p);
};
// matches/0x001336a0.cpp (stub O_1336a0), size 0x14
struct O_1336a0 {
    char pad[0x10]; // +0x00
    int mField; // +0x10
    bool FUN_001336a0(int a);
};
// matches/0x001336c0.cpp (stub Obj_1336c0), size 0x18
struct Obj_1336c0 {
    char pad[0x14]; // +0x00
    float mAngle; // +0x14
    bool FUN_001336c0(float v);
};
// matches/0x00133700.cpp (stub Obj_133700), size 0x24
struct Obj_133700 {
    char pad[0x18]; // +0x00
    int a; // +0x18
    int b; // +0x1c
    int c; // +0x20
    bool FUN_00133700(int* x);
};
// matches/0x00133730.cpp (stub X_133730), size 0x28
struct X_133730 {
    char FUN_00133730(int a);
    char pad[0x24]; // +0x00
    int m24; // +0x24
};
// matches/0x00133750.cpp (stub Obj), size 0x2c
struct Obj_133750 {
    char pad[0x28]; // +0x00
    float angle; // +0x28
    char FUN_00133750(float a);
};
// matches/0x00133780.cpp (stub X_133780), size 0x30
struct X_133780 {
    char pad[0x2c]; // +0x00
    int mVal; // +0x2c
    bool FUN_00133780(int v);
};
// matches/0x001337a0.cpp (stub C_1337a0), size 0x30
struct C_1337a0 {
    char pad[0x30]; // +0x00
    char FUN_001337a0(int x);
};
// matches/0x001337c0.cpp (stub Obj_1337c0), size 0x38
struct Obj_1337c0 {
    char pad[0x34]; // +0x00
    int m34; // +0x34
    bool FUN_001337c0(int x);
};
// matches/0x001337e0.cpp (stub Obj_1337e0), size 0x3c
struct Obj_1337e0 {
    char pad[0x38]; // +0x00
    int m38; // +0x38
    char FUN_001337e0(int x);
};
// matches/0x001337f0.cpp (stub Obj_1337f0), size 0x10
struct Obj_1337f0 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    bool FUN_001337f0(int v);
};
// matches/0x00133800.cpp (stub X_133800), size 0x14
struct X_133800 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_00133800(int v);
};
// matches/0x00133860.cpp (stub Obj_133860), size 0x24
struct Obj_133860 {
    char Pad[0x20]; // +0x00
    int Value; // +0x20
    char FUN_00133860(int v);
};
// matches/0x00133880.cpp (stub Obj_133880), size 0x28
struct Obj_133880 {
    char pad[0x24]; // +0x00
    int mValue; // +0x24
    char FUN_00133880(int x);
};
// matches/0x001338a0.cpp (stub Obj_1338a0), size 0x2c
struct Obj_1338a0 {
    char mFlag; // +0x00
    char pad[0x27]; // +0x01
    int m28; // +0x28
    char FUN_001338a0(int x);
};
// matches/0x001338c0.cpp (stub O_1338c0), size 0x30
struct O_1338c0 {
    char m[0x2c]; // +0x00
    float value; // +0x2c
    char FUN_001338c0(float f);
};
// matches/0x001338f0.cpp (stub X_1338f0), size 0x31
struct X_1338f0 {
    char pad[0x30]; // +0x00
    char m30; // +0x30
    unsigned char FUN_001338f0(char b);
};
// matches/0x00133910.cpp (stub X_133910), size 0x38
struct X_133910 {
    bool FUN_00133910(int v);
    char pad[0x34]; // +0x00
    int m34; // +0x34
};
// matches/0x00133930.cpp (stub Obj_133930), size 0x3c
struct Obj_133930 {
    char FUN_00133930(int a);
    char pad[0x38]; // +0x00
    int m38; // +0x38
};
// matches/0x00133950.cpp (stub O_133950), size 0x40
struct O_133950 {
    char pad[0x3c]; // +0x00
    int mVal; // +0x3c
    char FUN_00133950(int v);
};
// matches/0x001399d0.cpp (stub Obj_1399d0), size 0x10
struct Obj_1399d0 {
    char pad[0x10]; // +0x00
    void* FUN_001399d0();
};
// matches/0x001399e0.cpp (stub X_1399e0), size 0x1c
struct X_1399e0 {
    char FUN_001399e0(int a);
    char pad[0x18]; // +0x00
    int m18; // +0x18
};
// matches/0x00139a30.cpp (stub C_139a30), size 0x10
struct C_139a30 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    bool FUN_00139a30(int x);
};
// matches/0x00139a40.cpp (stub S_139a40), size 0x14
struct S_139a40 {
    char pad[16]; // +0x00
    int m; // +0x10
    char FUN_00139a40(int x);
};
// matches/0x00139a70.cpp (stub X_139a70), size 0x24
struct X_139a70 {
    char pad[0x20]; // +0x00
    int value; // +0x20
    bool FUN_00139a70(int x);
};
// matches/0x00139a90.cpp (stub Obj_139a90), size 0x28
struct Obj_139a90 {
    char pad[0x24]; // +0x00
    int m24; // +0x24
    bool FUN_00139a90(int value);
};
// matches/0x00139ab0.cpp (stub X_139ab0), size 0x2c
struct X_139ab0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    bool FUN_00139ab0(int v);
};
// matches/0x00139ad0.cpp (stub Obj_139ad0), size 0x30
struct Obj_139ad0 {
    char pad[0x2c]; // +0x00
    int m; // +0x2c
    char FUN_00139ad0(int v);
};
// matches/0x00139af0.cpp (stub Obj_139af0), size 0x34
struct Obj_139af0 {
    char pad[0x30]; // +0x00
    int m; // +0x30
    char FUN_00139af0(int x);
};
// matches/0x00139b10.cpp (stub Obj_139b10), size 0x35
struct Obj_139b10 {
    char pad[0x34]; // +0x00
    char m34; // +0x34
    char FUN_00139b10(char b);
};
// matches/0x00139b20.cpp (stub X_139b20), size 0x38
struct X_139b20 {
    char pad[0x38]; // +0x00
    void* FUN_00139b20();
};
// matches/0x00139b40.cpp (stub Obj_139b40), size 0x44
struct Obj_139b40 {
    char pad[0x40]; // +0x00
    int value; // +0x40
    char FUN_00139b40(int x);
};
// matches/0x00139b60.cpp (stub Obj_139b60), size 0x48
struct Obj_139b60 {
    char pad[0x44]; // +0x00
    int m44; // +0x44
    char FUN_00139b60(int v);
};
// matches/0x00139b80.cpp (stub Obj_139b80), size 0x4c
struct Obj_139b80 {
    char pad[0x48]; // +0x00
    int mField; // +0x48
    bool FUN_00139b80(int x);
};
// matches/0x00139b90.cpp (stub S_139b90), size 0x10
struct S_139b90 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    char FUN_00139b90(int v);
};
// matches/0x00139ba0.cpp (stub Obj_139ba0), size 0x14
struct Obj_139ba0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_00139ba0(int x);
};
// matches/0x00139bd0.cpp (stub Obj_139bd0), size 0x24
struct Obj_139bd0 {
    char pad[0x20]; // +0x00
    unsigned int mValue; // +0x20
    bool FUN_00139bd0(unsigned int v);
};
// matches/0x00139bf0.cpp (stub Obj_139bf0), size 0x28
struct Obj_139bf0 {
    char pad[0x24]; // +0x00
    int m24; // +0x24
    bool FUN_00139bf0(int v);
};
// matches/0x00139c00.cpp (stub X_139c00), size 0x28
struct X_139c00 {
    char pad[0x28]; // +0x00
    void* FUN_00139c00();
};
// matches/0x00139c20.cpp (stub T_139c20), size 0x34
struct T_139c20 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_00139c20(int v);
};
// matches/0x00139c40.cpp (stub C_139c40), size 0x38
struct C_139c40 {
    char pad[0x34]; // +0x00
    int mValue; // +0x34
    char FUN_00139c40(int v);
};
// matches/0x00139c60.cpp (stub X_139c60), size 0x3c
struct X_139c60 {
    char FUN_00139c60(int v);
    char pad[0x37]; // +0x00
    int m38; // +0x38
};
// matches/0x00139c70.cpp (stub Obj_139c70), size 0x10
struct Obj_139c70 {
    char pad[12]; // +0x00
    int m1c; // +0x0c
    bool FUN_00139c70(int v);
};
// matches/0x00139c80.cpp (stub Obj_139c80), size 0x10
struct Obj_139c80 {
    char m[0x10]; // +0x00
    char FUN_00139c80(int x);
};
// matches/0x00139c90.cpp (stub Obj_139c90), size 0x18
struct Obj_139c90 {
    char pad[0x18]; // +0x00
    char* FUN_00139c90();
};
// matches/0x00139cb0.cpp (stub Obj_139cb0), size 0x24
struct Obj_139cb0 {
    char pad[0x20]; // +0x00
    int mField; // +0x20
    bool FUN_00139cb0(int value);
};
// matches/0x00139cd0.cpp (stub Obj_139cd0), size 0x28
struct Obj_139cd0 {
    char pad[0x24]; // +0x00
    int Value; // +0x24
    char FUN_00139cd0(int x);
};
// matches/0x00139cf0.cpp (stub C_139cf0), size 0x2c
struct C_139cf0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    bool FUN_00139cf0(int v);
};
// matches/0x00139d00.cpp (stub X_139d00), size 0x30
struct X_139d00 {
    char m[0x30]; // +0x00
    char* FUN_00139d00();
};
// matches/0x00139d20.cpp (stub Obj_139d20), size 0x3c
struct Obj_139d20 {
    char pad[0x38]; // +0x00
    int m38; // +0x38
    bool FUN_00139d20(int v);
};
// matches/0x00139d40.cpp (stub Obj_139d40), size 0x40
struct Obj_139d40 {
    char pad[0x3c]; // +0x00
    int m3c; // +0x3c
    char FUN_00139d40(int v);
};
// matches/0x00139d60.cpp (stub X_139d60), size 0x44
struct X_139d60 {
    char pad[0x40]; // +0x00
    int m; // +0x40
    bool FUN_00139d60(int v);
};
// matches/0x00139d70.cpp (stub Obj_139d70), size 0x10
struct Obj_139d70 {
    char pad[0x0c]; // +0x00
    int m; // +0x0c
    char FUN_00139d70(int v);
};
// matches/0x00139d80.cpp (stub Obj_139d80), size 0x14
struct Obj_139d80 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_00139d80(int value);
};
// matches/0x00139d90.cpp (stub Obj_139d90), size 0x1c
struct Obj_139d90 {
    char pad[0x18]; // +0x00
    int mValue; // +0x18
    void* FUN_00139d90();
};
// matches/0x00139db0.cpp (stub Obj_139db0), size 0x24
struct Obj_139db0 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    char FUN_00139db0(int v);
};
// matches/0x00139dd0.cpp (stub Obj_139dd0), size 0x1
struct Obj_139dd0 {
    char FUN_00139dd0(int v);
};
// matches/0x00139df0.cpp (stub A_139df0), size 0x2c
struct A_139df0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    char FUN_00139df0(int x);
};
// matches/0x00139e00.cpp (stub Obj_139e00), size 0x30
struct Obj_139e00 {
    char pad[0x30]; // +0x00
    void* FUN_00139e00();
};
// matches/0x00139e20.cpp (stub O_139e20), size 0x3c
struct O_139e20 {
    char pad[0x38]; // +0x00
    int value; // +0x38
    bool FUN_00139e20(int x);
};
// matches/0x00139e40.cpp (stub X_139e40), size 0x40
struct X_139e40 {
    char pad[0x3c]; // +0x00
    int mVal; // +0x3c
    bool FUN_00139e40(int v);
};
// matches/0x00139e60.cpp (stub X_139e60), size 0x44
struct X_139e60 {
    char pad[0x3d]; // +0x00
    int m40; // +0x40
    char FUN_00139e60(int v);
};
// matches/0x00139e70.cpp (stub A_139e70), size 0x10
struct A_139e70 {
    char Pad[12]; // +0x00
    int mVal; // +0x0c
    char FUN_00139e70(int x);
};
// matches/0x00139e80.cpp (stub Obj_139e80), size 0x14
struct Obj_139e80 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_00139e80(int v);
};
// matches/0x00139eb0.cpp (stub X_139eb0), size 0x24
struct X_139eb0 {
    bool FUN_00139eb0(int v);
    char pad[0x20]; // +0x00
    int m20; // +0x20
};
// matches/0x00139ec0.cpp (stub Obj_139ec0), size 0x28
struct Obj_139ec0 {
    char pad[0x24]; // +0x00
    int mField; // +0x24
    bool FUN_00139ec0(int v);
};
// matches/0x00139ee0.cpp (stub X_139ee0), size 0x2c
struct X_139ee0 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    bool FUN_00139ee0(int x);
};
// matches/0x00139f00.cpp (stub Obj_139f00), size 0x30
struct Obj_139f00 {
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
    bool FUN_00139f00(int x);
};
// matches/0x00139f20.cpp (stub Obj_139f20), size 0x34 (0x38)
struct Obj_139f20 {
    char pad[0x30]; // +0x00
    void* m30; // +0x30
    char FUN_00139f20(void* v);
};
// matches/0x00139f40.cpp (stub Obj_139f40), size 0x38
struct Obj_139f40 {
    char pad[0x34]; // +0x00
    int mVal; // +0x34
    bool FUN_00139f40(int v);
};
// matches/0x00139f60.cpp (stub Obj_139f60), size 0x3c
struct Obj_139f60 {
    bool FUN_00139f60(int x);
    char pad[0x38]; // +0x00
    int mX; // +0x38
};
// matches/0x00139f80.cpp (stub Obj_139f80), size 0x3c
struct Obj_139f80 {
    char pad[0x3c]; // +0x00
    char FUN_00139f80(int value);
};
// matches/0x00139fb0.cpp (stub Obj_139fb0), size 0x4c
struct Obj_139fb0 {
    char pad[0x48]; // +0x00
    int m48; // +0x48
    char FUN_00139fb0(int v);
};
// matches/0x00139fd0.cpp (stub Obj_139fd0), size 0x50
struct Obj_139fd0 {
    char pad[0x4c]; // +0x00
    int mValue; // +0x4c
    bool FUN_00139fd0(int v);
};
// matches/0x00139ff0.cpp (stub Obj_139ff0), size 0x54
struct Obj_139ff0 {
    char Pad[0x50]; // +0x00
    int mField; // +0x50
    char FUN_00139ff0(int value);
};
// matches/0x0013e810.cpp (stub X_13e810), size 0x10
struct X_13e810 {
    char pad[0xc]; // +0x00
    int m12; // +0x0c
    bool FUN_0013e810(int v);
};
// matches/0x0013e820.cpp (stub Obj_13e820), size 0x14
struct Obj_13e820 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_0013e820(int a);
};
// matches/0x0013e830.cpp (stub Obj_13e830), size 0x10
struct Obj_13e830 {
    char pad[12]; // +0x00
    int m1c; // +0x0c
    bool FUN_0013e830(int v);
};
// matches/0x0013e840.cpp (stub X_13e840), size 0x14
struct X_13e840 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0013e840(int v);
};
// matches/0x0013e860.cpp (stub Obj_13e860), size 0x18
struct Obj_13e860 {
    char pad[0x14]; // +0x00
    int mValue; // +0x14
    bool FUN_0013e860(int v);
};
// matches/0x0013e880.cpp (stub C_13e880), size 0x1c
struct C_13e880 {
    char pad[0x18]; // +0x00
    int mValue; // +0x18
    bool FUN_0013e880(int value);
};
// matches/0x0013e8a0.cpp (stub Obj_13e8a0), size 0x20
struct Obj_13e8a0 {
    char pad[0x1c]; // +0x00
    int mValue; // +0x1c
    bool FUN_0013e8a0(int x);
};
// matches/0x0013e8c0.cpp (stub Obj_13e8c0), size 0x24
struct Obj_13e8c0 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    char FUN_0013e8c0(int value);
};
// matches/0x0013e8e0.cpp (stub Obj_13e8e0), size 0x25
struct Obj_13e8e0 {
    char pad[36]; // +0x00
    char m24; // +0x24
    char FUN_0013e8e0(unsigned char a);
};
// matches/0x0013e900.cpp (stub Obj_13e900), size 0x2c
struct Obj_13e900 {
    char pad[0x28]; // +0x00
    int mValue; // +0x28
    bool FUN_0013e900(int v);
};
// matches/0x0013e920.cpp (stub Obj_13e920), size 0x30
struct Obj_13e920 {
    char Pad[0x2c]; // +0x00
    int m2c; // +0x2c
    char FUN_0013e920(int a);
};
// matches/0x0013e940.cpp (stub Obj_13e940), size 0x34
struct Obj_13e940 {
    char pad[0x30]; // +0x00
    float angle; // +0x30
    bool FUN_0013e940(float deg);
};
// matches/0x0013e970.cpp (stub R_13e970), size 0x38
struct R_13e970 {
    char pad[0x34]; // +0x00
    float v; // +0x34
    bool FUN_0013e970(float x);
};
// matches/0x0013e990.cpp (stub X_13e990), size 0x38
struct X_13e990 {
    char pad[0x38]; // +0x00
    void* FUN_0013e990();
};
// matches/0x0013e9d0.cpp (stub Obj_13e9d0), size 0x54
struct Obj_13e9d0 {
    char pad[0x50]; // +0x00
    int m50; // +0x50
    bool FUN_0013e9d0(int x);
};
// matches/0x0013e9f0.cpp (stub O_13e9f0), size 0x58
struct O_13e9f0 {
    char pad[0x54]; // +0x00
    int mValue; // +0x54
    bool FUN_0013e9f0(int x);
};
// matches/0x0013ea10.cpp (stub C_13ea10), size 0x5c
struct C_13ea10 {
    bool FUN_0013ea10(int x);
    char pad[0x58]; // +0x00
    int m; // +0x58
};
// matches/0x0013ea20.cpp (stub Obj_13ea20), size 0x10
struct Obj_13ea20 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    char FUN_0013ea20(int x);
};
// matches/0x0013ea50.cpp (stub Obj_13ea50), size 0x18
struct Obj_13ea50 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    char FUN_0013ea50(int v);
};
// matches/0x0013ea70.cpp (stub Obj_13ea70), size 0x1c
struct Obj_13ea70 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    char FUN_0013ea70(int v);
};
// matches/0x0013ea90.cpp (stub A_13ea90), size 0x20
struct A_13ea90 {
    char pad[0x1c]; // +0x00
    int m; // +0x1c
    char FUN_0013ea90(int x);
};
// matches/0x0013eab0.cpp (stub Obj_13eab0), size 0x20
struct Obj_13eab0 {
    char Pad[0x20]; // +0x00
    char FUN_0013eab0(int v);
};
// matches/0x0013ead0.cpp (stub Obj), size 0x28
struct Obj_13ead0 {
    char pad[0x24]; // +0x00
    float angle; // +0x24
    char FUN_0013ead0(float x);
};
// matches/0x0013eb00.cpp (stub X), size 0x2c
struct X_13eb00 {
    char pad[0x28]; // +0x00
    float angle; // +0x28
    char FUN_0013eb00(float x);
};
// matches/0x0013eb30.cpp (stub Obj), size 0x30
struct Obj_13eb30 {
    char pad[0x2c]; // +0x00
    float angle; // +0x2c
    char FUN_0013eb30(float a);
};
// matches/0x0013eb60.cpp (stub A_13eb60), size 0x34
struct A_13eb60 {
    char pad[0x30]; // +0x00
    float m; // +0x30
    unsigned char FUN_0013eb60(float x);
};
// matches/0x0013eb90.cpp (stub Obj_13eb90), size 0x38
struct Obj_13eb90 {
    char FUN_0013eb90(int x);
    char pad[0x33]; // +0x00
    int m34; // +0x34
};
// matches/0x0013ebb0.cpp (stub C_13ebb0), size 0x39
struct C_13ebb0 {
    char pad[0x38]; // +0x00
    char m38; // +0x38
    unsigned char FUN_0013ebb0(unsigned char x);
};
// matches/0x0013ebd0.cpp (stub Obj), size 0x40
struct Obj_13ebd0 {
    char pad[0x3c]; // +0x00
    float angle; // +0x3c
    char FUN_0013ebd0(float x);
};
// matches/0x0013ec00.cpp (stub X_13ec00), size 0x44
struct X_13ec00 {
    char pad[0x40]; // +0x00
    float angle; // +0x40
    bool FUN_0013ec00(float degrees);
};
// matches/0x0013ec60.cpp (stub Obj_13ec60), size 0x4c
struct Obj_13ec60 {
    char pad[0x48]; // +0x00
    int value; // +0x48
    bool FUN_0013ec60(int v);
};
// matches/0x0013ec80.cpp (stub Obj_13ec80), size 0x50
struct Obj_13ec80 {
    char pad[0x4c]; // +0x00
    int value; // +0x4c
    char FUN_0013ec80(int x);
};
// matches/0x0013eca0.cpp (stub X_13eca0), size 0x54
struct X_13eca0 {
    char pad[0x50]; // +0x00
    int m50; // +0x50
    bool FUN_0013eca0(int v);
};
// matches/0x0013ecb0.cpp (stub Obj_13ecb0), size 0x10
struct Obj_13ecb0 {
    char FUN_0013ecb0(int x);
    char pad[12]; // +0x00
    int mValue; // +0x0c
};
// matches/0x0013ecc0.cpp (stub Obj_13ecc0), size 0x14
struct Obj_13ecc0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_0013ecc0(int v);
};
// matches/0x0013ece0.cpp (stub Obj_13ece0), size 0x18
struct Obj_13ece0 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    char FUN_0013ece0(int v);
};
// matches/0x0013ed00.cpp (stub Obj_13ed00), size 0x1c
struct Obj_13ed00 {
    char pad[0x18]; // +0x00
    int mVal; // +0x18
    bool FUN_0013ed00(int v);
};
// matches/0x0013ed20.cpp (stub Obj_13ed20), size 0x20
struct Obj_13ed20 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    bool FUN_0013ed20(int x);
};
// matches/0x0013ed40.cpp (stub Obj_13ed40), size 0x24
struct Obj_13ed40 {
    char pad[0x20]; // +0x00
    float mAngle; // +0x20
    bool FUN_0013ed40(float angle);
};
// matches/0x0013ed70.cpp (stub Obj_13ed70), size 0x24
struct Obj_13ed70 {
    char FUN_0013ed70(float v);
    char pad[0x24]; // +0x00
};
// matches/0x0013eda0.cpp (stub X), size 0x2c
struct X_13eda0 {
    char pad[0x28]; // +0x00
    float angle; // +0x28
    char FUN_0013eda0(float x);
};
// matches/0x0013edd0.cpp (stub X_13edd0), size 0x30
struct X_13edd0 {
    char pad[0x2c]; // +0x00
    int mValue; // +0x2c
    bool FUN_0013edd0(int v);
};
// matches/0x0013edf0.cpp (stub O_13edf0), size 0x34
struct O_13edf0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0013edf0(int x);
};
// matches/0x0013ee10.cpp (stub Obj_13ee10), size 0x38
struct Obj_13ee10 {
    char pad[0x34]; // +0x00
    int m; // +0x34
    char FUN_0013ee10(int v);
};
// equivalent/0x00143100.cpp (stub RandomGen), size 0x8
struct RandomGen_143100 {
    unsigned int z; // +0x00
    unsigned int w; // +0x04
    float FUN_00143100();
};
// matches/0x00143180.cpp (stub Obj_143180), size 0x10
struct Obj_143180 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_00143180(int v);
};
// matches/0x001431a0.cpp (stub O_1431a0), size 0x14
struct O_1431a0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_001431a0(int v);
};
// matches/0x001431b0.cpp (stub Obj_1431b0), size 0x18
struct Obj_1431b0 {
    char pad[0x18]; // +0x00
    void* FUN_001431b0();
};
// matches/0x001431d0.cpp (stub X_1431d0), size 0x24
struct X_1431d0 {
    char pad0[0x20]; // +0x00
    int value; // +0x20
    char FUN_001431d0(int v);
};
// matches/0x00143200.cpp (stub T_143200), size 0x34
struct T_143200 {
    char pad[0x30]; // +0x00
    int m; // +0x30
    bool FUN_00143200(int x);
};
// matches/0x00143220.cpp (stub Obj_143220), size 0x38
struct Obj_143220 {
    char pad[0x34]; // +0x00
    int value; // +0x34
    char FUN_00143220(int v);
};
// matches/0x00143230.cpp (stub Obj_143230), size 0x10
struct Obj_143230 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    bool FUN_00143230(int v);
};
// matches/0x00143250.cpp (stub X_143250), size 0x14
struct X_143250 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    unsigned char FUN_00143250(int v);
};
// matches/0x00143270.cpp (stub Obj_143270), size 0x18
struct Obj_143270 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    bool FUN_00143270(int x);
};
// matches/0x00143290.cpp (stub Obj_143290), size 0x1c
struct Obj_143290 {
    char FUN_00143290(int a);
    char pad[0x18]; // +0x00
    int m18; // +0x18
};
// matches/0x001432b0.cpp (stub Obj_1432b0), size 0x20
struct Obj_1432b0 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    bool FUN_001432b0(int v);
};
// matches/0x001432d0.cpp (stub C_1432d0), size 0x21
struct C_1432d0 {
    char pad[0x20]; // +0x00
    char m20; // +0x20
    char FUN_001432d0(char value);
};
// matches/0x001432e0.cpp (stub Obj_1432e0), size 0x10
struct Obj_1432e0 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    char FUN_001432e0(int v);
};
// matches/0x00143320.cpp (stub Obj_143320), size 0x24
struct Obj_143320 {
    char pad[0x18]; // +0x00
    int a; // +0x18
    int b; // +0x1c
    int c; // +0x20
    char FUN_00143320(const int* p);
};
// matches/0x00143390.cpp (stub Obj_143390), size 0x34
struct Obj_143390 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_00143390(int x);
};
// matches/0x001433d0.cpp (stub X_1433d0), size 0x3c
struct X_1433d0 {
    char pad[0x38]; // +0x00
    int m38; // +0x38
    bool FUN_001433d0(int v);
};
// matches/0x001433f0.cpp (stub Obj_1433f0), size 0x40
struct Obj_1433f0 {
    char pad[0x3c]; // +0x00
    int m3c; // +0x3c
    char FUN_001433f0(int value);
};
// matches/0x00143400.cpp (stub A_143400), size 0x10
struct A_143400 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    bool FUN_00143400(int x);
};
// matches/0x001434e0.cpp (stub A_1434e0), size 0x38
struct A_1434e0 {
    char pad[0x34]; // +0x00
    float mAngle; // +0x34
    char FUN_001434e0(float x);
};
// matches/0x00143510.cpp (stub Obj_143510), size 0x3c
struct Obj_143510 {
    char pad[0x38]; // +0x00
    float value; // +0x38
    bool FUN_00143510(float a);
};
// matches/0x00143540.cpp (stub A_143540), size 0x40
struct A_143540 {
    char pad[0x3c]; // +0x00
    int m3c; // +0x3c
    bool FUN_00143540(int v);
};
// matches/0x00143560.cpp (stub C_143560), size 0x44
struct C_143560 {
    char FUN_00143560(int v);
    char pad[0x40]; // +0x00
    int mVal; // +0x40
};
// matches/0x00143580.cpp (stub X_143580), size 0x1
struct X_143580 {
    char FUN_00143580(int v);
};
// matches/0x001435a0.cpp (stub Obj_1435a0), size 0x4c
struct Obj_1435a0 {
    char pad[0x48]; // +0x00
    int m048; // +0x48
    char FUN_001435a0(int v);
};
// matches/0x001435c0.cpp (stub C_1435c0), size 0x50
struct C_1435c0 {
    char pad[0x4c]; // +0x00
    unsigned int m; // +0x4c
    char FUN_001435c0(unsigned int v);
};
// matches/0x001435e0.cpp (stub Obj_1435e0), size 0x54
struct Obj_1435e0 {
    char pad[0x50]; // +0x00
    int m50; // +0x50
    bool FUN_001435e0(int v);
};
// matches/0x00143600.cpp (stub Obj_143600), size 0x58
struct Obj_143600 {
    char pad[0x54]; // +0x00
    int value; // +0x54
    bool FUN_00143600(int x);
};
// matches/0x001436c0.cpp (stub X_1436c0), size 0x10
struct X_1436c0 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    bool FUN_001436c0(int v);
};
// matches/0x001436e0.cpp (stub Obj_1436e0), size 0x14
struct Obj_1436e0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_001436e0(int v);
};
// matches/0x00146900.cpp (stub O_146900), size 0x10
struct O_146900 {
    char FUN_00146900(int a);
    char pad[12]; // +0x00
    int m; // +0x0c
};
// matches/0x00146910.cpp (stub O_146910), size 0x10
struct O_146910 {
    char pad[0x10]; // +0x00
    void* FUN_00146910();
};
// matches/0x00146920.cpp (stub Obj_146920), size 0xd
struct Obj_146920 {
    char pad[12]; // +0x00
    char mFlag; // +0x0c
    bool FUN_00146920(char value);
};
// matches/0x00146930.cpp (stub Obj_146930), size 0xd
struct Obj_146930 {
    char pad[12]; // +0x00
    char m; // +0x0c
    unsigned char FUN_00146930(unsigned char c);
};
// matches/0x00146940.cpp (stub Obj_146940), size 0xd
struct Obj_146940 {
    char pad[12]; // +0x00
    char mVal; // +0x0c
    unsigned char FUN_00146940(unsigned char v);
};
// matches/0x00146950.cpp (stub Thing_146950), size 0xc
struct Thing_146950 {
    char FUN_00146950(float f);
    char pad[12]; // +0x00
};
// matches/0x00146970.cpp (stub Obj_146970), size 0x14
struct Obj_146970 {
    char pad[0x10]; // +0x00
    float value; // +0x10
    bool FUN_00146970(float degrees);
};
// matches/0x00146a40.cpp (stub Obj_146a40), size 0x10
struct Obj_146a40 {
    char pad[12]; // +0x00
    int value; // +0x0c
    unsigned char FUN_00146a40(int x);
};
// matches/0x00146aa0.cpp (stub Obj_146aa0), size 0x20
struct Obj_146aa0 {
    char pad[0x1c]; // +0x00
    int field; // +0x1c
    bool FUN_00146aa0(int x);
};
// matches/0x00146ac0.cpp (stub C_146ac0), size 0x24
struct C_146ac0 {
    char pad[0x20]; // +0x00
    int m; // +0x20
    bool FUN_00146ac0(int x);
};
// matches/0x00146ae0.cpp (stub Obj_146ae0), size 0x28
struct Obj_146ae0 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    char FUN_00146ae0(int x);
};
// matches/0x00146b00.cpp (stub Obj_146b00), size 0x2c
struct Obj_146b00 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    char FUN_00146b00(int x);
};
// matches/0x00146b20.cpp (stub Obj), size 0x30
struct Obj_146b20 {
    char pad[0x2c]; // +0x00
    float angle; // +0x2c
    char FUN_00146b20(float x);
};
// matches/0x00146b50.cpp (stub C_146b50), size 0x34
struct C_146b50 {
    char pad[0x30]; // +0x00
    float mRad; // +0x30
    bool FUN_00146b50(float deg);
};
// matches/0x00146b80.cpp (stub X_146b80), size 0x38
struct X_146b80 {
    bool FUN_00146b80(float v);
    char pad[0x34]; // +0x00
    float angle; // +0x34
};
// matches/0x00146bb0.cpp (stub Obj_146bb0), size 0x3c
struct Obj_146bb0 {
    char pad[0x38]; // +0x00
    int value; // +0x38
    bool FUN_00146bb0(int x);
};
// matches/0x00146bd0.cpp (stub Obj_146bd0), size 0x40
struct Obj_146bd0 {
    char pad[0x3c]; // +0x00
    int m3c; // +0x3c
    char FUN_00146bd0(int value);
};
// matches/0x00146be0.cpp (stub Obj_146be0), size 0x10
struct Obj_146be0 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    char FUN_00146be0(int value);
};
// matches/0x00146bf0.cpp (stub Obj_146bf0), size 0x14
struct Obj_146bf0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_00146bf0(int x);
};
// matches/0x00146c10.cpp (stub X_146c10), size 0x18
struct X_146c10 {
    char pad[0x14]; // +0x00
    int m; // +0x14
    bool FUN_00146c10(int a);
};
// matches/0x00146c30.cpp (stub X_146c30), size 0x1c (0x20)
struct X_146c30 {
    char FUN_00146c30(char* p);
    char pad[0x18]; // +0x00
    char* m18; // +0x18
};
// matches/0x00146c50.cpp (stub A_146c50), size 0x20
struct A_146c50 {
    char FUN_00146c50(int x);
    char pad[0x1c]; // +0x00
    int mVal; // +0x1c
};
// matches/0x00146c70.cpp (stub Target_146c70), size 0x24
struct Target_146c70 {
    char pad[0x20]; // +0x00
    int mValue; // +0x20
    bool FUN_00146c70(int v);
};
// matches/0x00146c80.cpp (stub Obj_146c80), size 0x10
struct Obj_146c80 {
    char pad[0xc]; // +0x00
    int m1c; // +0x0c
    bool FUN_00146c80(int a);
};
// matches/0x00146ce0.cpp (stub Obj_146ce0), size 0x20
struct Obj_146ce0 {
    char pad[0x1c]; // +0x00
    int mVal; // +0x1c
    bool FUN_00146ce0(int v);
};
// matches/0x00146d00.cpp (stub Obj_146d00), size 0x24
struct Obj_146d00 {
    char FUN_00146d00(int v);
    char pad[0x20]; // +0x00
    int mField; // +0x20
};
// matches/0x00146d20.cpp (stub X_146d20), size 0x28
struct X_146d20 {
    char pad[0x24]; // +0x00
    int m24; // +0x24
    bool FUN_00146d20(int v);
};
// matches/0x00146d40.cpp (stub Obj_146d40), size 0x2c
struct Obj_146d40 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    char FUN_00146d40(int value);
};
// matches/0x00146d60.cpp (stub Layout_146d60), size 0x30
struct Layout_146d60 {
    char pad[0x2c]; // +0x00
    float mAngle; // +0x2c
    bool FUN_00146d60(float angle);
};
// matches/0x00146d90.cpp (stub A_146d90), size 0x34
struct A_146d90 {
    char pad[0x30]; // +0x00
    float f30; // +0x30
    char FUN_00146d90(float v);
};
// matches/0x00146dc0.cpp (stub Obj_146dc0), size 0x38
struct Obj_146dc0 {
    char pad[0x34]; // +0x00
    float m; // +0x34
    bool FUN_00146dc0(float value);
};
// matches/0x00146df0.cpp (stub Obj_146df0), size 0x3c
struct Obj_146df0 {
    char pad[0x38]; // +0x00
    int m38; // +0x38
    bool FUN_00146df0(int x);
};
// matches/0x00146e10.cpp (stub Obj_146e10), size 0x40
struct Obj_146e10 {
    char pad[0x3c]; // +0x00
    int m3c; // +0x3c
    bool FUN_00146e10(int x);
};
// matches/0x00146e20.cpp (stub O_146e20), size 0x10
struct O_146e20 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    char FUN_00146e20(int);
};
// matches/0x00146e30.cpp (stub Obj_146e30), size 0x10
struct Obj_146e30 {
    char pad[0xc]; // +0x00
    int mVal; // +0x0c
    bool FUN_00146e30(int x);
};
// matches/0x00146e50.cpp (stub Obj_146e50), size 0x14 (0x18)
struct Obj_146e50 {
    char pad[0x10]; // +0x00
    void* m10; // +0x10
    bool FUN_00146e50(void* p);
};
// matches/0x00146e70.cpp (stub A_146e70), size 0x18
struct A_146e70 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    bool FUN_00146e70(int x);
};
// matches/0x00146e90.cpp (stub T_146e90), size 0x1c
struct T_146e90 {
    char pad[0x18]; // +0x00
    float v; // +0x18
    unsigned char FUN_00146e90(float x);
};
// matches/0x00146eb0.cpp (stub Obj_146eb0), size 0x20
struct Obj_146eb0 {
    char pad[0x20]; // +0x00
    void* FUN_00146eb0();
};
// matches/0x00146ed0.cpp (stub X_146ed0), size 0x2c
struct X_146ed0 {
    char pad[0x28]; // +0x00
    int field; // +0x28
    bool FUN_00146ed0(int a);
};
// matches/0x00146ef0.cpp (stub Obj_146ef0), size 0x30
struct Obj_146ef0 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    char FUN_00146ef0(int v);
};
// matches/0x00146f10.cpp (stub Obj_146f10), size 0x34
struct Obj_146f10 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_00146f10(int value);
};
// matches/0x00146f30.cpp (stub Obj_146f30), size 0x34
struct Obj_146f30 {
    char pad[0x34]; // +0x00
    bool FUN_00146f30(char a);
};
// matches/0x00146f50.cpp (stub Obj_146f50), size 0x3c (0x40)
struct Obj_146f50 {
    char pad[0x38]; // +0x00
    void* m38; // +0x38
    unsigned char FUN_00146f50(void* v);
};
// matches/0x00146f70.cpp (stub Base_146f70), size 0x40
struct Base_146f70 {
    char pad[0x3c]; // +0x00
    int m3c; // +0x3c
    bool FUN_00146f70(int x);
};
// matches/0x00146f90.cpp (stub Obj_146f90), size 0x44
struct Obj_146f90 {
    char pad[0x40]; // +0x00
    float value; // +0x40
    char FUN_00146f90(float deg);
};
// matches/0x00146fc0.cpp (stub X_146fc0), size 0x44
struct X_146fc0 {
    char pad[0x44]; // +0x00
    char FUN_00146fc0(int v);
};
// matches/0x00146fe0.cpp (stub Obj_146fe0), size 0x4c
struct Obj_146fe0 {
    char pad[0x48]; // +0x00
    int value; // +0x48
    char FUN_00146fe0(int x);
};
// matches/0x00147000.cpp (stub Obj_147000), size 0x50
struct Obj_147000 {
    char pad[0x4c]; // +0x00
    int mVal; // +0x4c
    char FUN_00147000(int v) throw();
};
// matches/0x00147020.cpp (stub Obj_147020), size 0x54
struct Obj_147020 {
    char pad[0x50]; // +0x00
    int m50; // +0x50
    char FUN_00147020(int x);
};
// matches/0x00147030.cpp (stub X_147030), size 0x10
struct X_147030 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    char FUN_00147030(int v);
};
// matches/0x00147040.cpp (stub Thing), size 0x14
struct Thing_147040 {
    char pad[16]; // +0x00
    int value; // +0x10
    bool FUN_00147040(int x);
};
// matches/0x00147050.cpp (stub Foo_147050), size 0x18
struct Foo_147050 {
    char pad[0x14]; // +0x00
    int mVal; // +0x14
    int* FUN_00147050();
};
// matches/0x00147070.cpp (stub Obj_147070), size 0x20
struct Obj_147070 {
    char m[0x20]; // +0x00
    char FUN_00147070(void* x);
};
// matches/0x00147080.cpp (stub Obj_147080), size 0x24
struct Obj_147080 {
    char pad[0x24]; // +0x00
    char* FUN_00147080();
};
// matches/0x00147090.cpp (stub O_147090), size 0x10
struct O_147090 {
    char p[12]; // +0x00
    int m; // +0x0c
    bool FUN_00147090(int);
};
// matches/0x001470b0.cpp (stub Target_1470b0), size 0x14
struct Target_1470b0 {
    char pad[0x10]; // +0x00
    int mField; // +0x10
    bool FUN_001470b0(int x);
};
// matches/0x001470c0.cpp (stub A_1470c0), size 0x1c (0x20)
struct A_1470c0 {
    char pad[0x18]; // +0x00
    void* data; // +0x18
    void* FUN_001470c0();
};
// matches/0x001470e0.cpp (stub Obj_1470e0), size 0x20
struct Obj_1470e0 {
    char pad[0x20]; // +0x00
    char FUN_001470e0(int x);
};
// matches/0x00147100.cpp (stub Obj_147100), size 0x28
struct Obj_147100 {
    char pad[0x24]; // +0x00
    int m24; // +0x24
    char FUN_00147100(int x);
};
// matches/0x00147120.cpp (stub X_147120), size 0x29
struct X_147120 {
    char pad[0x28]; // +0x00
    char m28; // +0x28
    char FUN_00147120(unsigned char a);
};
// matches/0x00147140.cpp (stub Obj_147140), size 0x30
struct Obj_147140 {
    char Pad[0x2c]; // +0x00
    int Value; // +0x2c
    char FUN_00147140(int x);
};
// matches/0x0014c470.cpp (stub Obj_14c470), size 0x10
struct Obj_14c470 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_0014c470(int x);
};
// matches/0x0014c480.cpp (stub Obj_14c480), size 0x14
struct Obj_14c480 {
    char pad[0x10]; // +0x00
    int mField; // +0x10
    bool FUN_0014c480(int x);
};
// matches/0x0014c4b0.cpp (stub Obj_14c4b0), size 0x14
struct Obj_14c4b0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0014c4b0(int v);
};
// matches/0x0014c4c0.cpp (stub Obj_14c4c0), size 0xd
struct Obj_14c4c0 {
    char pad[12]; // +0x00
    char mField; // +0x0c
    bool FUN_0014c4c0(unsigned char x);
};
// matches/0x0014c510.cpp (stub X_14c510), size 0x10
struct X_14c510 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    bool FUN_0014c510(int v);
};
// matches/0x0014c530.cpp (stub T_14c530), size 0x14
struct T_14c530 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0014c530(int x);
};
// matches/0x0014c540.cpp (stub Obj_14c540), size 0xd
struct Obj_14c540 {
    char pad[12]; // +0x00
    char value; // +0x0c
    char FUN_0014c540(unsigned char c);
};
// matches/0x0014c570.cpp (stub X_14c570), size 0xe
struct X_14c570 {
    char pad[0xc]; // +0x00
    unsigned char mValue; // +0x0c
    bool mSet; // +0x0d
    unsigned char FUN_0014c570(unsigned char v);
};
// matches/0x0014c5a0.cpp (stub Obj_14c5a0), size 0xd
struct Obj_14c5a0 {
    char pad[0xc]; // +0x00
    unsigned char mVal; // +0x0c
    unsigned char FUN_0014c5a0(unsigned char v);
};
// matches/0x0014c5b0.cpp (stub Obj), size 0x10
struct Obj_14c5b0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    char FUN_0014c5b0(int x);
};
// matches/0x0014c5d0.cpp (stub Obj_14c5d0), size 0x14
struct Obj_14c5d0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0014c5d0(int v);
};
// matches/0x0014c5e0.cpp (stub Obj_14c5e0), size 0xd
struct Obj_14c5e0 {
    char pad[0xc]; // +0x00
    char m; // +0x0c
    char FUN_0014c5e0(char v);
};
// matches/0x0014c5f0.cpp (stub X_14c5f0), size 0x10
struct X_14c5f0 {
    char pad[0x10]; // +0x00
    char* FUN_0014c5f0();
};
// matches/0x0014c600.cpp (stub Obj_14c600), size 0xd
struct Obj_14c600 {
    char pad[0xc]; // +0x00
    char value; // +0x0c
    char FUN_0014c600(char x);
};
// matches/0x0014c690.cpp (stub Obj_14c690), size 0x10
struct Obj_14c690 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    char FUN_0014c690(int x);
};
// matches/0x0014c6a0.cpp (stub Obj_14c6a0), size 0x10
struct Obj_14c6a0 {
    char pad[0x10]; // +0x00
    int* FUN_0014c6a0();
};
// matches/0x0014c740.cpp (stub Obj_14c740), size 0x10
struct Obj_14c740 {
    char pad[12]; // +0x00
    unsigned int value; // +0x0c
    bool FUN_0014c740(unsigned int x);
};
// matches/0x0014c750.cpp (stub Obj_14c750), size 0x14 (0x18)
struct Obj_14c750 {
    char pad[16]; // +0x00
    void* m; // +0x10
    void* FUN_0014c750();
};
// matches/0x0014c760.cpp (stub A_14c760), size 0x10
struct A_14c760 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0014c760(int v);
};
// matches/0x0014c780.cpp (stub Obj_14c780), size 0x14
struct Obj_14c780 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_0014c780(int x);
};
// matches/0x0014c790.cpp (stub X_14c790), size 0x10
struct X_14c790 {
    char pad[12]; // +0x00
    int m12; // +0x0c
    bool FUN_0014c790(int v);
};
// matches/0x0014c7a0.cpp (stub X_14c7a0), size 0x14
struct X_14c7a0 {
    bool FUN_0014c7a0(int v);
    char pad[0x10]; // +0x00
    int m10; // +0x10
};
// matches/0x0014c7c0.cpp (stub X_14c7c0), size 0x15
struct X_14c7c0 {
    char pad[0x14]; // +0x00
    char mX; // +0x14
    char FUN_0014c7c0(char value);
};
// matches/0x0014c7e0.cpp (stub C_14c7e0), size 0x1c
struct C_14c7e0 {
    char pad[0x18]; // +0x00
    float mDeg; // +0x18
    char FUN_0014c7e0(float x);
};
// matches/0x0014c810.cpp (stub Obj), size 0x20
struct Obj_14c810 {
    char pad[0x1c]; // +0x00
    int value; // +0x1c
    char FUN_0014c810(int x);
};
// matches/0x0014c830.cpp (stub Obj_14c830), size 0x24
struct Obj_14c830 {
    char Pad[0x20]; // +0x00
    int Value; // +0x20
    char FUN_0014c830(int arg);
};
// matches/0x0014c850.cpp (stub Obj), size 0x28
struct Obj_14c850 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    bool FUN_0014c850(int x);
};
// matches/0x0014c870.cpp (stub Obj_14c870), size 0x2c
struct Obj_14c870 {
    char FUN_0014c870(int v);
    char pad[0x28]; // +0x00
    int m28; // +0x28
};
// matches/0x0014c880.cpp (stub Obj_14c880), size 0x10
struct Obj_14c880 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_0014c880(int x);
};
// matches/0x0014c8a0.cpp (stub Obj_14c8a0), size 0x14
struct Obj_14c8a0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0014c8a0(int v);
};
// matches/0x0014c8c0.cpp (stub C_14c8c0), size 0x18
struct C_14c8c0 {
    bool FUN_0014c8c0(float x);
    char pad[0x14]; // +0x00
    float mAngle; // +0x14
};
// matches/0x0014c8e0.cpp (stub Obj_14c8e0), size 0x1c (0x20)
struct Obj_14c8e0 {
    char pad[0x18]; // +0x00
    void* p; // +0x18
    void* FUN_0014c8e0();
};
// matches/0x0014c900.cpp (stub Obj_14c900), size 0x24
struct Obj_14c900 {
    char pad[0x20]; // +0x00
    int field; // +0x20
    bool FUN_0014c900(int x);
};
// matches/0x0014c920.cpp (stub C_14c920), size 0x28
struct C_14c920 {
    char pad[0x24]; // +0x00
    float mAngle; // +0x24
    bool FUN_0014c920(float v);
};
// matches/0x0014c950.cpp (stub X_14c950), size 0x28
struct X_14c950 {
    bool FUN_0014c950(int a);
    char pad[0x28]; // +0x00
};
// matches/0x0014c970.cpp (stub Obj_14c970), size 0x30
struct Obj_14c970 {
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
    bool FUN_0014c970(int v);
};
// matches/0x0014c990.cpp (stub O_14c990), size 0x34
struct O_14c990 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0014c990(int v);
};
// matches/0x0014c9b0.cpp (stub Obj_14c9b0), size 0x38
struct Obj_14c9b0 {
    bool FUN_0014c9b0(int value);
    char pad[0x34]; // +0x00
    int mField; // +0x34
};
// matches/0x0014c9d0.cpp (stub Obj_14c9d0), size 0x3c
struct Obj_14c9d0 {
    char pad[0x38]; // +0x00
    int m38; // +0x38
    bool FUN_0014c9d0(int value);
};
// matches/0x0014c9f0.cpp (stub Obj_14c9f0), size 0x40
struct Obj_14c9f0 {
    char Pad[0x3c]; // +0x00
    int Value; // +0x3c
    char FUN_0014c9f0(int x);
};
// matches/0x0014ca10.cpp (stub Obj_14ca10), size 0x44
struct Obj_14ca10 {
    char pad[0x40]; // +0x00
    int mVal; // +0x40
    char FUN_0014ca10(int v);
};
// matches/0x0014ca30.cpp (stub Obj_14ca30), size 0x48
struct Obj_14ca30 {
    char pad[0x44]; // +0x00
    int mVal; // +0x44
    bool FUN_0014ca30(int x);
};
// matches/0x0014ca50.cpp (stub Obj_14ca50), size 0x50
struct Obj_14ca50 {
    char pad[0x48]; // +0x00
    int field; // +0x48
    char flag; // +0x4c
    bool FUN_0014ca50(int value);
};
// matches/0x0014ca70.cpp (stub Obj_14ca70), size 0x50
struct Obj_14ca70 {
    char pad[0x4c]; // +0x00
    int m4c; // +0x4c
    bool FUN_0014ca70(int v);
};
// matches/0x0014ca90.cpp (stub Obj_14ca90), size 0x51
struct Obj_14ca90 {
    char pad[0x50]; // +0x00
    char m50; // +0x50
    unsigned char FUN_0014ca90(unsigned char x);
};
// matches/0x0014caf0.cpp (stub O_14caf0), size 0x10
struct O_14caf0 {
    char FUN_0014caf0(int x);
    char pad[0xc]; // +0x00
    int m1c; // +0x0c
};
// matches/0x0014cb10.cpp (stub X_14cb10), size 0x14
struct X_14cb10 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0014cb10(int v);
};
// matches/0x0014cb30.cpp (stub C_14cb30), size 0x18
struct C_14cb30 {
    char pad[0x14]; // +0x00
    float mAngle; // +0x14
    bool FUN_0014cb30(float deg);
};
// matches/0x0014cb50.cpp (stub Obj_14cb50), size 0x1c (0x20)
struct Obj_14cb50 {
    char pad[0x18]; // +0x00
    int* value; // +0x18
    int** FUN_0014cb50();
};
// matches/0x0014cb70.cpp (stub X_14cb70), size 0x24
struct X_14cb70 {
    char FUN_0014cb70(int v);
    char pad[0x20 - 1]; // +0x00
    int m; // +0x20
};
// matches/0x0014cb90.cpp (stub T_14cb90), size 0x28
struct T_14cb90 {
    char pad[0x24]; // +0x00
    int mVal; // +0x24
    bool FUN_0014cb90(int v);
};
// matches/0x0014cbb0.cpp (stub Obj_14cbb0), size 0x29
struct Obj_14cbb0 {
    char m0[0x28]; // +0x00
    char m28; // +0x28
    char FUN_0014cbb0(char c);
};
// matches/0x0014cbd0.cpp (stub Obj_14cbd0), size 0x30
struct Obj_14cbd0 {
    char pad[0x2c]; // +0x00
    int m_field; // +0x2c
    bool FUN_0014cbd0(int value);
};
// matches/0x0014cbf0.cpp (stub Obj), size 0x34
struct Obj_14cbf0 {
    char pad[0x30]; // +0x00
    float angle; // +0x30
    char FUN_0014cbf0(float a);
};
// matches/0x0014cc20.cpp (stub Obj_14cc20), size 0x38 (0x40)
struct Obj_14cc20 {
    char pad[0x34]; // +0x00
    void* m; // +0x34 (+0x38)
    char FUN_0014cc20(void* v);
};
// matches/0x0014cc40.cpp (stub Obj_14cc40), size 0x3c
struct Obj_14cc40 {
    char pad[0x38]; // +0x00
    int m38; // +0x38
    bool FUN_0014cc40(int v);
};
// matches/0x0014cc60.cpp (stub X_14cc60), size 0x40
struct X_14cc60 {
    char pad[0x3c]; // +0x00
    int m3c; // +0x3c
    char FUN_0014cc60(int v);
};
// matches/0x0014cc80.cpp (stub C_14cc80), size 0x44
struct C_14cc80 {
    char FUN_0014cc80(int value);
    char pad[0x40]; // +0x00
    int mValue; // +0x40
};
// matches/0x0014cca0.cpp (stub X_14cca0), size 0x45
struct X_14cca0 {
    char pad[0x44]; // +0x00
    char m44; // +0x44
    char FUN_0014cca0(char v);
};
// matches/0x0014ccb0.cpp (stub X_14ccb0), size 0x10
struct X_14ccb0 {
    int pad[3]; // +0x00
    int m; // +0x0c
    char FUN_0014ccb0(int v);
};
// matches/0x0014ccd0.cpp (stub Obj_14ccd0), size 0x14
struct Obj_14ccd0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0014ccd0(int x);
};
// matches/0x0014cd20.cpp (stub X_14cd20), size 0x10
struct X_14cd20 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    char FUN_0014cd20(int v);
};
// matches/0x0014cd30.cpp (stub Target_14cd30), size 0x14
struct Target_14cd30 {
    char pad[0x10]; // +0x00
    int mArg; // +0x10
    char FUN_0014cd30(int x);
};
// matches/0x0014cd50.cpp (stub C_14cd50), size 0x18
struct C_14cd50 {
    char pad[0x14]; // +0x00
    float mAngle; // +0x14
    bool FUN_0014cd50(float v);
};
// matches/0x0014cd80.cpp (stub X_14cd80), size 0x1c
struct X_14cd80 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    bool FUN_0014cd80(int v);
};
// matches/0x0014cda0.cpp (stub Obj), size 0x20
struct Obj_14cda0 {
    char pad[0x1c]; // +0x00
    int value; // +0x1c
    char FUN_0014cda0(int x);
};
// matches/0x0014cdc0.cpp (stub Obj_14cdc0), size 0x24
struct Obj_14cdc0 {
    char pad[0x20]; // +0x00
    int m; // +0x20
    char FUN_0014cdc0(int v);
};
// matches/0x0014cdd0.cpp (stub Obj), size 0x10
struct Obj_14cdd0 {
    char pad[12]; // +0x00
    int field; // +0x0c
    char FUN_0014cdd0(int v);
};
// matches/0x0014cde0.cpp (stub Obj_14cde0), size 0x14
struct Obj_14cde0 {
    char FUN_0014cde0(int x);
    char pad[0x10]; // +0x00
    int m10; // +0x10
};
// matches/0x0014ce00.cpp (stub Obj_14ce00), size 0x15
struct Obj_14ce00 {
    char pad[0x14]; // +0x00
    char m; // +0x14
    bool FUN_0014ce00(unsigned char x);
};
// matches/0x0014ce20.cpp (stub C_14ce20), size 0x1c
struct C_14ce20 {
    char pad[0x18]; // +0x00
    float mRadians; // +0x18
    bool FUN_0014ce20(float deg);
};
// matches/0x0014ce50.cpp (stub Obj_14ce50), size 0x20
struct Obj_14ce50 {
    char Pad[0x1c]; // +0x00
    int Value; // +0x1c
    char FUN_0014ce50(int x);
};
// matches/0x0014ce70.cpp (stub T_14ce70), size 0x24
struct T_14ce70 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_0014ce70(int v);
};
// matches/0x0014ce90.cpp (stub Obj_14ce90), size 0x28
struct Obj_14ce90 {
    char pad[0x24]; // +0x00
    int m24; // +0x24
    char FUN_0014ce90(int a);
};
// matches/0x0014cea0.cpp (stub Obj_14cea0), size 0x10 (0x18)
struct Obj_14cea0 {
    char pad[0xc]; // +0x00
    void* mField; // +0x0c (+0x10)
    bool FUN_0014cea0(void* arg);
};
// matches/0x0014ceb0.cpp (stub Target_14ceb0), size 0x10 (0x18)
struct Target_14ceb0 {
    bool FUN_0014ceb0(void* p);
    char pad[0xc]; // +0x00
    void* mValue; // +0x0c (+0x10)
};
// matches/0x0014ced0.cpp (stub X_14ced0), size 0x14
struct X_14ced0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_0014ced0(int v);
};
// matches/0x0014cee0.cpp (stub O_14cee0), size 0x10
struct O_14cee0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    char FUN_0014cee0(int x);
};
// matches/0x0014cf00.cpp (stub O_14cf00), size 0x14
struct O_14cf00 {
    char p[0x10]; // +0x00
    int m; // +0x10
    bool FUN_0014cf00(int x);
};
// matches/0x0014cf20.cpp (stub Thing_14cf20), size 0x15
struct Thing_14cf20 {
    char pad[20]; // +0x00
    char m14; // +0x14
    char FUN_0014cf20(char v);
};
// matches/0x0014cf40.cpp (stub X_14cf40), size 0x16
struct X_14cf40 {
    char pad[0x15]; // +0x00
    char m; // +0x15
    char FUN_0014cf40(char v);
};
// matches/0x0014cf60.cpp (stub X_14cf60), size 0x17
struct X_14cf60 {
    char FUN_0014cf60(char v);
    char Pad[0x16]; // +0x00
    char m16; // +0x16
};
// matches/0x0014cf70.cpp (stub Obj_14cf70), size 0x10
struct Obj_14cf70 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    char FUN_0014cf70(int x);
};
// matches/0x0014cf90.cpp (stub Obj_14cf90), size 0x14
struct Obj_14cf90 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0014cf90(int value);
};
// matches/0x0014cfa0.cpp (stub Obj_14cfa0), size 0x10
struct Obj_14cfa0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    char FUN_0014cfa0(int x);
};
// matches/0x0014cfb0.cpp (stub Target_14cfb0), size 0x14
struct Target_14cfb0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_0014cfb0(int value);
};
// matches/0x0014cfd0.cpp (stub C_14cfd0), size 0x18
struct C_14cfd0 {
    char pad[0x14]; // +0x00
    float mAngle; // +0x14
    bool FUN_0014cfd0(float v);
};
// matches/0x0014d000.cpp (stub X_14d000), size 0x1
struct X_14d000 {
    char FUN_0014d000(int v);
};
// matches/0x0014d020.cpp (stub Obj_14d020), size 0x20
struct Obj_14d020 {
    char pad[0x1c]; // +0x00
    int m; // +0x1c
    bool FUN_0014d020(int v);
};
// matches/0x0014d040.cpp (stub X_14d040), size 0x24
struct X_14d040 {
    char FUN_0014d040(int v);
    char m0; // +0x00
    char m1; // +0x01
    char m2; // +0x02
    char m3; // +0x03
    char m4; // +0x04
    char m5; // +0x05
    char m6; // +0x06
    char m7; // +0x07
    char m8; // +0x08
    char m9; // +0x09
    char m10; // +0x0a
    char m11; // +0x0b
    char m12; // +0x0c
    char m13; // +0x0d
    char m14; // +0x0e
    char m15; // +0x0f
    char m16; // +0x10
    char m17; // +0x11
    char m18; // +0x12
    char m19; // +0x13
    char pad[10]; // +0x14
    int m20; // +0x20
};
// matches/0x0014d060.cpp (stub X_14d060), size 0x28
struct X_14d060 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    bool FUN_0014d060(int x);
};
// matches/0x0014d080.cpp (stub C_14d080), size 0x2c
struct C_14d080 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    bool FUN_0014d080(int v);
};
// matches/0x0014d0a0.cpp (stub Obj_14d0a0), size 0x30
struct Obj_14d0a0 {
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
    bool FUN_0014d0a0(int x);
};
// matches/0x0014d0c0.cpp (stub X_14d0c0), size 0x34
struct X_14d0c0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0014d0c0(int v);
};
// matches/0x0014d0e0.cpp (stub X_14d0e0), size 0x38
struct X_14d0e0 {
    char pad[0x34]; // +0x00
    int m34; // +0x34
    bool FUN_0014d0e0(int v);
};
// matches/0x0014d0f0.cpp (stub X_14d0f0), size 0x10
struct X_14d0f0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0014d0f0(int v);
};
// matches/0x0014d100.cpp (stub Obj_14d100), size 0x14
struct Obj_14d100 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    bool FUN_0014d100(int x);
};
// matches/0x0014d120.cpp (stub Obj_14d120), size 0x18
struct Obj_14d120 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    bool FUN_0014d120(int v);
};
// matches/0x0014d140.cpp (stub Obj_14d140), size 0x1c
struct Obj_14d140 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    char FUN_0014d140(int x);
};
// matches/0x0014d160.cpp (stub T_14d160), size 0x1d
struct T_14d160 {
    char pad[0x1c]; // +0x00
    unsigned char value; // +0x1c
    unsigned char FUN_0014d160(unsigned char v);
};
// matches/0x0014d180.cpp (stub C_14d180), size 0x24
struct C_14d180 {
    char FUN_0014d180(float x);
    char pad[0x20]; // +0x00
    float mAngle; // +0x20
};
// matches/0x0014d1b0.cpp (stub C_14d1b0), size 0x28
struct C_14d1b0 {
    char pad[0x24]; // +0x00
    float m_rad; // +0x24
    bool FUN_0014d1b0(float deg);
};
// matches/0x0014d1e0.cpp (stub C_14d1e0), size 0x2c
struct C_14d1e0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    bool FUN_0014d1e0(int v);
};
// matches/0x0014d200.cpp (stub Obj_14d200), size 0x30
struct Obj_14d200 {
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
    char FUN_0014d200(int n);
};
// matches/0x0014d220.cpp (stub Obj_14d220), size 0x34
struct Obj_14d220 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0014d220(int a);
};
// matches/0x0014d230.cpp (stub A_14d230), size 0x10
struct A_14d230 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    char FUN_0014d230(int value);
};
// matches/0x0014d240.cpp (stub C_14d240), size 0x1
struct C_14d240 {
    char FUN_0014d240(int a);
};
// matches/0x0015a820.cpp (stub Obj_15a820), size 0xc
struct Obj_15a820 {
    char FUN_0015a820(char value);
    char pad[12]; // +0x00
};
// matches/0x0015a870.cpp (stub A_15a870), size 0x10
struct A_15a870 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    bool FUN_0015a870(int x);
};
// matches/0x0015a890.cpp (stub T_15a890), size 0x14 (0x18)
struct T_15a890 {
    char FUN_0015a890(void* p);
    char pad[0x10]; // +0x00
    void* m; // +0x10
};
// matches/0x0015a8a0.cpp (stub Obj_15a8a0), size 0x10
struct Obj_15a8a0 {
    char Pad[0xc]; // +0x00
    int mValue; // +0x0c
    char FUN_0015a8a0(int x);
};
// matches/0x0015a8b0.cpp (stub C_15a8b0), size 0x14
struct C_15a8b0 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    char FUN_0015a8b0(int x);
};
// matches/0x0015a8c0.cpp (stub Obj_15a8c0), size 0x10
struct Obj_15a8c0 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    bool FUN_0015a8c0(int v);
};
// matches/0x0015a8d0.cpp (stub A_15a8d0), size 0x14
struct A_15a8d0 {
    char m[0x10]; // +0x00
    int mVal; // +0x10
    char FUN_0015a8d0(int v);
};
// matches/0x0015a8f0.cpp (stub Obj_15a8f0), size 0x18
struct Obj_15a8f0 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    char FUN_0015a8f0(int x);
};
// matches/0x0015a910.cpp (stub C_15a910), size 0x1c
struct C_15a910 {
    char pad[0x18]; // +0x00
    int m; // +0x18
    char FUN_0015a910(int v);
};
// matches/0x0015a930.cpp (stub T_15a930), size 0x1c
struct T_15a930 {
    char FUN_0015a930(int x);
    char pad[0x1c]; // +0x00
};
// matches/0x0015a950.cpp (stub Obj_15a950), size 0x20
struct Obj_15a950 {
    char FUN_0015a950(int v);
    char m[0x20]; // +0x00
};
// matches/0x0015a970.cpp (stub Obj_15a970), size 0x28
struct Obj_15a970 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    bool FUN_0015a970(int x);
};
// matches/0x0015a990.cpp (stub Obj_15a990), size 0x2c
struct Obj_15a990 {
    bool FUN_0015a990(int value);
    char pad[0x28]; // +0x00
    int mValue; // +0x28
};
// matches/0x0015a9b0.cpp (stub Obj_15a9b0), size 0x30
struct Obj_15a9b0 {
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
    bool FUN_0015a9b0(int a);
};
// matches/0x0015a9d0.cpp (stub X_15a9d0), size 0x34
struct X_15a9d0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0015a9d0(int v);
};
// matches/0x0015a9e0.cpp (stub T_15a9e0), size 0x38
struct T_15a9e0 {
    char pad[0x38]; // +0x00
    void* FUN_0015a9e0();
};
// matches/0x0015aa10.cpp (stub Obj_15aa10), size 0x50
struct Obj_15aa10 {
    char pad[0x50]; // +0x00
    char* FUN_0015aa10();
};
// matches/0x0015aa30.cpp (stub Obj_15aa30), size 0x64
struct Obj_15aa30 {
    char pad[0x60]; // +0x00
    int m; // +0x60
    int* FUN_0015aa30();
};
// matches/0x0015aa40.cpp (stub Obj_15aa40), size 0x68
struct Obj_15aa40 {
    char pad[0x68]; // +0x00
    void* FUN_0015aa40();
};
// matches/0x0015aa60.cpp (stub X_15aa60), size 0x78
struct X_15aa60 {
    char pad[0x78]; // +0x00
    int* FUN_0015aa60();
};
// matches/0x0015aa70.cpp (stub Obj_15aa70), size 0x80
struct Obj_15aa70 {
    char pad[0x80]; // +0x00
    char* FUN_0015aa70();
};
// matches/0x0015aa80.cpp (stub Obj_15aa80), size 0x88
struct Obj_15aa80 {
    char pad[0x88]; // +0x00
    Obj_15aa80* FUN_0015aa80();
};
// matches/0x0015aaa0.cpp (stub Target_15aaa0), size 0x94
struct Target_15aaa0 {
    char pad[0x90]; // +0x00
    int value; // +0x90
    unsigned char FUN_0015aaa0(int x);
};
// matches/0x0015aac0.cpp (stub Obj_15aac0), size 0x98
struct Obj_15aac0 {
    char pad[0x94]; // +0x00
    int m94; // +0x94
    char FUN_0015aac0(int value);
};
// matches/0x0015aae0.cpp (stub Obj_15aae0), size 0x9c
struct Obj_15aae0 {
    char Pad[0x98]; // +0x00
    int m98; // +0x98
    char FUN_0015aae0(int x);
};
// matches/0x0015aaf0.cpp (stub Obj_15aaf0), size 0x10
struct Obj_15aaf0 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_0015aaf0(int v);
};
// matches/0x0015ab00.cpp (stub Target_15ab00), size 0x10
struct Target_15ab00 {
    char FUN_0015ab00(int value);
    char pad[16]; // +0x00
};
// matches/0x0015ab20.cpp (stub O_15ab20), size 0x18
struct O_15ab20 {
    char pad[0x14]; // +0x00
    int mField; // +0x14
    char FUN_0015ab20(int x);
};
// matches/0x0015ab40.cpp (stub C_15ab40), size 0x1c
struct C_15ab40 {
    char pad[0x18]; // +0x00
    float mRad; // +0x18
    bool FUN_0015ab40(float deg);
};
// matches/0x0015ab70.cpp (stub Obj_15ab70), size 0x1c
struct Obj_15ab70 {
    char m[0x1c]; // +0x00
    char FUN_0015ab70(char c);
};
// matches/0x0015ab90.cpp (stub O_15ab90), size 0x20
struct O_15ab90 {
    char pad[0x20]; // +0x00
    char FUN_0015ab90(int v);
};
// matches/0x0015abb0.cpp (stub Obj_15abb0), size 0x28
struct Obj_15abb0 {
    char pad[0x24]; // +0x00
    int mVal; // +0x24
    bool FUN_0015abb0(int v);
};
// matches/0x0015abd0.cpp (stub Obj_15abd0), size 0x2c
struct Obj_15abd0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    bool FUN_0015abd0(int v);
};
// matches/0x0015abf0.cpp (stub Obj_15abf0), size 0x30
struct Obj_15abf0 {
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
    bool FUN_0015abf0(int x);
};
// matches/0x0015ac10.cpp (stub C_15ac10), size 0x34
struct C_15ac10 {
    char pad[0x30]; // +0x00
    int flag; // +0x30
    bool FUN_0015ac10(int x);
};
// matches/0x0015ac30.cpp (stub X_15ac30), size 0x38
struct X_15ac30 {
    char pad[0x34]; // +0x00
    int value; // +0x34
    bool FUN_0015ac30(int v);
};
// matches/0x0015ac50.cpp (stub O_15ac50), size 0x38
struct O_15ac50 {
    char p[0x38]; // +0x00
    bool FUN_0015ac50(int x);
};
// matches/0x0015ac60.cpp (stub Obj_15ac60), size 0x1
struct Obj_15ac60 {
    void* FUN_0015ac60();
};
// matches/0x0015ac80.cpp (stub Obj_15ac80), size 0x50
struct Obj_15ac80 {
    char pad[0x50]; // +0x00
    Obj_15ac80* FUN_0015ac80();
};
// matches/0x0015aca0.cpp (stub X_15aca0), size 0x1
struct X_15aca0 {
    void* FUN_0015aca0();
};
// matches/0x0015acb0.cpp (stub A_15acb0), size 0x6c (0x70)
struct A_15acb0 {
    char pad[0x68]; // +0x00
    int* m; // +0x68
    int* FUN_0015acb0();
};
// matches/0x0015acc0.cpp (stub C_15acc0), size 0x71
struct C_15acc0 {
    char pad[0x70]; // +0x00
    char m; // +0x70
    char* FUN_0015acc0();
};
// matches/0x0015acd0.cpp (stub Obj_15acd0), size 0x7c (0x80)
struct Obj_15acd0 {
    char pad[0x78]; // +0x00
    void* mField; // +0x78
    void* FUN_0015acd0();
};
// matches/0x0015ace0.cpp (stub A_15ace0), size 0x80
struct A_15ace0 {
    char pad[0x80]; // +0x00
    int* FUN_0015ace0();
};
// matches/0x0015ad00.cpp (stub Obj_15ad00), size 0x90
struct Obj_15ad00 {
    char pad[0x90]; // +0x00
    void* FUN_0015ad00();
};
// matches/0x0015ad20.cpp (stub C_15ad20), size 0x9c
struct C_15ad20 {
    char pad[0x98]; // +0x00
    int m; // +0x98
    char FUN_0015ad20(int x);
};
// matches/0x0015ad40.cpp (stub Obj_15ad40), size 0xa0
struct Obj_15ad40 {
    char pad[0x9c]; // +0x00
    int m9c; // +0x9c
    bool FUN_0015ad40(int x);
};
// matches/0x0015ad60.cpp (stub O_15ad60), size 0xa4
struct O_15ad60 {
    char pad[0xa0]; // +0x00
    int value; // +0xa0
    char FUN_0015ad60(int x);
};
// matches/0x0015ad70.cpp (stub O_15ad70), size 0x10
struct O_15ad70 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0015ad70(int x);
};
// matches/0x0015ad80.cpp (stub Obj_15ad80), size 0x14
struct Obj_15ad80 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_0015ad80(int value);
};
// matches/0x0015ada0.cpp (stub C_15ada0), size 0x18
struct C_15ada0 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    char FUN_0015ada0(int x);
};
// matches/0x0015adc0.cpp (stub Obj_15adc0), size 0x1c
struct Obj_15adc0 {
    char pad[24]; // +0x00
    int mField; // +0x18
    char FUN_0015adc0(int x);
};
// matches/0x0015ade0.cpp (stub C_15ade0), size 0x20
struct C_15ade0 {
    char pad[0x1c]; // +0x00
    float mAngle; // +0x1c
    char FUN_0015ade0(float x);
};
// matches/0x0015ae10.cpp (stub C_15ae10), size 0x24
struct C_15ae10 {
    char pad[0x20]; // +0x00
    float mAngle; // +0x20
    char FUN_0015ae10(float a);
};
// matches/0x0015ae40.cpp (stub C_15ae40), size 0x28
struct C_15ae40 {
    char pad[0x24]; // +0x00
    float mVal; // +0x24
    char FUN_0015ae40(float x);
};
// matches/0x0015ae70.cpp (stub Foo_15ae70), size 0x2c
struct Foo_15ae70 {
    char pad[0x28]; // +0x00
    float mRadians; // +0x28
    bool FUN_0015ae70(float deg);
};
// matches/0x0015aea0.cpp (stub C_15aea0), size 0x30
struct C_15aea0 {
    bool FUN_0015aea0(float deg);
    char pad[0x2c]; // +0x00
    float mRad; // +0x2c
};
// matches/0x0015aed0.cpp (stub C_15aed0), size 0x34
struct C_15aed0 {
    char pad[0x30]; // +0x00
    float m; // +0x30
    bool FUN_0015aed0(float deg);
};
// matches/0x0015af00.cpp (stub Obj_15af00), size 0x38
struct Obj_15af00 {
    char pad[0x34]; // +0x00
    int m34; // +0x34
    bool FUN_0015af00(int value);
};
// matches/0x0015af40.cpp (stub C_15af40), size 0x40
struct C_15af40 {
    char pad[0x3c]; // +0x00
    int m3c; // +0x3c
    bool FUN_0015af40(int x);
};
// matches/0x0015afa0.cpp (stub C_15afa0), size 0x50
struct C_15afa0 {
    char pad[0x4c]; // +0x00
    float mRad; // +0x4c
    bool FUN_0015afa0(float deg);
};
// matches/0x0015afd0.cpp (stub Foo_15afd0), size 0x54
struct Foo_15afd0 {
    char pad[0x50]; // +0x00
    float m_rad; // +0x50
    bool FUN_0015afd0(float deg);
};
// matches/0x0015b000.cpp (stub C_15b000), size 0x58
struct C_15b000 {
    char pad[0x54]; // +0x00
    float mAngle; // +0x54
    bool FUN_0015b000(float v);
};
// matches/0x0015b030.cpp (stub C_15b030), size 0x5c
struct C_15b030 {
    char pad[0x58]; // +0x00
    float mDeg; // +0x58
    bool FUN_0015b030(float x);
};
// matches/0x0015b060.cpp (stub C_15b060), size 0x60
struct C_15b060 {
    char pad[0x5c]; // +0x00
    int value; // +0x5c
    bool FUN_0015b060(int x);
};
// matches/0x0015b080.cpp (stub Obj_15b080), size 0x64
struct Obj_15b080 {
    char pad[0x60]; // +0x00
    int value; // +0x60
    bool FUN_0015b080(int x);
};
// matches/0x0015b0a0.cpp (stub Obj_15b0a0), size 0x68
struct Obj_15b0a0 {
    char pad[0x64]; // +0x00
    int value; // +0x64
    bool FUN_0015b0a0(int x);
};
// matches/0x0015b180.cpp (stub Obj_15b180), size 0x90
struct Obj_15b180 {
    char pad[0x8c]; // +0x00
    int mValue; // +0x8c
    bool FUN_0015b180(int value);
};
// matches/0x0015b1a0.cpp (stub Obj_15b1a0), size 0x94
struct Obj_15b1a0 {
    char pad[0x90]; // +0x00
    int m90; // +0x90
    bool FUN_0015b1a0(int x);
};
// matches/0x0015b1c0.cpp (stub Obj_15b1c0), size 0x98
struct Obj_15b1c0 {
    char pad[0x94]; // +0x00
    int value; // +0x94
    bool FUN_0015b1c0(int v);
};
// matches/0x0015b1e0.cpp (stub Obj_15b1e0), size 0x98
struct Obj_15b1e0 {
    char m[0x98]; // +0x00
    char FUN_0015b1e0(int x);
};
// matches/0x0015b210.cpp (stub Obj_15b210), size 0xac
struct Obj_15b210 {
    char pad[0xa8]; // +0x00
    int mValue; // +0xa8
    bool FUN_0015b210(int v);
};
// matches/0x0015b220.cpp (stub Obj), size 0xb8
struct Obj_15b220 {
    char pad[0xac]; // +0x00
    int a; // +0xac
    int b; // +0xb0
    int c; // +0xb4
    bool FUN_0015b220(int* p);
};
// matches/0x0015b250.cpp (stub Obj_15b250), size 0xb8
struct Obj_15b250 {
    char FUN_0015b250(int value);
    char pad[0xb8]; // +0x00
};
// matches/0x0015b270.cpp (stub Obj_15b270), size 0xc0
struct Obj_15b270 {
    char pad[0xbc]; // +0x00
    int mField; // +0xbc
    bool FUN_0015b270(int value);
};
// matches/0x0015b290.cpp (stub Obj_15b290), size 0xc4
struct Obj_15b290 {
    char pad[0xc0]; // +0x00
    int mValue; // +0xc0
    char FUN_0015b290(int value);
};
// matches/0x0015b2b0.cpp (stub Obj_15b2b0), size 0xc8
struct Obj_15b2b0 {
    char pad[0xc4]; // +0x00
    int value; // +0xc4
    bool FUN_0015b2b0(int v);
};
// matches/0x0015b2d0.cpp (stub Obj_15b2d0), size 0xcc
struct Obj_15b2d0 {
    char m0[0xc8]; // +0x00
    int mValue; // +0xc8
    char FUN_0015b2d0(int value);
};
// matches/0x0015b340.cpp (stub Obj_15b340), size 0x10
struct Obj_15b340 {
    char pad[0xc]; // +0x00
    int mVal; // +0x0c
    char FUN_0015b340(int v);
};
// matches/0x0015b350.cpp (stub C_15b350), size 0x14
struct C_15b350 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0015b350(int v);
};
// matches/0x0015b370.cpp (stub X_15b370), size 0x18
struct X_15b370 {
    char pad[0x14]; // +0x00
    int m; // +0x14
    bool FUN_0015b370(int v);
};
// matches/0x0015b390.cpp (stub Thing), size 0x1c
struct Thing_15b390 {
    char pad[0x18]; // +0x00
    float angle; // +0x18
    char FUN_0015b390(float value);
};
// matches/0x0015b3c0.cpp (stub Obj_15b3c0), size 0x20
struct Obj_15b3c0 {
    char pad[0x1c]; // +0x00
    int mX; // +0x1c
    bool FUN_0015b3c0(int v);
};
// matches/0x0015b3e0.cpp (stub O_15b3e0), size 0x24
struct O_15b3e0 {
    char FUN_0015b3e0(int x);
    char pad[0x20]; // +0x00
    int m; // +0x20
};
// matches/0x0015b400.cpp (stub Obj_15b400), size 0x28
struct Obj_15b400 {
    char pad[0x24]; // +0x00
    int mVal; // +0x24
    bool FUN_0015b400(int x);
};
// matches/0x0015b420.cpp (stub Obj_15b420), size 0x30
struct Obj_15b420 {
    char pad[0x30]; // +0x00
    char* FUN_0015b420();
};
// matches/0x0015b430.cpp (stub O_15b430), size 0x38
struct O_15b430 {
    char pad[0x38]; // +0x00
    char* FUN_0015b430();
};
// matches/0x0015b460.cpp (stub Obj_15b460), size 0x49
struct Obj_15b460 {
    char pad[0x48]; // +0x00
    char f48; // +0x48
    char FUN_0015b460(char c);
};
// matches/0x0015b470.cpp (stub Obj_15b470), size 0x50
struct Obj_15b470 {
    char pad[0x50]; // +0x00
    char* FUN_0015b470();
};
// matches/0x0015b490.cpp (stub X_15b490), size 0x5c
struct X_15b490 {
    char FUN_0015b490(int v);
    char pad[0x58]; // +0x00
    int m58; // +0x58
};
// matches/0x0015b4b0.cpp (stub Obj_15b4b0), size 0x60
struct Obj_15b4b0 {
    char pad[0x5c]; // +0x00
    int mVal; // +0x5c
    bool FUN_0015b4b0(int v);
};
// matches/0x0015b4d0.cpp (stub Obj_15b4d0), size 0x64
struct Obj_15b4d0 {
    char pad[0x60]; // +0x00
    int mValue; // +0x60
    bool FUN_0015b4d0(int param);
};
// matches/0x0015b4e0.cpp (stub Obj_15b4e0), size 0x10
struct Obj_15b4e0 {
    char FUN_0015b4e0(int value);
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
};
// matches/0x0015b4f0.cpp (stub Obj_15b4f0), size 0x14
struct Obj_15b4f0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0015b4f0(int v);
};
// matches/0x0015b510.cpp (stub X_15b510), size 0x18
struct X_15b510 {
    char p14[0x14]; // +0x00
    int m14; // +0x14
    char FUN_0015b510(int v);
};
// matches/0x0015b530.cpp (stub Angle), size 0x1c
struct Angle_15b530 {
    char pad[0x18]; // +0x00
    float angle; // +0x18
    bool FUN_0015b530(float x);
};
// matches/0x0015b560.cpp (stub Angle), size 0x20
struct Angle_15b560 {
    char pad[0x1c]; // +0x00
    float value; // +0x1c
    char FUN_0015b560(float angle);
};
// matches/0x0015b590.cpp (stub X_15b590), size 0x24
struct X_15b590 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_0015b590(int v);
};
// matches/0x0015b5b0.cpp (stub Obj_15b5b0), size 0x24
struct Obj_15b5b0 {
    char FUN_0015b5b0(int value);
    char pad[0x24]; // +0x00
};
// matches/0x0015b5d0.cpp (stub A_15b5d0), size 0x2c (0x30)
struct A_15b5d0 {
    char pad[0x28]; // +0x00
    void* mThing; // +0x28
    bool FUN_0015b5d0(void* p);
};
// matches/0x0015b610.cpp (stub Obj_15b610), size 0x48
struct Obj_15b610 {
    char pad[0x48]; // +0x00
    char* FUN_0015b610();
};
// matches/0x0015b620.cpp (stub Obj_15b620), size 0x50
struct Obj_15b620 {
    char pad[0x50]; // +0x00
    void* FUN_0015b620();
};
// matches/0x0015b640.cpp (stub Obj_15b640), size 0x5c
struct Obj_15b640 {
    char pad[0x58]; // +0x00
    int value; // +0x58
    bool FUN_0015b640(int x);
};
// matches/0x0015b660.cpp (stub X_15b660), size 0x60
struct X_15b660 {
    char pad[0x5c]; // +0x00
    int m5c; // +0x5c
    bool FUN_0015b660(int v);
};
// matches/0x0015b680.cpp (stub Obj_15b680), size 0x64
struct Obj_15b680 {
    char pad[0x60]; // +0x00
    int value; // +0x60
    bool FUN_0015b680(int x);
};
// matches/0x0015b690.cpp (stub Obj_15b690), size 0x10
struct Obj_15b690 {
    char pad[12]; // +0x00
    int value; // +0x0c
    char FUN_0015b690(int x);
};
// matches/0x0015b6a0.cpp (stub Obj_15b6a0), size 0x14
struct Obj_15b6a0 {
    char pad[0x10]; // +0x00
    int mVal; // +0x10
    bool FUN_0015b6a0(int v);
};
// matches/0x0015b6b0.cpp (stub Obj_15b6b0), size 0x18
struct Obj_15b6b0 {
    char pad[0x18]; // +0x00
    void* FUN_0015b6b0();
};
// matches/0x0015b6c0.cpp (stub Obj_15b6c0), size 0x20
struct Obj_15b6c0 {
    char pad[0x20]; // +0x00
    void* FUN_0015b6c0();
};
// matches/0x0015b6f0.cpp (stub Obj_15b6f0), size 0x38
struct Obj_15b6f0 {
    char pad[0x38]; // +0x00
    void* FUN_0015b6f0();
};
// matches/0x0015b710.cpp (stub Obj_15b710), size 0x44
struct Obj_15b710 {
    char pad[0x40]; // +0x00
    int mValue; // +0x40
    bool FUN_0015b710(int v);
};
// matches/0x0015b730.cpp (stub Obj_15b730), size 0x48
struct Obj_15b730 {
    char pad[0x44]; // +0x00
    int mVal; // +0x44
    bool FUN_0015b730(int v);
};
// matches/0x0015b750.cpp (stub Obj_15b750), size 0x49
struct Obj_15b750 {
    char pad[0x48]; // +0x00
    char flag; // +0x48
    char FUN_0015b750(int a);
};
// matches/0x001653e0.cpp (stub Obj_1653e0), size 0x10
struct Obj_1653e0 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    char FUN_001653e0(int v);
};
// matches/0x001653f0.cpp (stub X_1653f0), size 0x1
struct X_1653f0 {
    char FUN_001653f0(int);
};
// matches/0x00165400.cpp (stub Obj_165400), size 0x10
struct Obj_165400 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    bool FUN_00165400(int value);
};
// matches/0x00165410.cpp (stub Obj_165410), size 0x14
struct Obj_165410 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_00165410(int value);
};
// matches/0x00165420.cpp (stub X_165420), size 0x10
struct X_165420 {
    bool FUN_00165420(int v);
    char pad[12]; // +0x00
    int m; // +0x0c
};
// matches/0x00165440.cpp (stub A_165440), size 0x10
struct A_165440 {
    char pad[0x10]; // +0x00
    void* FUN_00165440();
};
// matches/0x001654e0.cpp (stub Obj_1654e0), size 0x34
struct Obj_1654e0 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_001654e0(int x);
};
// matches/0x00165500.cpp (stub X_165500), size 0x35
struct X_165500 {
    char pad[0x34]; // +0x00
    char m34; // +0x34
    char FUN_00165500(char v);
};
// matches/0x00165510.cpp (stub X_165510), size 0x10
struct X_165510 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    char FUN_00165510(int v);
};
// matches/0x00165520.cpp (stub Thing), size 0x14
struct Thing_165520 {
    char pad[16]; // +0x00
    float angle; // +0x10
    char FUN_00165520(float x);
};
// matches/0x001655c0.cpp (stub Obj_1655c0), size 0x14 (0x18)
struct Obj_1655c0 {
    char pad[0x10]; // +0x00
    int* ptr; // +0x10
    int* FUN_001655c0();
};
// matches/0x00165620.cpp (stub Obj_165620), size 0x28
struct Obj_165620 {
    char Pad[0x24]; // +0x00
    int Value; // +0x24
    char FUN_00165620(int x);
};
// matches/0x00165640.cpp (stub X_165640), size 0x2c
struct X_165640 {
    char FUN_00165640(int v);
    char mPad[0x28]; // +0x00
    int mVal; // +0x28
};
// matches/0x00165660.cpp (stub X_165660), size 0x30
struct X_165660 {
    char pad[0x2c]; // +0x00
    int m; // +0x2c
    char FUN_00165660(int v);
};
// matches/0x00165680.cpp (stub Obj_165680), size 0x31
struct Obj_165680 {
    char pad[0x30]; // +0x00
    char m30; // +0x30
    char FUN_00165680(char v);
};
// matches/0x00165690.cpp (stub Obj), size 0xd
struct Obj_165690 {
    char pad[12]; // +0x00
    char value; // +0x0c
    bool FUN_00165690(char v);
};
// matches/0x001656a0.cpp (stub Obj_1656a0), size 0xc
struct Obj_1656a0 {
    char m[0xc]; // +0x00
    char FUN_001656a0(int v);
};
// matches/0x001656b0.cpp (stub X_1656b0), size 0x14
struct X_1656b0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_001656b0(int value);
};
// matches/0x001656e0.cpp (stub X_1656e0), size 0x10
struct X_1656e0 {
    char FUN_001656e0(int a);
    char pad[12]; // +0x00
    int m; // +0x0c
};
// matches/0x00165700.cpp (stub Obj_165700), size 0x14
struct Obj_165700 {
    char pad[0x10]; // +0x00
    int mField; // +0x10
    char FUN_00165700(int v);
};
// matches/0x00165750.cpp (stub C_165750), size 0xc
struct C_165750 {
    char pad[12]; // +0x00
    bool FUN_00165750(int a);
};
// matches/0x00165770.cpp (stub Obj_165770), size 0x14
struct Obj_165770 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_00165770(int v);
};
// matches/0x00165780.cpp (stub Obj_165780), size 0x10
struct Obj_165780 {
    char pad[0xc]; // +0x00
    float mAngle; // +0x0c
    char FUN_00165780(float v);
};
// matches/0x001657a0.cpp (stub A_1657a0), size 0x14
struct A_1657a0 {
    char pad[0x10]; // +0x00
    float f; // +0x10
    bool FUN_001657a0(float v);
};
// matches/0x001657c0.cpp (stub Obj_1657c0), size 0x10
struct Obj_1657c0 {
    char pad[0x10]; // +0x00
    void* FUN_001657c0();
};
// matches/0x00165860.cpp (stub Target_165860), size 0x30
struct Target_165860 {
    char pad[0x30]; // +0x00
    char FUN_00165860(int arg);
};
// matches/0x00165880.cpp (stub A_165880), size 0x35
struct A_165880 {
    char pad[0x34]; // +0x00
    char m34; // +0x34
    char FUN_00165880(char x);
};
// matches/0x001658a0.cpp (stub T_1658a0), size 0x36
struct T_1658a0 {
    char pad[0x35]; // +0x00
    unsigned char m35; // +0x35
    unsigned char FUN_001658a0(unsigned char v);
};
// matches/0x001658c0.cpp (stub Obj_1658c0), size 0x3c
struct Obj_1658c0 {
    char Pad[0x38]; // +0x00
    int m38; // +0x38
    bool FUN_001658c0(int x);
};
// matches/0x001658d0.cpp (stub T_1658d0), size 0xc
struct T_1658d0 {
    char m[12]; // +0x00
    char FUN_001658d0(char c);
};
// matches/0x001658e0.cpp (stub Obj), size 0x10
struct Obj_1658e0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_001658e0(int v);
};
// matches/0x001658f0.cpp (stub X_1658f0), size 0x1
struct X_1658f0 {
    char FUN_001658f0(int v);
};
// matches/0x00165900.cpp (stub Angle), size 0x10
struct Angle_165900 {
    char pad[12]; // +0x00
    float val; // +0x0c
    char FUN_00165900(float x);
};
// matches/0x00165920.cpp (stub O_165920), size 0x14
struct O_165920 {
    char pad[0x10]; // +0x00
    float m; // +0x10
    bool FUN_00165920(float value);
};
// matches/0x00165960.cpp (stub X_165960), size 0xd
struct X_165960 {
    char pad[0xc]; // +0x00
    unsigned char value; // +0x0c
    unsigned char FUN_00165960(unsigned char a);
};
// matches/0x00165970.cpp (stub O_165970), size 0x10
struct O_165970 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    bool FUN_00165970(int v);
};
// matches/0x00165980.cpp (stub C_165980), size 0x14
struct C_165980 {
    char Pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_00165980(int value);
};
// matches/0x001659a0.cpp (stub Obj_1659a0), size 0xd
struct Obj_1659a0 {
    char pad[12]; // +0x00
    char mValue; // +0x0c
    char FUN_001659a0(char x);
};
// matches/0x001659b0.cpp (stub X_1659b0), size 0x10
struct X_1659b0 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_001659b0(int value);
};
// matches/0x001659c0.cpp (stub Obj_1659c0), size 0x14
struct Obj_1659c0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_001659c0(int x);
};
// equivalent/0x00166230.cpp (stub Thing), size 0x10 (0x18)
struct Thing_166230 {
    char pad[12]; // +0x00
    char *text; // +0x0c (+0x10)
    bool FUN_00166230(const char *source);
};
// matches/0x0016e720.cpp (stub Obj_16e720), size 0x10
struct Obj_16e720 {
    char pad[12]; // +0x00
    int m; // +0x0c
    bool FUN_0016e720(int x);
};
// matches/0x0016e730.cpp (stub Obj_16e730), size 0x14
struct Obj_16e730 {
    char pad[0x10]; // +0x00
    int mVal; // +0x10
    bool FUN_0016e730(int v);
};
// matches/0x0016e740.cpp (stub A_16e740), size 0x1c
struct A_16e740 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    int* FUN_0016e740();
};
// matches/0x0016e7e0.cpp (stub A_16e7e0), size 0x3c
struct A_16e7e0 {
    char pad[0x38]; // +0x00
    float value; // +0x38
    char FUN_0016e7e0(float degrees);
};
// matches/0x0016e810.cpp (stub Obj), size 0x40
struct Obj_16e810 {
    char pad[0x3c]; // +0x00
    float angle; // +0x3c
    bool FUN_0016e810(float x);
};
// matches/0x0016e840.cpp (stub Obj), size 0x44
struct Obj_16e840 {
    char pad[0x40]; // +0x00
    float angle; // +0x40
    char FUN_0016e840(float v);
};
// matches/0x0016e870.cpp (stub X_16e870), size 0x1
struct X_16e870 {
    char FUN_0016e870(float x);
};
// matches/0x0016e8a0.cpp (stub Obj_16e8a0), size 0x4c
struct Obj_16e8a0 {
    char Pad[0x48]; // +0x00
    float Value; // +0x48
    char FUN_0016e8a0(float x);
};
// matches/0x0016e8d0.cpp (stub C_16e8d0), size 0x4d
struct C_16e8d0 {
    char pad[0x4c]; // +0x00
    unsigned char m4c; // +0x4c
    bool FUN_0016e8d0(unsigned char v);
};
// matches/0x0016e8f0.cpp (stub Target_16e8f0), size 0x54
struct Target_16e8f0 {
    char pad[0x50]; // +0x00
    float value; // +0x50
    char FUN_0016e8f0(float x);
};
// matches/0x0016e920.cpp (stub Obj_16e920), size 0x58
struct Obj_16e920 {
    char Pad[0x54]; // +0x00
    int Value; // +0x54
    char FUN_0016e920(int x);
};
// matches/0x0016e940.cpp (stub Obj_16e940), size 0x5c
struct Obj_16e940 {
    char pad[0x58]; // +0x00
    int field; // +0x58
    bool FUN_0016e940(int x);
};
// matches/0x0016e960.cpp (stub Obj_16e960), size 0x60
struct Obj_16e960 {
    char pad[0x5c]; // +0x00
    int mVal; // +0x5c
    char FUN_0016e960(int x);
};
// matches/0x0016e980.cpp (stub Obj_16e980), size 0x64
struct Obj_16e980 {
    char pad[0x60]; // +0x00
    int m60; // +0x60
    bool FUN_0016e980(int v);
};
// matches/0x0016e9a0.cpp (stub Obj_16e9a0), size 0x68
struct Obj_16e9a0 {
    char FUN_0016e9a0(int v);
    char pad[0x64]; // +0x00
    int m64; // +0x64
};
// matches/0x0016e9b0.cpp (stub Obj_16e9b0), size 0x10
struct Obj_16e9b0 {
    char FUN_0016e9b0(int v);
    char mPad[12]; // +0x00
    int mVal; // +0x0c
};
// matches/0x0016e9c0.cpp (stub Obj_16e9c0), size 0x14 (0x18)
struct Obj_16e9c0 {
    char pad[0x10]; // +0x00
    int* mPtr; // +0x10
    char FUN_0016e9c0(int* p);
};
// matches/0x0016e9e0.cpp (stub Obj_16e9e0), size 0x18
struct Obj_16e9e0 {
    char pad[0x14]; // +0x00
    int mVal; // +0x14
    unsigned char FUN_0016e9e0(int v);
};
// matches/0x0016ea00.cpp (stub O_16ea00), size 0x19
struct O_16ea00 {
    char pad[0x18]; // +0x00
    char m18a; // +0x18
    char FUN_0016ea00(char v);
};
// matches/0x0016ea20.cpp (stub O_16ea20), size 0x1c
struct O_16ea20 {
    char pad[0x1c]; // +0x00
    unsigned char FUN_0016ea20(unsigned int x);
};
// matches/0x0016ea30.cpp (stub C_16ea30), size 0x10
struct C_16ea30 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_0016ea30(int v);
};
// matches/0x0016ea40.cpp (stub Foo_16ea40), size 0x14
struct Foo_16ea40 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    char FUN_0016ea40(int v);
};
// matches/0x0016ea50.cpp (stub Obj_16ea50), size 0x18
struct Obj_16ea50 {
    char pad[0x18]; // +0x00
    char* FUN_0016ea50();
};
// matches/0x0016ea70.cpp (stub O_16ea70), size 0x24
struct O_16ea70 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    char FUN_0016ea70(int x);
};
// matches/0x0016ea90.cpp (stub X_16ea90), size 0x28
struct X_16ea90 {
    char pad[0x24]; // +0x00
    int m24; // +0x24
    char FUN_0016ea90(int v);
};
// matches/0x0016eab0.cpp (stub Obj_16eab0), size 0x2c
struct Obj_16eab0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    bool FUN_0016eab0(int v);
};
// matches/0x0016eac0.cpp (stub C_16eac0), size 0x10
struct C_16eac0 {
    char pad[12]; // +0x00
    unsigned int m; // +0x0c
    char FUN_0016eac0(unsigned int x);
};
// matches/0x0016ead0.cpp (stub Obj_16ead0), size 0x10
struct Obj_16ead0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    char FUN_0016ead0(int x);
};
// matches/0x0016eae0.cpp (stub Obj_16eae0), size 0x14
struct Obj_16eae0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0016eae0(int x);
};
// matches/0x0016eaf0.cpp (stub Obj_16eaf0), size 0x18
struct Obj_16eaf0 {
    char pad[0x18]; // +0x00
    char* FUN_0016eaf0();
};
// matches/0x0016eb10.cpp (stub Obj_16eb10), size 0x22
struct Obj_16eb10 {
    char pad[32]; // +0x00
    char m20; // +0x20
    char m21; // +0x21
    char FUN_0016eb10(char v);
};
// matches/0x0016eb30.cpp (stub Obj_16eb30), size 0x22
struct Obj_16eb30 {
    char pad[0x21]; // +0x00
    unsigned char value; // +0x21
    unsigned char FUN_0016eb30(unsigned char c);
};
// matches/0x0016eb90.cpp (stub Obj_16eb90), size 0x31
struct Obj_16eb90 {
    char Pad[0x30]; // +0x00
    char Value; // +0x30
    char FUN_0016eb90(char x);
};
// matches/0x0016ebc0.cpp (stub Obj), size 0x40
struct Obj_16ebc0 {
    char pad[0x34]; // +0x00
    volatile float x; // +0x34
    float y; // +0x38
    volatile float z; // +0x3c
    unsigned char FUN_0016ebc0(const volatile float* p);
};
// matches/0x0016ec10.cpp (stub Obj_16ec10), size 0x44
struct Obj_16ec10 {
    char pad[0x40]; // +0x00
    int value; // +0x40
    unsigned char FUN_0016ec10(int x);
};
// matches/0x0016ec30.cpp (stub X_16ec30), size 0x48
struct X_16ec30 {
    char pad[0x44]; // +0x00
    int m44; // +0x44
    char FUN_0016ec30(int a);
};
// matches/0x0016ec50.cpp (stub Obj_16ec50), size 0x4c
struct Obj_16ec50 {
    char pad[0x48]; // +0x00
    int value; // +0x48
    bool FUN_0016ec50(int x);
};
// matches/0x0016ec60.cpp (stub Obj_16ec60), size 0x10
struct Obj_16ec60 {
    char Pad[0xc]; // +0x00
    int mVal; // +0x0c
    char FUN_0016ec60(int v);
};
// matches/0x0016ec70.cpp (stub Obj_16ec70), size 0x14
struct Obj_16ec70 {
    bool FUN_0016ec70(int v);
    char pad[16]; // +0x00
    int mValue; // +0x10
};
// matches/0x0016ec90.cpp (stub Obj_16ec90), size 0x18
struct Obj_16ec90 {
    char pad[0x14]; // +0x00
    int field; // +0x14
    bool FUN_0016ec90(int value);
};
// matches/0x0016ecb0.cpp (stub Obj_16ecb0), size 0x1c
struct Obj_16ecb0 {
    char pad[0x18]; // +0x00
    int mValue; // +0x18
    bool FUN_0016ecb0(int v);
};
// matches/0x0016ecc0.cpp (stub Obj_16ecc0), size 0x24
struct Obj_16ecc0 {
    char pad[0x20]; // +0x00
    int m; // +0x20
    int* FUN_0016ecc0();
};
// matches/0x0016ed00.cpp (stub Obj_16ed00), size 0x34
struct Obj_16ed00 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_0016ed00(int v);
};
// matches/0x0016ed20.cpp (stub Obj_16ed20), size 0x38
struct Obj_16ed20 {
    char pad[0x34]; // +0x00
    float m; // +0x34
    char FUN_0016ed20(float v);
};
// matches/0x0016ed90.cpp (stub Obj_16ed90), size 0x48
struct Obj_16ed90 {
    char FUN_0016ed90(int x);
    char pad[0x44]; // +0x00
    int mVal; // +0x44
};
// matches/0x0016edb0.cpp (stub X_16edb0), size 0x4c
struct X_16edb0 {
    char FUN_0016edb0(int value);
    char pad[0x48]; // +0x00
    int m48; // +0x48
};
// matches/0x0016edd0.cpp (stub Obj_16edd0), size 0x50
struct Obj_16edd0 {
    char pad[0x4c]; // +0x00
    int mValue; // +0x4c
    char FUN_0016edd0(int v);
};
// matches/0x0016ede0.cpp (stub X_16ede0), size 0x10
struct X_16ede0 {
    char Pad0[12]; // +0x00
    int mValue; // +0x0c
    char FUN_0016ede0(int v);
};
// matches/0x0016edf0.cpp (stub Obj_16edf0), size 0x14
struct Obj_16edf0 {
    char FUN_0016edf0(int x);
    char pad[0x10]; // +0x00
    int mValue; // +0x10
};
// matches/0x0016ee10.cpp (stub X_16ee10), size 0x18
struct X_16ee10 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    char FUN_0016ee10(int v);
};
// matches/0x0016ee30.cpp (stub Obj_16ee30), size 0x1c
struct Obj_16ee30 {
    char pad[0x18]; // +0x00
    int mValue; // +0x18
    char FUN_0016ee30(int v);
};
// matches/0x0016ee50.cpp (stub O_16ee50), size 0x20
struct O_16ee50 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    bool FUN_0016ee50(int x);
};
// matches/0x0016ee70.cpp (stub Obj_16ee70), size 0x24
struct Obj_16ee70 {
    char pad[0x20]; // +0x00
    int value; // +0x20
    char FUN_0016ee70(int x);
};
// matches/0x0016ee80.cpp (stub X_16ee80), size 0x10
struct X_16ee80 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    bool FUN_0016ee80(int a);
};
// matches/0x0016eea0.cpp (stub C_16eea0), size 0x14
struct C_16eea0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_0016eea0(int a);
};
// matches/0x0016eeb0.cpp (stub X_16eeb0), size 0x10
struct X_16eeb0 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    bool FUN_0016eeb0(int v);
};
// matches/0x0016eed0.cpp (stub C_16eed0), size 0x14
struct C_16eed0 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0016eed0(int value);
};
// matches/0x0016eef0.cpp (stub X_16eef0), size 0x18
struct X_16eef0 {
    char pad[0x14]; // +0x00
    int m; // +0x14
    bool FUN_0016eef0(int v);
};
// matches/0x0016ef00.cpp (stub Obj_16ef00), size 0x18
struct Obj_16ef00 {
    char pad[0x18]; // +0x00
    void* FUN_0016ef00();
};
// matches/0x0016efb0.cpp (stub Obj_16efb0), size 0x44 (0x48)
struct Obj_16efb0 {
    char pad[0x40]; // +0x00
    void* field; // +0x40
    char FUN_0016efb0(void* x);
};
// matches/0x0016efd0.cpp (stub Thing_16efd0), size 0x48
struct Thing_16efd0 {
    char pad[0x44]; // +0x00
    int mValue; // +0x44
    bool FUN_0016efd0(int x);
};
// matches/0x0016eff0.cpp (stub Obj_16eff0), size 0x48
struct Obj_16eff0 {
    char m[0x48]; // +0x00
    char FUN_0016eff0(int v);
};
// matches/0x0016f010.cpp (stub X_16f010), size 0x50
struct X_16f010 {
    char FUN_0016f010(int x);
    char pad[0x4c]; // +0x00
    int mValue; // +0x4c
};
// matches/0x0016f030.cpp (stub X_16f030), size 0x54
struct X_16f030 {
    char pad[0x50]; // +0x00
    int mValue; // +0x50
    bool FUN_0016f030(int value);
};
// matches/0x0016f050.cpp (stub X_16f050), size 0x55
struct X_16f050 {
    char FUN_0016f050(char b);
    char pad[0x54]; // +0x00
    char m54; // +0x54
};
// matches/0x0016f060.cpp (stub X_16f060), size 0x5c
struct X_16f060 {
    char pad[0x58]; // +0x00
    int value; // +0x58
    char FUN_0016f060(int value);
};
// matches/0x0016f070.cpp (stub Obj_16f070), size 0x60
struct Obj_16f070 {
    char pad[0x5c]; // +0x00
    int mFlag; // +0x5c
    bool FUN_0016f070(int value);
};
// matches/0x0016f080.cpp (stub Obj_16f080), size 0x64
struct Obj_16f080 {
    char pad[0x60]; // +0x00
    int mValue; // +0x60
    bool FUN_0016f080(int v);
};
// matches/0x0016f090.cpp (stub X_16f090), size 0x10
struct X_16f090 {
    char pad[0xc]; // +0x00
    int mX; // +0x0c
    bool FUN_0016f090(int x);
};
// matches/0x0016f0a0.cpp (stub Obj_16f0a0), size 0x14
struct Obj_16f0a0 {
    char Pad[0x10]; // +0x00
    int Value; // +0x10
    char FUN_0016f0a0(int v);
};
// matches/0x0016f0c0.cpp (stub C_16f0c0), size 0x1
struct C_16f0c0 {
    char FUN_0016f0c0(char x);
};
// matches/0x0016f120.cpp (stub Obj_16f120), size 0x25
struct Obj_16f120 {
    unsigned char FUN_0016f120(unsigned char x);
    char pad[0x24]; // +0x00
    unsigned char m24; // +0x24
};
// matches/0x0016f140.cpp (stub X_16f140), size 0x26
struct X_16f140 {
    char pad[0x25]; // +0x00
    char m; // +0x25
    bool FUN_0016f140(char c);
};
// matches/0x0016f240.cpp (stub X_16f240), size 0x10
struct X_16f240 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    bool FUN_0016f240(int v);
};
// matches/0x0016f250.cpp (stub Obj_16f250), size 0x10 (0x18)
struct Obj_16f250 {
    void* vptr; // +0x00
    float f; // +0x04 (+0x08)
    char pad[4]; // +0x08 (+0x0c)
    int mC; // +0x0c (+0x10)
    char FUN_0016f250(int x);
};
// matches/0x0016f260.cpp (stub X_16f260), size 0x14
struct X_16f260 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    char FUN_0016f260(int v);
};
// matches/0x0016f270.cpp (stub Obj_16f270), size 0x18
struct Obj_16f270 {
    char pad[0x18]; // +0x00
    void* FUN_0016f270();
};
// matches/0x0016f310.cpp (stub X_16f310), size 0x3c
struct X_16f310 {
    char FUN_0016f310(int v);
    char pad[0x38]; // +0x00
    int m38; // +0x38
};
// matches/0x0016f330.cpp (stub Thing), size 0x40
struct Thing_16f330 {
    char pad[0x3c]; // +0x00
    int value; // +0x3c
    char FUN_0016f330(int x);
};
// matches/0x0016f350.cpp (stub X_16f350), size 0x41
struct X_16f350 {
    char FUN_0016f350(char c);
    char pad[0x40]; // +0x00
    char m40; // +0x40
};
// matches/0x0016f360.cpp (stub Obj_16f360), size 0xc
struct Obj_16f360 {
    char m[0xc]; // +0x00
    char FUN_0016f360(int x);
};
// matches/0x0016f3b0.cpp (stub Obj_16f3b0), size 0x10
struct Obj_16f3b0 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    char FUN_0016f3b0(int x);
};
// matches/0x0016f3c0.cpp (stub Obj_16f3c0), size 0x14
struct Obj_16f3c0 {
    char pad[0x10]; // +0x00
    int mVal; // +0x10
    bool FUN_0016f3c0(int v);
};
// matches/0x0016f3d0.cpp (stub O_16f3d0), size 0x18
struct O_16f3d0 {
    char pad[0x18]; // +0x00
    void* FUN_0016f3d0();
};
// matches/0x0016f470.cpp (stub Obj_16f470), size 0x3c
struct Obj_16f470 {
    char Pad[0x38]; // +0x00
    float Value; // +0x38
    char FUN_0016f470(float x);
};
// matches/0x0016f4a0.cpp (stub Obj_16f4a0), size 0x1
struct Obj_16f4a0 {
    bool FUN_0016f4a0(float a);
};
// matches/0x0016f4d0.cpp (stub Obj_16f4d0), size 0x44
struct Obj_16f4d0 {
    char pad[0x40]; // +0x00
    float m_angle; // +0x40
    bool FUN_0016f4d0(float angle);
};
// matches/0x0016f500.cpp (stub Obj_16f500), size 0x45
struct Obj_16f500 {
    char pad[0x44]; // +0x00
    char m; // +0x44
    unsigned char FUN_0016f500(unsigned char a);
};
// matches/0x0016f520.cpp (stub Obj_16f520), size 0x4c
struct Obj_16f520 {
    char pad[0x48]; // +0x00
    float angle; // +0x48
    char FUN_0016f520(float v);
};
// matches/0x0016f550.cpp (stub Obj_16f550), size 0x50
struct Obj_16f550 {
    char pad[0x4c]; // +0x00
    int m4c; // +0x4c
    char FUN_0016f550(int x);
};
// matches/0x0016f570.cpp (stub Obj_16f570), size 0x58
struct Obj_16f570 {
    char pad[0x50]; // +0x00
    int value; // +0x50
    char ret; // +0x54
    char FUN_0016f570(int v);
};
// matches/0x0016f590.cpp (stub X_16f590), size 0x58
struct X_16f590 {
    char pad[0x54]; // +0x00
    int m; // +0x54
    bool FUN_0016f590(int v);
};
// matches/0x0016f5b0.cpp (stub X_16f5b0), size 0x5c
struct X_16f5b0 {
    char pad[0x58]; // +0x00
    int m58; // +0x58
    bool FUN_0016f5b0(int v);
};
// matches/0x0016f5d0.cpp (stub X_16f5d0), size 0x60
struct X_16f5d0 {
    char pad[0x5c]; // +0x00
    int mVal; // +0x5c
    char FUN_0016f5d0(int v);
};
// matches/0x0016f5e0.cpp (stub Obj_16f5e0), size 0x10
struct Obj_16f5e0 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    bool FUN_0016f5e0(int x);
};
// matches/0x0016f5f0.cpp (stub Obj_16f5f0), size 0x10
struct Obj_16f5f0 {
    char pad[0x10]; // +0x00
    bool FUN_0016f5f0(int value);
};
// matches/0x0016f610.cpp (stub Obj_16f610), size 0x18
struct Obj_16f610 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    bool FUN_0016f610(int x);
};
// matches/0x0016f630.cpp (stub Obj_16f630), size 0x1c
struct Obj_16f630 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    bool FUN_0016f630(int v);
};
// matches/0x0016f650.cpp (stub Target_16f650), size 0x20
struct Target_16f650 {
    char pad[0x1c]; // +0x00
    int m1c; // +0x1c
    char FUN_0016f650(int value);
};
// matches/0x0016f670.cpp (stub O_16f670), size 0x24
struct O_16f670 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_0016f670(int);
};
// matches/0x0016f690.cpp (stub Thing), size 0x28
struct Thing_16f690 {
    char pad[0x24]; // +0x00
    float angle; // +0x24
    bool FUN_0016f690(float v);
};
// matches/0x0016f6c0.cpp (stub Obj_16f6c0), size 0x2c
struct Obj_16f6c0 {
    char pad[0x28]; // +0x00
    float f; // +0x28
    char FUN_0016f6c0(float x);
};
// matches/0x0016f6f0.cpp (stub Obj_16f6f0), size 0x30
struct Obj_16f6f0 {
    char pad[0x2c]; // +0x00
    float m; // +0x2c
    char FUN_0016f6f0(float f);
};
// matches/0x0016f720.cpp (stub Obj), size 0x34
struct Obj_16f720 {
    char pad[0x30]; // +0x00
    float value; // +0x30
    char FUN_0016f720(float x);
};
// matches/0x0016f750.cpp (stub Obj), size 0x38
struct Obj_16f750 {
    char pad[0x34]; // +0x00
    float angle; // +0x34
    char FUN_0016f750(float a);
};
// matches/0x0016f780.cpp (stub Obj), size 0x3c
struct Obj_16f780 {
    char pad[0x38]; // +0x00
    float angle; // +0x38
    char FUN_0016f780(float v);
};
// matches/0x0016f7b0.cpp (stub O_16f7b0), size 0x40
struct O_16f7b0 {
    char Pad[0x3c]; // +0x00
    int m3c; // +0x3c
    char FUN_0016f7b0(int v);
};
// matches/0x0016f7d0.cpp (stub Obj_16f7d0), size 0x44
struct Obj_16f7d0 {
    char Pad[0x40]; // +0x00
    int mValue; // +0x40
    char FUN_0016f7d0(int v);
};
// matches/0x0016f7f0.cpp (stub Obj_16f7f0), size 0x48
struct Obj_16f7f0 {
    char pad[0x44]; // +0x00
    int value; // +0x44
    char FUN_0016f7f0(int x);
};
// matches/0x0016f800.cpp (stub Obj_16f800), size 0x10
struct Obj_16f800 {
    char pad[12]; // +0x00
    int mVal; // +0x0c
    bool FUN_0016f800(int v);
};
// matches/0x0016f810.cpp (stub Obj_16f810), size 0x14
struct Obj_16f810 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_0016f810(int v);
};
// matches/0x0016f830.cpp (stub Obj_16f830), size 0x18
struct Obj_16f830 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    bool FUN_0016f830(int arg);
};
// matches/0x0016f850.cpp (stub Obj_16f850), size 0x1c
struct Obj_16f850 {
    char pad[0x18]; // +0x00
    int mValue; // +0x18
    char FUN_0016f850(int v);
};
// matches/0x0016f870.cpp (stub X_16f870), size 0x20
struct X_16f870 {
    char pad[0x1c]; // +0x00
    int mField; // +0x1c
    bool FUN_0016f870(int value);
};
// matches/0x0016f8b0.cpp (stub Obj_16f8b0), size 0x1
struct Obj_16f8b0 {
    char FUN_0016f8b0(int v);
};
// matches/0x0016f8c0.cpp (stub Obj_16f8c0), size 0x14
struct Obj_16f8c0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_0016f8c0(int x);
};
// matches/0x0016f8e0.cpp (stub X_16f8e0), size 0x18
struct X_16f8e0 {
    char pad[0x14]; // +0x00
    int m; // +0x14
    bool FUN_0016f8e0(int x);
};
// matches/0x0016f900.cpp (stub Obj_16f900), size 0x1c
struct Obj_16f900 {
    char pad[0x18]; // +0x00
    int mVal; // +0x18
    bool FUN_0016f900(int v);
};
// matches/0x0016f920.cpp (stub C_16f920), size 0x20
struct C_16f920 {
    char FUN_0016f920(int v);
    char pad[0x1c]; // +0x00
    int m; // +0x1c
};
// matches/0x0016f9e0.cpp (stub X_16f9e0), size 0x10
struct X_16f9e0 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    bool FUN_0016f9e0(int v);
};
// matches/0x0016f9f0.cpp (stub Obj_16f9f0), size 0x14
struct Obj_16f9f0 {
    char m[16]; // +0x00
    int m10; // +0x10
    char FUN_0016f9f0(int x) throw();
};
// matches/0x0016faa0.cpp (stub Obj_16faa0), size 0x10
struct Obj_16faa0 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    char FUN_0016faa0(int v);
};
// matches/0x0016fac0.cpp (stub Obj_16fac0), size 0x11
struct Obj_16fac0 {
    char pad[0x10]; // +0x00
    char value; // +0x10
    char FUN_0016fac0(char v);
};
// matches/0x0016fad0.cpp (stub C_16fad0), size 0xc
struct C_16fad0 {
    char FUN_0016fad0(int x);
    char pad[0xc]; // +0x00
};
// matches/0x0016fae0.cpp (stub Obj_16fae0), size 0x14
struct Obj_16fae0 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    char FUN_0016fae0(int x);
};
// matches/0x0016faf0.cpp (stub X_16faf0), size 0x18
struct X_16faf0 {
    char pad[0x18]; // +0x00
    void* FUN_0016faf0();
};
// matches/0x0016fb20.cpp (stub A_16fb20), size 0x2c
struct A_16fb20 {
    char pad[0x20]; // +0x00
    int a; // +0x20
    int b; // +0x24
    int c; // +0x28
    bool FUN_0016fb20(int* x);
};
// matches/0x0016fb50.cpp (stub X_16fb50), size 0x30
struct X_16fb50 {
    char pad[0x2c]; // +0x00
    float value; // +0x2c
    unsigned char FUN_0016fb50(float angle);
};
// matches/0x0016fb80.cpp (stub Obj_16fb80), size 0x34
struct Obj_16fb80 {
    char pad[0x30]; // +0x00
    float angle; // +0x30
    char FUN_0016fb80(float deg);
};
// matches/0x0016fbb0.cpp (stub C_16fbb0), size 0x35
struct C_16fbb0 {
    char pad[0x34]; // +0x00
    char m34; // +0x34
    bool FUN_0016fbb0(char c);
};
// matches/0x0016fbd0.cpp (stub Obj_16fbd0), size 0x3c
struct Obj_16fbd0 {
    char pad[0x38]; // +0x00
    int m38; // +0x38
    char FUN_0016fbd0(int a);
};
// matches/0x0016fbf0.cpp (stub X_16fbf0), size 0x1
struct X_16fbf0 {
    char FUN_0016fbf0(int v);
};
// matches/0x0016fc10.cpp (stub Obj_16fc10), size 0x44
struct Obj_16fc10 {
    char pad[0x40]; // +0x00
    int m40; // +0x40
    bool FUN_0016fc10(int v);
};
// matches/0x0016fc60.cpp (stub Thing_16fc60), size 0xa4
struct Thing_16fc60 {
    char pad[0x98]; // +0x00
    int a; // +0x98
    int b; // +0x9c
    int c; // +0xa0
    void FUN_0016fc60(int* out);
};
// matches/0x00170130.cpp (stub StrHolder_170130), size 0x30 (0x38)
struct StrHolder_170130 {
    char pad[40]; // +0x00
    char* text; // +0x28
    int length; // +0x2c (+0x30)
    bool FUN_00170130(const char* src, int len);
};
// matches/0x0017f2b0.cpp (stub Obj_17f2b0), size 0x10
struct Obj_17f2b0 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    char FUN_0017f2b0(int v);
};
// matches/0x0017f2d0.cpp (stub O_17f2d0), size 0x11
struct O_17f2d0 {
    char pad[0x10]; // +0x00
    unsigned char v; // +0x10
    unsigned char FUN_0017f2d0(char x);
};
// matches/0x0017f2f0.cpp (stub Obj_17f2f0), size 0xd
struct Obj_17f2f0 {
    char m_pad[12]; // +0x00
    char m_val; // +0x0c
    char FUN_0017f2f0(char c);
};
// matches/0x0017f310.cpp (stub Obj_17f310), size 0x14
struct Obj_17f310 {
    char Pad[0x10]; // +0x00
    int mVal; // +0x10
    char FUN_0017f310(int v);
};
// matches/0x0017f330.cpp (stub Obj_17f330), size 0x15
struct Obj_17f330 {
    char m0[0x14]; // +0x00
    char m14; // +0x14
    char FUN_0017f330(char x);
};
// matches/0x0017f350.cpp (stub X_17f350), size 0x16
struct X_17f350 {
    char FUN_0017f350(unsigned char b);
    char pad[0x15]; // +0x00
    unsigned char value; // +0x15
};
// matches/0x0017f370.cpp (stub X_17f370), size 0x17
struct X_17f370 {
    char pad[0x16]; // +0x00
    char m; // +0x16
    char FUN_0017f370(char c);
};
// matches/0x0017f390.cpp (stub Obj_17f390), size 0x1c
struct Obj_17f390 {
    char pad[0x18]; // +0x00
    int mValue; // +0x18
    bool FUN_0017f390(int value);
};
// matches/0x0017f3b0.cpp (stub Obj_17f3b0), size 0x1d
struct Obj_17f3b0 {
    char m[28]; // +0x00
    char v; // +0x1c
    char FUN_0017f3b0(char a);
};
// matches/0x0017f3d0.cpp (stub Obj_17f3d0), size 0x24
struct Obj_17f3d0 {
    char pad[0x20]; // +0x00
    int m20; // +0x20
    bool FUN_0017f3d0(int value);
};
// matches/0x0017f3f0.cpp (stub Obj_17f3f0), size 0x25
struct Obj_17f3f0 {
    char pad[0x24]; // +0x00
    unsigned char val; // +0x24
    unsigned char FUN_0017f3f0(unsigned char a);
};
// matches/0x0017f410.cpp (stub Obj_17f410), size 0x2c
struct Obj_17f410 {
    char pad[0x28]; // +0x00
    int value; // +0x28
    bool FUN_0017f410(int x);
};
// matches/0x0017f470.cpp (stub X_17f470), size 0xd
struct X_17f470 {
    char pad[0xc]; // +0x00
    unsigned char m; // +0x0c
    unsigned char FUN_0017f470(unsigned char v);
};
// matches/0x0017f500.cpp (stub A_17f500), size 0xd
struct A_17f500 {
    char pad[12]; // +0x00
    char mField; // +0x0c
    char FUN_0017f500(char p);
};
// matches/0x0017f520.cpp (stub Obj_17f520), size 0x10
struct Obj_17f520 {
    char pad[12]; // +0x00
    int mField; // +0x0c
    bool FUN_0017f520(int value);
};
// matches/0x0017f530.cpp (stub Obj_17f530), size 0x11
struct Obj_17f530 {
    char pad[0x10]; // +0x00
    unsigned char value; // +0x10
    unsigned char FUN_0017f530(unsigned char x);
};
// matches/0x0017f660.cpp (stub Obj_17f660), size 0xc
struct Obj_17f660 {
    char pad[0xc]; // +0x00
    bool FUN_0017f660(int v);
};
// matches/0x0017f670.cpp (stub Obj_17f670), size 0x11
struct Obj_17f670 {
    char pad[0x10]; // +0x00
    char value; // +0x10
    bool FUN_0017f670(char c);
};
// matches/0x0017f690.cpp (stub Target_17f690), size 0x10
struct Target_17f690 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    bool FUN_0017f690(int value);
};
// matches/0x0017f6a0.cpp (stub C_17f6a0), size 0xd
struct C_17f6a0 {
    char pad[12]; // +0x00
    unsigned char mValue; // +0x0c
    bool FUN_0017f6a0(unsigned char x);
};
// matches/0x0017f760.cpp (stub Obj_17f760), size 0x10
struct Obj_17f760 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    char FUN_0017f760(int v);
};
// matches/0x0017f780.cpp (stub X_17f780), size 0x11
struct X_17f780 {
    char m[0x11]; // +0x00
    bool FUN_0017f780(char c);
};
// matches/0x0017f790.cpp (stub Obj_17f790), size 0x10
struct Obj_17f790 {
    char FUN_0017f790(int);
    char pad[12]; // +0x00
    int mValue; // +0x0c
};
// matches/0x0017f7b0.cpp (stub Obj_17f7b0), size 0x14
struct Obj_17f7b0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char FUN_0017f7b0(int x);
};
// matches/0x0017f7c0.cpp (stub X_17f7c0), size 0x10
struct X_17f7c0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_0017f7c0(int x);
};
// matches/0x0017f7d0.cpp (stub C_17f7d0), size 0x14
struct C_17f7d0 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    bool FUN_0017f7d0(int v);
};
// matches/0x0017f7f0.cpp (stub Obj_17f7f0), size 0x18
struct Obj_17f7f0 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    unsigned char FUN_0017f7f0(int x);
};
// matches/0x0017f820.cpp (stub Obj_17f820), size 0x24
struct Obj_17f820 {
    char pad[0x20]; // +0x00
    int m; // +0x20
    bool FUN_0017f820(int a);
};
// matches/0x0017f840.cpp (stub Obj_17f840), size 0x28
struct Obj_17f840 {
    char pad[0x24]; // +0x00
    int mValue; // +0x24
    bool FUN_0017f840(int v);
};
// matches/0x0017f860.cpp (stub Obj_17f860), size 0x2c
struct Obj_17f860 {
    char pad[0x28]; // +0x00
    int m; // +0x28
    char FUN_0017f860(int v);
};
// matches/0x0017f880.cpp (stub Obj_17f880), size 0x30
struct Obj_17f880 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    char FUN_0017f880(int v);
};
// matches/0x0017f900.cpp (stub X_17f900), size 0x10
struct X_17f900 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    char FUN_0017f900(int v);
};
// matches/0x0017f910.cpp (stub Obj_17f910), size 0x14
struct Obj_17f910 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_0017f910(int value);
};
// matches/0x0017f930.cpp (stub Obj_17f930), size 0x18
struct Obj_17f930 {
    char pad[0x14]; // +0x00
    int mValue; // +0x14
    bool FUN_0017f930(int v);
};
// matches/0x0017f950.cpp (stub Obj_17f950), size 0x19
struct Obj_17f950 {
    char pad[0x18]; // +0x00
    unsigned char m18; // +0x18
    unsigned char FUN_0017f950(unsigned char b);
};
// matches/0x0017f9b0.cpp (stub Obj_17f9b0), size 0x2c
struct Obj_17f9b0 {
    char pad[0x28]; // +0x00
    int m28; // +0x28
    bool FUN_0017f9b0(int v);
};
// matches/0x0017f9d0.cpp (stub C_17f9d0), size 0x30
struct C_17f9d0 {
    char pad[0x2c]; // +0x00
    int mValue; // +0x2c
    bool FUN_0017f9d0(int value);
};
// matches/0x0017f9f0.cpp (stub Obj_17f9f0), size 0x34
struct Obj_17f9f0 {
    char pad[0x30]; // +0x00
    int value; // +0x30
    bool FUN_0017f9f0(int x);
};
// matches/0x0017fa10.cpp (stub X_17fa10), size 0x38
struct X_17fa10 {
    char pad[0x34]; // +0x00
    int value; // +0x34
    bool FUN_0017fa10(int v);
};
// matches/0x0017fa30.cpp (stub Obj), size 0x3c
struct Obj_17fa30 {
    char pad[0x38]; // +0x00
    float angle; // +0x38
    char FUN_0017fa30(float x);
};
// matches/0x0017fa60.cpp (stub X_17fa60), size 0x40
struct X_17fa60 {
    char pad[0x3c]; // +0x00
    float mVal; // +0x3c
    char FUN_0017fa60(float v);
};
// matches/0x0017fa90.cpp (stub Obj), size 0x44
struct Obj_17fa90 {
    char pad[0x40]; // +0x00
    float angle; // +0x40
    bool FUN_0017fa90(float x);
};
// matches/0x0017fac0.cpp (stub Thing), size 0x48
struct Thing_17fac0 {
    char pad[0x44]; // +0x00
    float value; // +0x44
    unsigned char FUN_0017fac0(float angle);
};
// matches/0x0017faf0.cpp (stub Obj_17faf0), size 0x4c
struct Obj_17faf0 {
    char pad[0x48]; // +0x00
    int mValue; // +0x48
    bool FUN_0017faf0(int value);
};
// matches/0x0017fb10.cpp (stub Target_17fb10), size 0x50
struct Target_17fb10 {
    char pad0[0x4c]; // +0x00
    int value; // +0x4c
    bool FUN_0017fb10(int x);
};
// matches/0x0017fb30.cpp (stub Thing), size 0x54
struct Thing_17fb30 {
    char pad[0x50]; // +0x00
    float angle; // +0x50
    bool FUN_0017fb30(float a);
};
// matches/0x0017fb60.cpp (stub Obj_17fb60), size 0x58
struct Obj_17fb60 {
    char pad[0x54]; // +0x00
    int value; // +0x54
    bool FUN_0017fb60(int x);
};
// matches/0x0017fb80.cpp (stub C_17fb80), size 0x5c
struct C_17fb80 {
    char pad[0x58]; // +0x00
    int mVal; // +0x58
    bool FUN_0017fb80(int x);
};
// matches/0x0017fba0.cpp (stub Obj_17fba0), size 0x60
struct Obj_17fba0 {
    char pad[0x5c]; // +0x00
    int mValue; // +0x5c
    bool FUN_0017fba0(int x);
};
// matches/0x0017fbc0.cpp (stub Obj_17fbc0), size 0x64
struct Obj_17fbc0 {
    char pad[0x60]; // +0x00
    int m60; // +0x60
    bool FUN_0017fbc0(int x);
};
// matches/0x0017fbe0.cpp (stub Target_17fbe0), size 0x68
struct Target_17fbe0 {
    char pad[0x64]; // +0x00
    int mField; // +0x64
    unsigned char FUN_0017fbe0(int value);
};
// matches/0x0017fbf0.cpp (stub Base_17fbf0), size 0x68
struct Base_17fbf0 {
    char pad[0x68]; // +0x00
    char* FUN_0017fbf0();
};
// matches/0x0017fc20.cpp (stub Obj_17fc20), size 0x81
struct Obj_17fc20 {
    char FUN_0017fc20(char x);
    char pad[0x80]; // +0x00
    char m80; // +0x80
};
// matches/0x0017fc30.cpp (stub Obj_17fc30), size 0x10
struct Obj_17fc30 {
    char pad[12]; // +0x00
    int mValue; // +0x0c
    bool FUN_0017fc30(int v);
};
// matches/0x0017fc40.cpp (stub T_17fc40), size 0x14
struct T_17fc40 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0017fc40(int x);
};
// matches/0x0017fc60.cpp (stub Obj_17fc60), size 0x18
struct Obj_17fc60 {
    char Pad[0x14]; // +0x00
    int Member; // +0x14
    char FUN_0017fc60(int);
};
// matches/0x0017fc80.cpp (stub Obj_17fc80), size 0x1c (0x20)
struct Obj_17fc80 {
    char pad[0x18]; // +0x00
    void* m18; // +0x18
    bool FUN_0017fc80(void* x);
};
// matches/0x0017fca0.cpp (stub Obj_17fca0), size 0x20
struct Obj_17fca0 {
    char Pad[0x1c]; // +0x00
    int Value; // +0x1c
    char FUN_0017fca0(int v);
};
// matches/0x0017fcc0.cpp (stub Obj_17fcc0), size 0x24
struct Obj_17fcc0 {
    char Pad[0x20]; // +0x00
    float Angle; // +0x20
    char FUN_0017fcc0(float a);
};
// matches/0x0017fcf0.cpp (stub Obj), size 0x28
struct Obj_17fcf0 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    bool FUN_0017fcf0(int x);
};
// matches/0x0017fd10.cpp (stub Obj_17fd10), size 0x2c
struct Obj_17fd10 {
    char FUN_0017fd10(int);
    char pad[0x28]; // +0x00
    int m; // +0x28
};
// matches/0x0017fda0.cpp (stub Obj_17fda0), size 0x4c (0x50)
struct Obj_17fda0 {
    char pad[0x48]; // +0x00
    int* m; // +0x48
    int* FUN_0017fda0();
};
// matches/0x0017fdf0.cpp (stub T_17fdf0), size 0x60
struct T_17fdf0 {
    char pad[0x60]; // +0x00
    void* FUN_0017fdf0();
};
// matches/0x0017fe90.cpp (stub Obj_17fe90), size 0x10
struct Obj_17fe90 {
    char pad[0xc]; // +0x00
    int m1c; // +0x0c
    bool FUN_0017fe90(int v);
};
// matches/0x0017fea0.cpp (stub Obj_17fea0), size 0x14
struct Obj_17fea0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0017fea0(int v);
};
// matches/0x0017fec0.cpp (stub Obj_17fec0), size 0x18
struct Obj_17fec0 {
    char pad[0x14]; // +0x00
    int mValue; // +0x14
    bool FUN_0017fec0(int x);
};
// matches/0x0017ffa0.cpp (stub Obj_17ffa0), size 0x40
struct Obj_17ffa0 {
    char pad[0x3c]; // +0x00
    int value; // +0x3c
    bool FUN_0017ffa0(int x);
};
// matches/0x0017ffc0.cpp (stub Obj_17ffc0), size 0x44
struct Obj_17ffc0 {
    char pad[0x40]; // +0x00
    int mValue; // +0x40
    bool FUN_0017ffc0(int value);
};
// matches/0x0017ffe0.cpp (stub X_17ffe0), size 0x48
struct X_17ffe0 {
    char pad[0x44]; // +0x00
    int mValue; // +0x44
    char FUN_0017ffe0(int value);
};
// matches/0x00180000.cpp (stub T_180000), size 0x4c
struct T_180000 {
    char pad[0x48]; // +0x00
    int m48; // +0x48
    bool FUN_00180000(int a);
};
// matches/0x00180020.cpp (stub X_180020), size 0x50
struct X_180020 {
    char pad[0x4c]; // +0x00
    float value; // +0x4c
    char FUN_00180020(float arg);
};
// matches/0x00180050.cpp (stub Obj), size 0x54
struct Obj_180050 {
    char pad[0x50]; // +0x00
    float angle; // +0x50
    bool FUN_00180050(float x);
};
// matches/0x00180080.cpp (stub Obj), size 0x58
struct Obj_180080 {
    char pad[0x54]; // +0x00
    float angle; // +0x54
    char FUN_00180080(float degrees);
};
// matches/0x001800b0.cpp (stub Obj_1800b0), size 0x5c
struct Obj_1800b0 {
    char pad[0x58]; // +0x00
    int mValue; // +0x58
    bool FUN_001800b0(int value);
};
// matches/0x001800c0.cpp (stub Obj_1800c0), size 0x60
struct Obj_1800c0 {
    char pad[0x60]; // +0x00
    void* FUN_001800c0();
};
// matches/0x00180110.cpp (stub Obj_180110), size 0x78
struct Obj_180110 {
    char pad[0x78]; // +0x00
    void* FUN_00180110() throw();
};
// matches/0x00180190.cpp (stub Obj_180190), size 0x90
struct Obj_180190 {
    char pad[0x8c]; // +0x00
    int m8c; // +0x8c
    bool FUN_00180190(int value);
};
// matches/0x001801b0.cpp (stub C_1801b0), size 0x94
struct C_1801b0 {
    char pad[0x90]; // +0x00
    unsigned int m; // +0x90
    bool FUN_001801b0(unsigned int x);
};
// matches/0x001801c0.cpp (stub O_1801c0), size 0x10
struct O_1801c0 {
    char FUN_001801c0(int x);
    char pad[12]; // +0x00
    int mField; // +0x0c
};
// matches/0x001801d0.cpp (stub Obj_1801d0), size 0x14
struct Obj_1801d0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_001801d0(int value);
};
// matches/0x001801f0.cpp (stub X_1801f0), size 0x18
struct X_1801f0 {
    char FUN_001801f0(int v);
    char pad[0x14]; // +0x00
    int m14; // +0x14
};
// matches/0x00180210.cpp (stub Obj_180210), size 0x1c
struct Obj_180210 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    char FUN_00180210(int x);
};
// matches/0x00180230.cpp (stub X_180230), size 0x20
struct X_180230 {
    char pad[0x1c]; // +0x00
    int mValue; // +0x1c
    bool FUN_00180230(int value);
};
// matches/0x00180250.cpp (stub Obj_180250), size 0x24
struct Obj_180250 {
    char pad[0x20]; // +0x00
    float mAngle; // +0x20
    char FUN_00180250(float v);
};
// matches/0x00180280.cpp (stub Obj), size 0x28
struct Obj_180280 {
    char pad[0x24]; // +0x00
    float angle; // +0x24
    bool FUN_00180280(float x);
};
// equivalent/0x001802c0.cpp (stub Angles), size 0x34
struct Angles_1802c0 {
    char pad[0x28]; // +0x00
    float x, y, z; // +0x28
    unsigned char FUN_001802c0(const float *v);
};
// matches/0x00180300.cpp (stub X_180300), size 0x10
struct X_180300 {
    int pad[3]; // +0x00
    int mVal; // +0x0c
    bool FUN_00180300(int v);
};
// matches/0x00180320.cpp (stub Thing), size 0x14
struct Thing_180320 {
    char pad[16]; // +0x00
    float angle; // +0x10
    bool FUN_00180320(float a);
};
// matches/0x00180430.cpp (stub C_180430), size 0x10
struct C_180430 {
    bool FUN_00180430(int value);
    char pad[12]; // +0x00
    int mValue; // +0x0c
};
// matches/0x00180450.cpp (stub A_180450), size 0x18
struct A_180450 {
    char pad[0x18]; // +0x00
    A_180450* FUN_00180450();
};
// matches/0x00180580.cpp (stub X_180580), size 0x10
struct X_180580 {
    char FUN_00180580(int v);
    char pad[12]; // +0x00
    int mField; // +0x0c
};
// matches/0x001805a0.cpp (stub Obj_1805a0), size 0x14
struct Obj_1805a0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    bool FUN_001805a0(int v);
};
// matches/0x00181670.cpp (stub X), size 0x14 (0x18)
struct X_181670 {
    char pad[16]; // +0x00
    char* p; // +0x10
    unsigned char FUN_00181670(const char* s);
};
// matches/0x0018cab0.cpp (stub Obj_18cab0), size 0x10
struct Obj_18cab0 {
    char FUN_0018cab0(int a);
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
};
// matches/0x0018cac0.cpp (stub X_18cac0), size 0x14
struct X_18cac0 {
    char pad[0x10]; // +0x00
    unsigned int m; // +0x10
    char FUN_0018cac0(unsigned int v);
};
// matches/0x0018cad0.cpp (stub Obj_18cad0), size 0x18
struct Obj_18cad0 {
    char m[0x14]; // +0x00
    int mVal; // +0x14
    bool FUN_0018cad0(int x);
};
// matches/0x0018caf0.cpp (stub X_18caf0), size 0x19
struct X_18caf0 {
    char pad[0x18]; // +0x00
    char m18; // +0x18
    char FUN_0018caf0(char c);
};
// matches/0x0018cb10.cpp (stub Obj_18cb10), size 0x20
struct Obj_18cb10 {
    char Pad[0x1c]; // +0x00
    int mVal; // +0x1c
    char FUN_0018cb10(int x);
};
// matches/0x0018cbd0.cpp (stub O_18cbd0), size 0x10
struct O_18cbd0 {
    char pad[12]; // +0x00
    int m; // +0x0c
    char FUN_0018cbd0(int x);
};
// matches/0x0018cbe0.cpp (stub Obj_18cbe0), size 0x1
struct Obj_18cbe0 {
    char* FUN_0018cbe0();
};
// matches/0x0018cc00.cpp (stub Obj_18cc00), size 0x1c
struct Obj_18cc00 {
    char pad[0x18]; // +0x00
    int mValue; // +0x18
    unsigned char FUN_0018cc00(int value);
};
// matches/0x0018cc20.cpp (stub O_18cc20), size 0x20
struct O_18cc20 {
    char pad[0x1c]; // +0x00
    int m; // +0x1c
    bool FUN_0018cc20(int a);
};
// matches/0x0018cc40.cpp (stub Obj_18cc40), size 0x24
struct Obj_18cc40 {
    char pad[31]; // +0x00
    int m20; // +0x20
    char FUN_0018cc40(int a);
};
// matches/0x0018cc60.cpp (stub Obj_18cc60), size 0x25
struct Obj_18cc60 {
    char pad[0x24]; // +0x00
    char m24; // +0x24
    char FUN_0018cc60(char v);
};
// matches/0x0018ecb0.cpp (stub X_18ecb0), size 0x1
struct X_18ecb0 {
    char FUN_0018ecb0(int v);
};
// matches/0x0018ecc0.cpp (stub O_18ecc0), size 0x10
struct O_18ecc0 {
    char pad[0x10]; // +0x00
    int* FUN_0018ecc0();
};
// matches/0x0018eda0.cpp (stub Obj_18eda0), size 0x3d
struct Obj_18eda0 {
    char pad[0x3c]; // +0x00
    char m3c; // +0x3c
    unsigned char FUN_0018eda0(unsigned char a);
};
// matches/0x0018edc0.cpp (stub Obj_18edc0), size 0x44
struct Obj_18edc0 {
    char pad[0x40]; // +0x00
    int mValue; // +0x40
    bool FUN_0018edc0(int x);
};
// matches/0x0018edd0.cpp (stub X_18edd0), size 0x10
struct X_18edd0 {
    char pad[0xc]; // +0x00
    int m; // +0x0c
    char FUN_0018edd0(int a);
};
// matches/0x0018ede0.cpp (stub Obj_18ede0), size 0x14
struct Obj_18ede0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_0018ede0(int x);
};
// matches/0x0018edf0.cpp (stub Target_18edf0), size 0x10
struct Target_18edf0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    unsigned char FUN_0018edf0(int x);
};
// matches/0x0018ee00.cpp (stub Obj_18ee00), size 0x14
struct Obj_18ee00 {
    char pad[0x10]; // +0x00
    int mVal; // +0x10
    bool FUN_0018ee00(int v);
};
// matches/0x0018ee20.cpp (stub Obj_18ee20), size 0x18
struct Obj_18ee20 {
    char pad[0x14]; // +0x00
    int mValue; // +0x14
    bool FUN_0018ee20(int v);
};
// matches/0x0018ee40.cpp (stub Obj_18ee40), size 0x1c
struct Obj_18ee40 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    bool FUN_0018ee40(int v);
};
// matches/0x0018ee60.cpp (stub C_18ee60), size 0x20
struct C_18ee60 {
    char pad[0x1c]; // +0x00
    int m; // +0x1c
    bool FUN_0018ee60(int x);
};
// matches/0x0018ee80.cpp (stub X_18ee80), size 0x24 (0x28)
struct X_18ee80 {
    char pad[0x20]; // +0x00
    void* m; // +0x20
    bool FUN_0018ee80(void* v);
};
// matches/0x0018eea0.cpp (stub Obj), size 0x28
struct Obj_18eea0 {
    char pad[0x24]; // +0x00
    float angle; // +0x24
    char FUN_0018eea0(float x);
};
// matches/0x0018eed0.cpp (stub Obj), size 0x2c
struct Obj_18eed0 {
    char pad[0x28]; // +0x00
    float angle; // +0x28
    bool FUN_0018eed0(float x);
};
// matches/0x0018ef00.cpp (stub Obj), size 0x30
struct Obj_18ef00 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    bool FUN_0018ef00(int v);
};
// matches/0x0018ef20.cpp (stub Obj_18ef20), size 0x30
struct Obj_18ef20 {
    char pad[0x30]; // +0x00
    char FUN_0018ef20(int value);
};
// matches/0x0018ef80.cpp (stub Obj_18ef80), size 0x40
struct Obj_18ef80 {
    char pad[0x40]; // +0x00
    char FUN_0018ef80(int x);
};
// matches/0x0018efa0.cpp (stub Obj_18efa0), size 0x48
struct Obj_18efa0 {
    char pad[0x44]; // +0x00
    int value; // +0x44
    bool FUN_0018efa0(int x);
};
// matches/0x0018efc0.cpp (stub Obj_18efc0), size 0x4c
struct Obj_18efc0 {
    char pad[0x48]; // +0x00
    int mField; // +0x48
    bool FUN_0018efc0(int value);
};
// matches/0x0018efe0.cpp (stub X_18efe0), size 0x50
struct X_18efe0 {
    char pad[0x4c]; // +0x00
    int value; // +0x4c
    char FUN_0018efe0(int x);
};
// matches/0x0018f000.cpp (stub Obj), size 0x54
struct Obj_18f000 {
    char pad[0x50]; // +0x00
    float value; // +0x50
    bool FUN_0018f000(float x);
};
// matches/0x0018f030.cpp (stub C_18f030), size 0x58
struct C_18f030 {
    char pad[0x54]; // +0x00
    float m; // +0x54
    char FUN_0018f030(float x);
};
// matches/0x0018f060.cpp (stub X_18f060), size 0x5c
struct X_18f060 {
    char pad[0x58]; // +0x00
    int m58; // +0x58
    bool FUN_0018f060(int v);
};
// matches/0x0018f080.cpp (stub Obj_18f080), size 0x60
struct Obj_18f080 {
    char FUN_0018f080(int a);
    char pad[0x5c]; // +0x00
    int value; // +0x5c
};
// matches/0x0018f0a0.cpp (stub O_18f0a0), size 0x64
struct O_18f0a0 {
    char pad[0x60]; // +0x00
    int value; // +0x60
    bool FUN_0018f0a0(int x);
};
// matches/0x0018f0c0.cpp (stub Obj_18f0c0), size 0x68
struct Obj_18f0c0 {
    char pad[0x64]; // +0x00
    int m64; // +0x64
    char FUN_0018f0c0(int v);
};
// matches/0x0018f0e0.cpp (stub O_18f0e0), size 0x6c
struct O_18f0e0 {
    char pad[0x68]; // +0x00
    int m; // +0x68
    char FUN_0018f0e0(int value);
};
// matches/0x0018f100.cpp (stub Obj_18f100), size 0x70
struct Obj_18f100 {
    char pad[0x6c]; // +0x00
    int value; // +0x6c
    bool FUN_0018f100(int x);
};
// matches/0x0018f120.cpp (stub X_18f120), size 0x74
struct X_18f120 {
    char pad[0x70]; // +0x00
    int m70; // +0x70
    bool FUN_0018f120(int v);
};
// matches/0x00192160.cpp (stub X_192160), size 0xd
struct X_192160 {
    char pad[12]; // +0x00
    char m; // +0x0c
    char FUN_00192160(char c);
};
// matches/0x00192170.cpp (stub X_192170), size 0x10
struct X_192170 {
    char mPad[12]; // +0x00
    int mField; // +0x0c
    char FUN_00192170(int a);
};
// matches/0x00192180.cpp (stub O_192180), size 0x11
struct O_192180 {
    char pad[0x10]; // +0x00
    char m; // +0x10
    char FUN_00192180(char c);
};
// matches/0x00192190.cpp (stub X), size 0x10
struct X_192190 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_00192190(int v);
};
// matches/0x001921a0.cpp (stub C_1921a0), size 0x14
struct C_1921a0 {
    char pad[0x10]; // +0x00
    int m; // +0x10
    bool FUN_001921a0(int x);
};
// matches/0x00192210.cpp (stub Obj_192210), size 0x30
struct Obj_192210 {
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
    bool FUN_00192210(int value);
};
// matches/0x00192230.cpp (stub Obj_192230), size 0x34
struct Obj_192230 {
    char pad[0x30]; // +0x00
    int m30; // +0x30
    bool FUN_00192230(int v);
};
// matches/0x00192240.cpp (stub X_192240), size 0x38
struct X_192240 {
    char pad[0x38]; // +0x00
    void* FUN_00192240();
};
// matches/0x001922b0.cpp (stub Obj_1922b0), size 0x58
struct Obj_1922b0 {
    char pad[0x4c]; // +0x00
    int a; // +0x4c
    int b; // +0x50
    int c; // +0x54
    unsigned char FUN_001922b0(int* src);
};
// matches/0x001922e0.cpp (stub Target_1922e0), size 0x5c
struct Target_1922e0 {
    char pad[0x58]; // +0x00
    float value; // +0x58
    bool FUN_001922e0(float degrees);
};
// matches/0x00192310.cpp (stub X_192310), size 0x60
struct X_192310 {
    char pad[0x5c]; // +0x00
    int value; // +0x5c
    bool FUN_00192310(int v);
};
// matches/0x00192330.cpp (stub Obj_192330), size 0x64
struct Obj_192330 {
    char FUN_00192330(int v);
    char pad[0x60]; // +0x00
    int m; // +0x60
};
// matches/0x00192350.cpp (stub Obj_192350), size 0x68
struct Obj_192350 {
    char pad[0x64]; // +0x00
    int m; // +0x64
    bool FUN_00192350(int x);
};
// matches/0x00192370.cpp (stub Obj), size 0x6c
struct Obj_192370 {
    char pad[0x68]; // +0x00
    float angle; // +0x68
    bool FUN_00192370(float x);
};
// matches/0x001923a0.cpp (stub X_1923a0), size 0x70
struct X_1923a0 {
    char pad[0x6c]; // +0x00
    int m; // +0x6c
    char FUN_001923a0(int a);
};
// matches/0x001923c0.cpp (stub X_1923c0), size 0x74
struct X_1923c0 {
    char Pad[0x70]; // +0x00
    float Value; // +0x70
    char FUN_001923c0(float x);
};
// matches/0x001923f0.cpp (stub Obj_1923f0), size 0x75
struct Obj_1923f0 {
    char m0[0x74]; // +0x00
    char m74; // +0x74
    char FUN_001923f0(char value);
};
// matches/0x00192400.cpp (stub Obj_192400), size 0x76
struct Obj_192400 {
    char pad[0x75]; // +0x00
    char m; // +0x75
    char FUN_00192400(char x);
};
// matches/0x00192410.cpp (stub Obj_192410), size 0x77
struct Obj_192410 {
    char pad[0x76]; // +0x00
    char mVal; // +0x76
    char FUN_00192410(char value);
};
// matches/0x00192430.cpp (stub X_192430), size 0x7c (0x80)
struct X_192430 {
    char pad[0x78]; // +0x00
    void* m78; // +0x78
    bool FUN_00192430(void* p);
};
// matches/0x00192450.cpp (stub Obj_192450), size 0x80
struct Obj_192450 {
    char pad[0x7c]; // +0x00
    int value; // +0x7c
    char FUN_00192450(int arg);
};
// matches/0x00192470.cpp (stub X_192470), size 0x1
struct X_192470 {
    char FUN_00192470(int a);
};
// matches/0x00192480.cpp (stub Obj_192480), size 0x88
struct Obj_192480 {
    char pad[0x88]; // +0x00
    char* FUN_00192480();
};
// matches/0x00192500.cpp (stub Obj_192500), size 0xac
struct Obj_192500 {
    char pad[0xa8]; // +0x00
    int value; // +0xa8
    int* FUN_00192500();
};
// matches/0x00192520.cpp (stub Obj_192520), size 0xb8
struct Obj_192520 {
    char pad[0xb4]; // +0x00
    int mVal; // +0xb4
    char FUN_00192520(int val);
};
// matches/0x00192540.cpp (stub A_192540), size 0xbc
struct A_192540 {
    char pad[0xb8]; // +0x00
    int m; // +0xb8
    bool FUN_00192540(int v);
};
// matches/0x00192560.cpp (stub C_192560), size 0xc0
struct C_192560 {
    char mPad[0xbc]; // +0x00
    int mField; // +0xbc
    bool FUN_00192560(int value);
};
// matches/0x00192570.cpp (stub Obj_192570), size 0x10
struct Obj_192570 {
    char pad[0xc]; // +0x00
    int mVal; // +0x0c
    bool FUN_00192570(int v);
};
// matches/0x00192590.cpp (stub C_192590), size 0x14
struct C_192590 {
    char pad[16]; // +0x00
    int m; // +0x10
    bool FUN_00192590(int x);
};
// matches/0x00192610.cpp (stub Obj_192610), size 0x28
struct Obj_192610 {
    char pad[0x24]; // +0x00
    int mValue; // +0x24
    bool FUN_00192610(int value);
};
// matches/0x00192630.cpp (stub Obj_192630), size 0x2c
struct Obj_192630 {
    char FUN_00192630(int v);
    char pad[0x28]; // +0x00
    int value; // +0x28
};
// matches/0x00192650.cpp (stub Obj), size 0x30
struct Obj_192650 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    char FUN_00192650(int x);
};
// matches/0x00192670.cpp (stub Obj_192670), size 0x34
struct Obj_192670 {
    char pad[0x30]; // +0x00
    float value; // +0x30
    char FUN_00192670(float v);
};
// matches/0x001926a0.cpp (stub Obj), size 0x38
struct Obj_1926a0 {
    char pad[0x34]; // +0x00
    float angle; // +0x34
    char FUN_001926a0(float x);
};
// matches/0x001926d0.cpp (stub Obj), size 0x3c
struct Obj_1926d0 {
    char pad[0x38]; // +0x00
    float angle; // +0x38
    char FUN_001926d0(float degrees);
};
// matches/0x00192700.cpp (stub O_192700), size 0x3c
struct O_192700 {
    char FUN_00192700(float x);
    char pad[0x3c]; // +0x00
};
// matches/0x00192730.cpp (stub Obj_192730), size 0x44
struct Obj_192730 {
    char pad[0x40]; // +0x00
    float mAngle; // +0x40
    bool FUN_00192730(float angle);
};
// matches/0x00192760.cpp (stub Target_192760), size 0x48
struct Target_192760 {
    char pad[0x44]; // +0x00
    int m44; // +0x44
    bool FUN_00192760(int value);
};
// matches/0x00192830.cpp (stub Obj_192830), size 0x10
struct Obj_192830 {
    char pad[12]; // +0x00
    int m10; // +0x0c
    bool FUN_00192830(int x);
};
// matches/0x00192840.cpp (stub Obj_192840), size 0x14
struct Obj_192840 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    bool FUN_00192840(int v);
};
// matches/0x00192850.cpp (stub Obj_192850), size 0x18
struct Obj_192850 {
    char pad[0x18]; // +0x00
    Obj_192850* FUN_00192850();
};
// matches/0x00192890.cpp (stub Obj_192890), size 0x30
struct Obj_192890 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    bool FUN_00192890(int v);
};
// matches/0x001928a0.cpp (stub Obj_1928a0), size 0x30
struct Obj_1928a0 {
    char pad[0x30]; // +0x00
    void* FUN_001928a0();
};
// matches/0x00192940.cpp (stub Thing), size 0x54
struct Thing_192940 {
    char pad[0x50]; // +0x00
    int value; // +0x50
    char FUN_00192940(int v);
};
// matches/0x00192960.cpp (stub Obj_192960), size 0x58
struct Obj_192960 {
    char pad[0x54]; // +0x00
    float rads; // +0x54
    char FUN_00192960(float deg);
};
// matches/0x00192990.cpp (stub Obj_192990), size 0x5c
struct Obj_192990 {
    char pad[0x58]; // +0x00
    int m58; // +0x58
    bool FUN_00192990(int v);
};
// matches/0x001929b0.cpp (stub Obj_1929b0), size 0x60
struct Obj_1929b0 {
    char FUN_001929b0(float v);
    char pad[0x5c]; // +0x00
    float value; // +0x5c
};
// matches/0x001929e0.cpp (stub X_1929e0), size 0x61
struct X_1929e0 {
    char pad[0x60]; // +0x00
    unsigned char m; // +0x60
    bool FUN_001929e0(unsigned char v);
};
// matches/0x00192a00.cpp (stub Obj_192a00), size 0x68
struct Obj_192a00 {
    char pad[0x64]; // +0x00
    int m64; // +0x64
    bool FUN_00192a00(int x);
};
// matches/0x00192a20.cpp (stub Obj_192a20), size 0x6c
struct Obj_192a20 {
    char pad[0x68]; // +0x00
    int m68; // +0x68
    bool FUN_00192a20(int v);
};
// matches/0x00192a30.cpp (stub Thing_192a30), size 0x74 (0x78)
struct Thing_192a30 {
    char pad[0x70]; // +0x00
    void* field; // +0x70
    void* FUN_00192a30();
};
// matches/0x00192a80.cpp (stub Obj_192a80), size 0x84
struct Obj_192a80 {
    char pad[0x84]; // +0x00
    char* FUN_00192a80();
};
// matches/0x00192aa0.cpp (stub C_192aa0), size 0x94
struct C_192aa0 {
    char pad[0x90]; // +0x00
    int m90; // +0x90
    char FUN_00192aa0(int x);
};
// matches/0x00192ac0.cpp (stub Obj_192ac0), size 0x98
struct Obj_192ac0 {
    char pad[0x94]; // +0x00
    int value; // +0x94
    bool FUN_00192ac0(int x);
};
// matches/0x00192ae0.cpp (stub Obj_192ae0), size 0x9c
struct Obj_192ae0 {
    char pad[0x98]; // +0x00
    int m98; // +0x98
    bool FUN_00192ae0(int x);
};
// matches/0x00192b00.cpp (stub Obj), size 0x9d
struct Obj_192b00 {
    char pad[0x9c]; // +0x00
    unsigned char value; // +0x9c
    unsigned char FUN_00192b00(unsigned char x);
};
// matches/0x00192b20.cpp (stub X_192b20), size 0xa0
struct X_192b20 {
    char FUN_00192b20(int v);
    char pad[0xa0]; // +0x00
};
// matches/0x00192b40.cpp (stub Obj_192b40), size 0xa8
struct Obj_192b40 {
    char pad[0xa4]; // +0x00
    int mValue; // +0xa4
    char FUN_00192b40(int v);
};
// matches/0x00192b60.cpp (stub C_192b60), size 0xac
struct C_192b60 {
    char FUN_00192b60(int v);
    char mPad[0xa8]; // +0x00
    int mValue; // +0xa8
};
// matches/0x00192b80.cpp (stub O_192b80), size 0xad
struct O_192b80 {
    char pad[0xac]; // +0x00
    char mB1; // +0xac
    char FUN_00192b80(char b);
};
// matches/0x00192ba0.cpp (stub Obj_192ba0), size 0xc0
struct Obj_192ba0 {
    char pad[0xc0]; // +0x00
    void* FUN_00192ba0();
};
// matches/0x00192ce0.cpp (stub Obj_192ce0), size 0xf0
struct Obj_192ce0 {
    char pad[0xec]; // +0x00
    int value; // +0xec
    bool FUN_00192ce0(int v);
};
// matches/0x00192d00.cpp (stub X_192d00), size 0xf0
struct X_192d00 {
    char m[0xf0]; // +0x00
    char FUN_00192d00(char v);
};
// matches/0x00192d20.cpp (stub Obj_192d20), size 0xf8
struct Obj_192d20 {
    char pad[0xf4]; // +0x00
    float value; // +0xf4
    bool FUN_00192d20(float angle);
};
// matches/0x00192d50.cpp (stub X_192d50), size 0xfc
struct X_192d50 {
    char FUN_00192d50(int);
    char pad[0xf8]; // +0x00
    int m; // +0xf8
};
// matches/0x00192d70.cpp (stub Obj_192d70), size 0xfd
struct Obj_192d70 {
    char m0[0xfc]; // +0x00
    char m1; // +0xfc
    unsigned char FUN_00192d70(unsigned char v);
};
// matches/0x00192d90.cpp (stub Obj_192d90), size 0xfe
struct Obj_192d90 {
    char pad[0xfd]; // +0x00
    unsigned char value; // +0xfd
    unsigned char FUN_00192d90(unsigned char v);
};
// matches/0x00192db0.cpp (stub X_192db0), size 0xff
struct X_192db0 {
    char pad[0xfe]; // +0x00
    char m0fe; // +0xfe
    char FUN_00192db0(char b);
};
// matches/0x00192df0.cpp (stub C), size 0x10c
struct C_192df0 {
    char FUN_00192df0(const void* p);
    char pad[0x100]; // +0x00
    char m100[4]; // +0x100
    char m104[4]; // +0x104
    char m108[4]; // +0x108
};
// matches/0x00192e90.cpp (stub Obj_192e90), size 0x11c
struct Obj_192e90 {
    char pad[0x118]; // +0x00
    int mValue; // +0x118
    bool FUN_00192e90(int value);
};
// matches/0x00192f10.cpp (stub Obj_192f10), size 0x12c
struct Obj_192f10 {
    char FUN_00192f10(int v);
    char pad[0x128]; // +0x00
    int mValue; // +0x128
};
// matches/0x00192f30.cpp (stub Obj_192f30), size 0x12c
struct Obj_192f30 {
    char m[0x12c]; // +0x00
    char FUN_00192f30(char c);
};
// matches/0x00192f50.cpp (stub Target_192f50), size 0x134
struct Target_192f50 {
    char pad[0x130]; // +0x00
    int field; // +0x130
    bool FUN_00192f50(int value);
};
// matches/0x00192f70.cpp (stub Obj_192f70), size 0x138
struct Obj_192f70 {
    char pad[0x134]; // +0x00
    int m134; // +0x134
    bool FUN_00192f70(int x);
};
// matches/0x00192f80.cpp (stub Obj_192f80), size 0x10
struct Obj_192f80 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_00192f80(int value);
};
// matches/0x00192f90.cpp (stub Obj_192f90), size 0x10
struct Obj_192f90 {
    char pad[16]; // +0x00
    int* FUN_00192f90();
};
// matches/0x00192fa0.cpp (stub Obj_192fa0), size 0x18
struct Obj_192fa0 {
    char pad[0x18]; // +0x00
    char* FUN_00192fa0();
};
// matches/0x00192fb0.cpp (stub Obj_192fb0), size 0x20
struct Obj_192fb0 {
    char pad[0x20]; // +0x00
    char* FUN_00192fb0();
};
// matches/0x00193010.cpp (stub Obj_193010), size 0x38
struct Obj_193010 {
    char pad[0x34]; // +0x00
    int m34; // +0x34
    char FUN_00193010(int v);
};
// matches/0x00193020.cpp (stub Obj_193020), size 0x38
struct Obj_193020 {
    char pad[0x38]; // +0x00
    void* FUN_00193020();
};
// matches/0x001930c0.cpp (stub Obj_1930c0), size 0x59
struct Obj_1930c0 {
    char pad[0x58]; // +0x00
    unsigned char field; // +0x58
    unsigned char FUN_001930c0(unsigned char x);
};
// matches/0x001930e0.cpp (stub Obj_1930e0), size 0x60
struct Obj_1930e0 {
    char pad[0x5c]; // +0x00
    int value; // +0x5c
    bool FUN_001930e0(int v);
};
// matches/0x00193100.cpp (stub Obj_193100), size 0x64
struct Obj_193100 {
    char pad[0x60]; // +0x00
    int m60; // +0x60
    unsigned char FUN_00193100(int v);
};
// matches/0x00193120.cpp (stub Obj_193120), size 0x68
struct Obj_193120 {
    char pad[0x64]; // +0x00
    int m64; // +0x64
    char FUN_00193120(int x);
};
// matches/0x00193140.cpp (stub Obj), size 0x6c
struct Obj_193140 {
    char pad[0x68]; // +0x00
    float angle; // +0x68
    char FUN_00193140(float v);
};
// matches/0x00193170.cpp (stub Obj_193170), size 0x70
struct Obj_193170 {
    char pad[0x6c]; // +0x00
    int m6c; // +0x6c
    bool FUN_00193170(int v);
};
// matches/0x00193190.cpp (stub Thing), size 0x74
struct Thing_193190 {
    char pad[0x70]; // +0x00
    float value; // +0x70
    char FUN_00193190(float x);
};
// matches/0x001931c0.cpp (stub X_1931c0), size 0x75
struct X_1931c0 {
    char pad[0x74]; // +0x00
    char f; // +0x74
    char FUN_001931c0(char c);
};
// matches/0x001931e0.cpp (stub Sub_1931e0), size 0x76
struct Sub_1931e0 {
    char pad[0x75]; // +0x00
    char m75; // +0x75
    char FUN_001931e0(char v);
};
// matches/0x00193200.cpp (stub Obj_193200), size 0x77
struct Obj_193200 {
    char pad[0x76]; // +0x00
    char mField; // +0x76
    bool FUN_00193200(char b);
};
// matches/0x00193220.cpp (stub Obj_193220), size 0x78
struct Obj_193220 {
    char pad[0x77]; // +0x00
    char flag; // +0x77
    unsigned char FUN_00193220(unsigned char v);
};
// matches/0x00193240.cpp (stub X_193240), size 0x79
struct X_193240 {
    char FUN_00193240(int v);
    char pad[0x78]; // +0x00
    char m78; // +0x78
};
// matches/0x00193260.cpp (stub Obj_193260), size 0x80
struct Obj_193260 {
    char pad[0x7c]; // +0x00
    int m7c; // +0x7c
    bool FUN_00193260(int x);
};
// matches/0x00193280.cpp (stub Obj), size 0x84
struct Obj_193280 {
    char pad[0x80]; // +0x00
    float angle; // +0x80
    char FUN_00193280(float x);
};
// matches/0x001932e0.cpp (stub Obj_1932e0), size 0x8c
struct Obj_1932e0 {
    char pad[0x88]; // +0x00
    int mVal; // +0x88
    bool FUN_001932e0(int v);
};
// matches/0x00193300.cpp (stub Obj_193300), size 0x90
struct Obj_193300 {
    char pad[0x8c]; // +0x00
    int mValue; // +0x8c
    bool FUN_00193300(int x);
};
// matches/0x00193320.cpp (stub Obj_193320), size 0x94
struct Obj_193320 {
    char pad[0x90]; // +0x00
    int value; // +0x90
    bool FUN_00193320(int x);
};
// matches/0x00193340.cpp (stub X_193340), size 0x94
struct X_193340 {
    char field[0x94]; // +0x00
    char FUN_00193340(char value);
};
// matches/0x00193360.cpp (stub T_193360), size 0x96
struct T_193360 {
    char pad[0x95]; // +0x00
    unsigned char value; // +0x95
    bool FUN_00193360(unsigned char x);
};
// matches/0x00193380.cpp (stub Obj_193380), size 0x97
struct Obj_193380 {
    char pad[0x96]; // +0x00
    char m96; // +0x96
    char FUN_00193380(char x);
};
// matches/0x001933a0.cpp (stub Obj_1933a0), size 0x9c
struct Obj_1933a0 {
    char pad[0x98]; // +0x00
    int value; // +0x98
    bool FUN_001933a0(int x);
};
// matches/0x001933c0.cpp (stub Obj), size 0xa0
struct Obj_1933c0 {
    char pad[0x9c]; // +0x00
    float angle; // +0x9c
    unsigned char FUN_001933c0(float a);
};
// matches/0x001933f0.cpp (stub X_1933f0), size 0xa4
struct X_1933f0 {
    char FUN_001933f0(int value);
    char mPad[0xa0]; // +0x00
    int mValue; // +0xa0
};
// matches/0x00193410.cpp (stub Obj), size 0xa8
struct Obj_193410 {
    char pad[0xa4]; // +0x00
    float angle; // +0xa4
    char FUN_00193410(float x);
};
// matches/0x00193430.cpp (stub T_193430), size 0xac
struct T_193430 {
    char FUN_00193430(int value);
    char pad[0xa8]; // +0x00
    int value; // +0xa8
};
// matches/0x00193450.cpp (stub Obj_193450), size 0xb0
struct Obj_193450 {
    char pad[0xac]; // +0x00
    float mAngle; // +0xac
    bool FUN_00193450(float a);
};
// matches/0x00193480.cpp (stub Obj_193480), size 0xb4
struct Obj_193480 {
    char pad[0xb0]; // +0x00
    int value; // +0xb0
    bool FUN_00193480(int v);
};
// matches/0x001934a0.cpp (stub Obj_1934a0), size 0xb8
struct Obj_1934a0 {
    char Pad[0xb4]; // +0x00
    int Value; // +0xb4
    char FUN_001934a0(int x);
};
// matches/0x001934c0.cpp (stub Obj_1934c0), size 0xbc
struct Obj_1934c0 {
    char pad[0xb8]; // +0x00
    int mB8; // +0xb8
    char FUN_001934c0(int x);
};
// matches/0x001934d0.cpp (stub Obj_1934d0), size 0xbc
struct Obj_1934d0 {
    char pad[0xbc]; // +0x00
    int* FUN_001934d0();
};
// matches/0x001934e0.cpp (stub X_1934e0), size 0xc8
struct X_1934e0 {
    char pad[0xc8]; // +0x00
    void* FUN_001934e0();
};
// matches/0x00193500.cpp (stub X_193500), size 0xd8
struct X_193500 {
    char pad[0xd4]; // +0x00
    int mValue; // +0xd4
    bool FUN_00193500(int a);
};
// matches/0x00193520.cpp (stub Obj_193520), size 0xd8
struct Obj_193520 {
    char m[0xd8]; // +0x00
    char FUN_00193520(int x);
};
// matches/0x00193550.cpp (stub Target_193550), size 0xe4
struct Target_193550 {
    char pad[0xe0]; // +0x00
    int value; // +0xe0
    char FUN_00193550(int x);
};
// matches/0x00193560.cpp (stub Obj_193560), size 0xe8
struct Obj_193560 {
    char pad[0xe8]; // +0x00
    char* FUN_00193560();
};
// matches/0x001935a0.cpp (stub Obj), size 0xfc
struct Obj_1935a0 {
    char pad[0xf0]; // +0x00
    int a; // +0xf0
    int b; // +0xf4
    int c; // +0xf8
    char FUN_001935a0(int* p);
};
// matches/0x001935e0.cpp (stub X_1935e0), size 0x100
struct X_1935e0 {
    char pad[0xfc]; // +0x00
    int m1fc; // +0xfc
    bool FUN_001935e0(int a);
};
// matches/0x001935f0.cpp (stub T_1935f0), size 0x100
struct T_1935f0 {
    char pad[0x100]; // +0x00
    char* FUN_001935f0();
};
// matches/0x00193610.cpp (stub Obj_193610), size 0x110
struct Obj_193610 {
    char pad[0x10c]; // +0x00
    int mValue; // +0x10c
    bool FUN_00193610(int x);
};
// matches/0x00193630.cpp (stub Obj_193630), size 0x114
struct Obj_193630 {
    char pad[0x110]; // +0x00
    int value; // +0x110
    bool FUN_00193630(int x);
};
// matches/0x00193650.cpp (stub C_193650), size 0x118
struct C_193650 {
    char pad[0x114]; // +0x00
    int value; // +0x114
    char FUN_00193650(int x);
};
// matches/0x001936d0.cpp (stub Obj_1936d0), size 0x128
struct Obj_1936d0 {
    char pad[0x124]; // +0x00
    int value; // +0x124
    char FUN_001936d0(int v);
};
// matches/0x00193760.cpp (stub Obj_193760), size 0x140
struct Obj_193760 {
    char pad[0x13c]; // +0x00
    int mValue; // +0x13c
    bool FUN_00193760(int value);
};
// matches/0x00193780.cpp (stub C_193780), size 0x144
struct C_193780 {
    char pad[0x140]; // +0x00
    int m; // +0x140
    bool FUN_00193780(int x);
};
// matches/0x001937a0.cpp (stub Obj_1937a0), size 0x148
struct Obj_1937a0 {
    char FUN_001937a0(int x);
    char pad[0x144]; // +0x00
    int mVal; // +0x144
};
// matches/0x001937b0.cpp (stub Obj_1937b0), size 0x10
struct Obj_1937b0 {
    char FUN_001937b0(int x);
    char pad[12]; // +0x00
    int mField; // +0x0c
};
// matches/0x00193850.cpp (stub Obj_193850), size 0x2c
struct Obj_193850 {
    char pad[0x28]; // +0x00
    int mValue; // +0x28
    char FUN_00193850(int x);
};
// matches/0x00193870.cpp (stub Obj_193870), size 0x30
struct Obj_193870 {
    char pad[0x2c]; // +0x00
    int value; // +0x2c
    bool FUN_00193870(int x);
};
// matches/0x00193890.cpp (stub Obj_193890), size 0x34
struct Obj_193890 {
    char pad[0x30]; // +0x00
    int mField; // +0x30
    bool FUN_00193890(int v);
};
// matches/0x001938b0.cpp (stub C_1938b0), size 0x38
struct C_1938b0 {
    char pad[0x34]; // +0x00
    int value; // +0x34
    unsigned char FUN_001938b0(int x);
};
// matches/0x001938d0.cpp (stub Obj_1938d0), size 0x3c
struct Obj_1938d0 {
    char pad[0x38]; // +0x00
    int m38; // +0x38
    bool FUN_001938d0(int value);
};
// matches/0x001938f0.cpp (stub Obj_1938f0), size 0x1
struct Obj_1938f0 {
    char FUN_001938f0(int value);
};
// matches/0x00193900.cpp (stub Obj_193900), size 0x40
struct Obj_193900 {
    char pad[0x40]; // +0x00
    char* FUN_00193900();
};
// matches/0x00193960.cpp (stub Obj_193960), size 0x58
struct Obj_193960 {
    char pad[0x54]; // +0x00
    int mValue; // +0x54
    bool FUN_00193960(int value);
};
// matches/0x00193980.cpp (stub Obj_193980), size 0x5c
struct Obj_193980 {
    char pad[0x58]; // +0x00
    int value; // +0x58
    bool FUN_00193980(int v);
};
// matches/0x001939a0.cpp (stub Obj_1939a0), size 0x64
struct Obj_1939a0 {
    char pad[0x5c]; // +0x00
    int mVal; // +0x5c
    bool mFlag; // +0x60
    bool FUN_001939a0(int x);
};
// matches/0x001939c0.cpp (stub C_1939c0), size 0x64
struct C_1939c0 {
    char pad[0x60]; // +0x00
    int m60; // +0x60
    bool FUN_001939c0(int v);
};
// matches/0x001939e0.cpp (stub Thing), size 0x68
struct Thing_1939e0 {
    char pad[0x64]; // +0x00
    int value; // +0x64
    bool FUN_001939e0(int x);
};
// matches/0x00193a00.cpp (stub O_193a00), size 0x6c
struct O_193a00 {
    char pad[0x68]; // +0x00
    float value; // +0x68
    bool FUN_00193a00(float angle);
};
// matches/0x00193a30.cpp (stub O_193a30), size 0x70
struct O_193a30 {
    char pad[0x6c]; // +0x00
    int m; // +0x6c
    bool FUN_00193a30(int x);
};
// matches/0x00193a50.cpp (stub Obj_193a50), size 0x74
struct Obj_193a50 {
    char pad[0x70]; // +0x00
    int value; // +0x70
    bool FUN_00193a50(int x);
};
// matches/0x00193a70.cpp (stub Obj_193a70), size 0x78
struct Obj_193a70 {
    bool FUN_00193a70(int v);
    char pad[0x74]; // +0x00
    int value; // +0x74
};
// matches/0x00193a90.cpp (stub Obj_193a90), size 0x7c
struct Obj_193a90 {
    char FUN_00193a90(int v);
    char pad[0x78]; // +0x00
    int m78; // +0x78
};
// matches/0x00193ab0.cpp (stub X_193ab0), size 0x80
struct X_193ab0 {
    char pad[0x7c]; // +0x00
    int m7c; // +0x7c
    bool FUN_00193ab0(int v);
};
// matches/0x00193b80.cpp (stub Obj_193b80), size 0x98
struct Obj_193b80 {
    char pad[0x98]; // +0x00
    void* FUN_00193b80();
};
// equivalent/0x00194510.cpp (stub Object), size 0xe0 (0xe8)
struct Object_194510 {
    char pad[0xdc]; // +0x00
    char* text; // +0xdc (+0xe0)
    unsigned char FUN_00194510(const char* value);
};
// matches/0x00194720.cpp (stub C_194720), size 0x1d60
struct C_194720 {
    char pad[0x1d54]; // +0x00
    int a; // +0x1d54
    int b; // +0x1d58
    int c; // +0x1d5c
    void FUN_00194720(int* p);
};
// matches/0x001a1ed0.cpp (stub Obj), size 0xd
struct Obj_1a1ed0 {
    char pad[12]; // +0x00
    unsigned char value; // +0x0c
    unsigned char FUN_001a1ed0(unsigned char v);
};
// matches/0x001a1ee0.cpp (stub O_1a1ee0), size 0x10
struct O_1a1ee0 {
    char pad[0x10]; // +0x00
    void* FUN_001a1ee0();
};
// matches/0x001a1ef0.cpp (stub T_1a1ef0), size 0xd
struct T_1a1ef0 {
    char pad[0xc]; // +0x00
    unsigned char field; // +0x0c
    bool FUN_001a1ef0(unsigned char x);
};
// matches/0x001a1f50.cpp (stub Obj_1a1f50), size 0x10
struct Obj_1a1f50 {
    char pad[0x10]; // +0x00
    int* FUN_001a1f50();
};
// matches/0x001a1f60.cpp (stub X_1a1f60), size 0x10
struct X_1a1f60 {
    char pad[0x10]; // +0x00
    int* FUN_001a1f60();
};
// matches/0x001a1f80.cpp (stub C_1a1f80), size 0x10
struct C_1a1f80 {
    char pad[12]; // +0x00
    int m; // +0x0c
    char FUN_001a1f80(int x);
};
// matches/0x001a1fa0.cpp (stub Obj_1a1fa0), size 0x14
struct Obj_1a1fa0 {
    char pad[0x10]; // +0x00
    int m10; // +0x10
    char FUN_001a1fa0(int value);
};
// matches/0x001a1fb0.cpp (stub Obj_1a1fb0), size 0x18
struct Obj_1a1fb0 {
    char pad[0x18]; // +0x00
    char* FUN_001a1fb0();
};
// matches/0x001a1fc0.cpp (stub Obj_1a1fc0), size 0x20
struct Obj_1a1fc0 {
    char pad[0x20]; // +0x00
    int* FUN_001a1fc0();
};
// matches/0x001a1fe0.cpp (stub Obj_1a1fe0), size 0x28
struct Obj_1a1fe0 {
    char pad[0x28]; // +0x00
    char FUN_001a1fe0(int v);
};
// matches/0x001a1ff0.cpp (stub O_1a1ff0), size 0x30
struct O_1a1ff0 {
    char pad[0x30]; // +0x00
    char* FUN_001a1ff0() throw();
};
// matches/0x001a20b0.cpp (stub Obj_1a20b0), size 0x50
struct Obj_1a20b0 {
    char FUN_001a20b0(int value);
    char pad[0x50]; // +0x00
};
// matches/0x001a20e0.cpp (stub C_1a20e0), size 0x61
struct C_1a20e0 {
    char pad[0x60]; // +0x00
    char m; // +0x60
    char FUN_001a20e0(int v);
};
// matches/0x001a5700.cpp (stub Item_1a5700), size 0x34
struct Item_1a5700 {
    char pad[0x34]; // +0x00
    void FUN_001a5700(void* arg);
};
// matches/0x001a6e10.cpp (stub Owner_1a6e10), size 0x1
struct Owner_1a6e10 {
    void* Get();
    void* FUN_001a6e10();
};
// matches/0x001a6e50.cpp (stub Obj_1a6e50), size 0x1
struct Obj_1a6e50 {
    Obj_1a6e50* Get();
    Obj_1a6e50* FUN_001a6e50();
};
// matches/0x001a6e90.cpp (stub Obj_1a6e90), size 0x1
struct Obj_1a6e90 {
    void* Get();
    void* FUN_001a6e90();
};
// matches/0x001a92e0.cpp (stub Obj_1a92e0), size 0x1
struct Obj_1a92e0 {
    Obj_1a92e0* Get();
    Obj_1a92e0* Tail();
    Obj_1a92e0* FUN_001a92e0();
};
// matches/0x001aace0.cpp (stub Obj_1aace0), size 0x10
struct Obj_1aace0 {
    char pad[0x10]; // +0x00
    int* FUN_001aace0();
};
// matches/0x001aad00.cpp (stub O_1aad00), size 0xd
struct O_1aad00 {
    char pad[12]; // +0x00
    char m; // +0x0c
    char FUN_001aad00(char c);
};
// matches/0x001aad10.cpp (stub Obj_1aad10), size 0x10
struct Obj_1aad10 {
    char pad[0xc]; // +0x00
    int value; // +0x0c
    bool FUN_001aad10(int x);
};
// matches/0x001aad20.cpp (stub Obj_1aad20), size 0x14
struct Obj_1aad20 {
    char pad[0x10]; // +0x00
    int mValue; // +0x10
    bool FUN_001aad20(int value);
};
// matches/0x001aada0.cpp (stub Obj), size 0x10
struct Obj_1aada0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_001aada0(int x);
};
// matches/0x001aadb0.cpp (stub A_1aadb0), size 0x10
struct A_1aadb0 {
    char pad[0x10]; // +0x00
    int* FUN_001aadb0();
};
// matches/0x001ab0e0.cpp (stub Obj_1ab0e0), size 0x1
struct Obj_1ab0e0 {
    int Second(unsigned __int64);
    hulk_intptr FUN_001ab0e0(hulk_uintptr);
};
// matches/0x001acb90.cpp (stub Box_1acb90), size 0x18
struct Box_1acb90 {
    float lo[3]; // +0x00
    float hi[3]; // +0x0c
    unsigned char FUN_001acb90(const float* p);
};
// equivalent/0x001ae150.cpp (stub Ring_1ae150), size 0x28 (0x38)
struct Ring_1ae150 {
    char pad00[0x18]; // +0x00
    int *head; // +0x18
    int *tail; // +0x1c (+0x20)
    int *begin; // +0x20 (+0x28)
    int *end; // +0x24 (+0x30)
    void FUN_001ae150(hulk_intptr value);
};
// equivalent/0x001afb00.cpp (stub Obj), size 0x234
struct Obj_1afb00 {
    char pad[0x230]; // +0x00
    float value; // +0x230
    float FUN_001afb00();
    unsigned int FUN_001d64a0();
};
// matches/0x001b02c0.cpp (stub Obj_1b02c0), size 0x200
struct Obj_1b02c0 {
    char pad[0x1c9]; // +0x00
    unsigned char a; // +0x1c9
    char pad2[0x1fc - 0x1ca]; // +0x1ca
    int b; // +0x1fc
    int FUN_001b02c0();
};
// equivalent/0x001b3040.cpp (stub Object), size 0x38
struct Object_1b3040 {
    unsigned int x,y,z; // +0x00
    int index; // +0x0c
    char pad10[8]; // +0x10
    unsigned int value; // +0x18
    unsigned int a; // +0x1c
    unsigned int untouched20; // +0x20
    unsigned int b; // +0x24
    unsigned int firstHandle,secondHandle,c,d; // +0x28
    void FUN_001b3040(unsigned int, unsigned int, unsigned int, int);
};
// equivalent/0x001b3250.cpp (stub Object), size 0x10
struct Object_1b3250 {
    char pad[12]; // +0x00
    int index; // +0x0c
    int FUN_001b3250(float value);
};
// matches/0x001b32b0.cpp (stub X_1b32b0), size 0x3c
struct X_1b32b0 {
    char pad[0x34]; // +0x00
    int count; // +0x34
    int items[1]; // +0x38
    bool FUN_001b32b0(hulk_intptr value);
};
// matches/0x001b32e0.cpp (stub Thing_1b32e0), size 0x138
struct Thing_1b32e0 {
    char pad[0x34]; // +0x00
    int count; // +0x34
    int vals[64]; // +0x38
    void FUN_001b32e0(hulk_intptr value);
};
// equivalent/0x001b3440.cpp (stub Timeline_1b3440), size 0x28
struct Timeline_1b3440 {
    char pad0[0xc]; // +0x00
    int track; // +0x0c
    char pad10[8]; // +0x10
    float rate; // +0x18
    float pos; // +0x1c
    char pad20[4]; // +0x20
    float time; // +0x24
    int FUN_001b3250(float t);
    bool FUN_001b3440(float dt);
};
// equivalent/0x001b35d0.cpp (stub Obj), size 0x20
struct Obj_1b35d0 {
    char pad0[12]; // +0x00
    int index; // +0x0c
    char pad1[12]; // +0x10
    float limit; // +0x1c
    float FUN_001b35d0(float time);
    int FUN_001b3250(float);
};
// equivalent/0x001b3620.cpp (stub SampleTable), size 0x20
struct SampleTable_1b3620 {
    char padding[12]; // +0x00
    int row; // +0x0c
    char padding2[12]; // +0x10
    float limit; // +0x1c
    float FUN_001b3620(float value);
};
// matches/0x001b3670.cpp (stub Vec_1b3670), size 0x20
struct Vec_1b3670 {
    float x, y, z; // +0x00
    char pad[16]; // +0x0c
    float limit; // +0x1c
    unsigned char FUN_001b3670(const Vec_1b3670*);
};
// matches/0x001b4420.cpp (stub C_1b4420), size 0x594
struct C_1b4420 {
    int FUN_001b4420(int key);
    char pad[0x4fc]; // +0x00
    int data[0x13 + 0x13]; // +0x4fc
};
// matches/0x001b5760.cpp (stub Table_1b5760), size 0x4 (0x8)
struct Table_1b5760 {
    void** slots; // +0x00
    void* FUN_001b5760(unsigned int key);
};
// equivalent/0x001b6000.cpp (stub Tracker_1b6000), size 0x59c (0x5a8)
struct Tracker_1b6000 {
    char pad0[0x594]; // +0x00
    void **itemsBegin; // +0x594 (+0x598)
    void **itemsEnd; // +0x598 (+0x5a0)
    char FUN_001b6000(int id, void ***outList, int *outId);
};
// matches/0x001b68e0.cpp (stub C_1b68e0), size 0x1
struct C_1b68e0 {
    hulk_intptr FUN_001b68e0(int index);
};
// matches/0x001b6d70.cpp (stub Obj_1b6d70), size 0x18
struct Obj_1b6d70 {
    int a; // +0x00
    float b; // +0x04
    int c; // +0x08
    float d; // +0x0c
    int e; // +0x10
    float f; // +0x14
    void FUN_001b6d70(float);
};
// matches/0x001b6de0.cpp (stub C_1b6de0), size 0x18
struct C_1b6de0 {
    int a[6]; // +0x00
    void FUN_001b6de0(hulk_intptr x);
};
// matches/0x001b6e60.cpp (stub Thing_1b6e60), size 0x18
struct Thing_1b6e60 {
    int a[6]; // +0x00
    void fallback(int);
    void FUN_001b6e60(hulk_intptr);
};
// matches/0x001b6e90.cpp (stub X_1b6e90), size 0x1
struct X_1b6e90 {
    bool FUN_001b6e90(hulk_intptr v);
};
// matches/0x001b6f00.cpp (stub Obj_1b6f00), size 0x9
struct Obj_1b6f00 {
    char pad[9]; // +0x00
    char FUN_001b6f00();
};
// matches/0x001b7260.cpp (stub C_1b7260), size 0x130
struct C_1b7260 {
    char pad[0x118]; // +0x00
    int a; // +0x118
    int b; // +0x11c
    int c; // +0x120
    char gap[8]; // +0x124
    int d; // +0x12c
    void FUN_001b7260(hulk_intptr x, hulk_intptr y, hulk_intptr z, hulk_intptr w);
};
// matches/0x001b83c0.cpp (stub Object), size 0x18
struct Object_1b83c0 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    char data[4]; // +0x14
    void FUN_001b83c0();
    void FUN_001b8350(void*, int);
};
// matches/0x001b8810.cpp (stub Obj_1b8810), size 0x34
struct Obj_1b8810 {
    char pad[0x33]; // +0x00
    unsigned char field; // +0x33
    unsigned char FUN_001b8810();
};
// matches/0x001b8820.cpp (stub C_1b8820), size 0x40
struct C_1b8820 {
    char pad[0x34]; // +0x00
    int a, b, c; // +0x34
    void FUN_001b8820(int*, int*, int*);
};
// matches/0x001b8840.cpp (stub C_1b8840), size 0x4c
struct C_1b8840 {
    char pad[0x40]; // +0x00
    int a, b, c; // +0x40
    void FUN_001b8840(int* x, int* y, int* z);
};
// matches/0x001b8860.cpp (stub C_1b8860), size 0x64
struct C_1b8860 {
    char pad[0x4c]; // +0x00
    int a, b, c, d, e, f; // +0x4c
    void FUN_001b8860(int* p1, int* p2, int* p3, int* p4, int* p5, int* p6);
};
// matches/0x001b8ae0.cpp (stub A_1b8ae0), size 0x19
struct A_1b8ae0 {
    char pad[0x18]; // +0x00
    unsigned char x; // +0x18
    void FUN_001b8ae0();
};
// matches/0x001bde50.cpp (stub Thing_1bde50), size 0x4c (0x58)
struct Thing_1bde50 {
    char pad[0x34]; // +0x00
    Thing_1bde50* a; // +0x34 (+0x38)
    Thing_1bde50* b; // +0x38 (+0x40)
    char pad2[0x0c]; // +0x3c (+0x48)
    int value; // +0x48 (+0x54)
    void Prepare(int);
    void Finish();
    bool FUN_001bde50(int);
};
// matches/0x001c05d0.cpp (stub Obj_1c05d0), size 0x54 (0x60)
struct Obj_1c05d0 {
    float value; // +0x00
    void* ptr; // +0x04 (+0x08)
    char pad08[4]; // +0x08 (+0x10)
    char active; // +0x0c (+0x14)
    char up; // +0x0d (+0x15)
    char pad0e[0x42]; // +0x0e (+0x16)
    int amount; // +0x50 (+0x58)
    void Tick();
    void FUN_001c05d0(float a, float b);
};
// matches/0x001c16a0.cpp (stub Target_1c16a0), size 0xc0 (0xc8)
struct Target_1c16a0 {
    char pad[0xbc]; // +0x00
    hulk_intptr value; // +0xbc (+0xc0)
    void FUN_001c16a0(void*);
};
// matches/0x001c16e0.cpp (stub Obj_1c16e0), size 0xdc
struct Obj_1c16e0 {
    char p[0xd0]; // +0x00
    float a; // +0xd0
    float b; // +0xd4
    unsigned char c; // +0xd8
    void FUN_001c16e0(float x, float y);
};
// matches/0x001c1750.cpp (stub Obj_1c1750), size 0xd8
struct Obj_1c1750 {
    char pad[0xd0]; // +0x00
    int a; // +0xd0
    int b; // +0xd4
    void FUN_001c1750(int* x, int* y);
};
// matches/0x001c1780.cpp (stub Target_1c1780), size 0xda
struct Target_1c1780 {
    char pad[0xD9]; // +0x00
    unsigned char value; // +0xd9
    void FUN_001c1780(unsigned char v);
};
// matches/0x001c1790.cpp (stub C_1c1790), size 0xe0
struct C_1c1790 {
    char pad[0xdc]; // +0x00
    int value; // +0xdc
    int FUN_001c1790(int x);
};
// matches/0x001c17a0.cpp (stub Obj_1c17a0), size 0xec
struct Obj_1c17a0 {
    char pad[0xe4]; // +0x00
    unsigned a; // +0xe4
    unsigned b; // +0xe8
    void FUN_001c17a0(unsigned x, unsigned y);
};
// matches/0x001c17c0.cpp (stub C_1c17c0), size 0xf0
struct C_1c17c0 {
    char pad[0xec]; // +0x00
    int value; // +0xec
    int FUN_001c17c0(int);
};
// matches/0x001c27d0.cpp (stub C_1c27d0), size 0x8
struct C_1c27d0 {
    int count; // +0x00
    float data[1]; // +0x04
    bool FUN_001c27d0(float* p);
};
// matches/0x001c3770.cpp (stub Thing_1c3770), size 0x14
struct Thing_1c3770 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    void FUN_001c3770(hulk_intptr x);
};
// matches/0x001c3810.cpp (stub C_1c3810), size 0x18 (0x20)
struct C_1c3810 {
    char pad[0x14]; // +0x00
    C_1c3810* p; // +0x14 (+0x18)
    void FUN_001c3810(int, int, int, int);
    void helper(int, int, int, int);
};
// matches/0x001c38b0.cpp (stub Obj_1c38b0), size 0x70
struct Obj_1c38b0 {
    char pad[0x5c]; // +0x00
    float x; // +0x5c
    float y; // +0x60
    char pad2[8]; // +0x64
    unsigned char dirty; // +0x6c
    void FUN_001c38b0(float a, float b);
};
// matches/0x001c38f0.cpp (stub Thing_1c38f0), size 0x64
struct Thing_1c38f0 {
    char pad[0x5c]; // +0x00
    int a; // +0x5c
    int b; // +0x60
    void FUN_001c38f0(int* x, int* y);
};
// matches/0x001c3910.cpp (stub Obj_1c3910), size 0x70
struct Obj_1c3910 {
    char pad[0x64]; // +0x00
    float a; // +0x64
    float b; // +0x68
    unsigned char dirty; // +0x6c
    void FUN_001c3910(float x, float y);
};
// matches/0x001c3950.cpp (stub Thing_1c3950), size 0x6c
struct Thing_1c3950 {
    char pad[0x64]; // +0x00
    int a; // +0x64
    int b; // +0x68
    void FUN_001c3950(int* x, int* y);
};
// matches/0x001c3970.cpp (stub Obj_1c3970), size 0x70
struct Obj_1c3970 {
    char pad[0x1c]; // +0x00
    unsigned int data[16]; // +0x1c
    char pad2[0x10]; // +0x5c
    unsigned char flag; // +0x6c
    void FUN_001c3970(unsigned int* src);
};
// matches/0x001c39d0.cpp (stub Object), size 0x4c
struct Object_1c39d0 {
    char pad[0x4c]; // +0x00
    void* FUN_001c39d0();
};
// matches/0x001c3ca0.cpp (stub C_1c3ca0), size 0x70
struct C_1c3ca0 {
    char pad[0x6f]; // +0x00
    unsigned char value; // +0x6f
    void FUN_001c3ca0(unsigned char x);
};
// matches/0x001c4010.cpp (stub Thing_1c4010), size 0x70
struct Thing_1c4010 {
    char pad[0x5c]; // +0x00
    int a; // +0x5c
    int b; // +0x60
    int c; // +0x64
    int d; // +0x68
    char done; // +0x6c
    int FUN_001c4010(hulk_intptr);
};
// matches/0x001c4050.cpp (stub Thing_1c4050), size 0x70
struct Thing_1c4050 {
    char pad[0x5c]; // +0x00
    int a; // +0x5c
    int b; // +0x60
    int c; // +0x64
    int d; // +0x68
    char done; // +0x6c
    int FUN_001c4050(hulk_intptr);
};
// equivalent/0x001c4390.cpp (stub State_1c4390), size 0x38
struct State_1c4390 {
    char pad[0x14]; // +0x00
    unsigned char firstActive; // +0x14
    char pad15[3]; // +0x15
    float firstValue, firstTarget, firstRate; // +0x18
    unsigned char secondActive; // +0x24
    char pad25[3]; // +0x25
    float secondValue, secondTarget, secondRate; // +0x28
    unsigned char dirty; // +0x34
    void FUN_001c4390(float target, unsigned char secondEnabled, float secondDuration, unsigned char firstEnabled, float firstDuration);
};
// equivalent/0x001c4450.cpp (stub Transition_1c4450), size 0x34
struct Transition_1c4450 {
    char pad[0x14]; // +0x00
    unsigned char active1; // +0x14
    char pad15[3]; // +0x15
    float current1, target1, rate1; // +0x18
    unsigned char active2; // +0x24
    char pad25[3]; // +0x25
    float current2, target2, rate2; // +0x28
    void FUN_001c4450(unsigned char first, float firstTime, unsigned char second, float secondTime);
};
// matches/0x001c4580.cpp (stub Slider_1c4580), size 0x10
struct Slider_1c4580 {
    bool active; // +0x00
    char pad01[3]; // +0x01
    float position; // +0x04
    float target; // +0x08
    float rate; // +0x0c
    void FUN_001c4580(float dt);
};
// matches/0x001c4ac0.cpp (stub Obj_1c4ac0), size 0xa8
struct Obj_1c4ac0 {
    char pad[0x9c]; // +0x00
    unsigned a, b, c; // +0x9c
    void FUN_001c4ac0(unsigned* p, unsigned v);
};
// matches/0x001c4b20.cpp (stub Target_1c4b20), size 0xb0
struct Target_1c4b20 {
    char pad0[0x80]; // +0x00
    int a80; // +0x80
    int a84; // +0x84
    int a88; // +0x88
    char pad8c[0x20]; // +0x8c
    int aac; // +0xac
    void FUN_001c4b20();
};
// matches/0x001c4d60.cpp (stub X_1c4d60), size 0x70
struct X_1c4d60 {
    char pad[0x30]; // +0x00
    unsigned int data[16]; // +0x30
    void FUN_001c4d60(unsigned int*);
};
// matches/0x001c5080.cpp (stub Blend_1c5080), size 0x8c
struct Blend_1c5080 {
    char pad0[0x80]; // +0x00
    float held; // +0x80
    float value; // +0x84
    float rate; // +0x88
    void FUN_001c5080(float input, float duration);
};
// matches/0x001c52f0.cpp (stub Blender_1c52f0), size 0xa4
struct Blender_1c52f0 {
    char pad0[0x80]; // +0x00
    float value; // +0x80
    float limit; // +0x84
    float accel; // +0x88
    char fresh; // +0x8c
    char pad8d[3]; // +0x8d
    float current; // +0x90
    float target; // +0x94
    float rate; // +0x98
    char pad9c[4]; // +0x9c
    float timer; // +0xa0
    void FUN_001c52f0(float unused);
};
// matches/0x001c59e0.cpp (stub Obj_1c59e0), size 0x20 (0x28)
struct Obj_1c59e0 {
    char pad[0x10]; // +0x00
    unsigned int limit; // +0x10
    char pad2[4]; // +0x14
    int count; // +0x18
    int* items; // +0x1c (+0x20)
    void FUN_001c59e0(int);
};
// matches/0x001c5b10.cpp (stub Obj_1c5b10), size 0x128
struct Obj_1c5b10 {
    char pad[0x128]; // +0x00
    void FUN_001c5b10(unsigned int arg);
};
// matches/0x001c5e40.cpp (stub Obj_1c5e40), size 0x8
struct Obj_1c5e40 {
    char pad[8]; // +0x00
    void FUN_001c5e40(hulk_uintptr);
};
// matches/0x001c5ed0.cpp (stub Owner_1c5ed0), size 0x14 (0x18)
struct Owner_1c5ed0 {
    char pad[16]; // +0x00
    int* target; // +0x10
    void FUN_001c5ed0(void* src);
};
// matches/0x001c5ef0.cpp (stub Obj_1c5ef0), size 0x14 (0x18)
struct Obj_1c5ef0 {
    char pad[0x10]; // +0x00
    void* ptr; // +0x10
    void FUN_001c5ef0(unsigned char v);
};
// matches/0x001c5f20.cpp (stub Target_1c5f20), size 0x8
struct Target_1c5f20 {
    char pad[4]; // +0x00
    unsigned int value; // +0x04
    void FUN_001c5f20();
};
// matches/0x001c5f30.cpp (stub Thing_1c5f30), size 0x10 (0x18)
struct Thing_1c5f30 {
    int pad0; // +0x00
    unsigned int* data; // +0x04 (+0x08)
    unsigned int count; // +0x08 (+0x10)
    unsigned int capacity; // +0x0c (+0x14)
    void FUN_001c5f30(hulk_uintptr value);
};
// matches/0x001c7f80.cpp (stub Thing_1c7f80), size 0x30 (0x38)
struct Thing_1c7f80 {
    char pad[0x20]; // +0x00
    unsigned int count; // +0x20
    char pad2[8]; // +0x24
    unsigned int* values; // +0x2c (+0x30)
    hulk_uintptr FUN_001c7f80(unsigned int i);
};
// matches/0x001c8810.cpp (stub Bag_1c8810), size 0x53c
struct Bag_1c8810 {
    char pad0[0x138]; // +0x00
    int items[256]; // +0x138
    volatile unsigned int count; // +0x538
    void FUN_001c8810(hulk_intptr value);
};
// matches/0x001c8860.cpp (stub C_1c8860), size 0x53c
struct C_1c8860 {
    char pad[0x138]; // +0x00
    int items[256]; // +0x138
    volatile unsigned int count; // +0x538
    void FUN_001c8860(int value);
};
// matches/0x001c96e0.cpp (stub C_1c96e0), size 0x8
struct C_1c96e0 {
    int pad[2]; // +0x00
    int FUN_001c96e0(int i);
};
// matches/0x001c9700.cpp (stub Thing_1c9700), size 0x8
struct Thing_1c9700 {
    int pad[2]; // +0x00
    bool FUN_001c9700(int index, int value);
};
// equivalent/0x001c9750.cpp (stub Object), size 0xa4
struct Object_1c9750 {
    unsigned size; // +0x00
    unsigned arg; // +0x04
    char pad0[8]; // +0x08
    unsigned id; // +0x10
    char name[0x40]; // +0x14
    char text1[0x20]; // +0x54
    char text2[0x20]; // +0x74
    char pad1[4]; // +0x94
    unsigned value1; // +0x98
    unsigned value2; // +0x9c
    unsigned extra; // +0xa0
    Object_1c9750* FUN_001c9750(unsigned, unsigned, unsigned);
};
// matches/0x001c9920.cpp (stub Obj_1c9920), size 0xbc
struct Obj_1c9920 {
    char pad[0xC]; // +0x00
    volatile int value; // +0x0c
    char rest[0xA0]; // +0x10
    unsigned int a; // +0xb0
    unsigned int b; // +0xb4
    volatile unsigned char c; // +0xb8
    Obj_1c9920* FUN_001c9920(int, hulk_intptr, int, unsigned char);
};
// equivalent/0x001c9970.cpp (stub Object), size 0xbc
struct Object_1c9970 {
    char padding[0xb0]; // +0x00
    unsigned int originLow; // +0xb0
    unsigned int originHigh; // +0xb4
    unsigned char devastator; // +0xb8
    bool FUN_001c9840();
    bool FUN_001c9970();
};
// matches/0x001c9a20.cpp (stub Obj_1c9a20), size 0x4
struct Obj_1c9a20 {
    unsigned int pad; // +0x00
    hulk_uintptr FUN_001c9a20(unsigned int);
};
// matches/0x001c9a40.cpp (stub C_1c9a40), size 0x1
struct C_1c9a40 {
    C_1c9a40* helper(int, int, unsigned);
    C_1c9a40* FUN_001c9a40(unsigned);
};
// equivalent/0x001c9aa0.cpp (stub ChargeEvent), size 0x1c
struct ChargeEvent_1c9aa0 {
    char pad[0x10]; // +0x00
    int actorId; // +0x10
    int chargeType; // +0x14
    int charge; // +0x18
    bool FUN_001c9aa0();
};
// equivalent/0x001c9b30.cpp (stub Task), size 0x20
struct Task_1c9b30 {
    unsigned type, kind, a, b, c, d, arg1, arg2; // +0x00
    Task_1c9b30 * FUN_001c9b30(unsigned x, unsigned y);
};
// equivalent/0x001c9cd0.cpp (stub Item), size 0x20 (0x40)
struct Item_1c9cd0 {
    hulk_uintptr size, kind, a, b, c, d, first, second; // +0x00
    Item_1c9cd0* FUN_001c9cd0(unsigned int x, unsigned int y);
};
// equivalent/0x001c9e70.cpp (stub Obj), size 0x20
struct Obj_1c9e70 {
    unsigned a,b,c,d,e,f,g,h; // +0x00
    Obj_1c9e70* FUN_001c9e70(unsigned x, unsigned y);
};
// matches/0x001c9f40.cpp (stub Obj_1c9f40), size 0x54
struct Obj_1c9f40 {
    int v; // +0x00
    int a; // +0x04
    char pad[12]; // +0x08
    char s1[32]; // +0x14
    char s2[32]; // +0x34
    Obj_1c9f40* FUN_001c9f40(int, const char*, const char*);
};
// matches/0x001ca000.cpp (stub C_1ca000), size 0x1
struct C_1ca000 {
    void helper(int, int, int);
    hulk_intptr FUN_001ca000(hulk_intptr, hulk_intptr);
};
// matches/0x001ca020.cpp (stub C_1ca020), size 0x1
struct C_1ca020 {
    void callee(int, int, int);
    C_1ca020* FUN_001ca020(hulk_intptr, hulk_intptr);
};
// matches/0x001ca040.cpp (stub Obj_1ca040), size 0x1
struct Obj_1ca040 {
    Obj_1ca040* FUN_001ca040(hulk_intptr, hulk_intptr);
    void helper(int, int, int);
};
// matches/0x001ca090.cpp (stub Owner_1ca090), size 0x18
struct Owner_1ca090 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    bool FUN_001ca090();
};
// equivalent/0x001ca170.cpp (stub PositionEvent), size 0x60
struct PositionEvent_1ca170 {
    char pad[0x10]; // +0x00
    int actorId; // +0x10
    char pad14[0x54 - 0x14]; // +0x14
    int x, y, z; // +0x54
    bool FUN_001ca170();
};
// equivalent/0x001ca250.cpp (stub Event_1ca250), size 0x1c
struct Event_1ca250 {
    char pad00[0x10]; // +0x00
    int actorId; // +0x10
    int oldValue; // +0x14
    int newValue; // +0x18
    bool FUN_001ca250();
};
// equivalent/0x001ca2e0.cpp (stub Record), size 0x5c
struct Record_1ca2e0 {
    unsigned int size; // +0x00
    unsigned int kind; // +0x04
    char reserved[8]; // +0x08
    unsigned int value; // +0x10
    char text[0x40]; // +0x14
    unsigned int extra; // +0x54
    unsigned char flag; // +0x58
    char tail[3]; // +0x59
    Record_1ca2e0 * FUN_001ca2e0(const char *text, unsigned int value, unsigned int extra, unsigned char flag);
};
// equivalent/0x001ca330.cpp (stub WaypointEvent), size 0x5c
struct WaypointEvent_1ca330 {
    char pad[0x10]; // +0x00
    int actorId; // +0x10
    char path[0x54 - 0x14]; // +0x14
    int waypoint; // +0x54
    unsigned char firstTime; // +0x58
    bool FUN_001ca330();
};
// equivalent/0x001ca3d0.cpp (stub Packet), size 0x30
struct Packet_1ca3d0 {
    unsigned int kind; // +0x00
    unsigned int subtype; // +0x04
    unsigned int unused08; // +0x08
    unsigned int unused0c; // +0x0c
    unsigned int value10; // +0x10
    unsigned int unused14; // +0x14
    unsigned int value18; // +0x18
    unsigned int value1c; // +0x1c
    unsigned int value20; // +0x20
    unsigned int value24; // +0x24
    unsigned int value28; // +0x28
    unsigned int unused2c; // +0x2c
    Packet_1ca3d0* FUN_001ca3d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f);
};
// matches/0x001cacc0.cpp (stub Owner_1cacc0), size 0x1c
struct Owner_1cacc0 {
    char pad[0x14]; // +0x00
    int oldValue; // +0x14
    int newValue; // +0x18
    bool FUN_001cacc0();
};
// matches/0x001cad40.cpp (stub Owner_1cad40), size 0x18
struct Owner_1cad40 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    bool FUN_001cad40();
};
// matches/0x001cadb0.cpp (stub Owner_1cadb0), size 0x18
struct Owner_1cadb0 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    bool FUN_001cadb0();
};
// equivalent/0x001cadf0.cpp (stub Item), size 0x20 (0x40)
struct Item_1cadf0 {
    hulk_uintptr a,b,c,d,e,f,g,h; // +0x00
    Item_1cadf0 * FUN_001cadf0(unsigned int x, unsigned int y);
};
// equivalent/0x001cae40.cpp (stub Result), size 0x20
struct Result_1cae40 {
    unsigned int first, second, a, b, c, d, low, high; // +0x00
    Result_1cae40* FUN_001cae40(hulk_uintptr value);
};
// matches/0x001caf40.cpp (stub Owner_1caf40), size 0x18
struct Owner_1caf40 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    bool FUN_001caf40();
};
// matches/0x001caf80.cpp (stub Obj_1caf80), size 0x54
struct Obj_1caf80 {
    unsigned int data[21]; // +0x00
    Obj_1caf80* FUN_001caf80(const char* a, unsigned int b);
};
// matches/0x001cafd0.cpp (stub Actor_1cafd0), size 0x18
struct Actor_1cafd0 {
    char pad[0x10]; // +0x00
    int mId; // +0x10
    char mName[4]; // +0x14
    bool FUN_001cafd0();
};
// matches/0x001cb050.cpp (stub Obj_1cb050), size 0x54
struct Obj_1cb050 {
    unsigned int data[21]; // +0x00
    Obj_1cb050* FUN_001cb050(hulk_intptr a, unsigned int b);
};
// matches/0x001cb0a0.cpp (stub Actor_1cb0a0), size 0x18
struct Actor_1cb0a0 {
    char pad[0x10]; // +0x00
    int mId; // +0x10
    char mName[4]; // +0x14
    bool FUN_001cb0a0();
};
// equivalent/0x001cb170.cpp (stub Dispatcher_1cb170), size 0x8
struct Dispatcher_1cb170 {
    int pad0; // +0x00
    int type; // +0x04
    void FUN_001c9840();
    void FUN_001c9970();
    void FUN_001c9aa0();
    void FUN_001c9b80();
    void FUN_001c9c50();
    void FUN_001c9d20();
    void FUN_001c9df0();
    void FUN_001c9ec0();
    void FUN_001c9fb0();
    void FUN_001ca090();
    void FUN_001ca170();
    void FUN_001ca250();
    void FUN_001ca330();
    void FUN_001ca430();
    void FUN_001ca5b0();
    void FUN_001ca730();
    void FUN_001ca890();
    void FUN_001caa10();
    void FUN_001cab60();
    void FUN_001cacc0();
    void FUN_001cad40();
    void FUN_001cadb0();
    void FUN_001cae90();
    void FUN_001caf40();
    void FUN_001cafd0();
    void FUN_001cb0a0();
    bool FUN_001cb170();
};
// matches/0x001cb3f0.cpp (stub C_1cb3f0), size 0x8
struct C_1cb3f0 {
    int x; // +0x00
    int y; // +0x04
    void FUN_001cb3f0(hulk_intptr);
};
// matches/0x001cbcb0.cpp (stub Owner_1cbcb0), size 0x3fc
struct Owner_1cbcb0 {
    char pad[0x3e4]; // +0x00
    unsigned char active[0x18]; // +0x3e4
    bool FUN_001cbcb0(int);
};
// matches/0x001cbd40.cpp (stub Obj_1cbd40), size 0x8 (0x10)
struct Obj_1cbd40 {
    char pad[4]; // +0x00
    unsigned int* mEnd; // +0x04 (+0x08)
    void FUN_001cbd40(unsigned int* dst, unsigned int* src);
};
// matches/0x001ccb80.cpp (stub C_1ccb80), size 0x1190
struct C_1ccb80 {
    char pad[0x1190]; // +0x00
    void FUN_001ccb80();
};
// matches/0x001cd3d0.cpp (stub Obj_1cd3d0), size 0x1198
struct Obj_1cd3d0 {
    char pad0[8]; // +0x00
    int field8; // +0x08
    int padc; // +0x0c
    int data[0x40]; // +0x10
    char pad110[0x1194 - 0x110]; // +0x110
    int last; // +0x1194
    void FUN_001cd3d0(hulk_intptr);
    void Tail(int);
};
// matches/0x001cd650.cpp (stub Thing_1cd650), size 0x11b4
struct Thing_1cd650 {
    char pad[0x11a8]; // +0x00
    float timer; // +0x11a8
    int a; // +0x11ac
    int b; // +0x11b0
    void FUN_001cd650(float dt);
};
// matches/0x001ce020.cpp (stub Obj_1ce020), size 0x11a4
struct Obj_1ce020 {
    char pad[0x1198]; // +0x00
    float value; // +0x1198
    char pad2[4]; // +0x119c
    unsigned char flag; // +0x11a0
    int Check();
    void First(float);
    void Second(float);
    void FUN_001ce020(float);
};
// matches/0x001d04b0.cpp (stub CAgent), size 0xc (0x18)
struct CAgent_1d04b0 {
    void* vftable; // +0x00
    hulk_intptr name; // +0x04 (+0x08)
    hulk_intptr field; // +0x08 (+0x10)
    void FUN_001d04b0(hulk_intptr);
};
// matches/0x001d15d0.cpp (stub Obj_1d15d0), size 0xc (0x18)
struct Obj_1d15d0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr value; // +0x08 (+0x10)
    void FUN_001d15d0(char flag);
};
// equivalent/0x001d17f0.cpp (stub Object), size 0xc (0x18)
struct Object_1d17f0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    void* state; // +0x08 (+0x10)
    int FUN_001d17f0(void* context);
};
// matches/0x001d1900.cpp (stub Obj_1d1900), size 0xc (0x18)
struct Obj_1d1900 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr field; // +0x08 (+0x10)
    bool FUN_001d1900(hulk_intptr n);
};
// matches/0x001d1930.cpp (stub C_1d1930), size 0xc (0x18)
struct C_1d1930 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr m; // +0x08 (+0x10)
    bool FUN_001d1930(int n);
};
// matches/0x001d1980.cpp (stub Obj_1d1980), size 0xc (0x18)
struct Obj_1d1980 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr member; // +0x08 (+0x10)
    bool FUN_001d1980(hulk_uintptr arg, unsigned char flag);
};
// matches/0x001d19d0.cpp (stub Obj_1d19d0), size 0xc (0x18)
struct Obj_1d19d0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_uintptr value; // +0x08 (+0x10)
    unsigned char FUN_001d19d0(unsigned int arg);
};
// matches/0x001d19f0.cpp (stub Obj_1d19f0), size 0xc (0x18)
struct Obj_1d19f0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr field; // +0x08 (+0x10)
    bool FUN_001d19f0(hulk_intptr a, int b, char flag);
};
// matches/0x001d1a50.cpp (stub C_1d1a50), size 0xc (0x18)
struct C_1d1a50 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_uintptr member; // +0x08 (+0x10)
    bool FUN_001d1a50(hulk_uintptr arg);
};
// matches/0x001d1ac0.cpp (stub C_1d1ac0), size 0xc (0x18)
struct C_1d1ac0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_uintptr member; // +0x08 (+0x10)
    bool FUN_001d1ac0(unsigned int arg);
};
// matches/0x001d1ae0.cpp (stub Owner_1d1ae0), size 0xc (0x18)
struct Owner_1d1ae0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr value; // +0x08 (+0x10)
    unsigned char FUN_001d1ae0(unsigned char*);
};
// matches/0x001d1bc0.cpp (stub Obj_1d1bc0), size 0xc (0x18)
struct Obj_1d1bc0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr value; // +0x08 (+0x10)
    bool FUN_001d1bc0();
};
// matches/0x001d1c10.cpp (stub C_1d1c10), size 0xc (0x18)
struct C_1d1c10 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr obj; // +0x08 (+0x10)
    bool FUN_001d1c10(int);
};
// matches/0x001d1d50.cpp (stub Thing_1d1d50), size 0xc (0x18)
struct Thing_1d1d50 {
    bool FUN_001d1d50(hulk_uintptr a, hulk_uintptr b);
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    void* m; // +0x08 (+0x10)
};
// matches/0x001d1d90.cpp (stub Obj_1d1d90), size 0xc (0x18)
struct Obj_1d1d90 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr member; // +0x08 (+0x10)
    bool FUN_001d1d90(hulk_intptr, int);
};
// matches/0x001d1dd0.cpp (stub Obj_1d1dd0), size 0xc (0x18)
struct Obj_1d1dd0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr field; // +0x08 (+0x10)
    bool FUN_001d1dd0(hulk_intptr a, int b);
};
// matches/0x001d1e10.cpp (stub Obj_1d1e10), size 0xc (0x18)
struct Obj_1d1e10 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    void* member; // +0x08 (+0x10)
    bool FUN_001d1e10(hulk_intptr a, unsigned char b);
};
// matches/0x001d1f30.cpp (stub C_1d1f30), size 0x4 (0x8)
struct C_1d1f30 {
    unsigned int* p; // +0x00
    void FUN_001d1f30(unsigned int a, unsigned int b, unsigned int c);
};
// matches/0x001d2890.cpp (stub Object), size 0xc (0x18)
struct Object_1d2890 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    void* state; // +0x08 (+0x10)
    unsigned int FUN_001d2890(hulk_uintptr a, unsigned int b, unsigned int c);
};
// matches/0x001d29b0.cpp (stub Runner_1d29b0), size 0xc (0x18)
struct Runner_1d29b0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr handle; // +0x08 (+0x10)
    int FUN_001d17f0(hulk_intptr h);
    char FUN_001d29b0(hulk_intptr arg, char *failed);
};
// matches/0x001d2b10.cpp (stub Obj_1d2b10), size 0xc (0x18)
struct Obj_1d2b10 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    void* data; // +0x08 (+0x10)
    int FUN_001d2b10(int, int);
};
// matches/0x001d2c60.cpp (stub K_1d2c60), size 0xc (0x18)
struct K_1d2c60 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr state; // +0x08 (+0x10)
    bool FUN_001d2c60(hulk_intptr a, hulk_intptr b, int c);
};
// matches/0x001d2cd0.cpp (stub C_1d2cd0), size 0xc (0x18)
struct C_1d2cd0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr field; // +0x08 (+0x10)
    bool FUN_001d2cd0(int, hulk_intptr, int);
};
// matches/0x001d2d40.cpp (stub Obj_1d2d40), size 0xc (0x18)
struct Obj_1d2d40 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr field; // +0x08 (+0x10)
    bool FUN_001d2d40(hulk_intptr arg, float* out);
};
// matches/0x001d2da0.cpp (stub Converter), size 0x1
struct Converter_1d2da0 {
    unsigned char FUN_001d2d40(unsigned int, float*);
    unsigned char FUN_001d2da0(hulk_uintptr value, int* result);
};
// matches/0x001d2de0.cpp (stub C_1d2de0), size 0xc (0x18)
struct C_1d2de0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr member; // +0x08 (+0x10)
    int FUN_001d2de0(hulk_intptr a, hulk_intptr b);
    int finish(int);
};
// matches/0x001d2e10.cpp (stub C_1d2e10), size 0xc (0x18)
struct C_1d2e10 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr L; // +0x08 (+0x10)
    bool FUN_001d2e10(hulk_intptr a, int* out);
};
// matches/0x001d2e80.cpp (stub Obj_1d2e80), size 0xc (0x18)
struct Obj_1d2e80 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    void* m; // +0x08 (+0x10)
    void F1d1cb0();
    bool FUN_001d2e80();
};
// matches/0x001d35a0.cpp (stub Obj_1d35a0), size 0xc (0x18)
struct Obj_1d35a0 {
    void* vftable; // +0x00
    int state; // +0x04 (+0x08)
    hulk_intptr handle; // +0x08 (+0x10)
    int FUN_001d35a0(const char* text, hulk_intptr x, hulk_intptr len);
    int Do(int h, const char* text, hulk_intptr len, int x);
};
// equivalent/0x001d3600.cpp (stub Object), size 0xc (0x18)
struct Object_1d3600 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_uintptr context; // +0x08 (+0x10)
    int FUN_001d2810(hulk_uintptr, char*, unsigned int, const char*);
    int FUN_001d3600(const char* name, unsigned int unused);
};
// matches/0x001d3b70.cpp (stub Obj_1d3b70), size 0x10 (0x20)
struct Obj_1d3b70 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    void* field8; // +0x08 (+0x10)
    char pad2[4]; // +0x0c (+0x18)
    void FUN_001d3b70(hulk_uintptr a, hulk_intptr b);
};
// matches/0x001d3c50.cpp (stub Thing_1d3c50), size 0x1
struct Thing_1d3c50 {
    void Load(const char*, int);
    void FUN_001d3c50();
};
// matches/0x001d40b0.cpp (stub Obj_1d40b0), size 0xc (0x18)
struct Obj_1d40b0 {
    void* vftable; // +0x00
    int status; // +0x04 (+0x08)
    hulk_intptr value; // +0x08 (+0x10)
    void Init();
    void FUN_001d40b0();
};
// matches/0x001d4de0.cpp (stub C_1d4de0), size 0x94
struct C_1d4de0 {
    char pad[0x94]; // +0x00
    int FUN_001d4de0();
};
// matches/0x001d4df0.cpp (stub Target_1d4df0), size 0xac
struct Target_1d4df0 {
    char pad[0xa8]; // +0x00
    int value; // +0xa8
    int FUN_001d4df0();
};
// matches/0x001d4e00.cpp (stub C_1d4e00), size 0xac
struct C_1d4e00 {
    char pad[0xa8]; // +0x00
    unsigned int value; // +0xa8
    hulk_uintptr FUN_001d4e00();
};
// matches/0x001d4e10.cpp (stub C_1d4e10), size 0xb0
struct C_1d4e10 {
    char pad[0xac]; // +0x00
    unsigned int value; // +0xac
    unsigned int FUN_001d4e10();
};
// matches/0x001d4e20.cpp (stub Obj_1d4e20), size 0xb2
struct Obj_1d4e20 {
    char pad[0xb1]; // +0x00
    unsigned char value; // +0xb1
    unsigned char FUN_001d4e20();
};
// matches/0x001d4e40.cpp (stub Obj_1d4e40), size 0xb4
struct Obj_1d4e40 {
    char pad[0xb3]; // +0x00
    unsigned char value; // +0xb3
    unsigned char FUN_001d4e40();
};
// matches/0x001d4e50.cpp (stub C_1d4e50), size 0xb4
struct C_1d4e50 {
    char pad[0xb4]; // +0x00
    unsigned char FUN_001d4e50();
};
// matches/0x001d4e60.cpp (stub C_1d4e60), size 0xb6
struct C_1d4e60 {
    char pad[0xb5]; // +0x00
    unsigned char value; // +0xb5
    unsigned char FUN_001d4e60();
};
// matches/0x001d4e70.cpp (stub C_1d4e70), size 0xb7
struct C_1d4e70 {
    char pad[0xb6]; // +0x00
    unsigned char field; // +0xb6
    unsigned char FUN_001d4e70();
};
// matches/0x001d4e80.cpp (stub C_1d4e80), size 0xa0
struct C_1d4e80 {
    char pad[0x9c]; // +0x00
    int value; // +0x9c
    int FUN_001d4e80();
};
// matches/0x001d4ea0.cpp (stub Target_1d4ea0), size 0xbc (0xc0)
struct Target_1d4ea0 {
    char pad[0xb8]; // +0x00
    float* values; // +0xb8
    float FUN_001d4ea0(int index);
};
// matches/0x001d4ef0.cpp (stub Thing_1d4ef0), size 0x98
struct Thing_1d4ef0 {
    char pad[0x94]; // +0x00
    int state; // +0x94
    int FUN_001d4ef0();
};
// matches/0x001d4f30.cpp (stub C_1d4f30), size 0x9c
struct C_1d4f30 {
    char pad[0x98]; // +0x00
    int value; // +0x98
    int FUN_001d4f30();
};
// matches/0x001d4fc0.cpp (stub C_1d4fc0), size 0x94
struct C_1d4fc0 {
    char pad[0x90]; // +0x00
    unsigned int value; // +0x90
    hulk_uintptr FUN_001d4fc0();
};
// matches/0x001d6290.cpp (stub Target_1d6290), size 0xfa
struct Target_1d6290 {
    char pad[0xf9]; // +0x00
    unsigned char value; // +0xf9
    void FUN_001d6290(unsigned char x);
};
// matches/0x001d62b0.cpp (stub C_1d62b0), size 0x101
struct C_1d62b0 {
    char pad[0x100]; // +0x00
    unsigned char value; // +0x100
    void FUN_001d62b0(unsigned char x);
};
// matches/0x001d62c0.cpp (stub Obj_1d62c0), size 0x101
struct Obj_1d62c0 {
    char pad[0x100]; // +0x00
    unsigned char value; // +0x100
    unsigned char FUN_001d62c0();
};
// matches/0x001d63b0.cpp (stub C_1d63b0), size 0x114
struct C_1d63b0 {
    char pad[0x108]; // +0x00
    int value; // +0x108
    char gap[4]; // +0x10c
    char flag; // +0x110
    void FUN_001d63b0(int x);
};
// matches/0x001d6490.cpp (stub C_1d6490), size 0x250
struct C_1d6490 {
    char pad[0x24c]; // +0x00
    int value; // +0x24c
    hulk_intptr FUN_001d6490();
};
// matches/0x001d6650.cpp (stub Object), size 0x1ec
struct Object_1d6650 {
    char pad[0x1e8]; // +0x00
    int value; // +0x1e8
    void FUN_001d6650(hulk_intptr);
};
// matches/0x001d6660.cpp (stub C_1d6660), size 0x1ec
struct C_1d6660 {
    char pad[0x1e8]; // +0x00
    unsigned value; // +0x1e8
    hulk_uintptr FUN_001d6660();
};
// matches/0x001d69a0.cpp (stub Target_1d69a0), size 0x154
struct Target_1d69a0 {
    char pad[0x150]; // +0x00
    int value; // +0x150
    int FUN_001d69a0();
};
// matches/0x001d69b0.cpp (stub C_1d69b0), size 0x1d1
struct C_1d69b0 {
    char pad[0x1d0]; // +0x00
    unsigned char value; // +0x1d0
    unsigned char FUN_001d69b0();
};
// matches/0x001d69c0.cpp (stub A_1d69c0), size 0x1d0
struct A_1d69c0 {
    char pad[0x1d0]; // +0x00
    void FUN_001d69c0(unsigned char x);
};
// matches/0x001d69d0.cpp (stub Obj_1d69d0), size 0x1d8
struct Obj_1d69d0 {
    char pad[0x1d4]; // +0x00
    int mValue; // +0x1d4
    int FUN_001d69d0();
};
// matches/0x001d69e0.cpp (stub A_1d69e0), size 0x1d8
struct A_1d69e0 {
    char pad[0x1d4]; // +0x00
    int x; // +0x1d4
    void FUN_001d69e0(int a);
};
// matches/0x001d6a90.cpp (stub Target_1d6a90), size 0x1e1
struct Target_1d6a90 {
    char pad[0x1e0]; // +0x00
    unsigned char value; // +0x1e0
    unsigned char FUN_001d6a90();
};
// matches/0x001d6aa0.cpp (stub Target_1d6aa0), size 0x1e0
struct Target_1d6aa0 {
    char pad[0x1e0]; // +0x00
    void FUN_001d6aa0(unsigned char value);
};
// matches/0x001d6ac0.cpp (stub Target_1d6ac0), size 0x112
struct Target_1d6ac0 {
    char pad[0x111]; // +0x00
    unsigned char value; // +0x111
    void FUN_001d6ac0(unsigned char x);
};
// matches/0x001d6ad0.cpp (stub Target_1d6ad0), size 0x188
struct Target_1d6ad0 {
    char pad[0x17c]; // +0x00
    int a, b, c; // +0x17c
    void FUN_001d6ad0(int* p);
};
// matches/0x001d6b30.cpp (stub Thing_1d6b30), size 0x17c
struct Thing_1d6b30 {
    char pad[0x17c]; // +0x00
    int* FUN_001d6b30();
};
// matches/0x001d6c60.cpp (stub C_1d6c60), size 0x254
struct C_1d6c60 {
    char pad[0x250]; // +0x00
    int value; // +0x250
    void FUN_001d6c60(int x);
};
// matches/0x001d6c70.cpp (stub C_1d6c70), size 0x258
struct C_1d6c70 {
    char pad[0x254]; // +0x00
    int value; // +0x254
    int FUN_001d6c70();
};
// matches/0x001d6c80.cpp (stub C_1d6c80), size 0x258
struct C_1d6c80 {
    char pad[0x254]; // +0x00
    int value; // +0x254
    void FUN_001d6c80(int x);
};
// matches/0x001d6ca0.cpp (stub A_1d6ca0), size 0x25c
struct A_1d6ca0 {
    char pad[0x258]; // +0x00
    int field; // +0x258
    void FUN_001d6ca0(int value);
};
// matches/0x001d6cc0.cpp (stub C_1d6cc0), size 0x274
struct C_1d6cc0 {
    char pad[0x270]; // +0x00
    int value; // +0x270
    void FUN_001d6cc0(int x);
};
// matches/0x001d72e0.cpp (stub C_1d72e0), size 0xa4 (0xa8)
struct C_1d72e0 {
    char pad[0xa0]; // +0x00
    void* p; // +0xa0
    hulk_intptr FUN_001d72e0();
};
// matches/0x001d7450.cpp (stub Self_1d7450), size 0x1
struct Self_1d7450 {
    int FUN_001d73f0();
    bool FUN_001d7450();
};
// matches/0x001dc0b0.cpp (stub CGrabAction), size 0x1e824
struct CGrabAction_1dc0b0 {
    hulk_intptr FUN_001dc0b0(int index);
    char pad[0x1e820]; // +0x00
    int mCount; // +0x1e820
};
// matches/0x001dc0d0.cpp (stub Obj_1dc0d0), size 0x14620
struct Obj_1dc0d0 {
    char pad[0x620]; // +0x00
    int vals[0x800][10]; // +0x620
    hulk_intptr FUN_001dc0d0(hulk_intptr);
};
// matches/0x001dc1f0.cpp (stub Obj_1dc1f0), size 0x62c
struct Obj_1dc1f0 {
    char pad[0x62a]; // +0x00
    short values[1]; // +0x62a
    bool FUN_001dc1f0(void* param);
};
// matches/0x001e11d0.cpp (stub Obj_1e11d0), size 0x1ed68
struct Obj_1e11d0 {
    char pad[0x1ed68]; // +0x00
    void Dec();
    void Df();
    void FUN_001e11d0();
};
// matches/0x001e3200.cpp (stub A_1e3200), size 0x8
struct A_1e3200 {
    unsigned int pad[2]; // +0x00
    unsigned int FUN_001e3200(hulk_uintptr, unsigned int, unsigned int);
};
// matches/0x001e8710.cpp (stub Obj_1e8710), size 0xaf0 (0xaf8)
struct Obj_1e8710 {
    char pad[0xaec]; // +0x00
    void* member; // +0xaec (+0xaf0)
    bool FUN_001e8710();
};
// matches/0x001e8a50.cpp (stub X), size 0x1
struct X_1e8a50 {
    void FUN_001e8a50(int);
};
// matches/0x001e8d00.cpp (stub Thing), size 0x10 (0x18)
struct Thing_1e8d00 {
    char pad[12]; // +0x00
    void* value; // +0x0c (+0x10)
    void FUN_001e8d00(unsigned int);
};
// equivalent/0x001e8d40.cpp (stub Clip), size 0x14
struct Clip_1e8d40 {
    int active; // +0x00
    int reserved; // +0x04
    unsigned int size; // +0x08
    int reserved2; // +0x0c
    unsigned int kind; // +0x10
    void FUN_001e8d40();
};
// matches/0x001e9a90.cpp (stub ThisWrap_001e9a90), size 0x1
struct ThisWrap_001e9a90 {
    hulk_intptr GetThing(int);
    void FUN_001e9a90(hulk_intptr a, unsigned int b);
};
// matches/0x001e9b00.cpp (stub Obj), size 0x518 (0x520)
struct Obj_1e9b00 {
    char pad[0x514]; // +0x00
    void* value; // +0x514 (+0x518)
    void FUN_001e9b00(hulk_intptr);
};
// matches/0x001ea010.cpp (stub X), size 0x1
struct X_1ea010 {
    int consume(__int64*);
    int FUN_001ea010(hulk_intptr);
};
// matches/0x001eb060.cpp (stub Manager_1eb060), size 0x524
struct Manager_1eb060 {
    char pad[0x514]; // +0x00
    int mainMix; // +0x514
    char pad518[8]; // +0x518
    unsigned char loaded; // +0x520
    void FUN_001eab10(const char *);
    int FUN_001e9960(const char *);
    void FUN_001e9a90(const char *, int);
    void FUN_001eb060(const char *first, const char *second);
};
// equivalent/0x001eb220.cpp (stub State_1eb220), size 0x1c (0x28)
struct State_1eb220 {
    void* resource; // +0x00
    void* owner; // +0x04 (+0x08): the game (a CGame*: 0x00088020 passes it; decls/managers.h HulkSoundRealTimeManager)
    unsigned char mode; // +0x08 (+0x10)
    unsigned char active; // +0x09 (+0x11)
    char padding[2]; // +0x0a (+0x12)
    float first; // +0x0c (+0x14)
    float second; // +0x10 (+0x18)
    float third; // +0x14 (+0x1c)
    unsigned int count; // +0x18 (+0x20)
    State_1eb220* FUN_001eb220(hulk_uintptr ownerValue, hulk_uintptr unused, unsigned char modeValue);
};
// matches/0x001eb2a0.cpp (stub Thing_1eb2a0), size 0x9
struct Thing_1eb2a0 {
    char pad[8]; // +0x00
    unsigned char enabled; // +0x08
    void FUN_001eb2a0(int a, int b);
};
// matches/0x001eba20.cpp (stub CHapticTrack), size 0x14
struct CHapticTrack_1eba20 {
    char pad[0x10]; // +0x00
    float value; // +0x10
    float FUN_001eba20();
};
// matches/0x001eba70.cpp (stub CJumpTrack), size 0x18
struct CJumpTrack_1eba70 {
    char pad[0x14]; // +0x00
    float value; // +0x14
    float FUN_001eba70();
};
// matches/0x001ebba0.cpp (stub C_1ebba0), size 0x8
struct C_1ebba0 {
    C_1ebba0* FUN_001ebba0(hulk_intptr x, hulk_intptr y);
    int a; // +0x00
    int b; // +0x04
};
// matches/0x001ebd00.cpp (stub Owner_1ebd00), size 0x1
struct Owner_1ebd00 {
    void FUN_001ebd00(const char*, const char*);
};
// equivalent/0x001ebea0.cpp (stub Crusher_1ebea0), size 0x1
struct Crusher_1ebea0 {
    void FUN_001ebd80(int arg2, const char *name, float strength, int flag);
    void FUN_001ebea0(const char *suffix, hulk_intptr arg2);
};
// equivalent/0x001ecd00.cpp (stub Crusher_1ecd00), size 0x1
struct Crusher_1ecd00 {
    void FUN_001ec980(int a, const char *name);
    void FUN_001ecd00(const char *name, hulk_intptr a);
};
// matches/0x001eef00.cpp (stub Obj_1eef00), size 0x10 (0x18)
struct Obj_1eef00 {
    char pad[12]; // +0x00
    char* data; // +0x0c (+0x10)
    void FUN_001eef00();
};
// equivalent/0x001ef2a0.cpp (stub Spawner_1ef2a0), size 0x18
struct Spawner_1ef2a0 {
    char pad0[0x14]; // +0x00
    int count; // +0x14
    void FUN_001ef2a0(int a, int b);
};
// matches/0x001ef320.cpp (stub Obj_1ef320), size 0x44
struct Obj_1ef320 {
    char pad[0x40]; // +0x00
    int field; // +0x40
    void Init();
    Obj_1ef320* FUN_001ef320();
};
// matches/0x001ef350.cpp (stub C_1ef350), size 0x40
struct C_1ef350 {
    char pad[0x40]; // +0x00
    void FUN_001ef350();
};
// matches/0x001ef3c0.cpp (stub Owner_1ef3c0), size 0x44
struct Owner_1ef3c0 {
    char pad[0x40]; // +0x00
    int count; // +0x40
    void FUN_001ef3c0(void*, void*);
};
// matches/0x001f3370.cpp (stub Obj_1f3370), size 0x8
struct Obj_1f3370 {
    int pad; // +0x00
    volatile int member; // +0x04
    int FUN_001f3370(hulk_intptr arg);
};
// matches/0x001f33b0.cpp (stub Obj_1f33b0), size 0x20
struct Obj_1f33b0 {
    char pad0[4]; // +0x00
    unsigned int mArg; // +0x04
    char pad8[16]; // +0x08
    unsigned int mResult; // +0x18
    unsigned char mFlag; // +0x1c
    void FUN_001f33b0(unsigned int);
};
// matches/0x001f3400.cpp (stub Obj_1f3400), size 0x1c
struct Obj_1f3400 {
    char pad0[4]; // +0x00
    unsigned int a; // +0x04
    char pad8[16]; // +0x08
    unsigned int b; // +0x18
    void FUN_001f3400(unsigned int);
};
// matches/0x001f34a0.cpp (stub Owner_1f34a0), size 0x8
struct Owner_1f34a0 {
    char pad[4]; // +0x00
    int value; // +0x04
    void FUN_001f34a0(hulk_intptr a, int b);
};
// matches/0x001f36e0.cpp (stub Object), size 0x1c
struct Object_1f36e0 {
    char pad[8]; // +0x00
    int field8; // +0x08
    int fieldC; // +0x0c
    int field10; // +0x10
    int field14; // +0x14
    unsigned char field18; // +0x18
    void FUN_001f36e0();
};
// matches/0x001f3950.cpp (stub Obj_1f3950), size 0x330 (0x338)
struct Obj_1f3950 {
    char pad0[0xc0]; // +0x00
    hulk_intptr mPtr; // +0xc0
    char pad1[0x268]; // +0xc4 (+0xc8)
    int mBusy; // +0x32c (+0x330)
    void FUN_001f3950(float value);
};
// matches/0x001f3990.cpp (stub Thing_1f3990), size 0x330 (0x338)
struct Thing_1f3990 {
    char pad0[0x8c]; // +0x00
    hulk_intptr mA; // +0x8c (+0x90)
    char pad1[0x32c - 0x90]; // +0x90 (+0x98)
    int mB; // +0x32c (+0x334)
    void FUN_001f3990(float);
};
// matches/0x001f39d0.cpp (stub Obj_1f39d0), size 0x330 (0x338)
struct Obj_1f39d0 {
    char p0[8]; // +0x00
    int* items[1]; // +0x08
    char p1[0x88 - 0x0c]; // +0x0c (+0x10)
    int count; // +0x88 (+0x8c)
    int at8c; // +0x8c (+0x90)
    char p2[0xc0 - 0x90]; // +0x90 (+0x94)
    int skip; // +0xc0 (+0xc4)
    char p3[0x32c - 0xc4]; // +0xc4 (+0xc8)
    int flag; // +0x32c (+0x330)
    void FUN_001f39d0(float);
};
// matches/0x001f3e50.cpp (stub Obj), size 0x1
struct Obj_1f3e50 {
    void FUN_001f3e50(int, hulk_intptr, int, hulk_intptr, float, int);
    void other(int, int, int, int, int, int);
};
// matches/0x001f3e90.cpp (stub Obj), size 0x1
struct Obj_1f3e90 {
    void fn(int, int, int, int, int, int);
    void FUN_001f3e90(int, hulk_intptr, int, float, int);
};
// equivalent/0x001f4940.cpp (stub Thing), size 0x8 (0x10)
struct Thing_1f4940 {
    void *unused; // +0x00
    void *handle; // +0x04 (+0x08)
    void FUN_001f4940();
};
// matches/0x001f67c0.cpp (stub Obj_1f67c0), size 0x20
struct Obj_1f67c0 {
    void FUN_001f67c0();
    void Step(float f);
    int pad0; // +0x00
    int mA; // +0x04
    char pad[0x10]; // +0x08
    int mB; // +0x18
    char mFlag; // +0x1c
};
// matches/0x001f6ff0.cpp (stub Weather_1f6ff0), size 0x58
struct Weather_1f6ff0 {
    char pad[0x4c]; // +0x00
    char rainOn; // +0x4c
    char dustOn; // +0x4d
    int hRain; // +0x50
    int hDust; // +0x54
    char FUN_001f6ff0(char on);
};
// matches/0x001f7080.cpp (stub Weather_1f7080), size 0x58
struct Weather_1f7080 {
    char pad[0x4c]; // +0x00
    char rainOn; // +0x4c
    char dustOn; // +0x4d
    int hRain; // +0x50
    int hDust; // +0x54
    char FUN_001f7080(char on);
};
// matches/0x001f7110.cpp (stub Obj_1f7110), size 0x1
struct Obj_1f7110 {
    char FUN_001f7110(int arg);
};
// equivalent/0x001f84d0.cpp (stub Key), size 0xc
struct Key_1f84d0 {
    unsigned int low; // +0x00
    unsigned int high; // +0x04
    signed char category; // +0x08
    signed char subcategory; // +0x09
    bool FUN_001f84d0(const Key_1f84d0 *other);
};
// matches/0x001f8710.cpp (stub Target_1f8710), size 0x440
struct Target_1f8710 {
    char pad[0x43c]; // +0x00
    int value; // +0x43c
    void FUN_001f8710(int);
};
// matches/0x001f8720.cpp (stub C_1f8720), size 0x440
struct C_1f8720 {
    char pad[0x440]; // +0x00
    void FUN_001f8720(int i, unsigned char v);
};
// matches/0x001f8740.cpp (stub Thing_1f8740), size 0x446
struct Thing_1f8740 {
    char pad[0x440]; // +0x00
    unsigned char bytes[6]; // +0x440
    unsigned char FUN_001f8740(hulk_intptr index);
};
// matches/0x001f8790.cpp (stub C_1f8790), size 0x450
struct C_1f8790 {
    char pad[0x44c]; // +0x00
    int value; // +0x44c
    C_1f8790* get_obj();
    void FUN_001f8790(int);
};
// matches/0x001f87c0.cpp (stub X_1f87c0), size 0x450
struct X_1f87c0 {
    char pad[0x450]; // +0x00
    void FUN_001f87c0(unsigned char x);
};
// matches/0x001f87d0.cpp (stub C_1f87d0), size 0x458
struct C_1f87d0 {
    char pad[0x454]; // +0x00
    int value; // +0x454
    void FUN_001f87d0(int x);
};
// matches/0x001f8940.cpp (stub Obj_1f8940), size 0xa
struct Obj_1f8940 {
    char pad[8]; // +0x00
    unsigned char a; // +0x08
    unsigned char b; // +0x09
    Obj_1f8940* Copy(Obj_1f8940*);
    Obj_1f8940* FUN_001f8940(Obj_1f8940* other);
};
// matches/0x001f8f40.cpp (stub Target_1f8f40), size 0x8
struct Target_1f8f40 {
    char pad[8]; // +0x00
    void FUN_001f8f40(const char*);
};
// matches/0x001f9130.cpp (stub Obj_1f9130), size 0x28
struct Obj_1f9130 {
    char pad[4]; // +0x00
    unsigned int a, b, c, d, e, f, g, h; // +0x04
    unsigned char flag; // +0x24
    char Check(unsigned int);
    char FUN_001f9130(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned char);
};
// matches/0x001f9370.cpp (stub C_1f9370), size 0x1
struct C_1f9370 {
    void FUN_001f9370(int param_2, char param_3);
};
// matches/0x001f93e0.cpp (stub Obj_1f93e0), size 0x6e4
struct Obj_1f93e0 {
    char pad[0x6e0]; // +0x00
    int count; // +0x6e0
    int FUN_001f93e0(hulk_intptr, int, int, int, int, int, int, int, int, int);
};
// matches/0x001fac40.cpp (stub C_1fac40), size 0x10
struct C_1fac40 {
    char pad[8]; // +0x00
    int count; // +0x08
    int items[1]; // +0x0c
    void FUN_001fac40(hulk_intptr x);
};
// matches/0x001fac60.cpp (stub X_1fac60), size 0x2c
struct X_1fac60 {
    int pad[2]; // +0x00
    int a; // +0x08
    int b; // +0x0c
    int c; // +0x10
    int d; // +0x14
    int e; // +0x18
    int f; // +0x1c
    int g; // +0x20
    int h; // +0x24
    int i; // +0x28
    void FUN_001fac60();
};
// matches/0x001fb940.cpp (stub Obj_1fb940), size 0xd0
struct Obj_1fb940 {
    char pad[0xcd]; // +0x00
    unsigned char a; // +0xcd
    char gap; // +0xce
    unsigned char b; // +0xcf
    void FUN_001fb940();
};
// matches/0x001fb990.cpp (stub Target_1fb990), size 0x1c
struct Target_1fb990 {
    char pad[0x10]; // +0x00
    int a, b, c; // +0x10
    void FUN_001fb990(const int* p);
};
// matches/0x001fb9b0.cpp (stub C_1fb9b0), size 0x20
struct C_1fb9b0 {
    char pad[0x1c]; // +0x00
    int value; // +0x1c
    void FUN_001fb9b0(int x);
};
// matches/0x001fd180.cpp (stub C_1fd180), size 0x234 (0x258)
struct C_1fd180 {
    char pad0[0x214]; // +0x00
    int* a[6]; // +0x214 (+0x218)
    int* slots; // +0x22c (+0x248)
    int last; // +0x230 (+0x250)
    void FUN_001fd180(int);
};
// matches/0x001fd360.cpp (stub X_1fd360), size 0x230 (0x238)
struct X_1fd360 {
    char pad[0x22c]; // +0x00
    int* items; // +0x22c (+0x230)
    int FUN_001fd360(int value);
};
// matches/0x00201bc0.cpp (stub C_201bc0), size 0x1c
struct C_201bc0 {
    char pad[0x18]; // +0x00
    int m18; // +0x18
    void FUN_00201bc0(int x);
};
// matches/0x00201be0.cpp (stub X_201be0), size 0x1
struct X_201be0 {
    void FUN_00201be0(hulk_intptr value);
};
// matches/0x002036e0.cpp (stub Obj_2036e0), size 0xafc
struct Obj_2036e0 {
    char pad[0xaf8]; // +0x00
    int mAf8; // +0xaf8
    void FUN_002036e0(int x);
};
// matches/0x002036f0.cpp (stub Obj_2036f0), size 0x5a4
struct Obj_2036f0 {
    char pad[0x5a0]; // +0x00
    int value; // +0x5a0
    int FUN_002036f0();
};
// matches/0x00203780.cpp (stub Vec_203780), size 0xa54 (0xa58)
struct Vec_203780 {
    char pad[0xa4c]; // +0x00
    int mCount; // +0xa4c
    void* mItems[1]; // +0xa50
    void FUN_00203780(void* item);
};
// matches/0x002037a0.cpp (stub Obj), size 0x6a4
struct Obj_2037a0 {
    char pad[0x5a4]; // +0x00
    char flags[256]; // +0x5a4
    int FUN_002037a0();
};
// matches/0x00203860.cpp (stub Thing_203860), size 0xaa4
struct Thing_203860 {
    char pad[0xaa4]; // +0x00
    void* FUN_00203860();
};
// matches/0x00203870.cpp (stub Target_203870), size 0xaa4
struct Target_203870 {
    char pad[0xaa4]; // +0x00
    void FUN_00203870(char* p);
};
// equivalent/0x00203890.cpp (stub Object), size 0x1
struct Object_203890 {
    void FUN_00203870(const char* name);
    void FUN_00203890(int index);
};
// matches/0x002039a0.cpp (stub Obj_2039a0), size 0x1
struct Obj_2039a0 {
    void Set(int);
    void FUN_002039a0(int, int);
};
// matches/0x00203a10.cpp (stub C_203a10), size 0xac4
struct C_203a10 {
    char pad[0xaa4]; // +0x00
    char name[0x20]; // +0xaa4
    void Apply(int);
    void FUN_00203a10();
};
// matches/0x00203d60.cpp (stub C_203d60), size 0x578
struct C_203d60 {
    char pad[0x578]; // +0x00
    hulk_intptr FUN_00203d60(int index);
};
// matches/0x00203d70.cpp (stub Target_203d70), size 0x48
struct Target_203d70 {
    char pad[0x44]; // +0x00
    int value; // +0x44
    hulk_intptr FUN_00203d70();
};
// matches/0x00203db0.cpp (stub Obj_203db0), size 0x578
struct Obj_203db0 {
    char pad[0x530]; // +0x00
    int values[2]; // +0x530
    char pad2[0x38]; // +0x538
    int keys[2]; // +0x570
    hulk_intptr FUN_00203db0(hulk_intptr key);
};
// matches/0x00204060.cpp (stub Owner_204060), size 0x598 (0x5a0)
struct Owner_204060 {
    char pad[0x58c]; // +0x00
    short* items; // +0x58c (+0x590)
    int gap; // +0x590 (+0x598)
    int count; // +0x594 (+0x59c)
    short* FUN_00204060(int a, int b);
};
// matches/0x00204470.cpp (stub C_204470), size 0x9a4
struct C_204470 {
    char pad[0x5a4]; // +0x00
    char a[0x400]; // +0x5a4
    bool FUN_00204470(hulk_intptr i);
};
// matches/0x00204760.cpp (stub Thing_204760), size 0x578
struct Thing_204760 {
    char pad[0x570]; // +0x00
    int slots[2]; // +0x570
    void FUN_00204760(int value);
};
// matches/0x002062d0.cpp (stub Owner_2062d0), size 0x58c
struct Owner_2062d0 {
    char pad[0x588]; // +0x00
    int param; // +0x588
    void FUN_002062d0(hulk_intptr);
};
// matches/0x00207130.cpp (stub Obj_207130), size 0x1
struct Obj_207130 {
    int GetCount(int);
    void DoThing(int);
    bool FUN_00207130();
};
// matches/0x00207150.cpp (stub C_207150), size 0x578
struct C_207150 {
    char pad[0x570]; // +0x00
    int a[2]; // +0x570
    bool Check(int);
    int Get(int);
    void Do(int);
    void Finish(int);
    bool FUN_00207150();
};
// equivalent/0x00207850.cpp (stub LoadInventory_207850), size 0xaf0
struct LoadInventory_207850 {
    char pad0[0x590]; // +0x00
    int pending; // +0x590
    char pad594[0xaec - 0x594]; // +0x594
    int blocked; // +0xaec
    int FUN_002037a0();
    int FUN_00204c10(int mode);
    void FUN_00207080(int n);
    void FUN_00207580(int n, int flag);
    bool FUN_00207850(int flag);
};
// matches/0x002078d0.cpp (stub Obj_2078d0), size 0xaf0 (0xaf8)
struct Obj_2078d0 {
    char pad[0xaec]; // +0x00
    void* field; // +0xaec (+0xaf0)
    bool FUN_00207410();
    bool FUN_002078d0();
};
// equivalent/0x002089f0.cpp (stub Pump_2089f0), size 0xb00
struct Pump_2089f0 {
    void FUN_002089f0();
    void FUN_00207410();
    void FUN_00204e40();
    char FUN_00207850(char flag);
    char FUN_00208920();
    char pad0[0x9a8]; // +0x00
    int busy; // +0x9a8
    char pad1[0xaf3 - 0x9ac]; // +0x9ac
    char pending; // +0xaf3
    char dirty; // +0xaf4
    char locked; // +0xaf5
    char pad2[0xafc - 0xaf6]; // +0xaf6
    int tick; // +0xafc
};
// matches/0x00208ac0.cpp (stub A_208ac0), size 0x6
struct A_208ac0 {
    unsigned short a; // +0x00
    unsigned short b; // +0x02
    unsigned char c; // +0x04
    unsigned char d; // +0x05
    void FUN_00208ac0(unsigned short x, unsigned short y);
};
// matches/0x00208b40.cpp (stub A_208b40), size 0x5
struct A_208b40 {
    char pad[4]; // +0x00
    signed char count; // +0x04
    void FUN_00208b40(unsigned short x);
};
// matches/0x00208b60.cpp (stub Obj_208b60), size 0x30
struct Obj_208b60 {
    char pad[5]; // +0x00
    signed char count; // +0x05
    char gap[0x28]; // +0x06
    unsigned short values[1]; // +0x2e
    void FUN_00208b60(unsigned short);
};
// matches/0x00208b80.cpp (stub X_208b80), size 0x2
struct X_208b80 {
    short data[1]; // +0x00
    int FUN_00208b80(int i);
};
// matches/0x00208b90.cpp (stub C_208b90), size 0x30
struct C_208b90 {
    char pad[0x2e]; // +0x00
    short items[1]; // +0x2e
    int FUN_00208b90(int index);
};
// matches/0x00221e60.cpp (stub Obj_221e60), size 0x54
struct Obj_221e60 {
    char pad[0x50]; // +0x00
    int state; // +0x50
    void FUN_00221e60(hulk_uintptr);
};
// matches/0x00221f70.cpp (stub Obj_221f70), size 0x54
struct Obj_221f70 {
    char pad[0x50]; // +0x00
    int state; // +0x50
    void FUN_00221f70(hulk_intptr, hulk_intptr);
    void callee2(int, int);
};
// matches/0x00222bf0.cpp (stub A_222bf0), size 0x6c
struct A_222bf0 {
    char pad[0x68]; // +0x00
    unsigned count; // +0x68
    int FUN_00222bf0(hulk_intptr key);
};
// matches/0x00222d70.cpp (stub Obj_222d70), size 0x16c
struct Obj_222d70 {
    char pad[0x68]; // +0x00
    unsigned count; // +0x68
    char rest[0x100]; // +0x6c
    bool FUN_00222d70(hulk_intptr key, int value);
};
// matches/0x00222e20.cpp (stub C_222e20), size 0x70
struct C_222e20 {
    char pad[0x68]; // +0x00
    unsigned count; // +0x68
    unsigned char rest[1]; // +0x6c
    hulk_uintptr FUN_00222e20(unsigned i);
};
// equivalent/0x00225cf0.cpp (stub Object), size 0x240
struct Object_225cf0 {
    char pad[0x224]; // +0x00
    unsigned char flag; // +0x224
    char pad2[7]; // +0x225
    int value1; // +0x22c
    int value2; // +0x230
    char pad3[4]; // +0x234
    float result1; // +0x238
    float result2; // +0x23c
    void FUN_00225cf0(int input);
};
// matches/0x00228700.cpp (stub C_228700), size 0x8b0
struct C_228700 {
    char pad[0x8ac]; // +0x00
    float value; // +0x8ac
    void FUN_00228700(hulk_intptr x);
};
// matches/0x002287a0.cpp (stub C_2287a0), size 0x854
struct C_2287a0 {
    char pad[0x854]; // +0x00
    float FUN_002287a0(int i);
};
// matches/0x0022a9e0.cpp (stub Thing_22a9e0), size 0x28
struct Thing_22a9e0 {
    char pad[0x20]; // +0x00
    int a; // +0x20
    int b; // +0x24
    Thing_22a9e0* FUN_0022a9e0(Thing_22a9e0*);
    Thing_22a9e0* FUN_00222460(Thing_22a9e0*);
};
// equivalent/0x0022aba0.cpp (stub Random_22aba0), size 0x8
struct Random_22aba0 {
    void FUN_0022aba0(unsigned int seed);
    unsigned int a; // +0x00
    unsigned int b; // +0x04
};
// matches/0x0022b120.cpp (stub Vec4), size 0x10
struct Vec4_22b120 {
    float x, y, z, w; // +0x00
    void FUN_0022b120();
};
// matches/0x0022b170.cpp (stub Vec4_22b170), size 0x10
struct Vec4_22b170 {
    float x, y, z, w; // +0x00
    void FUN_0022b170(float angle, float* v);
};
// matches/0x0022b1c0.cpp (stub X_22b1c0), size 0x10
struct X_22b1c0 {
    int a; // +0x00
    float b; // +0x04
    int c; // +0x08
    float d; // +0x0c
    void FUN_0022b1c0(float);
};
// equivalent/0x0022b220.cpp (stub Quaternion_22b220), size 0x10
struct Quaternion_22b220 {
    float x,y,z,w; // +0x00
    void FUN_0022b220(float a, float b, float c);
};
// equivalent/0x0022b370.cpp (stub Quat_22b370), size 0x10
struct Quat_22b370 {
    float x, y, z, w; // +0x00
    void FUN_0022b370(const float *m);
};
// matches/0x0022b560.cpp (stub Vec4_22b560), size 0x10
struct Vec4_22b560 {
    float x, y, z, w; // +0x00
    Vec4_22b560* FUN_0022b560(Vec4_22b560*);
};
// equivalent/0x0022b750.cpp (stub Quaternion_22b750), size 0x10
struct Quaternion_22b750 {
    float x,y,z,w; // +0x00
    void FUN_0022b750(const Quaternion_22b750* a, const Quaternion_22b750* b, float t);
};
// matches/0x0022b9f0.cpp (stub C_22b9f0), size 0x3c
struct C_22b9f0 {
    char pad[0x30]; // +0x00
    int a; // +0x30
    int b; // +0x34
    int c; // +0x38
    void FUN_0022b9f0();
};
// matches/0x0022ba30.cpp (stub Matrix), size 0x2c
struct Matrix_22ba30 {
    unsigned int m[11]; // +0x00
    void FUN_0022ba30(float);
};
// matches/0x0022ba70.cpp (stub Mat), size 0x2c
struct Mat_22ba70 {
    float a[11]; // +0x00
    void FUN_0022ba70(float x);
};
// matches/0x0022bab0.cpp (stub Mat_22bab0), size 0x2c
struct Mat_22bab0 {
    float v[11]; // +0x00
    void FUN_0022bab0(float);
};
// equivalent/0x0022bc20.cpp (stub Matrix), size 0x30
struct Matrix_22bc20 {
    float m[3][4]; // +0x00
    void FUN_0022bc20(float x, float y, float z);
};
// matches/0x0022bcd0.cpp (stub Matrix), size 0x30
struct Matrix_22bcd0 {
    float m[3][4]; // +0x00
    void FUN_0022bcd0(float x, float y, float z);
};
// equivalent/0x0022bda0.cpp (stub Matrix), size 0x30
struct Matrix_22bda0 {
    float m[3][4]; // +0x00
    void FUN_0022bda0(float a, float b, float c);
};
// matches/0x0022be40.cpp (stub Target_22be40), size 0x3c
struct Target_22be40 {
    char pad[0x30]; // +0x00
    int a, b, c; // +0x30
    void FUN_0022be40(const int* p);
};
// matches/0x0022be60.cpp (stub C_22be60), size 0x2c
struct C_22be60 {
    int a[11]; // +0x00
    void FUN_0022be60(int p, int q, int r);
};
// matches/0x0022c0b0.cpp (stub M_22c0b0), size 0x40
struct M_22c0b0 {
    float m[4][4]; // +0x00
    void FUN_0022c0b0();
};
// equivalent/0x0022c120.cpp (stub Matrix), size 0x40
struct Matrix_22c120 {
    float m[16]; // +0x00
    void FUN_0022c0b0();
    void FUN_0022c120();
};
// matches/0x0022c2b0.cpp (stub Mat_22c2b0), size 0x40
struct Mat_22c2b0 {
    float x0; // +0x00
    float x1; // +0x04
    float x2; // +0x08
    float x3; // +0x0c
    float x4; // +0x10
    float x5; // +0x14
    float x6; // +0x18
    float x7; // +0x1c
    float x8; // +0x20
    float x9; // +0x24
    float x10; // +0x28
    float x11; // +0x2c
    float x12; // +0x30
    float x13; // +0x34
    float x14; // +0x38
    float x15; // +0x3c
    void FUN_0022c2b0(float*, float*);
};
// matches/0x0022c3b0.cpp (stub M_22c3b0), size 0x30
struct M_22c3b0 {
    float a[12]; // +0x00
    void FUN_0022c3b0(float* p, float* out);
};
// equivalent/0x0022ca90.cpp (stub Matrix), size 0x40
struct Matrix_22ca90 {
    float m[4][4]; // +0x00
    void FUN_0022ca90(const Matrix_22ca90* a, const Matrix_22ca90* b);
};
// equivalent/0x0022cc10.cpp (stub Matrix), size 0x40
struct Matrix_22cc10 {
    float m[4][4]; // +0x00
    void FUN_0022cc10(const Matrix_22cc10* a, const Matrix_22cc10* b);
};
// equivalent/0x0022cdb0.cpp (stub Matrix), size 0x40
struct Matrix_22cdb0 {
    float m[16]; // +0x00
    void FUN_0022c120();
    void FUN_0022cdb0();
};
// matches/0x0022d1c0.cpp (stub Vec3_22d1c0), size 0xc
struct Vec3_22d1c0 {
    float x, y, z; // +0x00
    void FUN_0022d1c0(const Vec3_22d1c0* p);
};
// matches/0x0022d210.cpp (stub Obj_22d210), size 0xc
struct Obj_22d210 {
    unsigned int x[3]; // +0x00
    void FUN_0022d210(Obj_22d210*);
};
// matches/0x0022d240.cpp (stub C_22d240), size 0x1
struct C_22d240 {
    void FUN_0022d240(hulk_intptr a, hulk_intptr b);
};
// matches/0x0022d260.cpp (stub Obj_22d260), size 0xc
struct Obj_22d260 {
    unsigned int x[3]; // +0x00
    void FUN_0022d260(Obj_22d260*);
};
// matches/0x0022d290.cpp (stub C_22d290), size 0x1
struct C_22d290 {
    void FUN_0022d290(hulk_intptr a, hulk_intptr b);
};
// matches/0x0022d2b0.cpp (stub V), size 0xc
struct V_22d2b0 {
    float x, y, z; // +0x00
    int FUN_0022d2b0(V_22d2b0* other, float limit);
};
// equivalent/0x0022e080.cpp (stub Plane_22e080), size 0x10
struct Plane_22e080 {
    float nx, ny, nz, w; // +0x00
    bool FUN_0022e080(const float *box);
};
// matches/0x0022e320.cpp (stub Obj_22e320), size 0x1
struct Obj_22e320 {
    void FUN_0022e320(unsigned int);
};
// matches/0x0022ef20.cpp (stub Obj_22ef20), size 0x118
struct Obj_22ef20 {
    unsigned int mCache[67]; // +0x00
    unsigned int mSize, mDiv, mBase; // +0x10c
    char FUN_0022ef20(int index, float value);
};
// equivalent/0x0022fe40.cpp (stub Box_22fe40), size 0x18
struct Box_22fe40 {
    float v[6]; // +0x00
    Box_22fe40* FUN_0022fe40(Box_22fe40* out);
};
// matches/0x002306c0.cpp (stub Obj_2306c0), size 0x10
struct Obj_2306c0 {
    unsigned int a, b, c, d; // +0x00
    void FUN_002306c0(hulk_intptr);
};
// matches/0x00230b60.cpp (stub X_230b60), size 0x18
struct X_230b60 {
    int a; // +0x00
    int b; // +0x04
    int c; // +0x08
    int d; // +0x0c
    unsigned char e; // +0x10
    char pad[3]; // +0x11
    int f; // +0x14
    void FUN_00230b60();
};
// matches/0x00231050.cpp (stub C_231050), size 0x20
struct C_231050 {
    char pad[0x18]; // +0x00
    int a; // +0x18
    int b; // +0x1c
    void FUN_00231050();
};
// matches/0x00231070.cpp (stub X_231070), size 0x1c (0x20)
struct X_231070 {
    unsigned count; // +0x00
    unsigned a; // +0x04
    unsigned b; // +0x08
    char pad[0x18 - 12]; // +0x0c
    unsigned* data; // +0x18
    void FUN_00231070();
};
// matches/0x00231770.cpp (stub Obj_231770), size 0x20 (0x28)
struct Obj_231770 {
    unsigned int count; // +0x00
    unsigned int remaining; // +0x04
    unsigned int found; // +0x08
    unsigned char flag; // +0x0c
    unsigned char pad0[3]; // +0x0d
    unsigned int limit; // +0x10
    unsigned int pad14; // +0x14
    // (x64t8) the hash table's slots (pointers: 0x002310a0 allocates them by sizeof(void*)), its key pairs and the
    // deleted-slot sentinel (0x00231590 / 0x00231180 compare the slot with its address)
    void** keys; // +0x18
    unsigned int* data; // +0x1c
    char sentinel[4]; // +0x20
    void Resize();
    int FUN_00231770(hulk_uintptr key);
};
// matches/0x00231ee0.cpp (stub C_231ee0), size 0x24
struct C_231ee0 {
    char p[4]; // +0x00
    int a; // +0x04
    char q[0x18]; // +0x08
    int b; // +0x20
    unsigned char FUN_00231ee0();
};
// matches/0x00232600.cpp (stub X_232600), size 0x10
struct X_232600 {
    char pad[12]; // +0x00
    unsigned int flags; // +0x0c
    void FUN_00232600(unsigned int mask, bool enabled);
};
// matches/0x00232b80.cpp (stub A_232b80), size 0x1
struct A_232b80 {
    int g(int, hulk_intptr, int, int);
    int FUN_00232b80(hulk_intptr, hulk_intptr, int);
};
// matches/0x00232ed0.cpp (stub Node), size 0x18 (0x20)
struct Node_232ed0 {
    char pad[0x14]; // +0x00
    Node_232ed0* next; // +0x14 (+0x18)
    bool FUN_00232ed0(Node_232ed0*);
};
// matches/0x00232f60.cpp (stub Node), size 0x18 (0x20)
struct Node_232f60 {
    int pad0[4]; // +0x00
    int type; // +0x10
    Node_232f60* next; // +0x14 (+0x18)
    void* FUN_00232f60();
};
// equivalent/0x00232fe0.cpp (stub Node), size 0x24 (0x38)
struct Node_232fe0 {
    char pad0[0x14]; // +0x00
    Node_232fe0* parent; // +0x14 (+0x18)
    char pad18[4]; // +0x18 (+0x20)
    Node_232fe0* boundary; // +0x1c (+0x28)
    Node_232fe0* value; // +0x20 (+0x30)
    Node_232fe0* FUN_00232fe0();
};
// equivalent/0x00233320.cpp (stub Node), size 0x24 (0x30)
struct Node_233320 {
    char pad0[8]; // +0x00
    int key1; // +0x08
    int key2; // +0x0c
    char pad10[12]; // +0x10
    Node_233320 *child; // +0x1c (+0x20)
    Node_233320 *next; // +0x20 (+0x28)
    Node_233320 * FUN_00233320(int key1, int key2);
};
// equivalent/0x00233460.cpp (stub Node), size 0x18 (0x20)
struct Node_233460 {
    char pad[8]; // +0x00
    unsigned low; // +0x08
    unsigned high; // +0x0c
    char pad10[4]; // +0x10
    Node_233460* next; // +0x14 (+0x18)
    bool FUN_00233460(char* output, int capacity);
};
// matches/0x00235950.cpp (stub C_235950), size 0x10
struct C_235950 {
    char pad[12]; // +0x00
    int m; // +0x0c
    char FUN_00235950(int x);
};
// matches/0x00235960.cpp (stub Thing_235960), size 0x10
struct Thing_235960 {
    char pad[0x10]; // +0x00
    char* FUN_00235960();
};
// matches/0x002359a0.cpp (stub X_2359a0), size 0x10
struct X_2359a0 {
    char FUN_002359a0(int a);
    char pad[12]; // +0x00
    int m; // +0x0c
};
// matches/0x002359b0.cpp (stub Obj_2359b0), size 0x10
struct Obj_2359b0 {
    char m[0x10]; // +0x00
    char FUN_002359b0(int v);
};
// matches/0x00236790.cpp (stub Target_236790), size 0x14
struct Target_236790 {
    char pad[0x14]; // +0x00
    int FUN_00236790(int a, int b);
};
// matches/0x00237230.cpp (stub Obj_237230), size 0x10
struct Obj_237230 {
    char pad[12]; // +0x00
    int value; // +0x0c
    char FUN_00237230(int x);
};
// matches/0x00237240.cpp (stub Obj_237240), size 0x10
struct Obj_237240 {
    char FUN_00237240(int v);
    char pad[0x10]; // +0x00
};
// matches/0x00237250.cpp (stub Obj_237250), size 0x18
struct Obj_237250 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    bool FUN_00237250(int v);
};
// matches/0x00237270.cpp (stub C_237270), size 0x24
struct C_237270 {
    char pad[0x24]; // +0x00
    char FUN_00237270(int x);
};
// matches/0x00237280.cpp (stub Obj_237280), size 0x28
struct Obj_237280 {
    char pad[0x28]; // +0x00
    char* FUN_00237280();
};
// matches/0x002381c0.cpp (stub Obj_2381c0), size 0x10
struct Obj_2381c0 {
    char pad[12]; // +0x00
    int mX; // +0x0c
    bool FUN_002381c0(int v);
};
// matches/0x002381d0.cpp (stub A_2381d0), size 0x10
struct A_2381d0 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    bool FUN_002381d0(int v);
};
// equivalent/0x00238910.cpp (stub Object), size 0x10 (0x18)
struct Object_238910 {
    char pad[12]; // +0x00
    char *text; // +0x0c (+0x10)
    bool FUN_00238910(const char *value);
};
// matches/0x00238970.cpp (stub Obj_00238970), size 0x14 (0x18)
struct Obj_00238970 {
    char pad[0x10]; // +0x00
    char* name; // +0x10
    bool FUN_00238970(const char* s);
};
// matches/0x002393a0.cpp (stub Obj_2393a0), size 0x10
struct Obj_2393a0 {
    char pad[0xc]; // +0x00
    int mValue; // +0x0c
    char FUN_002393a0(int v);
};
// matches/0x002393b0.cpp (stub O_2393b0), size 0x14
struct O_2393b0 {
    char FUN_002393b0(int x);
    char pad[0x10]; // +0x00
    int m; // +0x10
};
// matches/0x002393c0.cpp (stub X_2393c0), size 0x18 (0x20)
struct X_2393c0 {
    char pad[0x14]; // +0x00
    int* m; // +0x14 (+0x18)
    int** FUN_002393c0();
};
// matches/0x002393e0.cpp (stub O_2393e0), size 0x20
struct O_2393e0 {
    char pad[0x20]; // +0x00
    bool FUN_002393e0(int v);
};
// matches/0x002393f0.cpp (stub C_2393f0), size 0x24
struct C_2393f0 {
    char pad[0x24]; // +0x00
    char* FUN_002393f0();
};
// matches/0x0023a660.cpp (stub Owner_23a660), size 0x130
struct Owner_23a660 {
    char pad0[0x12c]; // +0x00
    int count; // +0x12c
    int FUN_0023a660(void* arg);
};
// matches/0x0023c8a0.cpp (stub C_23c8a0), size 0xc
struct C_23c8a0 {
    char pad[12]; // +0x00
    void* FUN_0023c8a0();
};
// matches/0x0023d880.cpp (stub Obj), size 0x10 (0x18)
struct Obj_23d880 {
    char pad[12]; // +0x00
    char* text; // +0x0c (+0x10)
    char FUN_0023d880(const char* s);
};
// matches/0x0023f0d0.cpp (stub Obj), size 0x10
struct Obj_23f0d0 {
    char pad[12]; // +0x00
    int value; // +0x0c
    bool FUN_0023f0d0(int x);
};
// matches/0x0023f0e0.cpp (stub Obj_23f0e0), size 0x10
struct Obj_23f0e0 {
    char pad[0x10]; // +0x00
    void* FUN_0023f0e0();
};
// matches/0x0023f690.cpp (stub C_23f690), size 0x4
struct C_23f690 {
    int x; // +0x00
    void FUN_0023f690(hulk_intptr);
};
// matches/0x0023fb10.cpp (stub C_23fb10), size 0xa
struct C_23fb10 {
    char pad[8]; // +0x00
    unsigned short value; // +0x08
    void FUN_0023fb10(unsigned short x);
};
// matches/0x0023fb20.cpp (stub Obj_23fb20), size 0xc (0x10)
struct Obj_23fb20 {
    const char *value; // +0x00
    unsigned short a; // +0x04 (+0x08)
    unsigned short pad; // +0x06 (+0x0a)
    unsigned short b; // +0x08 (+0x0c)
    void FUN_0023fb20(const char *a1, hulk_uintptr a2, hulk_uintptr a3, int a4);
};
// equivalent/0x0023fbb0.cpp (stub String), size 0xc (0x10)
struct String_23fbb0 {
    char* data; // +0x00
    unsigned short kind; // +0x04 (+0x08)
    unsigned short pad6; // +0x06 (+0x0a)
    unsigned short length; // +0x08 (+0x0c)
    unsigned short pad10; // +0x0a (+0x0e)
    char* FUN_0023fbb0();
};
// equivalent/0x0023fc40.cpp (stub String), size 0xc (0x10)
struct String_23fc40 {
    char *data; // +0x00
    unsigned short capacity; // +0x04 (+0x08)
    char pad[2]; // +0x06 (+0x0a)
    unsigned short extra; // +0x08 (+0x0c)
    String_23fc40 * FUN_0023fc40(const char *text, int option);
    void FUN_0023fb20(const char *text, hulk_intptr length, hulk_intptr capacity, int option);
};
// matches/0x0023fc90.cpp (stub Obj_23fc90), size 0xc (0x10)
struct Obj_23fc90 {
    void* mPtr; // +0x00
    short mB; // +0x04 (+0x08)
    short pad; // +0x06 (+0x0a)
    short mC; // +0x08 (+0x0c)
    void helper(int, int, int, int);
    Obj_23fc90* FUN_0023fc90(hulk_intptr, int, int);
};
// matches/0x0023fd20.cpp (stub Thing_23fd20), size 0xc
struct Thing_23fd20 {
    int value; // +0x00
    unsigned short a; // +0x04
    unsigned short pad; // +0x06
    unsigned short b; // +0x08
    Thing_23fd20* FUN_0023fd20(int arg);
};
// equivalent/0x0023fe50.cpp (stub String), size 0xc (0x10)
struct String_23fe50 {
    char* data; // +0x00
    unsigned short kind; // +0x04 (+0x08)
    unsigned short reserved; // +0x06 (+0x0a)
    unsigned short length; // +0x08 (+0x0c)
    String_23fe50* FUN_0023fe50(const char* source);
};
// equivalent/0x0023ff50.cpp (stub String), size 0xc (0x10)
struct String_23ff50 {
    char *data; // +0x00
    unsigned short kind; // +0x04 (+0x08)
    unsigned short unused; // +0x06 (+0x0a)
    unsigned short length; // +0x08 (+0x0c)
    String_23ff50 * FUN_0023ff50(String_23ff50 *other);
};
// matches/0x00240060.cpp (stub Str), size 0x8 (0x10)
struct Str_240060 {
    char* data; // +0x00
    short type; // +0x04 (+0x08)
    void FUN_00240060();
};
// equivalent/0x00240090.cpp (stub Handle_240090), size 0xc (0x10)
struct Handle_240090 {
    hulk_intptr text; // +0x00
    unsigned short kind; // +0x04 (+0x08)
    unsigned short pad6; // +0x06 (+0x0a)
    unsigned short extra; // +0x08 (+0x0c)
    void FUN_00240090(const Handle_240090* other);
};
// matches/0x00240170.cpp (stub Thing_240170), size 0x1
struct Thing_240170 {
    void FUN_00240090(const void*);
    Thing_240170* FUN_00240170(hulk_intptr);
};
// equivalent/0x00240190.cpp (stub Text), size 0x8 (0x10)
struct Text_240190 {
    char *data; // +0x00
    short kind; // +0x04 (+0x08)
    Text_240190 *FUN_00240090(const Text_240190 *other);
    Text_240190 * FUN_00240190(const Text_240190 *other);
};
// equivalent/0x002401f0.cpp (stub String), size 0xc (0x10)
struct String_2401f0 {
    char* data; // +0x00
    unsigned short kind; // +0x04 (+0x08)
    unsigned short pad6; // +0x06 (+0x0a)
    unsigned short length; // +0x08 (+0x0c)
    unsigned short pad10; // +0x0a (+0x0e)
    void FUN_00240090(const String_2401f0* src);
    char* FUN_0023fbb0();
    String_2401f0* FUN_002401f0(String_2401f0* out);
};
// matches/0x00240380.cpp (stub StringLike), size 0x4 (0x8)
struct StringLike_240380 {
    char* mData; // +0x00
    char FUN_00240380(const char* other);
};
// matches/0x00240410.cpp (stub ThisWrap_00240410), size 0x1
struct ThisWrap_00240410 {
    signed char FUN_00240380(int);
    bool FUN_00240410(hulk_intptr param_1);
};
// matches/0x00243390.cpp (stub CFightParamsCollision), size 0x18
struct CFightParamsCollision_243390 {
    char pad[0x18]; // +0x00
    CFightParamsCollision_243390* FUN_00243390();
};
// equivalent/0x00245b70.cpp (stub RingReader), size 0x9c
struct RingReader_245b70 {
    unsigned char buf[0x80]; // +0x00
    char pad80[4]; // +0x80
    unsigned int windowStart; // +0x84
    unsigned int windowLen; // +0x88
    unsigned int base; // +0x8c
    char pad90[8]; // +0x90
    unsigned int limit; // +0x98
    void FUN_002459d0();
    unsigned char FUN_00245b70(unsigned int index);
};
// matches/0x0024b270.cpp (stub Target_24b270), size 0x7b
struct Target_24b270 {
    char pad[0x78]; // +0x00
    unsigned char index; // +0x78
    unsigned char count; // +0x79
    unsigned char divisor; // +0x7a
    int FUN_0024b270();
};
// matches/0x0024b2d0.cpp (stub Obj_24b2d0), size 0x7a
struct Obj_24b2d0 {
    char pad[0x78]; // +0x00
    unsigned char index; // +0x78
    unsigned char enabled; // +0x79
    Obj_24b2d0* FUN_0024b2d0();
};
// matches/0x0024b310.cpp (stub X_24b310), size 0x7b
struct X_24b310 {
    char pad[0x78]; // +0x00
    unsigned char a, b, c; // +0x78
    hulk_intptr FUN_0024b310(void* p);
};
// matches/0x00257270.cpp (stub C_257270), size 0x44
struct C_257270 {
    char pad[0x44]; // +0x00
    hulk_intptr FUN_00257270(hulk_uintptr x);
};
// matches/0x0025c000.cpp (stub Target_25c000), size 0x4
struct Target_25c000 {
    int value; // +0x00
    int FUN_0025c000(void* p);
};
// matches/0x0025d3e0.cpp (stub Object), size 0x5c
struct Object_25d3e0 {
    int FUN_0025d3e0();
    char pad[0x58]; // +0x00
    int mValue; // +0x58
};
// matches/0x0025d3f0.cpp (stub Obj_25d3f0), size 0x60
struct Obj_25d3f0 {
    char p[0x34]; // +0x00
    int value; // +0x34
    char q[0x20]; // +0x38
    int state; // +0x58
    char flag; // +0x5c
    void FUN_0025d3f0(int*);
};
// matches/0x0025d780.cpp (stub Owner_25d780), size 0x5c (0x60)
struct Owner_25d780 {
    char pad[0x40]; // +0x00
    char* mData; // +0x40
    char pad2[0x14]; // +0x44 (+0x48)
    int mState; // +0x58 (+0x5c)
    void FUN_0025d780();
};
// matches/0x0025dba0.cpp (stub Queue_25dba0), size 0x54 (0x60)
struct Queue_25dba0 {
    char pad[0x4c]; // +0x00
    int* head; // +0x4c (+0x50)
    int* tail; // +0x50 (+0x58)
    void FUN_0025dba0(int* item);
};
// matches/0x0025dbd0.cpp (stub Owner_25dbd0), size 0x54 (0x60)
struct Owner_25dbd0 {
    char pad[0x4c]; // +0x00
    int* head; // +0x4c (+0x50)
    int* tail; // +0x50 (+0x58)
    void FUN_0025dbd0(int*);
};
// equivalent/0x0025df40.cpp (stub Scheduler), size 0x60 (0x88)
struct Scheduler_25df40 {
    float one; // +0x00
    int f04; // +0x04
    Scheduler_25df40* list0; // +0x08
    Scheduler_25df40* list0a; // +0x0c (+0x10)
    Scheduler_25df40* list0b; // +0x10 (+0x18)
    Scheduler_25df40* list0c; // +0x14 (+0x20)
    int count0; // +0x18 (+0x28)
    Scheduler_25df40* list1; // +0x1c (+0x30)
    Scheduler_25df40* list1a; // +0x20 (+0x38)
    Scheduler_25df40* list1b; // +0x24 (+0x40)
    Scheduler_25df40* list1c; // +0x28 (+0x48)
    int count1; // +0x2c (+0x50)
    int f30; // +0x30 (+0x54)
    int f34; // +0x34 (+0x58)
    int f38; // +0x38 (+0x5c)
    int f3c; // +0x3c (+0x60)
    int f40; // +0x40 (+0x64)
    int f44; // +0x44 (+0x68)
    int f48; // +0x48 (+0x6c)
    int f4c; // +0x4c (+0x70)
    int f50; // +0x50 (+0x74)
    char b54; // +0x54 (+0x78)
    char pad55[3]; // +0x55 (+0x79)
    int f58; // +0x58 (+0x7c)
    char b5c; // +0x5c (+0x80)
    Scheduler_25df40* FUN_0025df40(hulk_intptr a, hulk_intptr b, hulk_intptr c);
    void FUN_0025db30();
};
// matches/0x00261a80.cpp (stub Target_261a80), size 0x4
struct Target_261a80 {
    int value; // +0x00
    int FUN_00261a80(void* p);
};
// matches/0x00261ef0.cpp (stub Obj_261ef0), size 0x8 (0x10)
struct Obj_261ef0 {
    int* mHead; // +0x00
    int* mTail; // +0x04 (+0x08)
    bool FUN_00261ef0(const char*);
};
// matches/0x00263d30.cpp (stub X_263d30), size 0x1
struct X_263d30 {
    void FUN_00263d30();
};
// equivalent/0x00264140.cpp (stub Converter), size 0x10
struct Converter_264140 {
    char pad[15]; // +0x00
    unsigned char reverse; // +0x0f
    void FUN_00264140(unsigned char* data, unsigned int count, unsigned int size);
};
// equivalent/0x002642c0.cpp (stub Controller), size 0x38 (0x40)
struct Controller_2642c0 {
    char pad0[0x1c]; // +0x00
    unsigned int selected; // +0x1c
    char pad20[0x8]; // +0x20
    char* currentBuffer; // +0x28
    unsigned int position; // +0x2c (+0x30)
    unsigned int limit; // +0x30 (+0x34)
    unsigned int capacity; // +0x34 (+0x38)
    void FUN_002640f0();
    void FUN_00264050(char* buffer);
    void FUN_002642c0();
};
// matches/0x00264510.cpp (stub S_264510), size 0x34
struct S_264510 {
    char p0[0xc]; // +0x00
    char m0c; // +0x0c
    char pd; // +0x0d
    char m0e; // +0x0e
    char pf[5]; // +0x0f
    unsigned m14; // +0x14
    char p18[0x14]; // +0x18
    unsigned m2c, m30; // +0x2c
    void A(unsigned);
    void B();
    void FUN_00264510(unsigned n);
};
// matches/0x002647e0.cpp (stub X_2647e0), size 0xf
struct X_2647e0 {
    char pad[0xC]; // +0x00
    unsigned char a; // +0x0c
    char padD; // +0x0d
    unsigned char b; // +0x0e
    unsigned char FUN_002647e0(hulk_intptr, hulk_intptr, int, hulk_intptr);
    unsigned char first(int, int, int, int);
    unsigned char second(int, int, int, int);
};
// matches/0x00264860.cpp (stub C_264860), size 0x8
struct C_264860 {
    int pad; // +0x00
    int value; // +0x04
    void FUN_00264860(int);
};
// matches/0x00264c70.cpp (stub X_264c70), size 0x24
struct X_264c70 {
    int f0; // +0x00
    int f4; // +0x04
    int f8; // +0x08
    int fc; // +0x0c
    int f10; // +0x10
    unsigned int f14; // +0x14
    unsigned int f18; // +0x18
    unsigned int f1c; // +0x1c
    unsigned int f20; // +0x20
    int FUN_00264c70();
};
// matches/0x00264d20.cpp (stub Q_264d20), size 0x24
struct Q_264d20 {
    void FUN_00264d20();
    char pad[8]; // +0x00
    int m8; // +0x08
    char pad2[8]; // +0x0c
    unsigned m14; // +0x14
    unsigned m18; // +0x18
    int m1c; // +0x1c
    int m20; // +0x20
};
// matches/0x00265310.cpp (stub Obj_265310), size 0x14
struct Obj_265310 {
    // (x64t8) the content registry's words (0x002656b0): the tables at 0xc / 0x10 are pointers
    char pad0[4]; // +0x00
    int pad4, pad8; // +0x04
    void* first; // +0x0c
    void* value; // +0x10 the second table
    hulk_intptr FUN_00265310(hulk_intptr);
};
// matches/0x00265340.cpp (stub Thing_265340), size 0x10
struct Thing_265340 {
    // (x64t8) the content registry's words (0x002656b0): the first table at 0xc is a pointer
    char pad0[4]; // +0x00
    int pad4, pad8; // +0x04
    void* field; // +0x0c the first table
    hulk_intptr FUN_00265340(char*);
};
// matches/0x00266090.cpp (stub A_266090), size 0x10 (0x18)
struct A_266090 {
    char pad[12]; // +0x00
    int* p; // +0x0c (+0x10)
    int FUN_00266090();
};
// matches/0x00266130.cpp (stub X_266130), size 0xa
struct X_266130 {
    char pad[9]; // +0x00
    unsigned char field; // +0x09
    void FUN_00266130(unsigned char value);
};
// matches/0x002666e0.cpp (stub C_2666e0), size 0x18
struct C_2666e0 {
    char pad[0x14]; // +0x00
    int value; // +0x14
    void FUN_002666e0();
};
// matches/0x00266800.cpp (stub C_266800), size 0x20
struct C_266800 {
    char pad[0x20]; // +0x00
    void FUN_00266800(char* p);
};
// matches/0x00266880.cpp (stub PartitionDriver), size 0x1c
struct PartitionDriver_266880 {
    char pad[0x1c]; // +0x00
    hulk_intptr FUN_00266880();
};
// matches/0x002669d0.cpp (stub Copy), size 0x1
struct Copy_2669d0 {
    void FUN_002669d0(const char* source);
};
// matches/0x00266c90.cpp (stub Target_266c90), size 0x288
struct Target_266c90 {
    char pad[0x284]; // +0x00
    unsigned int value; // +0x284
    unsigned int FUN_00266c90();
};
// equivalent/0x00268d30.cpp (stub InputValue), size 0x2c (0x30)
struct InputValue_268d30 {
    char padding[0x20]; // +0x00
    void *kind; // +0x20
    char gap[4]; // +0x24 (+0x28)
    unsigned int data; // +0x28 (+0x2c)
    double FUN_00268d30(unsigned int *source);
};
// equivalent/0x0026e030.cpp (stub Device_26e030), size 0xc4
struct Device_26e030 {
    char reserved[0x10]; // +0x00
    unsigned long first[22]; // +0x10
    unsigned long second[22]; // +0x68
    int active; // +0xc0
    void FUN_0026e030();
};
// matches/0x0026e200.cpp (stub X_26e200), size 0x1d8
struct X_26e200 {
    char pad[0x1d4]; // +0x00
    int mHead; // +0x1d4
    bool FUN_0026e200(void*);
};
// matches/0x0026e470.cpp (stub C_26e470), size 0x1c
struct C_26e470 {
    char pad[0x1c]; // +0x00
    void helper(void*, unsigned int);
    void FUN_0026e470(hulk_uintptr, char*);
};
// equivalent/0x00270020.cpp (stub Pool_270020), size 0x34 (0x58)
struct Pool_270020 {
    const void* vftable; // +0x00
    struct { const void* vftable; int heap; } object; // +0x00
    int refs; // +0x0c (+0x18)
    void* freeHead; // +0x10 (+0x20)
    void* owner; // +0x14 (+0x28)
    void* blocks; // +0x18 (+0x30)
    unsigned stride; // +0x1c (+0x38)
    unsigned count; // +0x20 (+0x3c)
    unsigned flags; // +0x24 (+0x40)
    unsigned zero28; // +0x28 (+0x44)
    unsigned zero2c; // +0x2c (+0x48)
    void* zero30; // +0x30 (+0x50)
    void FUN_00270020(void* buffer, unsigned itemSize, unsigned itemCount, unsigned flagsValue, void* allocator, hulk_uintptr unused6, unsigned itemAdjustment);
};
// matches/0x002728d0.cpp (stub ProjectileMissile), size 0x60
struct ProjectileMissile_2728d0 {
    char pad[0x60]; // +0x00
    ProjectileMissile_2728d0* FUN_002728d0();
};
// matches/0x00272b40.cpp (stub C_272b40), size 0x5d
struct C_272b40 {
    char pad[0x5c]; // +0x00
    unsigned char value; // +0x5c
    void FUN_00272b40(unsigned char x);
};
// matches/0x002775f0.cpp (stub X_2775f0), size 0x14
struct X_2775f0 {
    int data[4]; // +0x00
    int value; // +0x10
    void FUN_002775f0(int i);
};
// matches/0x00277630.cpp (stub Obj_277630), size 0x24
struct Obj_277630 {
    char pad[0x14]; // +0x00
    int m14; // +0x14
    int m18; // +0x18
    int m1c; // +0x1c
    int m20; // +0x20
    void FUN_00277630(int, hulk_intptr, int);
};
// matches/0x00277cd0.cpp (stub C_277cd0), size 0x10
struct C_277cd0 {
    char pad[12]; // +0x00
    unsigned int value; // +0x0c
    unsigned int FUN_00277cd0();
};
// matches/0x00278010.cpp (stub Obj_278010), size 0x20
struct Obj_278010 {
    char pad[0x1c]; // +0x00
    int state; // +0x1c
    int A(int, int, int, int, int, int, int, int, int);
    int B(int, int, int, int, int, int, int, int, int);
    int FUN_00278010(hulk_intptr a, int b, hulk_intptr c, int d, int e, hulk_intptr f, int g, hulk_intptr h, int i);
};
// matches/0x002780c0.cpp (stub Bits_2780c0), size 0x1
struct Bits_2780c0 {
    unsigned char value; // +0x00
    bool FUN_002780c0(int a, int b);
};
// matches/0x002783d0.cpp (stub Obj_2783d0), size 0xd5
struct Obj_2783d0 {
    char pad[0xcc]; // +0x00
    char flag; // +0xcc
    char pad2[6]; // +0xcd
    char x; // +0xd3
    char y; // +0xd4
    void FUN_002783d0(int* a, int* b);
};
// matches/0x0027a570.cpp (stub X_27a570), size 0xa0
struct X_27a570 {
    char pad[0xa0]; // +0x00
    void FUN_0027a570();
};
// matches/0x0027a590.cpp (stub Obj_27a590), size 0xf4
struct Obj_27a590 {
    char pad[0xa0]; // +0x00
    int values[20]; // +0xa0
    int count; // +0xf0
    void FUN_0027a590(hulk_intptr, hulk_intptr);
};
// matches/0x0027a8c0.cpp (stub Target_27a8c0), size 0x38
struct Target_27a8c0 {
    char pad0[0x10]; // +0x00
    int field10; // +0x10
    int field14; // +0x14
    char text[0x1f]; // +0x18
    char flag; // +0x37
    void FUN_0027a8c0(const char* source);
};
// matches/0x0027a8f0.cpp (stub Thing_27a8f0), size 0x1d38
struct Thing_27a8f0 {
    char pad0[0x14]; // +0x00
    int count; // +0x14
    char pad1[0x20]; // +0x18
    char names[0xd00]; // +0x38
    char desc[0x1000]; // +0xd38
    char FUN_0027a8f0(const char*, const char*);
};
// matches/0x0027a9d0.cpp (stub Obj_27a9d0), size 0xd38
struct Obj_27a9d0 {
    bool FUN_0027a9d0(hulk_intptr a, hulk_intptr b);
    char pad[0x10]; // +0x00
    int index; // +0x10
    char more[0xd24]; // +0x14
};
// matches/0x0027aa20.cpp (stub Obj_27aa20), size 0xd38
struct Obj_27aa20 {
    bool FUN_0027aa20(hulk_intptr a, hulk_intptr b);
    char pad[0x10]; // +0x00
    int index; // +0x10
    char more[0xd24]; // +0x14
};
// matches/0x0027aac0.cpp (stub Obj_27aac0), size 0x14
struct Obj_27aac0 {
    char pad[0x10]; // +0x00
    int index; // +0x10
    unsigned char Check(int);
    unsigned char FUN_0027aac0(hulk_intptr, int*);
};
// matches/0x0027ab00.cpp (stub Obj_27ab00), size 0x18
struct Obj_27ab00 {
    char pad[0x10]; // +0x00
    int index; // +0x10
    char rest[1]; // +0x14
    bool Check(int);
    bool FUN_0027ab00(hulk_intptr a, float* p);
};
// equivalent/0x0027acf0.cpp (stub ConfigParser), size 0x154 (0x160)
struct ConfigParser_27acf0 {
    char pad0[4]; // +0x00
    void* source; // +0x04 (+0x08)
    char* buf; // +0x08 (+0x10)
    int pos; // +0x0c (+0x18)
    int end; // +0x10 (+0x1c)
    char pad1[0x34 - 0x14]; // +0x14 (+0x20)
    char key[0x20]; // +0x34 (+0x40)
    char value[0x100]; // +0x54 (+0x60)
    bool FUN_0027acf0(char** outKey, char** outValue);
};
// matches/0x0027af10.cpp (stub Pair_27af10), size 0x8
struct Pair_27af10 {
    unsigned int a; // +0x00
    unsigned int b; // +0x04
    Pair_27af10* FUN_0027af10(unsigned int x, unsigned int y);
};
// matches/0x0027af60.cpp (stub Pair_27af60), size 0x8
struct Pair_27af60 {
    int a; // +0x00
    int b; // +0x04
    void FUN_0027af60(int x, int y);
};
// matches/0x0027b040.cpp (stub Target_27b040), size 0x8
struct Target_27b040 {
    unsigned int a; // +0x00
    unsigned int b; // +0x04
    unsigned __int64 FUN_0027b040(hulk_uintptr value);
};
// matches/0x0027b3b0.cpp (stub Buffer_27b3b0), size 0xc (0x18)
struct Buffer_27b3b0 {
    int *mStart, *mCurrent, *mEnd; // +0x00
    bool FUN_0027b3b0(int count);
};
// equivalent/0x0027be00.cpp (stub Buffer), size 0x8 (0x10)
struct Buffer_27be00 {
    void* begin; // +0x00
    void* end; // +0x04 (+0x08)
    bool FUN_0027be00(hulk_uintptr count, hulk_intptr value);
};
// matches/0x0027cb70.cpp (stub C_27cb70), size 0x8c
struct C_27cb70 {
    char pad[0x88]; // +0x00
    int value; // +0x88
    int FUN_0027cb70();
};
// matches/0x0027cb80.cpp (stub C_27cb80), size 0x9c (0xa8)
struct C_27cb80 {
    char pad[0x90]; // +0x00
    int count; // +0x90
    void* items[2]; // +0x94 (+0x98)
    bool FUN_0027cb80(void* p);
};
// matches/0x0027cf40.cpp (stub Owner_27cf40), size 0x10
struct Owner_27cf40 {
    char pad[8]; // +0x00
    int a; // +0x08
    int b; // +0x0c
    Owner_27cf40* GetThing();
    void DoThing(int, int, int);
    void FUN_0027cf40(int x);
};
// matches/0x0027e760.cpp (stub Obj_27e760), size 0x1
struct Obj_27e760 {
    void Second(unsigned __int64);
    void FUN_0027e760(unsigned int);
};
// equivalent/0x0027f070.cpp (stub Vertex_27f070), size 0x18
struct Vertex_27f070 {
    float x, y, z; // +0x00
    unsigned char b, g, r, a; // +0x0c
    float u, v; // +0x10
    void FUN_0027f070(const Vertex_27f070* from, const Vertex_27f070* to, float t);
};
// equivalent/0x0027fa00.cpp (stub State_27fa00), size 0xa0
struct State_27fa00 {
    unsigned int words[40]; // +0x00
    State_27fa00* FUN_0027fa00(const State_27fa00* source);
};
// matches/0x00280160.cpp (stub Owner_280160), size 0x70 (0x78)
struct Owner_280160 {
    char pad0[0x10]; // +0x00
    int state; // +0x10
    char pad14[4]; // +0x14
    int clear; // +0x18
    char pad1c[0x44]; // +0x1c
    hulk_intptr first; // +0x60
    hulk_intptr second; // +0x64 (+0x68)
    int x; // +0x68 (+0x70)
    int y; // +0x6c (+0x74)
    void FUN_00280160();
};
// matches/0x00284820.cpp (stub C_284820), size 0x28
struct C_284820 {
    char pad[0x24]; // +0x00
    int count; // +0x24
    void A(int);
    void B(int);
    void D(int);
    void E(int);
    void FUN_00284820(hulk_intptr);
};
// matches/0x002848b0.cpp (stub Obj_2848b0), size 0x2c (0x38)
struct Obj_2848b0 {
    char pad[0x1c]; // +0x00
    int* base; // +0x1c (+0x20)
    int unk20; // +0x20 (+0x28)
    int count; // +0x24 (+0x2c)
    char pad28[4]; // +0x28 (+0x30)
    void H1(int);
    void H2(int);
    void H3(int);
    void H4(int);
    void FUN_002848b0(hulk_intptr, int, int*);
};
// matches/0x00284ad0.cpp (stub C_284ad0), size 0x11
struct C_284ad0 {
    char pad[0x10]; // +0x00
    unsigned char value; // +0x10
    void FUN_00284ad0(unsigned char x);
};
// matches/0x00284ae0.cpp (stub C_284ae0), size 0x10
struct C_284ae0 {
    char pad[0x10]; // +0x00
    unsigned char FUN_00284ae0();
};
// matches/0x00284f50.cpp (stub Target_284f50), size 0x2c
struct Target_284f50 {
    char pad[0x28]; // +0x00
    unsigned int value; // +0x28
    hulk_uintptr FUN_00284f50();
};
// matches/0x00284f60.cpp (stub CJumpTrack), size 0x18
struct CJumpTrack_284f60 {
    char pad[0x14]; // +0x00
    float value; // +0x14
    float FUN_00284f60();
};
// matches/0x002888c0.cpp (stub C_2888c0), size 0x20
struct C_2888c0 {
    char pad[0x10]; // +0x00
    volatile unsigned a[2]; // +0x10
    volatile unsigned b[2]; // +0x18
    hulk_intptr FUN_002888c0(unsigned n, unsigned x);
};
// matches/0x00288950.cpp (stub C_288950), size 0x1c (0x20)
struct C_288950 {
    char pad[0x18]; // +0x00
    int* p; // +0x18
    hulk_intptr FUN_00288950(int index);
};
// matches/0x00288a10.cpp (stub Target_288a10), size 0x30 (0x38)
struct Target_288a10 {
    char pad[0x2c]; // +0x00
    int* values; // +0x2c (+0x30)
    hulk_intptr FUN_00288a10(int index);
};
// equivalent/0x00289f80.cpp (stub Table_289f80), size 0x18 (0x20)
struct Table_289f80 {
    char padding[16]; // +0x00
    int count; // +0x10
    short* values; // +0x14 (+0x18)
    bool FUN_00289f80(float value, int* lower, int* upper);
};
// matches/0x0028a080.cpp (stub X_28a080), size 0x1c (0x28)
struct X_28a080 {
    char pad[0x14]; // +0x00
    short* a; // +0x14 (+0x18)
    int* b; // +0x18 (+0x20)
    void FUN_0028a080(int i, float* out, int* out2);
};
// equivalent/0x0028a0b0.cpp (stub Track), size 0x1c (0x28)
struct Track_28a0b0 {
    int unknown; // +0x00
    int interpolate; // +0x04
    char padding[12]; // +0x08
    short* times; // +0x14 (+0x18)
    int* values; // +0x18 (+0x20)
    bool FUN_00289f80(float time, int* first, int* second);
    void FUN_0028a0b0(float time, int* result);
};
// equivalent/0x0028a1c0.cpp (stub Curve_28a1c0), size 0x1c (0x28)
struct Curve_28a1c0 {
    char pad0[4]; // +0x00
    int enabled; // +0x04
    char pad8[12]; // +0x08
    short* times; // +0x14 (+0x18)
    float* values; // +0x18 (+0x20)
    bool FUN_00289f80(float time, int* first, int* second);
    void FUN_0028a1c0(float time, float* output);
};
// matches/0x0028ac00.cpp (stub Obj_28ac00), size 0x1c (0x20)
struct Obj_28ac00 {
    char pad[0x18]; // +0x00
    int* arr; // +0x18
    void helper(int, int*, int*);
    void FUN_0028ac00(int a, int* out);
};
// matches/0x0028ac90.cpp (stub Obj_28ac90), size 0x1c (0x20)
struct Obj_28ac90 {
    char pad[0x18]; // +0x00
    char* bits; // +0x18
    void Normalize(unsigned int, unsigned int*, unsigned int*);
    void FUN_0028ac90(unsigned int, bool*);
};
// equivalent/0x0028ad20.cpp (stub Track), size 0x1c (0x28)
struct Track_28ad20 {
    char pad0[4]; // +0x00
    int enabled; // +0x04
    char pad8[12]; // +0x08
    short* times; // +0x14 (+0x18)
    unsigned int* colors; // +0x18 (+0x20)
    bool FUN_00289f80(float value,int* lower,int* upper);
    void FUN_0028ad20(float value, unsigned int* output);
};
// equivalent/0x0028d220.cpp (stub Quat16), size 0x8
struct Quat16_28d220 {
    short x, y, z, w; // +0x00
    float* FUN_0028d220(float* out);
};
// matches/0x0028f9a0.cpp (stub X_28f9a0), size 0xf8 (0x120)
// (x64t3) Pure3D's context (p3d's, DAT_0052c2b4): 0x00292560 allocates it, 0x0028f800 constructs it, 0x0028f920
// releases its pddi objects; the views of src/engine/pure3d/unk_28f800.cpp use this record
struct X_28f9a0 {
    int refs; // +0x00
    void* helper; // +0x04 (+0x08) (0x00293bd0's object)
    void* f08; // +0x08 (+0x10)
    char world[0x40]; // +0x0c (+0x18) (matrices: 0x0022b980 sets them to identity)
    char view[0x40]; // +0x4c (+0x58)
    char proj[0x40]; // +0x8c (+0x98)
    int a, b, c, d; // +0xcc (+0xd8) (a: the clear colour, b: a scale (float 1.0))
    int f_dc; // +0xdc (+0xe8)
    void* device; // +0xe0 (+0xf0) (the pddiDevice)
    void* context; // +0xe4 (+0xf8) (the render context: pddiDevice::vfunc_8's)
    void* display; // +0xe8 (+0x100) (the display: pddiDevice::vfunc_7's)
    hulk_intptr f_ec, f_f0; // +0xec (+0x108) (the render context's extensions 0x102 / 0x106: vfunc_89)
    unsigned char flag; // +0xf4 (+0x118)
    void FUN_0028f9a0();
};
// matches/0x0028fa30.cpp (stub X_28fa30), size 0x8 (0x10)
struct X_28fa30 {
    int pad; // +0x00
    hulk_uintptr value; // +0x04 (+0x08) (x64t3: X_28f9a0's helper, a pointer)
    hulk_uintptr FUN_0028fa30(unsigned int arg);
};
// matches/0x0028fad0.cpp (stub Obj_28fad0), size 0xf8 (0x120)
// (x64t3) the context record X_28f9a0: value = its f_ec (were a 0xec-byte pad and a 4-byte word)
struct Obj_28fad0 : X_28f9a0 {
    hulk_uintptr FUN_0028fad0();
};
// matches/0x0028fe80.cpp (stub Obj), size 0xc (0x10)
struct Obj_28fe80 {
    char pad[8]; // +0x00
    char* text; // +0x08
    void FUN_0028fe80(const char* src);
};
// matches/0x00290790.cpp (stub Buffer_290790), size 0x8 (0x10)
struct Buffer_290790 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_00290790(unsigned int count, void* arg);
};
// equivalent/0x002909c0.cpp (stub Buffer), size 0x8 (0x10)
struct Buffer_2909c0 {
    void* begin; // +0x00
    void* end; // +0x04 (+0x08)
    bool FUN_002909c0(unsigned count, hulk_uintptr value);
};
// equivalent/0x00292330.cpp (stub Settings_292330), size 0x34
struct Settings_292330 {
    unsigned width; // +0x00
    unsigned height; // +0x04
    unsigned depth; // +0x08
    unsigned mode; // +0x0c
    unsigned format; // +0x10
    unsigned primaryCapacity; // +0x14
    unsigned secondaryCapacity; // +0x18
    unsigned tertiaryCapacity; // +0x1c
    unsigned count; // +0x20
    unsigned flags; // +0x24
    unsigned reserved; // +0x28
    unsigned char option0; // +0x2c
    unsigned char option1; // +0x2d
    unsigned char option2; // +0x2e
    unsigned char option3; // +0x2f
    unsigned char option4; // +0x30
    void FUN_00292330();
};
// matches/0x00293a90.cpp (stub C_293a90), size 0xe8
struct C_293a90 {
    char pad[0xcc]; // +0x00
    unsigned char flag; // +0xcc
    char pad2[0xf]; // +0xcd
    int a; // +0xdc
    int b; // +0xe0
    int c; // +0xe4
    void FUN_00293a90(int* p);
};
// matches/0x00293af0.cpp (stub C_293af0), size 0xdc
struct C_293af0 {
    char pad[0xcc]; // +0x00
    unsigned char flag; // +0xcc
    char pad2[3]; // +0xcd
    int a, b, c; // +0xd0
    void FUN_00293af0(int* p);
};
// matches/0x00293e40.cpp (stub A_293e40), size 0x8
struct A_293e40 {
    char pad[8]; // +0x00
    void FUN_00293e40(int a, int b, int c, int d);
};
// matches/0x00293e60.cpp (stub Obj), size 0x18
struct Obj_293e60 {
    char pad[8]; // +0x00
    int a, b, c, d; // +0x08
    void FUN_00293e60(int* x, int* y, int* z, int* w);
};
// matches/0x00293e90.cpp (stub C_293e90), size 0x20
struct C_293e90 {
    char pad[0x1c]; // +0x00
    int value; // +0x1c
    void FUN_00293e90(int x);
};
// matches/0x00294ed0.cpp (stub Search_294ed0), size 0x44 (0x48)
struct Search_294ed0 {
    char pad0[0x38]; // +0x00
    int count; // +0x38
    char pad3c[4]; // +0x3c
    unsigned short* values; // +0x40
    int FUN_00294ed0(unsigned short key);
};
// matches/0x00295250.cpp (stub C_295250), size 0x38
struct C_295250 {
    char pad[0x34]; // +0x00
    int value; // +0x34
    bool FUN_00295250(int x);
};
// matches/0x002987d0.cpp (stub X_2987d0), size 0x40 (0x50)
struct X_2987d0 {
    char pad0[0x20]; // +0x00
    unsigned char count; // +0x20
    char pad21[3]; // +0x21
    unsigned char* buffer; // +0x24 (+0x28)
    char pad28[8]; // +0x28 (+0x30)
    unsigned char* output; // +0x30 (+0x38)
    char pad34[8]; // +0x34 (+0x40)
    int* entries; // +0x3c (+0x48)
    void FUN_002987d0(unsigned char);
};
// matches/0x002988e0.cpp (stub Obj_2988e0), size 0x44 (0x50)
struct Obj_2988e0 {
    char pad0[0x20]; // +0x00
    unsigned char flag; // +0x20
    char pad21[3]; // +0x21
    unsigned char* a; // +0x24 (+0x28)
    char pad28[8]; // +0x28 (+0x30)
    unsigned char* b; // +0x30 (+0x38)
    char pad34[8]; // +0x34 (+0x40)
    int start; // +0x3c (+0x48)
    int end; // +0x40 (+0x4c)
    void FUN_002988e0();
};
// matches/0x002989c0.cpp (stub Buffer_2989c0), size 0x28 (0x38)
struct Buffer_2989c0 {
    char pad0[8]; // +0x00
    unsigned char count; // +0x08
    char pad9[3]; // +0x09
    unsigned char* data; // +0x0c (+0x10)
    char pad10[8]; // +0x10 (+0x18)
    unsigned char* out; // +0x18 (+0x20)
    char pad1c[8]; // +0x1c (+0x28)
    unsigned int* flags; // +0x24 (+0x30)
    void FUN_002989c0(unsigned char value);
};
// matches/0x00298a00.cpp (stub X_298a00), size 0x1c (0x28)
struct X_298a00 {
    char pad0[8]; // +0x00
    unsigned char count; // +0x08
    char pad9[3]; // +0x09
    unsigned char* map; // +0x0c (+0x10)
    char pad10[8]; // +0x10 (+0x18)
    unsigned char* items; // +0x18 (+0x20)
    void FUN_00298a00(unsigned char value);
};
// matches/0x00298a60.cpp (stub Mapping), size 0x2c (0x40)
struct Mapping_298a60 {
    char pad0[8]; // +0x00
    unsigned char count; // +0x08
    char pad1[3]; // +0x09
    unsigned char* forward; // +0x0c (+0x10)
    char pad2[8]; // +0x10 (+0x18)
    unsigned char* reverse; // +0x18 (+0x20)
    char pad3[8]; // +0x1c (+0x28)
    void** first; // +0x24 (+0x30)
    void** last; // +0x28 (+0x38)
    void FUN_00298a60();
};
// matches/0x00299230.cpp (stub Obj_299230), size 0x10 (0x18)
struct Obj_299230 {
    char pad[0x0c]; // +0x00
    volatile unsigned char* table; // +0x0c (+0x10)
    void FUN_00299230(unsigned char index);
    void g(int v);
};
// matches/0x0029b380.cpp (stub Obj_29b380), size 0x48
struct Obj_29b380 {
    char pad[0x44]; // +0x00
    int mX; // +0x44
    void FUN_0029b380(int x);
};
// matches/0x0029b6d0.cpp (stub X_29b6d0), size 0x20 (0x28)
struct X_29b6d0 {
    char pad0[0x10]; // +0x00
    unsigned count; // +0x10
    char pad14[8]; // +0x14
    unsigned* items; // +0x1c (+0x20)
    hulk_uintptr FUN_0029b6d0(unsigned i);
};
// matches/0x0029c240.cpp (stub C_29c240), size 0x3c
struct C_29c240 {
    void FUN_0029c240(int a, const int* p, const int* q, int e, int f, int g, int h, int i, int j);
    char p0[4]; // +0x00
    int m4; // +0x04
    int m8; // +0x08
    int x0, y0, z0; // +0x0c
    int x1, y1, z1; // +0x18
    int m24; // +0x24
    int m28; // +0x28
    int m2c; // +0x2c
    int m30; // +0x30
    int m34; // +0x34
    int m38; // +0x38
};
// equivalent/0x0029c450.cpp (stub Object), size 0x40 (0x58)
struct Object_29c450 {
    char padding[0x2c]; // +0x00
    void* first; // +0x2c (+0x30)
    void* second; // +0x30 (+0x38)
    void* third; // +0x34 (+0x40)
    void* fourth; // +0x38 (+0x48)
    void* fifth; // +0x3c (+0x50)
    void* FUN_0029c450(void* value);
};
// matches/0x0029c550.cpp (stub C_29c550), size 0x28
struct C_29c550 {
    char pad[0x24]; // +0x00
    int value; // +0x24
    hulk_intptr FUN_0029c550(int x);
};
// matches/0x0029fd20.cpp (stub Caller_29fd20), size 0x1
struct Caller_29fd20 {
    void FUN_0029fd20(hulk_intptr value);
};
// matches/0x002a0800.cpp (stub Obj_2a0800), size 0x24
struct Obj_2a0800 {
    char pad[0x18]; // +0x00
    int a; // +0x18
    int b; // +0x1c
    int c; // +0x20
    void FUN_002a0800(int* x, int* y, int* z);
};
// matches/0x002a0840.cpp (stub Obj_2a0840), size 0x30
struct Obj_2a0840 {
    char pad[0x2c]; // +0x00
    int m2c; // +0x2c
    void FUN_002a0840(int v);
};
// matches/0x002a0850.cpp (stub C_2a0850), size 0x2c
struct C_2a0850 {
    char pad[0x2c]; // +0x00
    unsigned int FUN_002a0850();
};
// matches/0x002a08c0.cpp (stub Obj), size 0x50
struct Obj_2a08c0 {
    char pad[0x48]; // +0x00
    float s, c; // +0x48
    void FUN_002a08c0(float x);
};
// matches/0x002a08f0.cpp (stub Obj_2a08f0), size 0x54
struct Obj_2a08f0 {
    char pad[0x50]; // +0x00
    int field; // +0x50
    void FUN_002a08f0(int v);
};
// matches/0x002a10a0.cpp (stub Buffer_2a10a0), size 0x8 (0x10)
struct Buffer_2a10a0 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002a10a0(unsigned int count, void* arg);
};
// matches/0x002a1180.cpp (stub A_2a1180), size 0x18
struct A_2a1180 {
    char pad[0x10]; // +0x00
    int a; // +0x10
    int b; // +0x14
    void FUN_002a1180(int);
};
// matches/0x002a1340.cpp (stub C_2a1340), size 0x34
struct C_2a1340 {
    char pad[0x30]; // +0x00
    int value; // +0x30
    void FUN_002a1340(int x);
};
// matches/0x002a2f20.cpp (stub C_2a2f20), size 0x64
struct C_2a2f20 {
    char pad[0x58]; // +0x00
    int a, b, c; // +0x58
    void FUN_002a2f20(int* x, int* y, int* z);
};
// matches/0x002a31a0.cpp (stub C_2a31a0), size 0x8
struct C_2a31a0 {
    int pad; // +0x00
    int value; // +0x04
    void FUN_002a31a0(int);
};
// matches/0x002a31d0.cpp (stub Target), size 0xc
struct Target_2a31d0 {
    int pad[2]; // +0x00
    int value; // +0x08
    void FUN_002a31d0();
};
// matches/0x002a77c0.cpp (stub C_2a77c0), size 0x114
struct C_2a77c0 {
    char pad[0x110]; // +0x00
    int value; // +0x110
    void FUN_002a77c0(hulk_intptr x);
};
// matches/0x002a7cf0.cpp (stub Thing_2a7cf0), size 0x48
struct Thing_2a7cf0 {
    char pad[0x44]; // +0x00
    int value; // +0x44
    void FUN_002a7cf0(hulk_intptr x);
};
// matches/0x002a8000.cpp (stub Buffer_2a8000), size 0x8 (0x10)
struct Buffer_2a8000 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002a8000(unsigned int count, void* arg);
};
// matches/0x002a8060.cpp (stub Buffer_2a8060), size 0x8 (0x10)
struct Buffer_2a8060 {
    void* mData; // +0x00
    char* mEnd; // +0x04 (+0x08)
    bool FUN_002a8060(unsigned int size, hulk_uintptr arg);
};
// matches/0x002ab880.cpp (stub Buffer_2ab880), size 0x8 (0x10)
struct Buffer_2ab880 {
    // (x64t8) a list of particle pointers (decls/loaders.h HulkParticleList)
    void** begin; // +0x00
    void** end; // +0x04 (+0x08)
    bool FUN_002ab880(unsigned int count, void* arg);
};
// matches/0x002ab8e0.cpp (stub Buffer_2ab8e0), size 0x8 (0x10)
struct Buffer_2ab8e0 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002ab8e0(unsigned int count, void* arg);
};
// matches/0x002ab940.cpp (stub Buffer_2ab940), size 0x8 (0x10)
struct Buffer_2ab940 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002ab940(unsigned int count, void* arg);
};
// matches/0x002ab9a0.cpp (stub Buffer_2ab9a0), size 0x8 (0x10)
struct Buffer_2ab9a0 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002ab9a0(unsigned int count, void* arg);
};
// matches/0x002aba00.cpp (stub Buffer_2aba00), size 0x8 (0x10)
struct Buffer_2aba00 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002aba00(unsigned int count, void* arg);
};
// matches/0x002addb0.cpp (stub Transform_2addb0), size 0x38
struct Transform_2addb0 {
    char pad[0x18]; // +0x00
    unsigned int s0, s3, s2, s1, r1, r2, r0, r3; // +0x18
    unsigned int FUN_002addb0(unsigned int);
};
// matches/0x002ae950.cpp (stub C_2ae950), size 0xa4
struct C_2ae950 {
    char pad[0x94]; // +0x00
    int a, b, c, d; // +0x94
    void FUN_002ae950(int, int, int, int);
};
// matches/0x002aed60.cpp (stub SomeClass), size 0x90
struct SomeClass_2aed60 {
    char pad[0x8C]; // +0x00
    int field_8C; // +0x8c
    hulk_intptr FUN_002aed60(void* param2, void* param3);
};
// matches/0x002b0fb0.cpp (stub Buffer_2b0fb0), size 0x8 (0x10)
struct Buffer_2b0fb0 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002b0fb0(unsigned int count, void* arg);
};
// matches/0x002b1010.cpp (stub Buffer_2b1010), size 0x8 (0x10)
struct Buffer_2b1010 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002b1010(unsigned int count, void* arg);
};
// equivalent/0x002b1070.cpp (stub Buffer), size 0x8 (0x10)
struct Buffer_2b1070 {
    void* begin; // +0x00
    void* end; // +0x04 (+0x08)
    bool FUN_002b1070(unsigned count, hulk_intptr value);
};
// equivalent/0x002b93f0.cpp (stub Object), size 0xc8
struct Object_2b93f0 {
    char padding[0xc4]; // +0x00
    unsigned int limit; // +0xc4
    void FUN_002b93f0(float* result, unsigned int* value, unsigned int input, unsigned char randomize);
};
// matches/0x002bc520.cpp (stub Buffer_2bc520), size 0x8 (0x10)
struct Buffer_2bc520 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002bc520(unsigned int count, void* arg);
};
// matches/0x002bdd00.cpp (stub Thing_2bdd00), size 0x54 (0x60)
struct Thing_2bdd00 {
    char pad0[0x40]; // +0x00
    int count; // +0x40
    void* base; // +0x44 (+0x48)
    char pad48[8]; // +0x48 (+0x50)
    void* value; // +0x50 (+0x58)
    void FUN_002bdd00(void* p);
};
// matches/0x002c33b0.cpp (stub C_2c33b0), size 0xe8
struct C_2c33b0 {
    char pad[0xcc]; // +0x00
    unsigned char flag; // +0xcc
    char pad2[0xf]; // +0xcd
    int a; // +0xdc
    int b; // +0xe0
    int c; // +0xe4
    void FUN_002c33b0(int* p);
};
// matches/0x002c33e0.cpp (stub C_2c33e0), size 0xdc
struct C_2c33e0 {
    char pad[0xcc]; // +0x00
    unsigned char flag; // +0xcc
    char pad2[3]; // +0xcd
    int a, b, c; // +0xd0
    void FUN_002c33e0(int* p);
};
// matches/0x002c3d20.cpp (stub C_2c3d20), size 0x64
struct C_2c3d20 {
    char pad[0x60]; // +0x00
    int value; // +0x60
    void FUN_002c3d20(hulk_intptr a, hulk_intptr b, int* out);
};
// matches/0x002c3f20.cpp (stub C_2c3f20), size 0x64
struct C_2c3f20 {
    char pad[0x58]; // +0x00
    int a, b, c; // +0x58
    void FUN_002c3f20(int* x, int* y, int* z);
};
// matches/0x002c4150.cpp (stub C_2c4150), size 0x64
struct C_2c4150 {
    char pad[0x58]; // +0x00
    int a, b, c; // +0x58
    void FUN_002c4150(int* x, int* y, int* z);
};
// matches/0x002c41c0.cpp (stub C_2c41c0), size 0x70
struct C_2c41c0 {
    char pad[0x64]; // +0x00
    int a, b, c; // +0x64
    void FUN_002c41c0(int* x, int* y, int* z);
};
// matches/0x002c4200.cpp (stub Thing_2c4200), size 0x80
struct Thing_2c4200 {
    char pad[0x74]; // +0x00
    int a; // +0x74
    int b; // +0x78
    int c; // +0x7c
    void FUN_002c4200(int* x, int* y, int* z);
};
// matches/0x002c6d60.cpp (stub S_2c6d60), size 0x8
struct S_2c6d60 {
    unsigned short x[4]; // +0x00
    S_2c6d60* FUN_002c6d60(const S_2c6d60* src);
};
// matches/0x002c6f30.cpp (stub C_2c6f30), size 0x1c (0x20)
struct C_2c6f30 {
    char pad[0x18]; // +0x00
    float* arr[1]; // +0x18
    void FUN_002c6f30(int a, float* b, int c, float d);
};
// matches/0x002c7070.cpp (stub Thing_2c7070), size 0x30 (0x50)
struct Thing_2c7070 {
    char pad0[0x0c]; // +0x00
    int count; // +0x0c
    void* a; // +0x10
    void* b; // +0x14 (+0x18)
    void* c[4]; // +0x18 (+0x20)
    void* d[2]; // +0x28 (+0x40)
    void FUN_002c7070();
};
// equivalent/0x002c7120.cpp (stub ItemBuffer), size 0x14 (0x18)
struct ItemBuffer_2c7120 {
    char pad0[8]; // +0x00
    unsigned flags; // +0x08
    unsigned count; // +0x0c
    void* items; // +0x10
    void FUN_002c7120();
};
// equivalent/0x002c71b0.cpp (stub Buffer), size 0x18 (0x20)
struct Buffer_2c71b0 {
    char pad0[8]; // +0x00
    unsigned flags; // +0x08
    unsigned count; // +0x0c
    char pad10[4]; // +0x10
    void* data; // +0x14 (+0x18)
    void FUN_002c71b0();
};
// matches/0x002c7240.cpp (stub Obj_2c7240), size 0x1c (0x20)
struct Obj_2c7240 {
    char pad[8]; // +0x00
    unsigned int flags; // +0x08
    int count; // +0x0c
    char pad2[8]; // +0x10
    void* entries[1]; // +0x18
    void FUN_002c7240(int);
};
// equivalent/0x002c72e0.cpp (stub Object), size 0x2c (0x30)
struct Object_2c72e0 {
    char pad0[8]; // +0x00
    unsigned int flags; // +0x08
    int count; // +0x0c
    char pad10[0x18]; // +0x10
    void* entries[1]; // +0x28
    void FUN_002c72e0(int index);
};
// matches/0x002d0c80.cpp (stub X_2d0c80), size 0x14 (0x20)
struct X_2d0c80 {
    char pad[12]; // +0x00
    void** begin; // +0x0c (+0x10)
    void** end; // +0x10 (+0x18)
    void FUN_002d0c80();
};
// matches/0x002d0eb0.cpp (stub Buffer_2d0eb0), size 0x8 (0x10)
struct Buffer_2d0eb0 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002d0eb0(unsigned int count, void* arg);
};
// matches/0x002d1240.cpp (stub C_2d1240), size 0x28
struct C_2d1240 {
    char pad0[0x14]; // +0x00
    int a; // +0x14
    char pad1[0x0c]; // +0x18
    int b; // +0x24
    void FUN_002d1240(int x, int y);
};
// matches/0x002d1260.cpp (stub Target_2d1260), size 0x1c
struct Target_2d1260 {
    char pad0[8]; // +0x00
    unsigned a; // +0x08
    char pad1[12]; // +0x0c
    unsigned b; // +0x18
    void FUN_002d1260(unsigned x, unsigned y);
};
// matches/0x002d1280.cpp (stub C_2d1280), size 0x20
struct C_2d1280 {
    char pad0[0xc]; // +0x00
    int a; // +0x0c
    char pad1[0xc]; // +0x10
    int b; // +0x1c
    void FUN_002d1280(int x, int y);
};
// matches/0x002d12a0.cpp (stub C_2d12a0), size 0x24
struct C_2d12a0 {
    char pad0[0x10]; // +0x00
    int a; // +0x10
    char pad1[0x0c]; // +0x14
    int b; // +0x20
    void FUN_002d12a0(int x, int y);
};
// equivalent/0x002d49c0.cpp (stub Random), size 0x8
struct Random_2d49c0 {
    unsigned int first; // +0x00
    unsigned int second; // +0x04
    int FUN_002d49c0(int base, int range);
};
// matches/0x002df7e0.cpp (stub Object), size 0x5c
struct Object_2df7e0 {
    hulk_intptr FUN_002df7e0();
    char pad[0x58]; // +0x00
    int mValue; // +0x58
};
// matches/0x002df890.cpp (stub Thing_2df890), size 0x14
struct Thing_2df890 {
    char pad[0x10]; // +0x00
    int value; // +0x10
    void FUN_002df890(int x);
};
// matches/0x002e16f0.cpp (stub Buffer_2e16f0), size 0x8 (0x10)
struct Buffer_2e16f0 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002e16f0(unsigned int count, void* arg);
};
// matches/0x002e18c0.cpp (stub Object), size 0x1
struct Object_2e18c0 {
    int FUN_002e16f0(int value, int* output);
    int FUN_002e18c0(int value);
};
// equivalent/0x002e5330.cpp (stub SortedArray), size 0x10 (0x18)
struct SortedArray_2e5330 {
    char pad0[8]; // +0x00
    unsigned int* begin; // +0x08
    unsigned int* end; // +0x0c (+0x10)
    bool FUN_002e5330(unsigned int key, unsigned int* outIndex);
};
// equivalent/0x002e56a0.cpp (stub Buffer), size 0x8 (0x10)
struct Buffer_2e56a0 {
    void* data; // +0x00
    void* end; // +0x04 (+0x08)
    bool FUN_002e56a0(unsigned count, hulk_intptr value);
};
// equivalent/0x002e5700.cpp (stub Buffer), size 0x8 (0x10)
struct Buffer_2e5700 {
    void* begin; // +0x00
    void* end; // +0x04 (+0x08)
    bool FUN_002e5700(unsigned int count, void* source);
};
// equivalent/0x002e6160.cpp (stub Buffer), size 0x8 (0x10)
struct Buffer_2e6160 {
    void* data; // +0x00
    void* end; // +0x04 (+0x08)
    bool FUN_002e6160(unsigned int count, hulk_intptr value);
};
// matches/0x002eccd0.cpp (stub Cls_2eccd0), size 0x34
struct Cls_2eccd0 {
    char pad[0x2c]; // +0x00
    float a; // +0x2c
    float b; // +0x30
    void FUN_002eccd0(float f);
};
// equivalent/0x002ece90.cpp (stub ScaledVec), size 0x2c
struct ScaledVec_2ece90 {
    char pad00[0x10]; // +0x00
    float x, y, z; // +0x10
    float sx, sy, sz; // +0x1c
    float length; // +0x28
    void FUN_002ece90(float vx, float vy, float vz);
};
// matches/0x002ed6e0.cpp (stub Obj_2ed6e0), size 0xb0
struct Obj_2ed6e0 {
    char pad[0xb0]; // +0x00
    void FUN_002ed6e0(unsigned int arg);
};
// matches/0x002edc00.cpp (stub ThisWrap_002edc00), size 0x1
struct ThisWrap_002edc00 {
    unsigned char FUN_002ed7a0(unsigned int);
    unsigned char FUN_002edc00(hulk_uintptr param_1);
};
// matches/0x002ede00.cpp (stub Buffer_2ede00), size 0xc (0x18)
struct Buffer_2ede00 {
    void* p; // +0x00
    void* begin; // +0x04 (+0x08)
    void* end; // +0x08 (+0x10)
    void FUN_002ede00(int n);
};
// matches/0x002eefc0.cpp (stub Obj_2eefc0), size 0x6c; (x64t9-pw) the physics world's body pool (0x002eee10): its
// words as decls/physics_world.h's HulkBodyPool has them (vectors of begin, end, capacity and a 4-byte word; the counts
// are ints), so that the 64-bit offsets are the record's (unk_2ed240.cpp checks them)
struct Obj_2eefc0 {
    void Base();
    void FUN_002eefc0();
    void* p0; // +0x00
    void* p4; // +0x04
    void* p8; // +0x08
    int pc; // +0x0c
    void* p10; // +0x10
    void* p14; // +0x14
    char pad18[0x0c]; // +0x18
    void* p24; // +0x24
    int p28; // +0x28
    void* p2c; // +0x2c
    void* p30; // +0x30
    void* p34; // +0x34
    int p38; // +0x38
    void* p3c; // +0x3c
    void* p40; // +0x40
    void* p44; // +0x44
    int p48; // +0x48
    void* p4c; // +0x4c
    void* p50; // +0x50
    void* p54; // +0x54
    int p58; // +0x58
    void* p5c; // +0x5c
    void* p60; // +0x60
    void* p64; // +0x64
    int p68; // +0x68
};
// matches/0x002ee6b0.cpp (stub Obj_2ee6b0), size 0x6d
// (x64t9-pw) the physics world (DAT_00554c14): its body pool, then the flag (decls/physics_world.h HulkPhysicsWorld)
struct Obj_2ee6b0 {
    Obj_2eefc0 pool; // +0x00
    unsigned char flag; // +0x6c
    void callee(int);
    void FUN_002ee6b0(hulk_intptr);
};
// matches/0x002f2700.cpp (stub Obj), size 0x1c
struct Obj_2f2700 {
    char pad[8]; // +0x00
    float a; // +0x08
    char pad2[12]; // +0x0c
    float b; // +0x18
    void FUN_002f2700(float v);
};
// matches/0x002f2730.cpp (stub Obj_2f2730), size 0x20
struct Obj_2f2730 {
    char pad[8]; // +0x00
    int m8; // +0x08
    int mc; // +0x0c
    char pad2[0x18 - 0x10]; // +0x10
    int m18; // +0x18
    int m1c; // +0x1c
    void FUN_002f2730(int v);
};
// matches/0x002f2a80.cpp (stub PhysicsTable_2f2a80), size 0x1
struct PhysicsTable_2f2a80 {
    void FUN_002f27c0(unsigned __int64, float, float, float, float);
    void FUN_002f2a80();
};
// matches/0x002f2cb0.cpp (stub Obj_2f2cb0), size 0x804
struct Obj_2f2cb0 {
    int pad[3]; // +0x00
    int data[509]; // +0x0c
    int end; // +0x800
    void finish();
    void FUN_002f2cb0();
};
// equivalent/0x002f32b0.cpp (stub Axis), size 0x64
struct Axis_2f32b0 {
    char pad00[0x44]; // +0x00
    float x; // +0x44
    float y; // +0x48
    float z; // +0x4c
    char pad50[0x60 - 0x50]; // +0x50
    int dominant; // +0x60
    void FUN_002f32b0();
};
// matches/0x002f3360.cpp (stub Box_2f3360), size 0x18
struct Box_2f3360 {
    float v[6]; // +0x00
    unsigned char FUN_002f3360(Box_2f3360* b);
};
// equivalent/0x002f3960.cpp (stub Quantizer), size 0x48 (0x50)
struct Quantizer_2f3960 {
    char pad0[0x44]; // +0x00
    float *scale; // +0x44 (+0x48)
    void FUN_002f3960(unsigned short *out, const float *in);
};
// matches/0x002f3c60.cpp (stub T_2f3c60), size 0x18
struct T_2f3c60 {
    char d[0x18]; // +0x00
    void Dtor();
    T_2f3c60* FUN_002f3c60(unsigned char f);
};
// matches/0x002f8d90.cpp (stub Thing_2f8d90), size 0x44
struct Thing_2f8d90 {
    void FUN_002f8d90(int* a, int* c, int* b, int* e, int d, int* f);
    int m[17]; // +0x00
};
// equivalent/0x002f8ec0.cpp (stub Obj), size 0x1
struct Obj_2f8ec0 {
    void FUN_002f8d90(int, int, int, int, int, int);
    Obj_2f8ec0* FUN_002f8ec0(int, int, hulk_intptr, int, int, hulk_intptr);
};
// matches/0x002f8ef0.cpp (stub X_2f8ef0), size 0x14
struct X_2f8ef0 {
    unsigned int a, b, c, d; // +0x00
    unsigned char e; // +0x10
    X_2f8ef0* FUN_002f8ef0(hulk_uintptr, hulk_uintptr);
};
// matches/0x002f90c0.cpp (stub Vec_2f90c0), size 0x18
struct Vec_2f90c0 {
    float f[6]; // +0x00
    bool FUN_002f90c0(Vec_2f90c0* b);
};
// matches/0x002f9340.cpp (stub Buffer), size 0xc (0x18)
struct Buffer_2f9340 {
    short* start; // +0x00
    short* current; // +0x04 (+0x08)
    short* end; // +0x08 (+0x10)
    bool FUN_002f9340(unsigned int count);
};
// matches/0x002f9930.cpp (stub Buffer_2f9930), size 0xc (0x18)
struct Buffer_2f9930 {
    char pad0[4]; // +0x00
    unsigned short* cur; // +0x04 (+0x08)
    unsigned short* end; // +0x08 (+0x10)
    void FUN_002f9930(unsigned short*, int, hulk_intptr);
};
// equivalent/0x002f9a00.cpp (stub WideVector), size 0xc (0x18)
struct WideVector_2f9a00 {
    unsigned short* first; // +0x00
    unsigned short* last; // +0x04 (+0x08)
    unsigned short* cap; // +0x08 (+0x10)
    WideVector_2f9a00* FUN_002f9a00(const WideVector_2f9a00* other);
};
// matches/0x002f9b60.cpp (stub Buffer_2f9b60), size 0x8 (0x10)
struct Buffer_2f9b60 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    bool FUN_002f9b60(unsigned int count, void* arg);
};
// equivalent/0x002fa080.cpp (stub Buffer), size 0x8 (0x10)
struct Buffer_2fa080 {
    char* start; // +0x00
    char* end; // +0x04 (+0x08)
    bool FUN_002fa080(unsigned int count, void* value);
};
// equivalent/0x002fbf20.cpp (stub AxisRemap), size 0x78
struct AxisRemap_2fbf20 {
    char pad0[0x38]; // +0x00
    int snapped; // +0x38
    char pad3c[0x48 - 0x3c]; // +0x3c
    float scale[3]; // +0x48
    float m[3][3]; // +0x54
    void FUN_002fbf20();
};
// matches/0x002fc6f0.cpp (stub C_2fc6f0), size 0x10
struct C_2fc6f0 {
    char pad[0x10]; // +0x00
    hulk_intptr FUN_002fc6f0();
};
// matches/0x002fcaf0.cpp (stub V), size 0x1c
struct V_2fcaf0 {
    float a; // +0x00
    float b; // +0x04
    float c; // +0x08
    float d; // +0x0c
    float e; // +0x10
    float f; // +0x14
    float g; // +0x18
    void FUN_002fcaf0(V_2fcaf0*);
};
// matches/0x002fcb30.cpp (stub V), size 0x1c
struct V_2fcb30 {
    int pad; // +0x00
    float x1, x2, x3, x4, x5, x6; // +0x04
    void FUN_002fcb30(V_2fcb30*, V_2fcb30*);
};
// matches/0x002fcb80.cpp (stub X_2fcb80), size 0x1c
struct X_2fcb80 {
    char pad[4]; // +0x00
    float a[6]; // +0x04
    void FUN_002fcb80(float);
};
// matches/0x002fd020.cpp (stub Transform_2fd020), size 0x1c
struct Transform_2fd020 {
    char pad0[4]; // +0x00
    float m04, m08, m0c, m10, m14, m18; // +0x04
    void FUN_002fd020(float*, float*);
};
// matches/0x002fd0a0.cpp (stub C_2fd0a0), size 0x18
struct C_2fd0a0 {
    volatile int pad[6]; // +0x00
    void FUN_002fd0a0();
};
// equivalent/0x002fd0c0.cpp (stub Sym3), size 0x1c
struct Sym3_2fd0c0 {
    char pad0[4]; // +0x00
    float xx; // +0x04
    float xy; // +0x08
    float xz; // +0x0c
    float yy; // +0x10
    float yz; // +0x14
    float zz; // +0x18
    void FUN_002fd0c0(const Sym3_2fd0c0 *a);
};
// matches/0x002fd4a0.cpp (stub C_2fd4a0), size 0x74 (0x78)
struct C_2fd4a0 {
    char pad[0x70]; // +0x00
    int* p; // +0x70
    void FUN_002fd4a0();
};
// matches/0x002fd730.cpp (stub Obj), size 0x64 (0x68)
struct Obj_2fd730 {
    void* context; // +0x00
    char data[24]; // +0x04 (+0x08)
    unsigned char flag; // +0x1c (+0x20)
    char pad1[3]; // +0x1d (+0x21)
    char output[64]; // +0x20 (+0x24)
    unsigned int value; // +0x60 (+0x64)
    void FUN_002fd730();
};
// matches/0x00300b50.cpp (stub Obj_300b50), size 0x48 (0x70)
struct Obj_300b50 {
    void Init();
    void* p0; // +0x00
    void* q0; // +0x04 (+0x08)
    char x[8]; // +0x08 (+0x10)
    void* p1; // +0x10 (+0x18)
    void* q1; // +0x14 (+0x20)
    char y[8]; // +0x18 (+0x28)
    void* p2; // +0x20 (+0x30)
    void* q2; // +0x24 (+0x38)
    char z[8]; // +0x28 (+0x40)
    void* p3; // +0x30 (+0x48)
    void* q3; // +0x34 (+0x50)
    char w[8]; // +0x38 (+0x58)
    void* p4; // +0x40 (+0x60)
    void* q4; // +0x44 (+0x68)
    void FUN_00300b50();
};
// equivalent/0x00300d80.cpp (stub Item_300d80), size 0x6c (0x98)
struct Item_300d80 {
    void* a; // +0x00
    void* aEnd; // +0x04 (+0x08)
    char pad0[8]; // +0x08 (+0x10)
    void* b; // +0x10 (+0x18)
    void* bEnd; // +0x14 (+0x20)
    char pad1[8]; // +0x18 (+0x28)
    void* c; // +0x20 (+0x30)
    void* cEnd; // +0x24 (+0x38)
    char pad2[8]; // +0x28 (+0x40)
    void* d; // +0x30 (+0x48)
    void* dEnd; // +0x34 (+0x50)
    char pad3[8]; // +0x38 (+0x58)
    void* e; // +0x40 (+0x60)
    void* eEnd; // +0x44 (+0x68)
    char pad4[36]; // +0x48 (+0x70)
    void FUN_00300360();
    void FUN_00300b50();
    void* FUN_00300d80(unsigned char flags);
};
// matches/0x003012d0.cpp (stub C_3012d0), size 0x1
struct C_3012d0 {
    bool Check(int, int);
    void Pair(int, int);
    void Finish(int, int);
    void FUN_003012d0(hulk_intptr, hulk_intptr);
};
// matches/0x00302ed0.cpp (stub Obj), size 0x14
struct Obj_302ed0 {
    char pad[8]; // +0x00
    int a; // +0x08
    int b; // +0x0c
    int c; // +0x10
    void FUN_00302ed0(hulk_intptr x, hulk_intptr y, hulk_intptr z);
    void Other(int x, int y);
};
// matches/0x00302ef0.cpp (stub Thing_302ef0), size 0x40
struct Thing_302ef0 {
    char pad0[4]; // +0x00
    int a; // +0x04
    int b; // +0x08
    char pad10[0x30]; // +0x0c
    int c; // +0x3c
    void Init();
    void FUN_00302ef0(hulk_intptr x, hulk_intptr y, hulk_intptr z);
};
// matches/0x003037e0.cpp (stub Obj_3037e0), size 0x8
struct Obj_3037e0 {
    int mFirst; // +0x00
    int mSecond; // +0x04
    void FUN_003037e0();
};
// equivalent/0x00304300.cpp (stub Buffer), size 0xc (0x18)
struct Buffer_304300 {
    void* begin; // +0x00
    void* end; // +0x04 (+0x08)
    void* capacity; // +0x08 (+0x10)
    Buffer_304300* FUN_00304300();
};
// matches/0x00304740.cpp (stub C_304740), size 0x20
struct C_304740 {
    char pad[0x1c]; // +0x00
    int value; // +0x1c
    void FUN_00304740(hulk_intptr x);
};
// matches/0x003048a0.cpp (stub Buffer_3048a0), size 0x10 (0x18)
struct Buffer_3048a0 {
    int mSize; // +0x00
    int mCapacity; // +0x04
    void* mData; // +0x08
    char _pad; // +0x0c (+0x10)
    char mFlag; // +0x0d (+0x11)
    char _pad2[2]; // +0x0e (+0x12)
    void FUN_003048a0(int newCapacity);
};
// matches/0x00308a70.cpp (stub C_308a70), size 0x64
struct C_308a70 {
    char pad[0x60]; // +0x00
    int value; // +0x60
    void FUN_00308a70(hulk_intptr x);
};
// matches/0x00308e00.cpp (stub C_308e00), size 0x48
struct C_308e00 {
    char pad[0x40]; // +0x00
    int a; // +0x40
    int b; // +0x44
    void FUN_00308e00();
};
// matches/0x00308e10.cpp (stub C_308e10), size 0x200 (0x208)
struct C_308e10 {
    char pad[0x1f8]; // +0x00
    char* items; // +0x1f8
    int count; // +0x1fc (+0x200)
    bool FUN_00308e10(int index, unsigned char value);
};
// equivalent/0x00309b20.cpp (stub Node), size 0x20 (0x28)
struct Node_309b20 {
    char pad0[8]; // +0x00
    int value; // +0x08
    char pad1[16]; // +0x0c
    Node_309b20* next; // +0x1c (+0x20)
    bool FUN_00309b20(Node_309b20* other);
};
// matches/0x0030a130.cpp (stub Buffer_30a130), size 0xc (0x18)
struct Buffer_30a130 {
    int* begin; // +0x00
    int* end; // +0x04 (+0x08)
    int* limit; // +0x08 (+0x10)
    bool FUN_0030a130(int n);
};
// matches/0x0030a260.cpp (stub C_30a260), size 0x1c
struct C_30a260 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    void FUN_0030a260(hulk_intptr);
};
// equivalent/0x0030c580.cpp (stub Buffer_30c580), size 0xc (0x18)
struct Buffer_30c580 {
    unsigned int* begin; // +0x00
    unsigned int* end; // +0x04 (+0x08)
    unsigned int* capacityEnd; // +0x08 (+0x10)
    bool FUN_0030a130(unsigned int count);
    Buffer_30c580* FUN_0030c580(Buffer_30c580* source);
};
// equivalent/0x0030c8c0.cpp (stub Obj_30c8c0), size 0x15c
struct Obj_30c8c0 {
    char pad0[0xf8]; // +0x00
    char b0; // +0xf8
    int a[0x15]; // +0xfc
    char c0; // +0x150
    char c1; // +0x151
    char pad152[2]; // +0x152
    int d0; // +0x154
    int d1; // +0x158
    void FUN_0030c690(Obj_30c8c0 *src);
    Obj_30c8c0 * FUN_0030c8c0(Obj_30c8c0 *src);
};
// equivalent/0x0030d850.cpp (stub Range), size 0x14
struct Range_30d850 {
    unsigned int low, lowValue, high, highValue, extra; // +0x00
    void FUN_0030d850(unsigned int first, unsigned int firstValue, unsigned int second, unsigned int secondValue, hulk_uintptr last);
};
// matches/0x0030e190.cpp (stub A_30e190), size 0x10
struct A_30e190 {
    char pad[12]; // +0x00
    int value; // +0x0c
    void refresh();
    void FUN_0030e190(int);
};
// matches/0x0030e8a0.cpp (stub Obj_30e8a0), size 0x48
struct Obj_30e8a0 {
    char pad[0x38]; // +0x00
    float a; // +0x38
    float b; // +0x3c
    float c; // +0x40
    int state; // +0x44
    void FUN_0030e8a0();
};
// matches/0x0030ec20.cpp (stub A_30ec20), size 0x10
struct A_30ec20 {
    char pad[12]; // +0x00
    int value; // +0x0c
    void FUN_0030ec20(int x);
};
// matches/0x0030ec70.cpp (stub Buffer_30ec70), size 0x14 (0x18)
struct Buffer_30ec70 {
    char pad[12]; // +0x00
    int count; // +0x0c
    unsigned int* data; // +0x10
    bool FUN_0030ec70(hulk_uintptr);
};
// matches/0x0030ee70.cpp (stub A_30ee70), size 0xbc
struct A_30ee70 {
    char pad[0xBC]; // +0x00
    void Init();
    void Finish();
    void FUN_0030ee70(hulk_intptr);
};
// matches/0x0030efa0.cpp (stub C_30efa0), size 0xc0
struct C_30efa0 {
    char pad[0xbc]; // +0x00
    int value; // +0xbc
    void first();
    void second(int);
    void third();
    void FUN_0030efa0(hulk_intptr);
};
// matches/0x0030f140.cpp (stub Obj_30f140), size 0x54
struct Obj_30f140 {
    unsigned a[21]; // +0x00
    void FUN_0030f140(Obj_30f140* src);
};
// matches/0x0030f450.cpp (stub C_30f450), size 0xc (0x10)
struct C_30f450 {
    int pad[2]; // +0x00
    void* ptr; // +0x08
    int FUN_0030f450();
};
// matches/0x00310460.cpp (stub C_310460), size 0x200 (0x208)
struct C_310460 {
    char pad[0x1fc]; // +0x00
    void** arr; // +0x1fc (+0x200)
    bool FUN_00310460(int index, char value);
};
// matches/0x00311060.cpp (stub C_311060), size 0x214
struct C_311060 {
    char pad[0x20c]; // +0x00
    int a; // +0x20c
    int b; // +0x210
    void FUN_00311060();
};
// equivalent/0x00312ed0.cpp (stub Groups), size 0x4 (0x8)
struct Groups_312ed0 {
    short* parents; // +0x00
    int FUN_00312ed0(int count, short* output);
};
// matches/0x00319c80.cpp (stub DataBlock_319c80), size 0x60
struct DataBlock_319c80 {
    int m00, m04, m08, m0c, m10, m14, m18, m1c; // +0x00
    int m20, m24, m28, m2c, m30, m34, m38, m3c; // +0x20
    int m40, m44, m48, m4c, m50, m54, m58, m5c; // +0x40
    DataBlock_319c80* FUN_00319c80(const DataBlock_319c80* src);
};
// matches/0x00319d20.cpp (stub Obj_319d20), size 0xa4
struct Obj_319d20 {
    char pad[0xa0]; // +0x00
    int value; // +0xa0
    bool FUN_00319d20();
};
// matches/0x00319ef0.cpp (stub Thing_319ef0), size 0xa4
struct Thing_319ef0 {
    char pad0[0x10]; // +0x00
    int state; // +0x10
    char pad1[0x8c]; // +0x14
    int flag; // +0xa0
    void Change(int, int*);
    void FUN_00319ef0();
};
// matches/0x0031a380.cpp (stub Thing_31a380), size 0xa4
struct Thing_31a380 {
    int mVptr, mCopy; // +0x00
    char p[0x30 - 8]; // +0x08
    int u, v; // +0x30
    char p2[0x70 - 0x38]; // +0x38
    int a, b, c, d, e; // +0x70
    char p3[4]; // +0x84
    int x[7]; // +0x88
    void FUN_0031a380(int, int, int, int, int);
};
// matches/0x0031b180.cpp (stub A_31b180), size 0x435
struct A_31b180 {
    // (x64t5) pure3d::d3dDisplay's words up to its device pointer (gen/pure3d.h), so that the 64-bit offsets follow it
    void* vftable; int w04, w08, w0c; void* device; // +0x00
    char pad[0x434 - 0x14]; // +0x14
    unsigned char value; // +0x434
    unsigned char FUN_0031b180();
};
// matches/0x0031b360.cpp (stub C_31b360), size 0x490
struct C_31b360 {
    // (x64t5) pure3d::d3dDisplay's words up to its device pointer (gen/pure3d.h), so that the 64-bit offsets follow it
    void* vftable; int w04, w08, w0c; void* device; // +0x00
    char pad[0x484 - 0x14]; // +0x14
    int a; // +0x484
    int b; // +0x488
    int c; // +0x48c
    void FUN_0031b360(int* x, int* y, int* z);
};
// equivalent/0x0031b390.cpp (stub GammaControl), size 0x490
struct GammaControl_31b390 {
    // (x64t5) pure3d::d3dDisplay's words up to its device pointer (gen/pure3d.h), so that the 64-bit offsets follow it
    void* vftable; int w04, w08, w0c; void* device; // +0x00
    char pad0[0x12c - 0x14]; // +0x14
    unsigned char srcRed[256]; // +0x12c
    unsigned char srcGreen[256]; // +0x22c
    unsigned char srcBlue[256]; // +0x32c
    char pad1[0x484 - 0x42c]; // +0x42c
    float gammaR; // +0x484
    float gammaG; // +0x488
    float gammaB; // +0x48c
    void FUN_0031b390(float r, float g, float b);
};
// matches/0x0031eb70.cpp (stub Obj_31eb70), size 0x3ec
struct Obj_31eb70 {
    void* vftable; // +0x00 (a pddiLightingState: the vftable first)
    char block[8][0x7c]; // +0x04
    unsigned int tail[2]; // +0x3e4
    void FUN_0031eb70(const Obj_31eb70*);
};
// matches/0x00320d00.cpp (stub Holder_320d00), size 0x184
struct Holder_320d00 {
    char pad[0x184]; // +0x00
    bool FUN_00320d00(int value);
};
// matches/0x00326b00.cpp (stub Obj_326b00), size 0x6c
struct Obj_326b00 {
    char pad[0x10]; // +0x00
    unsigned long texA; // +0x10
    unsigned long texB; // +0x14
    unsigned long texC; // +0x18
    char pad2[0x4c]; // +0x1c
    unsigned long palette; // +0x68
    void FUN_00326b00(unsigned long);
};
// matches/0x00327130.cpp (stub Buffer_327130), size 0x30
struct Buffer_327130 {
    char pad0[0x20]; // +0x00
    int count; // +0x20
    char pad24[8]; // +0x24
    int resource; // +0x2c
    void FUN_00327130(int n);
};
// matches/0x00328250.cpp (stub C_328250), size 0x4
struct C_328250 {
    int value; // +0x00
    C_328250* FUN_00328250(hulk_intptr x);
};
// equivalent/0x003285d0.cpp (stub AccumulatorSource), size 0x98
struct AccumulatorSource_3285d0 {
    char padding[0x80]; // +0x00
    float x, y, z, w; // +0x80
    unsigned char red, green, blue, alpha; // +0x90
    unsigned char enabled; // +0x94
    void FUN_003285d0(unsigned int unused);
};
// equivalent/0x00328f10.cpp (stub State_328f10), size 0x124
struct State_328f10 {
    void* context; // +0x00 (the d3dContext: 0x00328fc0)
    int handle; // +0x04
    void* values08[4]; // +0x08 (the stages' textures)
    unsigned indices18[4]; // +0x18
    unsigned values28[4]; // +0x28
    unsigned values38[4]; // +0x38
    unsigned enabled48; // +0x48
    unsigned char flag4c; // +0x4c
    char reserved4d[7]; // +0x4d
    unsigned enabled54; // +0x54
    unsigned value58; // +0x58
    unsigned char flag5c; // +0x5c
    char reserved5d[3]; // +0x5d
    unsigned mode60; // +0x60
    unsigned values64[4]; // +0x64
    unsigned values74[4]; // +0x74
    unsigned values84[4]; // +0x84
    unsigned values94[4]; // +0x94
    unsigned valuesa4[4]; // +0xa4
    unsigned valuesb4[4]; // +0xb4
    unsigned valuesc4[4]; // +0xc4
    unsigned valuesd4[4]; // +0xd4
    unsigned valuese4[4]; // +0xe4
    unsigned valuesf4[4]; // +0xf4
    unsigned char flag104; // +0x104
    unsigned char flag105; // +0x105
    char reserved106[2]; // +0x106
    unsigned value108; // +0x108
    unsigned value10c; // +0x10c
    unsigned enabled110; // +0x110
    float scale114; // +0x114
    unsigned value118; // +0x118
    unsigned value11c; // +0x11c
    float scale120; // +0x120
    void FUN_00328bf0();
    void FUN_00328f10();
};
// matches/0x00329320.cpp (stub Registry_329320), size 0xc
struct Registry_329320 {
    char pad0[4]; // +0x00
    unsigned int count; // +0x04
    char pad8[4]; // +0x08
    void FUN_00329320(const char*, unsigned int);
};
// matches/0x00329400.cpp (stub Obj_329400), size 0x3d04
struct Obj_329400 {
    char pad[0x3d04]; // +0x00
    void FUN_00329400();
};
// matches/0x00329bb0.cpp (stub State_329bb0), size 0x84
struct State_329bb0 {
    char pad[0x64]; // +0x00
    int first[4]; // +0x64
    int second[4]; // +0x74
    void FUN_00329bb0(unsigned int);
};
// equivalent/0x00329c40.cpp (stub Device_329c40), size 0xa8
struct Device_329c40 {
    char pad[0x28]; // +0x00
    int texture[32]; // +0x28
    void FUN_00329c40(int stage, int value);
};
// equivalent/0x00329c90.cpp (stub Obj_329c90), size 0x3c
struct Obj_329c90 {
    char pad[0x38]; // +0x00
    int choices[1]; // +0x38
    void FUN_00329c90(int index, int value);
};
// matches/0x00329cf0.cpp (stub C_329cf0), size 0xa4
struct C_329cf0 {
    char pad[0x64]; // +0x00
    int a[8]; // +0x64
    int b[8]; // +0x84
    void FUN_00329cf0(int index, int value1, int value2);
};
// matches/0x00329d50.cpp (stub Obj_329d50), size 0x98
struct Obj_329d50 {
    char pad[0x94]; // +0x00
    int slots[1]; // +0x94
    void helper(int, int, int);
    void FUN_00329d50(int index, int a, int b, int value);
};
// matches/0x00329da0.cpp (stub C_329da0), size 0xf4
struct C_329da0 {
    char pad[0x74]; // +0x00
    int a[16]; // +0x74
    int b[16]; // +0xb4
    void FUN_00329da0(int, int, int);
};
// matches/0x00329e00.cpp (stub Obj_329e00), size 0x144
struct Obj_329e00 {
    char pad[0xc4]; // +0x00
    int values[32]; // +0xc4
    void Helper(int, int, int);
    void FUN_00329e00(int, int, int, int);
};
// matches/0x00329e50.cpp (stub Obj_329e50), size 0x104
struct Obj_329e50 {
    char pad[0x94]; // +0x00
    int a[12]; // +0x94
    int b[16]; // +0xc4
    void F1(int i, int x, int y);
    void F2(int i, int x, int y);
    void FUN_00329e50(int i, int x, int y, int v);
};
// matches/0x00329f20.cpp (stub Device_329f20), size 0x10c
struct Device_329f20 {
    char pad[0x108]; // +0x00
    unsigned int textureFactor; // +0x108
    void FUN_00329f20(unsigned int value);
};
// matches/0x0032a0c0.cpp (stub State_32a0c0), size 0x5c
struct State_32a0c0 {
    char pad[0x4c]; // +0x00
    unsigned char flag; // +0x4c
    char pad2[3]; // +0x4d
    int a; // +0x50
    int b; // +0x54
    int c; // +0x58
    void FUN_0032a0c0(unsigned char, int, int, int);
};
// matches/0x0032a190.cpp (stub Obj_32a190), size 0x110
struct Obj_32a190 {
    char pad0[0x5c]; // +0x00
    unsigned char mEnabled; // +0x5c
    int mMode; // +0x60
    char pad1[0x10c - 0x64]; // +0x64
    int mValue; // +0x10c
    void FUN_0032a190(unsigned char enabled, int mode, int value);
};
// equivalent/0x0032a5a0.cpp (stub ShaderState_32a5a0), size 0x94
struct ShaderState_32a5a0 {
    char pad[0x84]; // +0x00
    unsigned char enabled; // +0x84
    char pad2[3]; // +0x85
    float value; // +0x88
    char pad3[4]; // +0x8c
    int mode; // +0x90
    void FUN_0032a5a0();
};
// equivalent/0x0032b990.cpp (stub ShaderState_32b990), size 0x94
struct ShaderState_32b990 {
    char pad[0x88]; // +0x00
    unsigned char flag; // +0x88
    char gap[3]; // +0x89
    int mode; // +0x8c
    unsigned int value; // +0x90
    void FUN_0032b990();
};
// equivalent/0x0032db00.cpp (stub ShaderState_32db00), size 0x9c
struct ShaderState_32db00 {
    char pad[0x90]; // +0x00
    unsigned char enabled; // +0x90
    char pad2[3]; // +0x91
    int mode; // +0x94
    float value; // +0x98
    void FUN_0032db00();
};
// equivalent/0x003335e0.cpp (stub Obj_3335e0), size 0x74
struct Obj_3335e0 {
    char p0[0x18]; // +0x00
    unsigned int mode; // +0x18
    unsigned int activeMode; // +0x1c
    char p20[0x10]; // +0x20
    float scale; // +0x30
    float result; // +0x34
    unsigned int alpha; // +0x38
    char p3c[0xc]; // +0x3c
    unsigned char enabled; // +0x48
    char p49[7]; // +0x49
    unsigned int c50, c54, c58, c5c; // +0x50
    char p60[4]; // +0x60
    unsigned int c64, c68, c6c, c70; // +0x64
    void FUN_003335e0();
};
// matches/0x00333770.cpp (stub C_333770), size 0x1c
struct C_333770 {
    char pad[0x18]; // +0x00
    int value; // +0x18
    void FUN_00333770(int);
};
// matches/0x003352c0.cpp (stub Obj), size 0x10 (0x18)
struct Obj_3352c0 {
    char pad[12]; // +0x00
    char* text; // +0x0c (+0x10)
    void FUN_003352c0(const char* s);
};
// matches/0x00336d90.cpp (stub Obj), size 0x10
struct Obj_336d90 {
    int pad, a, b, c; // +0x00
    void FUN_00336d90();
};
// matches/0x00337070.cpp (stub Obj), size 0x1
struct Obj_337070 {
    char m4; // +0x00
    void FUN_00337070(char* s);
};
// matches/0x00337090.cpp (stub Thing_337090), size 0x48
struct Thing_337090 {
    char pad[0x44]; // +0x00
    int count; // +0x44
    void* FUN_00337090(int);
};
// matches/0x00337190.cpp (stub Thing_337190), size 0x48
struct Thing_337190 {
    char pad[0x44]; // +0x00
    int index; // +0x44
    void* FUN_00337190();
};
// matches/0x003371e0.cpp (stub Obj_3371e0), size 0x288
struct Obj_3371e0 {
    char pad[0x288]; // +0x00
    void FUN_003371e0();
};
// matches/0x003373e0.cpp (stub Table_3373e0), size 0xc
struct Table_3373e0 {
    int pad; // +0x00
    int count; // +0x04
    char first[1]; // +0x08
    char* FUN_003373e0(const char* s);
};
// matches/0x00337680.cpp (stub Thing_337680), size 0x510c
struct Thing_337680 {
    char pad0[4]; // +0x00
    int count; // +0x04
    char pad8[0x5108 - 8]; // +0x08
    int state; // +0x5108
    int Check(int);
    void Init(int);
    hulk_intptr FUN_00337680(hulk_intptr);
};
// matches/0x00337d50.cpp (stub A_337d50), size 0x10
struct A_337d50 {
    char pad0[4]; // +0x00
    int x; // +0x04
    char pad8[4]; // +0x08
    int y; // +0x0c
    void FUN_00337d50();
};
// equivalent/0x00337d60.cpp (stub Allocator), size 0x10
struct Allocator_337d60 {
    char pad[12]; // +0x00
    unsigned int offset; // +0x0c
    hulk_uintptr FUN_00337d60(unsigned int size, unsigned int alignment);
};
// equivalent/0x00337ec0.cpp (stub Object), size 0xc
struct Object_337ec0 {
    char pad[8]; // +0x00
    unsigned int kind; // +0x08
    int FUN_00337ec0();
};
// equivalent/0x00337f80.cpp (stub Value), size 0x10 (0x18)
struct Value_337f80 {
    char pad[8]; // +0x00
    unsigned int type; // +0x08
    char **text; // +0x0c (+0x10)
    unsigned int FUN_00337f80();
};
// matches/0x00338520.cpp (stub Obj_338520), size 0x18 (0x20)
struct Obj_338520 {
    int* vptr; // +0x00
    char pad[0x10]; // +0x04 (+0x08)
    void* m; // +0x14 (+0x18)
    void FUN_00338520();
};
// matches/0x003387a0.cpp (stub Obj_3387a0), size 0x833
struct Obj_3387a0 {
    char pad[0x832]; // +0x00
    char str[1]; // +0x832
    bool FUN_003387a0(char c);
};
// matches/0x003387d0.cpp (stub Obj_3387d0), size 0x837
struct Obj_3387d0 {
    char pad[0x836]; // +0x00
    char s[1]; // +0x836
    unsigned char FUN_003387d0(char c);
};
// matches/0x00338800.cpp (stub Obj), size 0x83b
struct Obj_338800 {
    char pad[0x83a]; // +0x00
    char text[1]; // +0x83a
    char Match(const char*, const char*, hulk_intptr);
    char* FUN_00338800(const char*);
};
// equivalent/0x00338860.cpp (stub Object), size 0x85b
struct Object_338860 {
    char pad[0x85a]; // +0x00
    char field; // +0x85a
    int FUN_00338860(hulk_intptr value);
};
// matches/0x003388c0.cpp (stub C_3388c0), size 0x822
struct C_3388c0 {
    char pad[0x820]; // +0x00
    unsigned char a; // +0x820
    unsigned char b; // +0x821
    void FUN_003388c0();
};
// matches/0x00338d80.cpp (stub Obj_338d80), size 0x1
struct Obj_338d80 {
    void A();
    void B();
    void FUN_00338d80();
};
} // namespace owners
#endif
