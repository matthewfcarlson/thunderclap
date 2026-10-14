extern void Ensure(int);
extern void Copy(void*, const void*, unsigned int);
struct Target_b10a0 {
    int count;
    char* data;
    void Check(int);
    void Write(int index, const void* source);
};
void Target_b10a0::Write(int index, const void* source) {
    if (count <= 0)
        Check(1);
    Copy(data + index * 32, source, 32);
}