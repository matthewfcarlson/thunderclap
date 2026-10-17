// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001d8160 @ 0x001d8160
struct ResultObject {
    virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
    virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
    virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual float slot36();
};
struct Inner { char pad[0x70]; void* object; };
struct Middle { char pad[0x10]; Inner* inner; };
extern char DAT_004c60bc;
extern char DAT_004c60e4;
ResultObject* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct Owner {
    char pad[0xa0]; Middle* middle;
    float FUN_001d8160();
};
float Owner::FUN_001d8160() {
    if (middle && middle->inner && middle->inner->object) {
        ResultObject* result = FUN_00344e74(middle->inner->object, 0, &DAT_004c60bc, &DAT_004c60e4, 0);
        if (result) return result->slot36();
    }
    return 1.0f;
}