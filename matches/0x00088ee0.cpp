struct Obj {
    char pad[0xc];
    unsigned char value;
    unsigned char Get();
};
unsigned char Obj::Get() {
    return value;
}