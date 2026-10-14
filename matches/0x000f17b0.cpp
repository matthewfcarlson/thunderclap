struct Receiver_f17b0 {
    void FUN_000f8b00(float);
};
struct Renderer_f17b0 {
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
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48(int);
};
struct Link_f17b0 {
    char pad[4];
    Renderer_f17b0* renderer;
};
struct Owner_f17b0 {
    char pad[8];
    Link_f17b0* link;
};
struct Object {
    char pad0[0x14];
    Owner_f17b0* owner;
    char pad1[0x138];
    float value;
    int state;
    char pad2[4];
    float minimum;
    float maximum;
    char pad3[4];
    int active;
    float decrement;
    char pad4[0x10];
    Receiver_f17b0* receiver;
    int FUN_000e9e60();
    int FUN_000f17b0();
};
int Object::FUN_000f17b0() {
    if (!active)
        value -= (decrement == 0.0f ? 1.0f : decrement);
    else
        state = 2;
    float result;
    if (value >= minimum && value <= maximum)
        result = value;
    else if (value > maximum)
        result = maximum;
    else
        result = minimum;
    Receiver_f17b0* r = receiver;
    value = result;
    if (r)
        r->FUN_000f8b00(result);
    owner->link->renderer->slot48(3);
    return FUN_000e9e60();
}