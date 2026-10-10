// cl-flags: /O2 /GR /GX

struct Param2 {
    char pad[0x2C];
    void* field_2C;
    char pad2[0xC];
    int field_3C;
    int field_40;
};

struct Param3 {
    char pad[0x34];
    void* field_34;
};

struct Out {
    int a;
    int b;
};

class ThisClass {
    char pad0[0x10];

  public:
    void* field_10;
    char pad1[0xFC];
    void* field_110;
    char pad2[0x17C];
    void* field_290;
    char pad3[0xC4];
    void* field_358;
    char pad4[0x28];
    void* field_384;
    char pad5[0x5C];
    void* field_3E4;
    char pad6[0x30];
    void* field_418;
    char pad7[0x6C];
    void* field_488;
    void* field_48C;

    void Func(Param2* p2, Param3* p3);
    void FUN_000b30c0(int, int, void*, void*, void*, void*, void*, void*, Out*);
};

void ThisClass::Func(Param2* p2, Param3* p3) {
    if (field_10) {
        Out out = {0, 0};
        FUN_000b30c0(0xB, 2, (void*)&field_110, (void*)&field_358, (void*)&field_384, field_48C, p2,
                     (void*)&p2->field_2C, &out);
        p2->field_3C = out.a;
        p2->field_40 = out.b;
        FUN_000b30c0(0xD, 2, (void*)&field_290, (void*)&field_3E4, (void*)&field_418, field_488, p3,
                     (void*)&p3->field_34, 0);
    }
}