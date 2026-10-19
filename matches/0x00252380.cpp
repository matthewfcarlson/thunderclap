extern void* vtable_252380;
class SeqEventVarVolumeRand {
  public:
    void* vf;
    int pad;
    float a;
    float b;
};
struct ThisCall_0025fd00 {
    void Init();
};
SeqEventVarVolumeRand* __fastcall FUN_00252380(SeqEventVarVolumeRand* self) {
    ((ThisCall_0025fd00*)(self))->Init();
    self->vf = &vtable_252380;
    self->a = 0.5f;
    self->b = 1.0f;
    return self;
}