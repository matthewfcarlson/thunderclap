struct Obj {
    char pad[0x119];
    unsigned char Get();
};

unsigned char Obj::Get() {
    return pad[0x119];
}
