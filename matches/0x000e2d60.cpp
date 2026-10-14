struct Result_e2d60 {
    int header;
    int slots[4];
};
struct Final_e2d60 {
    Result_e2d60* Get(int);
};
struct Mid_e2d60 {
    char pad[8];
    Final_e2d60* f;
};
struct First_e2d60 {
    char pad[4];
    Mid_e2d60* m;
};
struct Root_e2d60 {
    char pad[8];
    First_e2d60* first;
};
class Owner_e2d60 {
  public:
    char pad[0x14];
    Root_e2d60* root;
    char pad2[0x168];
    Result_e2d60* result;
    void Run(int);
};
void Owner_e2d60::Run(int arg) {
    Result_e2d60* p = root->first->m->f->Get(arg);
    result = p;
    if (p) {
        int i = 0;
        while (i < 4 && p->slots[i] != 0)
            ++i;
        if (i != 4)
            p->slots[i] = (int)this;
    }
}