struct Obj {
    char pad[0x64];
    float value;
    float Get();
};
float Obj::Get() {
    return value;
}
