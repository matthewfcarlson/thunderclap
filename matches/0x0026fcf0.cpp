extern int DAT_004cdbb0;
void* __cdecl FUN_00266e00(int, int);
struct Widget {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual void slot21(int);
    Widget* FUN_0026f570(int, int);
};
void __cdecl FUN_0026fcf0(Widget** result, int second, int third, int fourth) {
    DAT_004cdbb0 = third;
    Widget* allocated = (Widget*)FUN_00266e00(third, 0x1e4);
    Widget* object = allocated ? allocated->FUN_0026f570(second, third) : 0;
    *result = object;
    object->slot21(fourth);
}