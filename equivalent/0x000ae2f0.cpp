// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 30/40, incomplete)
// FUN_000ae2f0 @ 0x000ae2f0
struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3();
    virtual void v4();
    virtual void v5();
    virtual const char *v6();
};
struct Mgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Count();
    virtual Item *Get(int i);
};
Mgr *FUN_002684b0();
struct Entry {
    char pad0[0xd];
    char flag;
    char pad1[6];
    char name[0x120];
    char str134[1];
    void FUN_000b0740(const char *s);
    void FUN_000b2810();
};
struct Table {
    char pad0[0xc];
    char flag;
    char pad1[3];
    int count;
    Entry **entries;
    char pad2[0x134 - 0x18];
    char str134[0x100];
    void FUN_000ae090(int n);
    void FUN_000ae2f0(const char *key);
};
void Table::FUN_000ae2f0(const char *key)
{
    Table *self = this;
    int n = count;
    Entry **p = entries;
    Entry *e = 0;
    bool found = false;
    for (int i = 0; i < n; i++, p++) {
        e = *p;
        const char *a = e->name;
        const char *b = key;
        while (*a == *b && *a != 0) {
            a++;
            b++;
        }
        if (*a == *b) {
            found = true;
            break;
        }
        if (e->name[0] == 0) {
            e->FUN_000b0740(key);
            found = true;
            break;
        }
    }
    if (found) {
        if (self->str134[0] == 0) {
            e->flag = 0;
        } else {
            const char *a = key;
            const char *b = self->str134;
            while (*a == *b && *a != 0) {
                a++;
                b++;
            }
            e->flag = (*a != *b);
        }
        return;
    }
    self->FUN_000ae090(FUN_002684b0()->Count());
    for (int i = 0; i < FUN_002684b0()->Count(); i++) {
        Entry *en = self->entries[i];
        const char *arg;
        Item *it = FUN_002684b0()->Get(i);
        if (it != 0 && FUN_002684b0()->Get(i)->v3() != 0)
            arg = FUN_002684b0()->Get(i)->v6();
        else
            arg = "";
        en->FUN_000b0740(arg);
        en->FUN_000b2810();
    }
}
