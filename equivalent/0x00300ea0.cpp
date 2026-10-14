// STATUS: equivalent (tools/equiv.py level 3: 402 inputs, branch coverage 12/12)
// FUN_00300ea0 @ 0x00300ea0
struct Elem {
    char data[0x6c];
    Elem *FUN_00300a00();
};

struct ElemArray {
    void FUN_00300d80(int flags);
};

void *__cdecl FUN_0008d6d0(unsigned int size);

class ElemPool {
public:
    Elem *elems;            // 0
    int count;              // 4
    int *indices;           // 8
    int *begin;             // 0xc
    int *end;               // 0x10
    void FUN_00300ea0(int n);
};

void ElemPool::FUN_00300ea0(int n)
{
    if (elems != 0)
        ((ElemArray *)elems)->FUN_00300d80(3);

    Elem *arr;
    int *raw = (int *)FUN_0008d6d0(n * sizeof(Elem) + 4);
    if (raw != 0) {
        raw[0] = n;
        arr = (Elem *)(raw + 1);
        for (int i = 0; i < n; i++)
            arr[i].FUN_00300a00();
    } else {
        arr = 0;
    }
    elems = arr;
    count = n;

    if (n != 0) {
        unsigned int bytes = n * 4;
        int *q = (int *)FUN_0008d6d0(bytes);
        indices = q;
        if (q != 0) {
            end = (int *)((char *)q + bytes);
            begin = q;
            return;
        }
    } else {
        indices = 0;
    }
    begin = 0;
    end = 0;
}
