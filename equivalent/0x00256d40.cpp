// STATUS: equivalent (tools/equiv.py level 3: 154 inputs, branch coverage 8/8)
// FUN_00256d40 @ 0x00256d40
struct Tail { void FUN_002607a0(); };
struct Link { Link *next; Link *previous; };
struct SeqTrack {
    void *vptr;
    char reserved[0x10];
    Link link;
    Tail tail;
};
struct List { Link *first; Link *last; };
extern void *DAT_0042a600[];
void * __cdecl FUN_00262030(SeqTrack *track);
void __cdecl FUN_00247550(void *p);
void __cdecl FUN_00256d40(List *list) {
    while (list->first) {
        Link *link = list->first;
        SeqTrack *track = (SeqTrack *)((char *)link - 0x14);
        if (!track) break;
        if (link->previous) link->previous->next = link->next;
        else list->first = link->next;
        if (link->next) link->next->previous = link->previous;
        else list->last = link->previous;
        track->vptr = DAT_0042a600;
        track->tail.FUN_002607a0();
        FUN_00247550(FUN_00262030(track));
    }
}