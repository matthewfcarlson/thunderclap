extern "C" int strcmp(const char*, const char*);
void ReleaseThing(void*);
class Obj_f8c30 {
  public:
    char pad[4];
    void* items[129];
    void FindAndRemove(const char* name);
};
void Obj_f8c30::FindAndRemove(const char* name) {
    int i;
    for (i = 0; i < 128; ++i) {
        void* p = items[i];
        if (p) {
            const char* s = (const char*)((char*)p + 0x18);
            if (strcmp(s, name) == 0) {
                ReleaseThing(items[i]);
                items[i] = 0;
                return;
            }
        }
    }
}