class Path_262700 {
  public:
    unsigned int Length();
    char* Buffer();
    void SetLength(unsigned int);
    char* Data();
    void Append(Path_262700*);
    void AppendText(char*);
    void Finish();
};
struct Temp_262700 {
    char pad[12];
    char* Make(const char*, int);
    void Destroy();
};
Path_262700* FUN_00262700(Path_262700* self, Path_262700* other) {
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
                Temp_262700 t;
                char* x = t.Make("\\", 0);
                self->AppendText(x);
                t.Destroy();
            }
        }
        self->Append(other);
    }
    return self;
}