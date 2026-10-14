class Obj_1bc4e0 {
  public:
    void DoA();
    void DoB();
    void DoC(Obj_1bc4e0*);
};
Obj_1bc4e0* __cdecl GetObj();
void __fastcall target(Obj_1bc4e0* self) {
    Obj_1bc4e0* saved = self;
    GetObj()->DoA();
    GetObj()->DoB();
    GetObj()->DoC(saved);
}
