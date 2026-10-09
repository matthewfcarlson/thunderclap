struct Obj {
    char pad[0x118];
    void Copy(void* p, unsigned int v);
    void Target(unsigned int v);
};
void Obj::Target(unsigned int v) {
    Copy((char*)this + 0xC, v);
    Copy((char*)this + 0x118, v);
}