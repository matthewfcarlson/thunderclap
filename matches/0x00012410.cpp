struct Obj {
    char pad[0x14];
    float value;
    float Get();
};
float Obj::Get() {
    return value;
}
