class Obj {
  public:
    void Set(float*, float*, float);
};
struct ThisWrap_001fcb30 {
    Obj* Find(int);
    bool Target(int id, float a, float b, float c, float d, float e, float f, float angle);
};
bool ThisWrap_001fcb30::Target(int id, float a, float b, float c, float d, float e, float f, float angle) {
    Obj* o = this->Find(id);
    if (!o)
        return false;
    o->Set(&a, &d, angle * 0.017453292519943295f);
    return true;
}