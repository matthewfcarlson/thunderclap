struct Obj_221e60 {
    char pad[0x50];
    int state;
    void Target(unsigned int);
};
struct Work_221e60 {
    void First(Obj_221e60*);
    void Second(Obj_221e60*, unsigned int);
};
void Obj_221e60::Target(unsigned int arg) {
    char local[0x40];
    if (state == 1) {
        ((Work_221e60*)((char*)this + 0x40))->First(this);
        state = 0;
    }
    ((Work_221e60*)local)->Second(this, arg);
    struct Block {
        unsigned int a[16];
    };
    *(Block*)this = *(Block*)local;
    state = 2;
}