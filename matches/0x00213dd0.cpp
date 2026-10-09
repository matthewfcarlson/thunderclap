struct R {
    int type;
    void* data;
};
R* __fastcall GetR(int, int);
struct Ent {
    char pad[8];
    int* v;
};
struct Out {
    char pad[8];
    int* pos;
};
struct Inner {
    char pad[0x1c];
    int* arr;
    char pad2[4];
    int count;
};
struct Item {
    char pad[8];
    int a;
    int b;
};
struct Data {
    char pad[6];
    unsigned char isArray;
    unsigned char n;
    char pad2[4];
    Inner* inner;
    char pad3[4];
    Ent* items[1];
};
extern char gZero[];
char* FUN_00213dd0(Out* out, int x, int index) {
    R* r = GetR(x, (int)out);
    if (r->type != 6)
        return 0;
    Data* d = (Data*)r->data;
    int* p;
    char* ret;
    if (d->isArray) {
        if (index > d->n)
            return 0;
        p = (int*)((char*)d + 8 + index * 8);
        ret = gZero;
    } else {
        Inner* in = d->inner;
        if (index > in->count)
            return 0;
        p = d->items[index]->v;
        ret = (char*)in->arr[index - 1] + 16;
    }
    if (ret) {
        int* q = out->pos;
        q[0] = p[0];
        q[1] = p[1];
        out->pos += 2;
    }
    return ret;
}
