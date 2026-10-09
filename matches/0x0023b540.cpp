class Chunk {
  public:
    char pad[0x28];
    int field;
    void Init(int);
};
extern int vtable;
Chunk* __fastcall Build(Chunk* self) {
    self->Init(3);
    *(int*)self = (int)&vtable;
    self->field = 0;
    return self;
}