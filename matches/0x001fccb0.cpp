struct Item {
    char pad[8];
    int a;
    int b;
};
extern char buffer[];
extern void __cdecl format(char*, int, int, int);
class Obj {
    char pad[0x238];
    int count;
    Item* items[1];

  public:
    char* get(int index);
};
char* Obj::get(int index) {
    if (index >= count)
        return 0;
    Item* p = items[index];
    format(buffer, 0x40, p->a, p->b);
    return buffer;
}