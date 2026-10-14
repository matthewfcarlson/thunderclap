struct Base_11c10 {
    void Fn();
};
struct Obj_11c10 : Base_11c10 {
    char pad[0x1b50];
};
void __fastcall Target(Obj_11c10* p) {
    ((Base_11c10*)((char*)p + 0x1b50))->Fn();
}
