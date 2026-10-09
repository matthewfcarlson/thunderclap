class C {
  public:
    char pad[4];
    int x;
};
void __fastcall FUN_002314c0(C*);
void __fastcall FUN_00231640(C* p) {
    p->x = -1;
    FUN_002314c0(p);
}