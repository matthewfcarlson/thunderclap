// FUN_002f9a80 @ 0x002f9a80
void *FUN_0008d6d0(unsigned int size);

struct Vertex_2f9a80 {
    int w[4];
};

struct MeshBuffers_2f9a80 {
    char pad[0x30];
    Vertex_2f9a80 *vertsStart;
    Vertex_2f9a80 *vertsBegin;
    Vertex_2f9a80 *vertsEnd;
    char pad3c[4];
    unsigned short *indicesStart;
    unsigned short *indicesBegin;
    unsigned short *indicesEnd;
    void FUN_002f9a80(unsigned int numVerts, unsigned int numIndices);
};

void MeshBuffers_2f9a80::FUN_002f9a80(unsigned int numVerts, unsigned int numIndices)
{
    if (numVerts != 0) {
        vertsStart = (Vertex_2f9a80 *)FUN_0008d6d0(numVerts * sizeof(Vertex_2f9a80));
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
