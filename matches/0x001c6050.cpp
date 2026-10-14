extern "C" char DAT_00421990[];
struct Item_1c6050 {
    char pad[0x23];
    char flag;
};
struct Holder_1c6050 {
    Item_1c6050* Find(int);
};
struct Obj_1c6050 {
    char pad[12];
    Holder_1c6050* h;
    void Poke();
};
struct Sub_1c6050 {
    char pad[8];
    void Init();
    void Set(int);
};
Obj_1c6050* __stdcall Make2(int a, int b);
Obj_1c6050* __stdcall Make0();
struct Owner_1c6050 {
    void* vf;
    char pad[4];
    Sub_1c6050 s;
    int b;
    Owner_1c6050* Target(int arg1, int arg2);
};
Owner_1c6050* Owner_1c6050::Target(int arg1, int arg2) {
    vf = (void*)((int)DAT_00421990);
    s.Init();
    s.Set(arg1);
    Obj_1c6050* o = Make2(arg1, arg2);
    o->Poke();
    Obj_1c6050* p = Make0();
    Holder_1c6050* h = p->h;
    Item_1c6050* it = h->Find(arg1);
    b = (int)it;
    it->flag = 1;
    return this;
}
