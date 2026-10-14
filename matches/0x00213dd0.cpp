struct R_213dd0 {
    int type;
    void* data;
};
R_213dd0* __fastcall GetR(int, int);
struct Ent_213dd0 {
    char pad[8];
    int* v;
};
struct Out_213dd0 {
    char pad[8];
    int* pos;
};
struct Inner_213dd0 {
    char pad[0x1c];
    int* arr;
    char pad2[4];
    int count;
};
struct Item_213dd0 {
    char pad[8];
    int a;
    int b;
};
struct Data_213dd0 {
    char pad[6];
    unsigned char isArray;
    unsigned char n;
    char pad2[4];
    Inner_213dd0* inner;
    char pad3[4];
    Ent_213dd0* items[1];
};
extern char gZero_213dd0[];
char* FUN_00213dd0(Out_213dd0* out, int x, int index) {
    R_213dd0* r = GetR(x, (int)out);
    if (r->type != 6)
        return 0;
    Data_213dd0* d = (Data_213dd0*)r->data;
    int* p;
    char* ret;
    if (d->isArray) {
        if (index > d->n)
            return 0;
        p = (int*)((char*)d + 8 + index * 8);
        ret = gZero_213dd0;
    } else {
        Inner_213dd0* in = d->inner;
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
