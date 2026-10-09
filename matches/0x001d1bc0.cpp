extern int __cdecl FUN_00212d70(int);
extern void __cdecl FUN_00213320(int);
class Obj {
public:
    char pad0[8]; int value; char padc[0x5470 - 12]; int items[8]; int index;
    bool f();
};
bool Obj::f() {
    if (index < 7 && index >= -1) {
        ++index;
        items[index] = FUN_00212d70(value);
        FUN_00213320(value);
        return true;
    }
    return false;
}