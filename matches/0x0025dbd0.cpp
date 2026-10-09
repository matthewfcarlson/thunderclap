class Ref {
  public:
    virtual void A();
    virtual void Release(int);
};
class Owner {
  public:
    char pad[0x4c];
    int* head;
    int* tail;
    void Remove(int*);
};
void Owner::Remove(int* p) {
    int* next = p + 1;
    int* prev = 0;
    int* cur = head;
    while (cur != next) {
        prev = cur;
        cur = (int*)*cur;
    }
    if (prev == 0) {
        head = (int*)*next;
    } else {
        *prev = *next;
    }
    if (*next == 0)
        tail = prev;
    if (p != 0)
        ((Ref*)p)->Release(1);
}