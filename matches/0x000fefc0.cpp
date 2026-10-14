class Obj_fefc0 {
  public:
    char pad[0x110];
    int value;
    int Target();
};
extern void __cdecl Init(Obj_fefc0*, int*);
int Obj_fefc0::Target() {
    if (value == 0)
        Init(this, &value);
    return value;
}