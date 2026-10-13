struct Obj {
    char pad[0x353];
    unsigned char m353;
    void Clear();
};
void Obj::Clear() {
    m353 = 0;
}
