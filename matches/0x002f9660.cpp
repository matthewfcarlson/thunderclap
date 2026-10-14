struct Entry_2f9660 {
    int a;
    int b;
};
struct Container_2f9660 {
    char pad[0xc];
    Entry_2f9660* begin;
    Entry_2f9660* end;
};
void __fastcall target(Container_2f9660* self) {
    int n = (int)(((char*)self->end - (char*)self->begin) >> 3);
    while (n != 0) {
        --n;
        ++self->begin[n].b;
    }
}