// STATUS: equivalent (tools/equiv.py level 3: 712 inputs, branch coverage 12/12)
// FUN_00261e60 @ 0x00261e60
struct Writer {
    char pad00[0x24];
    int depth;
};

struct Output {
    Writer *writer;
};

char __cdecl FUN_00246f50(Writer *w, const char *fmt, ...);

struct Link {
    Link *next;
};

struct Elem {
    float value;
    Link link;
};

static Elem *ElemOf(Link *l)
{
    return l ? (Elem *)((char *)l - 4) : 0;
}

class FloatList {
public:
    Link *head;
    bool FUN_00261e60(Output *out);
};

// Writes "[\n", one "%f\n" line per element, then "]\n".
bool FloatList::FUN_00261e60(Output *out)
{
    if (!FUN_00246f50(out->writer, "[\n"))
        return false;
    out->writer->depth++;
    for (Elem *e = ElemOf(head); e; e = ElemOf(e->link.next)) {
        if (!FUN_00246f50(out->writer, "%f\n", (double)e->value))
            return false;
    }
    out->writer->depth--;
    return FUN_00246f50(out->writer, "]\n") != 0;
}
