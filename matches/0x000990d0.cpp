extern void* __cdecl thunk_FUN_0008d690(unsigned int);
struct Resource_990d0 {
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
    Resource_990d0* FUN_000ac3c0();
    void FUN_000a90f0(int index, unsigned int value);
    void FUN_000a9130(int index, unsigned int value);
    void FUN_000a9110(int index, unsigned int value);
};
struct Owner_990d0 {
    char padding[0xc0];
    Resource_990d0* resource;
    void FUN_000990d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                      unsigned int f);
};
void Owner_990d0::FUN_000990d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                         unsigned int f) {
    if (!resource) {
        Resource_990d0* allocated = static_cast<Resource_990d0*>(thunk_FUN_0008d690(0x178));
        resource = allocated ? allocated->FUN_000ac3c0() : 0;
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
