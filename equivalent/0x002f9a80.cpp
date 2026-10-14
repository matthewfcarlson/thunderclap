// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002f9a80 @ 0x002f9a80
void *FUN_0008d6d0(unsigned int size);

struct Vertex {
    int w[4];
};

struct MeshBuffers {
    char pad[0x30];
    Vertex *vertsStart;
    Vertex *vertsBegin;
    Vertex *vertsEnd;
    char pad3c[4];
    unsigned short *indicesStart;
    unsigned short *indicesBegin;
    unsigned short *indicesEnd;
    void FUN_002f9a80(unsigned int numVerts, unsigned int numIndices);
};

void MeshBuffers::FUN_002f9a80(unsigned int numVerts, unsigned int numIndices)
{
    if (numVerts != 0) {
        vertsStart = (Vertex *)FUN_0008d6d0(numVerts * sizeof(Vertex));
        if (vertsStart != 0) {
            vertsBegin = vertsStart;
            vertsEnd = vertsStart + numVerts;
        } else {
            vertsBegin = 0;
            vertsEnd = 0;
        }
    } else {
        vertsStart = 0;
        vertsBegin = 0;
        vertsEnd = 0;
    }
    if (numIndices != 0) {
        indicesStart = (unsigned short *)FUN_0008d6d0(numIndices * 2);
        if (indicesStart != 0) {
            indicesEnd = indicesStart + numIndices;
            indicesBegin = indicesStart;
        } else {
            indicesBegin = 0;
            indicesEnd = 0;
        }
    } else {
        indicesStart = 0;
        indicesBegin = 0;
        indicesEnd = 0;
    }
}
