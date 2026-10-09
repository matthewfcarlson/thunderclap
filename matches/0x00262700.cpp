class Path {
  public:
    unsigned int Length();
    char* Buffer();
    void SetLength(unsigned int);
    char* Data();
    void Append(Path*);
    void AppendText(char*);
    void Finish();
};
struct Temp {
    char pad[12];
    char* Make(const char*, int);
    void Destroy();
};
Path* FUN_00262700(Path* self, Path* other) {
    unsigned int n = self->Length();
    if (n > 0) {
        char* s = self->Buffer();
        char c = s[n - 1];
        if (c == '\\' || c == '/') {
            s[n - 1] = 0;
            --n;
            self->SetLength(n);
        }
    }
    unsigned int m = other->Length();
    if (m > 0) {
        char* p = self->Data();
        char c = *p;
        if (c != '\\' && c != '/') {
            if (self->Length() > 0) {
                Temp t;
                char* x = t.Make("\\", 0);
                self->AppendText(x);
                t.Destroy();
            }
        }
        self->Append(other);
    }
    return self;
}