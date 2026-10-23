#include "gen/global.h"
struct A_1d4530 {
    char pad[8];
};
struct R_1d4530 {
    void Middle();
};
struct ScriptHandler_nv_1d4530 {
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
void __fastcall target(ScriptHandler* self) {
    if (!(*(unsigned char *)&self->f_1064)) {
        (*(unsigned char *)&self->f_1064) = 1;
        ((ScriptHandler_nv_1d4530*)(self))->Init((A_1d4530*)((char*)self + 8));
        ((ScriptHandler_nv_1d4530*)(self))->Run();
        g1_1d4530->First()->Middle();
        ((End_1d4530*)g2_1d4530->r)->Finish();
    }
}