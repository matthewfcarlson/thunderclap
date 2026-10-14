class Obj {
  public:
    char pad[0x194];
    char flag;
    Obj* Find(int id);
    void Set(int id, char c);
};
void Obj::Set(int id, char c) {
    Obj* p = Find(id);
    if (p)
        p->flag = c;
}
