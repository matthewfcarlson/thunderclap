class Obj_1fa7a0 {
  public:
    char pad[0x18];
    struct V {
        virtual void f0();
        virtual void f1();
    };
    V* member;
    Obj_1fa7a0* target(unsigned char flag);
};
extern void __stdcall FUN_00230f50(void (*)(), Obj_1fa7a0*);
extern void FUN_00267090(Obj_1fa7a0*);
extern void FUN_001f9f80();
Obj_1fa7a0* Obj_1fa7a0::target(unsigned char flag) {
    FUN_00230f50(&FUN_001f9f80, this);
    member->f1();
    if (flag & 1)
        FUN_00267090(this);
    return this;
}