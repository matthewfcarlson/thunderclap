struct Result {
    int header;
    int slots[4];
};
struct Final {
    Result* Get(int);
};
struct Mid {
    char pad[8];
    Final* f;
};
struct First {
    char pad[4];
    Mid* m;
};
struct Root {
    char pad[8];
    First* first;
};
class Owner {
  public:
    char pad[0x14];
    Root* root;
    char pad2[0x168];
    Result* result;
    void Run(int);
};
void Owner::Run(int arg) {
    Result* p = root->first->m->f->Get(arg);
    result = p;
    if (p) {
        int i = 0;
        while (i < 4 && p->slots[i] != 0)
            ++i;
        if (i != 4)
            p->slots[i] = (int)this;
    }
}