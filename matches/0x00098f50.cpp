struct Resource_98f50 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    Resource_98f50* FUN_000a8400();
    void FUN_000a90f0(int index, unsigned value);
    void FUN_000a9130(int index, unsigned value);
    void FUN_000a9110(int index, unsigned value);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned size);
struct Owner_98f50 {
    char padding[0xb0];
    Resource_98f50* resource;
    void initialize(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f);
};
void Owner_98f50::initialize(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f) {
    if (!resource) {
        Resource_98f50* memory = (Resource_98f50*)thunk_FUN_0008d690(0x1c0);
        resource = memory ? memory->FUN_000a8400() : 0;
        resource->slot0();
        resource->slot28();
    }
    resource->FUN_000a90f0(0, a);
    resource->FUN_000a9130(0, b);
    resource->FUN_000a9110(0, c);
    resource->FUN_000a90f0(1, d);
    resource->FUN_000a9130(1, e);
    resource->FUN_000a9110(1, f);
}
