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
extern "C" bool __stdcall FUN_00025d30(Obj_36a20* o);
struct Single_36a20 { bool Test(Temp_36a20* t); };
extern "C" Single_36a20* FUN_001c3d90();

void __fastcall Target(Obj_36a20* self) {
    Temp_36a20 temp;
    if (self->flag == 1) {
        self->result = 0;
        return;
    }
    if (gGlobal_36a20->x != 0 && FUN_00025d30(self)) {
        self->result = 0;
        return;
    }
    self->Make(&temp);
    self->result = FUN_001c3d90()->Test(&temp) ? 0 : 1;
}
