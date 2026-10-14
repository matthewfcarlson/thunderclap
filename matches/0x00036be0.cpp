class Builder {
  public:
    void Make(void*);
};
class Dest_36be0 {
  public:
    void Send(int, void*);
};
class Obj_36be0 {
  public:
    char pad[0x10];
    Builder* builder;
    char pad2[0x1ca0 - 0x14];
    int m1ca0;
    void Run(int);
};
void Obj_36be0::Run(int arg) {
    char local[12];
    int value = m1ca0;
    if (value) {
        Dest_36be0* p = (Dest_36be0*)(value + 0x58);
        if (p) {
            builder->Make(local);
            p->Send(arg, local);
        }
    }
}