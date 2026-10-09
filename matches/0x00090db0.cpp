class Item {
  public:
    char pad[0x19];
    unsigned char flag;
    char tail[0x26];
    void Process();
};
class Obj {
  public:
    char pad[0xc80];
    int count;
    void Run(int a, int b);
};
void Obj::Run(int a, int b) {
    int i = 0;
    if (count > 0) {
        Item* p = (Item*)this;
        do {
            if (p->flag)
                p->Process();
            ++i;
            p = (Item*)((char*)p + 0x40);
        } while (i < count);
    }
}
