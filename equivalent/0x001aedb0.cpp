// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 33/34, incomplete)
// FUN_001aedb0 @ 0x001aedb0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
#include "compat/ptr.h"
struct Ctx;
struct Rec {
    int id, idx;
    float x, y, z;
    Rec* parent;
    float g, h;
    char closed;
    char pad21[3];
    int last;
    void FUN_001ad2b0(Ctx* d);
};
struct ANode {
    char hdr[0x10];
    Rec rec;
};
struct Map;
struct BNode {
    char hdr[0x10];
    ANode* an;
    Map* map;
};
struct Map {
    char pad0[0x14];
    int size;
    BNode* FUN_00230ea0();
    void FUN_00230de0(void* node);
    void* FUN_00230ba0(void* cmp, void* key);
    void* FUN_00230be0(void* cmp, void* key);
    void FUN_00230c30(void* node, void* cmp, void* parent);
};
struct Iter {
    int tile, cur, idx, flag;
    void FUN_001ad7d0(Ctx* d);
};
int __cdecl FUN_001ad4d0(void*, void*);
int __cdecl FUN_001ad4f0(void*, void*);
int __cdecl FUN_001aea70(void*, void*);
int __cdecl FUN_001aeae0(void*, void*);
char __cdecl FUN_001ad730(int tile, Ctx* d);
void* FUN_0008d6d0(hulk_uintptr size);
void thunk_FUN_00267090(void* p);
extern "C" double sqrt(double);

struct SearchState {
    float candidateCost;
    Map* savedMap;
    int processed;
    ANode* candidateNode;
    Map* candidateMap;
    ANode* currentNode;
    hulk_intptr currentMapValue;
    void* openEntry;
    Map* savedOpenMap;
    Iter neighbors;
    Iter start;
    int startExtra;
    Rec candidate;
};

Rec* FUN_001aedb0(Map* visited, Map* open, Rec* goal, Ctx* context, int* result) {
    SearchState state;
    BNode* front = open->FUN_00230ea0();
    if (front->an->rec.id == goal->id)
        return &open->FUN_00230ea0()->an->rec;

    front = open->FUN_00230ea0();
    state.start.tile = front->an->rec.id;
    state.start.idx = -1;
    state.start.flag = (unsigned char)FUN_001ad730(state.start.tile, context);
    state.start.FUN_001ad7d0(context);
    if (!open->size)
        return 0;

    state.processed = 0;
    for (;;) {
        if (state.processed++ == 0x80)
            return 0;

        BNode* front = open->FUN_00230ea0();
        state.currentNode = front->an;
        state.currentMapValue = (hulk_intptr)front->map;
        front = open->FUN_00230ea0();
        state.savedMap = open;
        open->FUN_00230de0(front);
        thunk_FUN_00267090(front);

        state.neighbors.tile = state.currentNode->rec.id;
        state.neighbors.idx = -1;
        state.neighbors.flag = (unsigned char)FUN_001ad730(state.neighbors.tile, context);
        state.neighbors.FUN_001ad7d0(context);
        while (state.neighbors.idx != -1) {
            state.candidate.id = state.neighbors.cur;
            *(int*)&state.candidate.x = state.start.idx;
            *(int*)&state.candidate.y = state.start.flag;
            *(int*)&state.candidate.z = state.startExtra;
            state.candidate.parent = 0;
            state.candidate.g = 0;
            state.candidate.h = 0;
            state.candidate.last = 0;
            state.candidate.idx = state.neighbors.idx;
            *(int*)&state.candidate.closed = 0;

            bool newlyCreated = true;
            void* insertionPoint = visited->FUN_00230be0((void*)FUN_001ad4f0, &state.candidate);
            ANode* allocated = 0;
            if (insertionPoint) {
                allocated = (ANode*)FUN_0008d6d0(0x38);
                if (allocated)
                    allocated->rec = state.candidate;
                visited->FUN_00230c30(allocated, (void*)FUN_001ad4d0, insertionPoint);
                state.candidateNode = allocated;
                state.candidateMap = visited;
            } else {
                state.candidateNode = 0;
                state.candidateMap = 0;
            }
            if (allocated) {
                allocated->rec.FUN_001ad2b0(context);
            } else {
                state.candidateNode = (ANode*)visited->FUN_00230ba0((void*)FUN_001ad4f0, &state.candidate);
                state.candidateMap = visited;
                newlyCreated = false;
            }

            ANode* candidate = state.candidateNode;
            Rec* next = &candidate->rec;
            Rec* current = &state.currentNode->rec;
            double dx = current->x - next->x;
            double dy = current->y - next->y;
            double dz = current->z - next->z;
            state.candidateCost = (float)(sqrt(dz * dz + dy * dy + dx * dx) + current->g);
            if (newlyCreated || state.candidateCost < next->g) {
                next->idx = state.candidate.idx;
                if (!newlyCreated && !next->closed) {
                    state.openEntry = open->FUN_00230ba0((void*)FUN_001aeae0, &state.candidateNode);
                    if (state.openEntry) {
                        open->FUN_00230de0(state.openEntry);
                        thunk_FUN_00267090(state.openEntry);
                    }
                }
                next->g = state.candidateCost;
                next->parent = current;
                double ex = next->x - goal->x;
                double ey = next->y - goal->y;
                double ez = next->z - goal->z;
                next->h = (float)(sqrt(ez * ez + ey * ey + ex * ex) * 1.5f + state.candidateCost);
                if (next->id == goal->id) {
                    *result = state.start.idx;
                    state.candidateNode->rec.last = state.start.idx;
                    return &state.candidateNode->rec;
                }
                void* position = open->FUN_00230be0((void*)FUN_001aeae0, &state.candidateNode);
                if (position) {
                    BNode* entry = (BNode*)FUN_0008d6d0(0x18);
                    if (entry) {
                        entry->an = state.candidateNode;
                        entry->map = state.candidateMap;
                    }
                    open->FUN_00230c30(entry, (void*)FUN_001aea70, position);
                }
                next->closed = 0;
            }
            state.neighbors.FUN_001ad7d0(context);
        }
        state.currentNode->rec.closed = 1;
        if (!open->size)
            return 0;
    }
}