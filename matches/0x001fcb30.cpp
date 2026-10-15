class Obj {
  public:
    void Set(float*, float*, float);
};
extern "C" Obj* __stdcall Find(int);
bool __stdcall Target(int id, float a, float b, float c, float d, float e, float f, float angle) {
    Obj* o = Find(id);
    if (!o)
        return false;
    o->Set(&a, &d, angle * 0.017453292519943295f);
    return true;
}