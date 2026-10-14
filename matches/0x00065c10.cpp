struct Manager_65c10 {
    char pad[0x0c];
    int count;
    void* GetItem(int);
};
struct Root_65c10 {
    char pad[0x20];
    Manager_65c10* manager;
};
extern Root_65c10* gRoot_65c10;
void __cdecl Target() {
    int n = gRoot_65c10->manager->count;
    for (int i = 0; i < n; ++i) {
        void* p = gRoot_65c10->manager->GetItem(i);
        if (p)
            *(int*)((char*)p + 0x214c) = 0;
    }
}