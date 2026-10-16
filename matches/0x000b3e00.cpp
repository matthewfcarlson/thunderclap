class Obj {
  public:
    virtual void Go();
};
class Source {
  public:
    Obj* Make(int);
};
class Target {
  public:
    char pad[4];
    Obj* obj;
    void Fn(Source* src);
};
void Target::Fn(Source* src) {
    if (src) {
        obj = src->Make(0);
        obj->Go();
    }
}