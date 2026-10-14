class Obj_1df330 {
  public:
    char pad[0x194];
    char flag;
    Obj_1df330* Find(int id);
    void Set(int id, char c);
};
void Obj_1df330::Set(int id, char c) {
    Obj_1df330* p = Find(id);
    if (p)
        p->flag = c;
}
