struct Entry {
    int a;
    int b;
};
struct Container {
    char pad[0xc];
    Entry* begin;
    Entry* end;
};
void __fastcall target(Container* self) {
    int n = (int)(((char*)self->end - (char*)self->begin) >> 3);
    while (n != 0) {
        --n;
        ++self->begin[n].b;
    }
}