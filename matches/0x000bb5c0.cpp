class Sub { public: void Init(); void Fn(int a, int b); };
class Obj {
public:
    char pad[0x34];
    Sub* flag;
    char pad2[0x14];
    Sub* sub;
    void Finish();
};
void __fastcall target(Obj* self) {
    if (self->flag) {
        self->flag->Init();
        for (int i = 0x248; i <= 0x257; ++i) self->sub->Fn(i, 0);
        self->Finish();
    }
}
