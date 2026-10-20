struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4();
};
struct Object {
    char padding[0x14];
    float x, y, z;
    void FUN_00317610(int a, Receiver* receiver, int result, int value);
    void FUN_00301410(int a, Receiver* receiver, int value);
};
void Object::FUN_00301410(int a, Receiver* receiver, int value) {
    x *= -1.0f;
    y *= -1.0f;
    z *= -1.0f;
    FUN_00317610(a, receiver, receiver->slot4(), value);
}