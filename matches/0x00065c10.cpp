struct Manager { char pad[0x0c]; int count; void* GetItem(int); };
struct Root { char pad[0x20]; Manager* manager; };
extern Root* gRoot;
void __cdecl Target() {
    int n = gRoot->manager->count;
    for (int i = 0; i < n; ++i) {
        void* p = gRoot->manager->GetItem(i);
        if (p) *(int*)((char*)p + 0x214c) = 0;
    }
}