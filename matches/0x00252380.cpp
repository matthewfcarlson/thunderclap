extern void* vtable_252380;
class SeqEventVarVolumeRand {
  public:
    void* vf;
    int pad;
    float a;
    float b;
};
void Init();
SeqEventVarVolumeRand* __fastcall FUN_00252380(SeqEventVarVolumeRand* self) {
    Init();
    self->vf = &vtable_252380;
    self->a = 0.5f;
    self->b = 1.0f;
    return self;
}