typedef unsigned int u32;
struct Item { char pad[0x10]; int member; char pad2[0x0c]; int at20; };
extern void f1(void*, Item*);
extern void f2(void*, void*);
extern void f3(void*, Item*);
char globalBss[4];
void target(void* param1, Item** param2) {
    Item* p = *param2;
    *param2 = 0;
    f1((char*)param1 + 0x14, p);
    f2((char*)p->at20 + 0x28, (char*)p + 0x10);
    f3(globalBss, p);
}