class Param {
  public:
    virtual void Prepare();
    virtual void Destroy();
    int unused;
    int a;
    int b;
};
class Owner_7b380 {
  public:
    char pad[0x354c];
    Param* entries[20];
    int count;
    int Find(int, int);
    void Add(Param* p);
};
void Owner_7b380::Add(Param* p) {
    int i = Find(p->a, p->b);
    if (i < 0 || entries[i] == 0) {
        i = count;
        if (i != 20) {
            p->Prepare();
            if (entries[i])
                entries[i]->Destroy();
            entries[i] = p;
            ++count;
        }
    }
}