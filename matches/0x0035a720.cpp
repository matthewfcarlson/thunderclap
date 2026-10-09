struct Item { virtual void Run(); };
extern Item* gItems[9];
extern int gCount;
void __cdecl Target(Item* p) {
    gItems[gCount] = p;
    p->Run();
    ++gCount;
}