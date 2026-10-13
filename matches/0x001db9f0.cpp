struct Obj {
    char pad[0x34];
    int value;
    int Get();
};

int Obj::Get() {
    return value;
}
