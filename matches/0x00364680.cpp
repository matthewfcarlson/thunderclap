struct Obj {
    void Run();
};
extern Obj gObj;
void __fastcall FUN_002580e0(Obj*) throw();
void __fastcall FUN_00364680() throw() {
    FUN_002580e0(&gObj);
}
