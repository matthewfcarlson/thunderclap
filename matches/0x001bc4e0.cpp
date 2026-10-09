class Obj { public: void DoA(); void DoB(); void DoC(Obj*); };
Obj* __cdecl GetObj();
void __fastcall target(Obj* self) {
    Obj* saved = self;
    GetObj()->DoA();
    GetObj()->DoB();
    GetObj()->DoC(saved);
}
