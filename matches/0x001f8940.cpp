class Obj { public: char pad[8]; unsigned char a; unsigned char b; Obj* Copy(Obj*); Obj* Target(Obj* other); };
Obj* Obj::Target(Obj* other) {
    Copy(other);
    a = other->a;
    b = other->b;
    return this;
}