// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 9/9)
// FUN_003353e0 @ 0x003353e0
struct Value_3353e0 {
    int f0;
    int f4;
    int type;
    void* data;     // 0xc
};

class Slots_3353e0 {
public:
    int f0;
    int f4;
    int* base;      // 0x8
    void FUN_003353e0(int index, Value_3353e0* v);
};

// Copies the value's payload into slot `index`, according to its type.
void Slots_3353e0::FUN_003353e0(int index, Value_3353e0* v)
{
    int* slot = base + index;
    switch (v->type) {
    case 0:
        *(char*)slot = *(char*)v->data;
        return;
    case 1:
    case 2:
    case 3:
        *slot = *(int*)v->data;
        return;
    case 4: {
        const char* src = *(const char**)v->data;
        char* dst = *(char**)slot;
        char c;
        do {
            c = *src++;
            *dst++ = c;
        } while (c != 0);
        return;
    }
    case 5:
    case 7: {
        int* src = (int*)v->data;
        int* dst = *(int**)slot;
        dst[0] = src[0];
        dst[1] = src[1];
        return;
    }
    case 6:
    case 8: {
        int* src = (int*)v->data;
        int* dst = *(int**)slot;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        return;
    }
    }
}
