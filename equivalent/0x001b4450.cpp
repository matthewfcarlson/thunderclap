// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_001b4450 @ 0x001b4450
typedef unsigned int uint;
extern uint DAT_004c39e8, DAT_004c39ec, DAT_004c39f0, DAT_004c39f4, DAT_004c39f8, DAT_004c39fc, DAT_004c3a08, DAT_004c3a0c, DAT_004c3a10, DAT_004c3a14, DAT_004c3a18, DAT_004c3a1c, DAT_004c3a20, DAT_004c3a24;
struct Payload { char pad[0x58]; uint firstLow, firstHigh, combinedLow, combinedHigh; };
struct Subject;
struct Record { char pad[8]; Subject* owner; uint kind; char pad2[0x64]; Payload* payload; };
struct Subject { char pad[0x1d9]; unsigned char flag; bool FUN_001d64c0(); Record* FUN_001d72e0(); };
struct Sink { void FUN_002ee6b0(Payload*); };
struct Controller { char pad[8]; Sink* sink; bool target(Subject* subject, bool force); };
bool Controller::target(Subject* subject, bool force) {
 if (!force && subject->FUN_001d64c0()) return false;
 Record* record = subject->FUN_001d72e0();
 if (!record || !record->payload) return false;
 Payload* p = record->payload;
 record->owner = subject;
 p->firstLow = DAT_004c39e8;
 p->firstHigh = DAT_004c39ec;
 p->combinedLow = DAT_004c3a20 | DAT_004c3a10 | DAT_004c39f8 | DAT_004c39e8 | DAT_004c3a08 | DAT_004c3a18 | DAT_004c39f0;
 p->combinedHigh = DAT_004c3a24 | DAT_004c3a14 | DAT_004c39fc | DAT_004c39ec | DAT_004c3a0c | DAT_004c3a1c | DAT_004c39f4;
 Payload* finalPayload = record->payload;
 record->kind = 5;
 sink->FUN_002ee6b0(finalPayload);
 subject->flag = 0;
 return true;
}
