extern const float gOne;
extern const float gZero;
struct Data {
    char pad[0x10];
    float value;
};
struct Target {
    int a;
    int b;
    float result;
    int c;
    int d;
    float one;
    float maxv;
    int e;
    int f;
    unsigned char flag;
    char pad[3];
    Data* data;
};
void __fastcall FUN_00285a70(Target* p) {
    p->a = 0;
    p->b = 0;
    float v;
    if (p->data == 0 || (v = p->data->value - gOne, v < gZero))
        v = gZero;
    p->result = v;
    p->c = 0;
    p->d = 0;
    p->one = 1.0f;
    p->maxv = 3.402823466e+38F;
    p->e = 0;
    p->f = 0;
    p->flag = 1;
}