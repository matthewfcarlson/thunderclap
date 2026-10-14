struct BasePart_e2940 {
    void Copy(BasePart_e2940*);
};
struct Item_e2940 {
    char pad[0x38];
    int value;
};
struct Thing_e2940 {
    char pad00[0x14];
    Item_e2940* item;
    BasePart_e2940 base;
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
    void Copy(Thing_e2940*);
};
void Thing_e2940::Copy(Thing_e2940* src) {
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
    Item_e2940* d = *(Item_e2940* volatile*)&item;
    if (d) {
        Item_e2940* s = src->item;
        d->value = s->value;
        s = src->item;
        d = item;
        d->value = s->value;
    }
}