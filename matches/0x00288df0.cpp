extern const float g_zero_288df0;
struct Key_288df0 {
    __int64 k;
    int a, b, c, d;
};
struct Row_288df0 {
    float p0, p1, v, m;
};
struct Obj_288df0 {
    char pad[0x10];
    float limit;
    char pad2[0x20];
    unsigned int count;
    char* base;
};
float __fastcall Fn(Obj_288df0* self, Key_288df0* arr, int idx, float x, __int64 key) {
    unsigned int i = 0;
    if (self->count > 0) {
        do {
            if (arr->k == key) {
                idx = idx + i * 3;
                Row_288df0* r = (Row_288df0*)(self->base + idx * 8);
                float v = x * r->m + r->v;
                if (v >= self->limit)
                    return v - self->limit;
                return v;
            }
            i++;
            arr = (Key_288df0*)((char*)arr + 0x18);
        } while (i < self->count);
    }
    return g_zero_288df0;
}
