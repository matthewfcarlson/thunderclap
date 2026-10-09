struct X { int Get(int); };
struct Y { void Use(int); };
struct C { void* v; int pad[2]; int count; int items[1]; void target(int,int,int); };
void C::target(int arg,int,int) {
    int i = 0;
    if (count > 0) {
        do {
            void* p = ((void**)v)[17];
            int x = ((X*)p)->Get(items[i]);
            if (x) ((Y*)x)->Use(arg);
            ++i;
        } while (i < count);
    }
}
