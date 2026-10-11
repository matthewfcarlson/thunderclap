struct BasePart {
    void Copy(BasePart*);
};
struct Item {
    char pad[0x38];
    int value;
};
struct Thing {
    char pad00[0x14];
    Item* item;
    BasePart base;
    char pad1c[0x20];
    unsigned int color3c;
    unsigned char flag40;
    char p41[3];
    unsigned int color44;
    unsigned char flag48;
    char p49[3];
    unsigned int field4c;
    char p50[0x1c];
    unsigned int field6c, field70;
    unsigned char flag74;
    char p75[3];
    unsigned int field78, field7c, field80;
    char p84[4];
    unsigned int field88, field8c, field90, field94;
    void Copy(Thing*);
};
void Thing::Copy(Thing* src) {
    base.Copy(&src->base);
    flag74 = src->flag74;
    field90 = src->field90;
    field94 = src->field94;
    color3c = 0xffc0c0c0;
    flag40 = src->flag40;
    color44 = 0xffc0c0c0;
    flag48 = src->flag48;
    field4c = src->field4c;
    field6c = src->field6c;
    field70 = src->field70;
    field88 = src->field88;
    field8c = src->field8c;
    field78 = src->field78;
    field7c = src->field7c;
    *(unsigned int volatile*)&field80 = src->field80;
    Item* d = *(Item* volatile*)&item;
    if (d) {
        Item* s = src->item;
        d->value = s->value;
        s = src->item;
        d = item;
        d->value = s->value;
    }
}