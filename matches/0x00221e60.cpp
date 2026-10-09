struct Obj {
    char pad[0x50];
    int state;
    void Target(unsigned int);
};
struct Work {
    void First(Obj*);
    void Second(Obj*, unsigned int);
};
void Obj::Target(unsigned int arg) {
    char local[0x40];
    if (state == 1) {
        ((Work*)((char*)this + 0x40))->First(this);
        state = 0;
    }
    ((Work*)local)->Second(this, arg);
    struct Block {
        unsigned int a[16];
    };
    *(Block*)this = *(Block*)local;
    state = 2;
}