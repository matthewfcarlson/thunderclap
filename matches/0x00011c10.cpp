struct Base {
    void Fn();
};
struct Obj : Base {
    char pad[0x1b50];
};
void __fastcall Target(Obj* p) {
    ((Base*)((char*)p + 0x1b50))->Fn();
}
