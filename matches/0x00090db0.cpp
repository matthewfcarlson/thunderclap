class Item_90db0 {
  public:
    char pad[0x19];
    unsigned char flag;
    char tail[0x26];
    void Process();
};
class Obj_90db0 {
  public:
    char pad[0xc80];
    int count;
    void Run(int a, int b);
};
void Obj_90db0::Run(int a, int b) {
    int i = 0;
    if (count > 0) {
        Item_90db0* p = (Item_90db0*)this;
        do {
            if (p->flag)
                p->Process();
            ++i;
            p = (Item_90db0*)((char*)p + 0x40);
        } while (i < count);
    }
}
