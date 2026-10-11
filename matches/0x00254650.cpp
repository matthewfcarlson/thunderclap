extern "C" char DAT_0042a30c[];
class SeqEventSilence {
  public:
    int* vptr;
    int pad4;
    int a;
    int b;
    void Init();
};
SeqEventSilence* __fastcall FUN_00254650(SeqEventSilence* self) {
    self->Init();
    self->vptr = (int*)((int)DAT_0042a30c);
    self->a = 500;
    self->b = 1000;
    return self;
}