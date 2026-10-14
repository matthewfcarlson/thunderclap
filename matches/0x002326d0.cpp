class Obj_2326d0 {
  public:
    virtual void F0();
    virtual void F1();
};
class Holder_2326d0 {
  public:
    char pad[8];
    Obj_2326d0* p;
    void Set(Obj_2326d0* value);
};
void Holder_2326d0::Set(Obj_2326d0* value) {
    if (value)
        value->F0();
    if (p)
        p->F1();
    p = value;
}