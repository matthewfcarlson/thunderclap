class Sub_bb5c0 {
  public:
    void Init();
    void Fn(int a, int b);
};
class Obj_bb5c0 {
  public:
    char pad[0x34];
    Sub_bb5c0* flag;
    char pad2[0x14];
    Sub_bb5c0* sub;
    void Finish();
};
void __fastcall target(Obj_bb5c0* self) {
    if (self->flag) {
        self->flag->Init();
        for (int i = 0x248; i <= 0x257; ++i)
            self->sub->Fn(i, 0);
        self->Finish();
    }
}
