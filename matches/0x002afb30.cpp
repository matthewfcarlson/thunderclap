extern "C" char DAT_0042e30c[];
class Expression {
  public:
    char pad[0x14];
    int a;
    int b;
    void Init();
};
Expression* __fastcall FUN_002afb30(Expression* self) {
    self->Init();
    self->a = 0;
    self->b = 0;
    *(int*)self = ((int)DAT_0042e30c);
    return self;
}