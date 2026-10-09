struct Temp {
    char data[16];
    bool Test();
};
struct Obj {
    char pad[0x1d78];
    unsigned char flag;
    unsigned char result;
    void Make(Temp* t);
};
struct Global {
    char pad[0x20];
    int x;
};
extern Global* gGlobal;
bool __stdcall CheckGlobal(Obj* o);
Temp* __stdcall Convert(Temp* t);

void __fastcall Target(Obj* self) {
    Temp temp;
    if (self->flag == 1)
        goto clear;
    if (gGlobal->x != 0 && CheckGlobal(self))
        goto clear;
    self->Make(&temp);
    Temp* p = Convert(&temp);
    self->result = p->Test() ? 0 : 1;
    return;
clear:
    self->result = 0;
}
