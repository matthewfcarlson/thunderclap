struct Block {
    unsigned int x[0x15];
};
struct Obj {
    char pad[0x68];
    Block data;
    int state;
    void Update();
    void Copy(const Block*);
};
void Obj::Copy(const Block* src) {
    data = *src;
    state = 1;
    Update();
}