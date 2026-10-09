class VertexOffsetList {
public:
    VertexOffsetList(int value);
    void* vptr;
    int a1;
    int a2;
    int a3;
    int a4, a5, a6, a7, a8, a9, a10, a11;
};

VertexOffsetList::VertexOffsetList(int value) {
    a1 = 0;
    vptr = (void*)0x42efb0;
    a2 = 0;
    a3 = value;
    a4 = 0; a5 = 0; a6 = 0; a7 = 0;
    a8 = 0; a9 = 0; a10 = 0; a11 = 0;
}
