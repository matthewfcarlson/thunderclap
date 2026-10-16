class Obj {
  public:
    void Do(const char*, void*);
};
void __fastcall FUN_00044be0(void* p, void* unused, Obj* obj) {
    obj->Do("RdlCharacterTemplate", p);
}