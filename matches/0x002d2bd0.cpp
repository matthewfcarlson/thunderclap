extern "C" char DAT_00444152[];
struct Owner {
    int pad;
    int Find(int, int);
};
extern int vtab;
struct BlendState {
    int* vptr;
    int a, b, c;
    BlendState(Owner*);
};
BlendState::BlendState(Owner* arg) {
    a = 0;
    vptr = &vtab;
    b = 0;
    c = 0;
    if (arg) {
        b = arg->Find(((int)DAT_00444152), 0x31544c46);
        c = arg->Find(0x41564452, 0x31544c46);
    }
}