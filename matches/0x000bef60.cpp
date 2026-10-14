class Sub_bef60 {
  public:
    int SubFn();
};

class Obj_bef60 {
  public:
    char pad[4];
    Sub_bef60* m;
    int Target(void* a, void* b);
};

int Obj_bef60::Target(void* a, void* b) {
    Sub_bef60* s = m;
    if (!s)
        return -1;
    s->SubFn();
    return 0;
}
