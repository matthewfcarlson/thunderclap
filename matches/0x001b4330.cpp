struct Data {
    char pad[0x74];
    void* ptr;
};
class Inner {
  public:
    void thunk(void*);
};
class Obj {
  public:
    char pad[8];
    Inner* field;
    bool Fn(Data* d);
};
bool Obj::Fn(Data* d) {
    void* p = d->ptr;
    bool ok = true;
    if (p)
        field->thunk(p);
    else
        ok = false;
    return ok;
}