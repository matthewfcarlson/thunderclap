void __fastcall cleanup(void*);
class X { public: char pad[12]; void** begin; void** end; void target(); };
void X::target() {
    unsigned int n = ((char*)end - (char*)begin) >> 2;
    for (unsigned int i=0; i<n; ++i) {
        void* p = begin[i];
        if (p) cleanup(p);
    }
}