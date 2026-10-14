// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 14/14)
// FUN_0024b170 @ 0x0024b170
// Pump a streaming ring buffer: refill what the play cursor has consumed and switch to the
// "finished" state (5) once the data runs out.
struct Ring_24b170 {
    char pad0[4];
    unsigned int size;
    char pad8[0x18 - 8];
    unsigned int readPos;
    unsigned int fillEnd;
    unsigned int pending;
    unsigned int filled;
};

struct Stream {
    char pad0[8];
    void* handle;
    char padc[4];
    Ring_24b170* ring;
    char pad14[0xc0 - 0x14];
    int state;
    int mode;
};

unsigned int __cdecl FUN_00258f00(void* handle);
bool __cdecl FUN_0025e350(Ring_24b170* ring, unsigned int count);
int __cdecl FUN_00259c50(void* handle);
void __cdecl FUN_00258e50(void* handle);

// equiv-conv: FUN_0024b170 eax
bool FUN_0024b170(Stream* s)
{
    unsigned int pos = FUN_00258f00(s->handle);
    Ring_24b170* r = s->ring;
    unsigned int start = r->readPos;
    unsigned int count;
    if (start > pos) {
        count = r->size - start + pos;
    } else {
        count = pos - start;
    }
    if (count != 0) {
        if (!FUN_0025e350(r, count)) {
            return false;
        }
        r = s->ring;
        if (r->filled >= r->fillEnd) {
            if (r->pending > 0 || s->mode == 5) {
                if (FUN_00259c50(s->handle) == 1) {
                    FUN_00258e50(s->handle);
                }
                s->state = 5;
                s->ring->filled = s->ring->fillEnd;
            }
        }
    }
    return true;
}
