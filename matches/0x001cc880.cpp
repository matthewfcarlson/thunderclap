struct Obj {
    char pad[0x119c];
    float value;
    float Get();
};
float Obj::Get() {
    return value;
}
