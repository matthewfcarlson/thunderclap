struct Item_35a720 {
    virtual void Run();
};
extern Item_35a720* gItems_35a720[9];
extern int gCount_35a720;
void __cdecl Target(Item_35a720* p) {
    gItems_35a720[gCount_35a720] = p;
    p->Run();
    ++gCount_35a720;
}