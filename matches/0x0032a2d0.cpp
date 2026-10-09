class Dev {
    char pad[0x48];

  public:
    int state;
    void Do(unsigned char, unsigned char, char*);
};
class Obj {
    char pad0[0x14];

  public:
    Dev* dev;
    char pad18[0x30];
    unsigned char first;
    char pad49[3];
    int value;
    char pad50[0x2c];
    unsigned char second;
};
extern void __fastcall D3DDevice_SetRenderState_Simple(const char*, int);
extern int global;
void __fastcall FUN_0032a2d0(Obj* self) {
    int x = self->value;
    if (x != self->dev->state) {
        self->dev->state = x;
        int v = (*(int*)(0x4d4f24 + x * 4));
        D3DDevice_SetRenderState_Simple((const char*)0x4037c, v);
        global = v;
    }
    self->dev->Do(self->first, self->second, (char*)self + 0x50);
}