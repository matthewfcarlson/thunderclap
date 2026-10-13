class Obj {
  public:
    Obj* Get();
};

Obj* Obj::Get() {
    return this;
}
