// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 14/14)
// FUN_00257290 @ 0x00257290
// Write the "mSeqTrackList" block: every track in the linked list, one per line.
struct Writer {
    char pad0[0x24];
    int indent;
};

struct Archive {
    Writer* writer;
};

char FUN_00246f50(Writer* writer, const char* fmt, ...);

struct Link {
    Link* next;
};

class Track {
public:
    virtual char Write(Archive* ar);
    char pad4[0x10];
};

class TrackItem : public Track, public Link {
};

class SeqTrackList {
public:
    char pad0[0x3c];
    Link* first;

    bool FUN_00257290(Archive* ar);
};

bool SeqTrackList::FUN_00257290(Archive* ar)
{
    if (!FUN_00246f50(ar->writer, "mSeqTrackList\n[\n")) {
        return false;
    }
    ar->writer->indent++;
    for (TrackItem* track = static_cast<TrackItem*>(first); track != 0; track = static_cast<TrackItem*>(track->next)) {
        if (!track->Write(ar)) {
            return false;
        }
        if (!FUN_00246f50(ar->writer, "\n")) {
            return false;
        }
    }
    ar->writer->indent--;
    return FUN_00246f50(ar->writer, "]\n") != 0;
}
