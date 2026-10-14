struct Block_30ee40 {
    unsigned int x[0x15];
};
struct Obj_30ee40 {
    char pad[0x68];
    Block_30ee40 data;
    int state;
    void Update();
    void Copy(const Block_30ee40*);
};
void Obj_30ee40::Copy(const Block_30ee40* src) {
    data = *src;
    state = 1;
    Update();
}