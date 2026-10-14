class Thing_7b480 {
  public:
    char pad[0x359c];
    int count;
    void step(int);
};
void __fastcall FUN_0007b480(Thing_7b480* self) {
    while (self->count > 0)
        self->step(0);
}