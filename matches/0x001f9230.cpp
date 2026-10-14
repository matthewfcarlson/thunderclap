extern void InitText(char*, unsigned int, const char*);
extern const float gZero_1f9230;
extern const char gText_1f9230[];
class Sub_1f9230 {
  public:
    void Init(const float*);
};
class Obj_1f9230 {
  public:
    char pad0[8];
    int value;
    char padc[0x2c];
    unsigned char a, b;
    char pad3a[6];
    int x40, x44, x48, x4c;
    unsigned char x50, x51;
    unsigned short x52;
};
void __fastcall Target(Obj_1f9230* self) {
    self->value = 0;
    InitText((char*)self + 0xc, 0x20, gText_1f9230);
    self->x40 = 0;
    self->x44 = 0;
    self->x48 = 0;
    self->x4c = 0;
    self->a = 0xff;
    ((Sub_1f9230*)((char*)self + 0x30))->Init(&gZero_1f9230);
    self->x50 = 0;
    self->b = 0xff;
    self->x51 = 1;
    self->x52 = 0xffff;
}