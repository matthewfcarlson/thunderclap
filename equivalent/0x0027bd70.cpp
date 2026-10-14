// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0027bd70 @ 0x0027bd70
struct Elem_27bd70 {
    char data[0x18];
};

class ElemVector {
public:
    Elem_27bd70 *first;             // 0x00
    Elem_27bd70 *last;              // 0x04
    Elem_27bd70 *capEnd;            // 0x08
    void FUN_0027b3b0(unsigned int n);
    void FUN_0027ba70(Elem_27bd70 *from, Elem_27bd70 *to);
    void FUN_0027bad0(Elem_27bd70 *at, int count);
    void FUN_0027bd70(unsigned int newSize, int fill);
};

void __cdecl FUN_0027bb30(Elem_27bd70 *at, int count, int fill);

void ElemVector::FUN_0027bd70(unsigned int newSize, int fill) {
    if (first == 0)
        FUN_0027b3b0(newSize);
    Elem_27bd70 *end = last;
    Elem_27bd70 *begin = first;
    unsigned int size = end - begin;
    if (newSize > size) {
        int extra = newSize - size;
        if (end + extra <= capEnd) {
            FUN_0027bad0(end, extra);
            FUN_0027bb30(end, extra, fill);
        }
    } else if (newSize < size) {
        FUN_0027ba70(begin + newSize, end);
    }
}
