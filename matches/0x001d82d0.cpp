struct Node {
    char pad[0x6c];
    int field6c;
};
struct Holder {
    char pad[0x10];
    Node* node;
};
class Manager {
  public:
    bool Check(void*);
    int Find(void*);
    void Use(int);
};
struct Root {
    char pad[0x4c];
    Manager* manager;
};
extern Root* gRoot;
class Obj {
  public:
    char pad0[0xa0];
    Holder* holder;
    char padA4[0xa8];
    unsigned char active;
    void Prepare();
    int Run();
};
int Obj::Run() {
    if (!active)
        return -1;
    int x;
    if (holder)
        x = (int)holder->node;
    else
        x = 0;
    if (*(int*)(x + 0x6c))
        return -1;
    Prepare();
    Manager* m = gRoot->manager;
    void* q = (char*)this + 8;
    if (!m->Check(q))
        return -1;
    int r = m->Find(q);
    if (r != -1)
        m->Use(r);
    return r;
}