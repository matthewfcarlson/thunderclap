struct Sub_d7d60 {
    void Clear();
};
struct Obj_d7d60 {
    char pad[0x10];
    Sub_d7d60 sub;
    char pad2[0x23];
    unsigned char flag;
    Obj_d7d60* Run();
};
Obj_d7d60* Obj_d7d60::Run() {
    sub.Clear();
    flag = 0;
    return this;
}