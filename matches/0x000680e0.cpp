struct Obj {
    char pad[0x30];
    float value;
    char Fn(float x);
};
char Obj::Fn(float x) {
    value = x * 0.01745329252f;
    return 1;
}
