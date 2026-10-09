class Item {
  public:
    char pad[4];
    Item* next;
    int state;
};
class Owner {
  public:
    char pad[8];
    Item* item;
    Item* alternate;
    char pad2[4];
    char flag;
};
bool __fastcall FUN_000f9e90(Owner* self) {
    Item* p = self->item;
    if (p != 0 && self->flag != 1) {
        Item* q = self->alternate;
        if (q == 0)
            p = p->next;
        else
            p = q->next;
        if (p != 0 && p->state < 2)
            p = 0;
    } else
        p = 0;
    return p != 0;
}
