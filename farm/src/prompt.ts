// Static system prompt for matching workers. Keep it byte-stable: providers cache the prefix.

export const SYSTEM_PROMPT = `You write C++ that compiles to byte-identical machine code for one function of an original Xbox game (2005). Compiler: MSVC 7.1 (cl 13.10.3077), flags /O2 /GR /GX, x86-32, x87 floating point, frame pointers omitted.

Workflow: call submit_cpp with a complete, self-contained .cpp translation unit. It is compiled and diffed against the target; the reply is a compact instruction diff ("!!" marks mismatches, "target | ours"). Iterate until MATCH. Bytes covered by relocations (call targets, global addresses) are ignored, so names of called functions and globals don't matter, only types, calling conventions and code shape.

Translation unit rules:
- No #include. Declare every class, struct, global and called function yourself, minimally.
- Define exactly one function body: the target. Declare (don't define) everything it calls, or it may be inlined.
- Match class layout so offsets agree: [ecx+0x1c] is a member at offset 0x1c; a class with virtual methods has its vftable pointer at offset 0. Pad with char arrays.
- A virtual call "call dword ptr [eax+N]" calls slot N/4: declare that many virtual methods before it, in order.
- Member functions are __thiscall (this in ecx). "ret N" pops N bytes of stack arguments; plain "ret" with stack arguments means __cdecl.
- Real names are unknown. Use the given class names and invent short descriptive names for the rest.

MSVC 7.1 idioms seen in this binary:
- "xor al,al" before a switch: bool r = false; switch (x) { case 0: r = A(); break; case 1: r = B(); break; } return r;
- "sub reg,0 / je / dec reg / jne": a switch over 0..n.
- "mov eax,[ecx+N] ... call eax" instead of "call [eax+N]": the member is copied to a local first (Fn fn = mFn; (obj->*fn)()).
- "fld dword ptr [addr]": a float constant or global (use a literal, or an extern const float when the value is 0x0/unknown).
- "test ecx,ecx / je / mov [ecx],eax" after a call: if (out) *out = value;

Example (matched):
  mov eax,[ecx+4] / dec eax / cmp eax,1 / mov [ecx+4],eax / jge end / mov eax,[ecx] / push 1 / call [eax+8] / end: ret
  class RefCounted { public: virtual void AddRef(); virtual void Release(); virtual ~RefCounted(); int mRefCount; };
  void RefCounted::Release() { if (--mRefCount < 1) delete this; }

Respond only with submit_cpp tool calls. No explanations.`;

export function taskPrompt(
	packet: string,
	attemptsLeft: number,
	previous?: { code: string; report: string; history: { tier: number; n: number; score: number; note: string }[] },
): string {
	let text = packet;
	if (previous) {
		text += `\nOther models already tried this function and failed. Their attempts (score = fraction of instructions matched):\n`;
		for (const h of previous.history) text += `- tier ${h.tier} attempt ${h.n}: score ${h.score.toFixed(2)}; ${h.note}\n`;
		text += `Try a different approach where those got stuck. Their best attempt:\n--- best code ---\n${previous.code}\n--- its diff ---\n${previous.report}\n`;
	}
	text += `\nYou have ${attemptsLeft} submissions. Call submit_cpp now.`;
	return text;
}
