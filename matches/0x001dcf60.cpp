struct Data {
    char pad[0x74];
    int p;
};
class Obj {
  public:
    Data* Get();
    char Check();
};
class CGrabAction {
  public:
    char pad[0x1e620];
    Obj* items[128];
    int count;
    void Set(char value);
};
void CGrabAction::Set(char value) {
    int i = 0;
    while (i < count) {
        Obj* o = items[i];
        Data* d = o->Get();
        if (d && !o->Check()) {
            d = o->Get();
            if (d->p)
                *((char*)d->p + 0x72) = value;
        }
        ++i;
    }
}
