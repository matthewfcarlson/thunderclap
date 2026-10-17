struct Object {
    char pad[0x10];
    int value;
    char data[4];
    void FUN_001b83c0();
    void FUN_001b8350(void*, int);
};
void Object::FUN_001b83c0() {
    FUN_001b8350(data, value);
}