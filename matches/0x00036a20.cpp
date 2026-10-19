struct Temp_36a20 {
    char data[16];
    bool Test();
};
struct Obj_36a20 {
    char pad[0x1d78];
    unsigned char flag;
    unsigned char result;
    void Make(Temp_36a20* t);
};
struct Global_36a20 {
    char pad[0x20];
    int x;
};
extern Global_36a20* gGlobal_36a20;
bool __stdcall CheckGlobal(Obj_36a20* o);
struct Single_36a20 { bool Test(Temp_36a20* t); };
Single_36a20* Convert();

void __fastcall Target(Obj_36a20* self) {
    Temp_36a20 temp;
    if (self->flag == 1)
        goto clear;
    if (gGlobal_36a20->x != 0 && CheckGlobal(self))
        goto clear;
    self->Make(&temp);
    self->result = Convert()->Test(&temp) ? 0 : 1;
    return;
clear:
    self->result = 0;
}
