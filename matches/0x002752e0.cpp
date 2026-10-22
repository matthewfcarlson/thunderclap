struct FileRequest_2752e0 {
    FileRequest_2752e0(int) throw();
    virtual void V0();
    char pad[8];
};
void After();
struct FileWriteRequest_2752e0 : FileRequest_2752e0 {
    int m0c, m10, m14;
    FileWriteRequest_2752e0(int a, int b, int c, int d);
    virtual void V0();
};
FileWriteRequest_2752e0::FileWriteRequest_2752e0(int a, int b, int c, int d) : FileRequest_2752e0(a) {
    m0c = b;
    m10 = c;
    m14 = d;
    After();
}
