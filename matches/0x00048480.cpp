struct CButtonCondition {
    void* vptr;
    int x04, x08, x0c, x10, x14;
};
struct ThisCall_00234590 {
    void Init(int);
};
extern char buttonVtable;
CButtonCondition* __fastcall FUN_00048480(CButtonCondition* self) {
    ((ThisCall_00234590*)(self))->Init(0);
    self->vptr = &buttonVtable;
    self->x0c = 0;
    self->x10 = 4;
    self->x14 = 0;
    return self;
}