class Sub {
  public:
    char pad[12];
    unsigned char flag;
    void Change();
};
class Holder {
  public:
    char pad[0x5c];
    Sub* sub;
};
class Obj {
  public:
    char pad[4];
    Holder* holder;
    void Set(void* p);
};
void Obj::Set(void* p) {
    if (holder) {
        unsigned char b = p == 0;
        Sub* s = holder->sub;
        if (s) {
            if (s->flag != b)
                s->Change();
            s->flag = b;
        }
    }
}