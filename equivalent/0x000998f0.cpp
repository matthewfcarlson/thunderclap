// STATUS: equivalent (tools/equiv.py level 3: 2981 inputs, branch coverage 0/0)
// FUN_000998f0 @ 0x000998f0
struct Sub_998f0 {
    char d[0x70];
    void FUN_000ac780(int a);
    void FUN_000ac790(float f);
};
struct Obj_998f0 {
    char pad0[0x218];
    Sub_998f0 sub;
    int i288;
    int i28c;
    int i290;
    int i294;
    int i298;
    int i29c;
};
struct Target_998f0 {
    char pad0[0xc4];
    Obj_998f0 *obj;
    void FUN_000998f0(int a1, int a2, int a3, int a4, int a5, int a6);
};
void Target_998f0::FUN_000998f0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    obj->i288 = a1;
    obj->i290 = a3;
    obj->i28c = a2;
    obj->sub.FUN_000ac780(0);
    obj->i294 = a4;
    obj->i298 = a5;
    obj->i29c = a6;
    obj->sub.FUN_000ac790(1.0f);
}
