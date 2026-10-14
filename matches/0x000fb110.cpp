extern "C" int __cdecl GetThing();
extern "C" void __cdecl Setup(int, int, void*, void*, int);
extern int RTTI1_fb110;
extern int RTTI2_fb110;
struct Obj_fb110 {
    char pad[8];
    int field8;
    int fieldc;
    char pad10[4];
    unsigned char field14;
    unsigned char field15;
};
void __fastcall Target(Obj_fb110* self) {
    int x = GetThing();
    self->field8 = x;
    if (x == 0)
        self->field15 = 1;
    self->field14 = 0;
    self->fieldc = 0;
    Setup(x, 0, &RTTI2_fb110, &RTTI1_fb110, 0);
}