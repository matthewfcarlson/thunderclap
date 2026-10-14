class Sub {
  public:
    int SubFn();
};

class Obj {
  public:
    char pad[4];
    Sub* m;
    int Target(void* a, void* b);
};

int Obj::Target(void* a, void* b) {
    Sub* s = m;
    if (!s)
        return -1;
    s->SubFn();
    return 0;
}
