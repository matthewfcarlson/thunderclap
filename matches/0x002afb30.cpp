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
    *(int*)self = 0x42e30c;
    return self;
}