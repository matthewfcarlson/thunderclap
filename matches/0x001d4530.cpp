struct A_1d4530 {
    char pad[8];
};
struct R_1d4530 {
    void Middle();
};
struct Obj_1d4530 {
    char pad[0x1064];
    unsigned char flag;
    void Init(A_1d4530*);
    void Run();
};
struct H {
    R_1d4530* First();
};
struct T_1d4530 {
    char pad[12];
    R_1d4530* r;
};
struct End_1d4530 {
    void Finish();
};
extern H* g1_1d4530;
extern T_1d4530* g2_1d4530;
void __fastcall target(Obj_1d4530* self) {
    if (!self->flag) {
        self->flag = 1;
        self->Init((A_1d4530*)((char*)self + 8));
        self->Run();
        g1_1d4530->First()->Middle();
        ((End_1d4530*)g2_1d4530->r)->Finish();
    }
}