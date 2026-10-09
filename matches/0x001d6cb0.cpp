struct Thing {
    char pad[0x25c];
};
Thing* __fastcall Target(Thing* self) {
    return (Thing*)((char*)self + 0x25c);
}