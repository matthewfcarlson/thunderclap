struct Base_89810 {
    void FUN_00088fe0();
};
struct Obj_89810 {
    char pad[0x80];
    void FUN_00089810();
};
void Obj_89810::FUN_00089810() {
    ((Base_89810*)((char*)this + 0x80))->FUN_00088fe0();
}