class Item_f9e90 {
  public:
    char pad[4];
    Item_f9e90* next;
    int state;
};
class Owner_f9e90 {
  public:
    char pad[8];
    Item_f9e90* item;
    Item_f9e90* alternate;
    char pad2[4];
    char flag;
};
bool __fastcall FUN_000f9e90(Owner_f9e90* self) {
    Item_f9e90* p = self->item;
    if (p != 0 && self->flag != 1) {
        Item_f9e90* q = self->alternate;
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
