struct Global_2f7a60 {
    char pad[0x28];
    int a;
    char pad2[4];
    int b;
};
extern Global_2f7a60* g_2f7a60;
class Obj_2f7a60 {
  public:
    char pad[0xe8];
    int a;
    int b;
};
void __fastcall target(Obj_2f7a60* self) {
    self->a = g_2f7a60->b;
    self->b = g_2f7a60->a;
}