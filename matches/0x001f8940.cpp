class Obj_1f8940 {
  public:
    char pad[8];
    unsigned char a;
    unsigned char b;
    Obj_1f8940* Copy(Obj_1f8940*);
    Obj_1f8940* Target(Obj_1f8940* other);
};
Obj_1f8940* Obj_1f8940::Target(Obj_1f8940* other) {
    Copy(other);
    a = other->a;
    b = other->b;
    return this;
}