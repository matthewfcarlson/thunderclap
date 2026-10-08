class PoseDriver { public: int pad0[4]; char active; void InitBase(); };
PoseDriver* __fastcall FUN_0030eb10(PoseDriver* self) {
    self->InitBase();
    *(void**)self = (void*)0x43209c;
    self->active = 1;
    return self;
}