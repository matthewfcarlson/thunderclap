#!/usr/bin/env python3
"""Regression cases for tools/equiv.py: sources that a checker bug once got wrong.

  build/venv/bin/python tests/equiv/regress.py [--jobs 4] [--only NAME] [--jobq [--name AGENT] [--per N]]

--jobq runs the cases as jobs of the shared queue (tools/jobq.py, docs/compute.md), spread over the hosts, with the
working tree's uncommitted tools/ and tests/ files shipped along.

Each case is a source in tests/equiv/cases/ (named 0xADDR_what.cpp) with the status it must get, a
piece of the mismatch text that shows the right thing was caught, and for some a minimum branch coverage.
Skips when the game files are absent.
"""
import argparse
import os
import sys
import time
from multiprocessing import Pool

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
CASES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "cases")

# name: (expected status, text one of the mismatches must contain or None[, minimum branch coverage[, verify()
# keyword arguments, e.g. the seeds of the one input in thousands that showed the bug]])
CASES = {
    # a stack local smaller than what the (stubbed) callee writes through the pointer
    "0x00241390_small_local": ("fail", "writes 0x40 bytes through ecx"),
    "0x00324e00_small_local": ("fail", "writes 0x8 bytes through argument 1"),
    # declared void, reached through a vtable, but the original returns the allocation in eax
    "0x0026ce10_void_eax": ("fail", "in eax"),
    # __security_check_cookie is __fastcall (cookie in ecx), not __cdecl
    "0x000bb600_cookie_cdecl": ("fail", "__security_check_cookie"),
    # a struct passed by value (0x2b8 bytes): the stub pops more than a trampoline's `ret N` covers
    "0x000bb600_big_pop": ("equivalent", None),
    # a wrong texcoord index far into a 192-byte vertex array passed as `const void*`
    "0x00323130_array_tail": ("fail", "the local passed as argument 3 differs"),
    # a callee with a plain ret (caller pops) declared as an ordinary thiscall member
    "0x00329f70_caller_pops": ("fail", "really pops 0"),
    # a WAVEFORMAT reached through a pointer inside the descriptor passed to the callee
    "0x00259610_nested_local": ("fail", "points to"),
    # equiv-conv on tail jumps
    "0x0026b500_conv_tail": ("equivalent", None),
    # a stub must not clobber registers the callee preserves
    "0x0026f990_preserved_regs": ("equivalent", None),
    # self-recursion: stubbed on both sides
    "0x001ec480_recursion": ("equivalent", None),
    # an LTCG register argument (esi) pushed on as a call argument is not a register save: the source drops
    # the third argument of FUN_002d7440
    "0x002ad9d0_dropped_arg": ("fail", "2 argument words, expected 3"),
    # an out-parameter compared by the original's branch (directed inputs fill it in); the source's
    # token test is inverted
    "0x0008ed60_outparam_directed": ("fail", "argument 1 is"),
    # varargs: the words beyond an equiv-conv's slots are compared, and the arity is per call site
    "0x00220310_vararg_extra": ("fail", "argument 6 is"),
    "0x001cd220_vararg": ("equivalent", None),
    "0x001cd220_vararg_dropped": ("fail", "4 argument words, expected 5"),
    # a `...` declaration used to pass register arguments (equiv-conv eax ecx): no extra words compared
    "0x00218170_varargs_conv": ("equivalent", None),
    # pushes left for a later call: `push 1; call <jmp [vtable] thunk>; push eax; ...; call f(ret 12)`
    "0x000b63a0_pending_thunk": ("equivalent", None),
    # a caller-cleaned virtual call whose words are reused as arguments of the next call
    "0x0013d7b0_shared_pushes": ("equivalent", None),
    "0x0004c7c0_pending_vcall": ("equivalent", None),
    # a thiscall vcall (ret 4) among words pushed early for a cdecl call of unknown arity; the deferred
    # `add esp, 0x18` after two later calls releases all but the vcall's word
    "0x001c1a40_deferred_vcall_pop": ("equivalent", None, 0.9),
    # an equiv-conv register-argument callee declared cdecl: our pushed word, cleaned up later, isn't an
    # extra argument of the next call
    "0x0021b230_conv_deferred_pop": ("equivalent", None, 0.9),
    # two switches whose jump tables sit back to back: the first table ends where the second starts
    # (read up to the first non-code word, it took the second's cases: 40/45 edges instead of 40/41)
    "0x001a5f00_two_tables": ("equivalent", None, 0.95),
    # a vcall (ret 0xc) followed by `add esp, 0x10` that releases the prologue's `sub esp, 0x10` frame, not
    # its arguments: the original faulted on every input when it was taken for cdecl cleanup
    "0x0028d2a0_frame_epilogue": ("equivalent", None),
    "0x002fb440_hoisted_push": ("equivalent", None),
    # stdcall imports through their kernel slots (`call [0x3f2c8c]`, RtlEnterCriticalSection) after other calls: the
    # import's pop isn't guessed from later code (round 13: radcore's job teardown replaces XAPILIB's 0x00212641,
    # library code that is never checked; pending_use's import-slot rule is taken at the same shape of calls)
    "0x0026dad0_import_pop": ("equivalent", None, 1.0),
    "0x0026dad0_import_pop_wrong": ("fail", "argument 1 is 0x0052a18c"),
    # string compares against .rdata literals: directed inputs plant the literal in the compared buffer
    # (`repe cmpsb` against "jp"-style literals; CRT strncmp called with a literal; a chain of
    # strcmp/strncmp where the second compare is only reached once the first matches)
    "0x00206320_repe_cmpsb_literal": ("equivalent", None, 0.95),
    "0x000c1790_strncmp_literal": ("equivalent", None, 0.9),
    # (round 9: the source had curBucket at +0x234 where the original reads +0x230; a directed input now sets the
    # `streamed` byte out-parameter and reaches it. Fixed here: buckets[7]. equivalent/0x001ff770.cpp has the bug)
    "0x001ff770_strcmp_chain": ("equivalent", None, 0.75),
    # a callee that never returns (luaD_throw -> longjmp): both runs stop there
    "0x00215790_noreturn": ("equivalent", None),
    # switch cases reached through the selector's source (a stub's result, `add eax, -2; cmp eax, 9`), never
    # by patching the byte table in .text; both sources map cases to the wrong fields
    "0x001b0310_switch_cases": ("fail", "returned"),
    "0x00321ea0_switch_cases": ("fail", "returned"),
    # &self stored as a member function pointer: our symbol is the original's address
    "0x000e7930_self_address": ("equivalent", None),
    # a loop's induction base at another field of the same global (level 2)
    "0x001b3c50_induction_base": ("equivalent", None),
    # a typed struct out-parameter
    "0x0021d630_typed_outparam": ("equivalent", None),
    # coverage: loops over begin/end pairs and magic-number divisions (loop repair), a type switch done with
    # dec/sub, float compares, a printf format parser (bytes kept in a local, a byte-table switch)
    "0x002ff3f0_loop_bounds": ("equivalent", None, 0.75),
    "0x00096b50_arith_compare": ("equivalent", None, 0.75),
    "0x000fbc00_format_parser": ("equivalent", None, 0.75),
    # false failures found re-checking equivalent/: a big frame's `add esp` is no argument cleanup; a virtual
    # call's words reused by a later call through another caller-cleaned virtual; `this + 0xb4 != 0`
    # (a base-class null check) is not a test to steer; a /GS cookie load inside the prologue; strings
    # reached through a table in .rdata can be patched (the table's own pointer is a fixed address)
    "0x0008c680_frame_release": ("equivalent", None),
    # (round 15, argcall: this source declares FUN_000fd8a0 (ret 0x10) with 2 words; the other two are v14's
    # arguments, which v14 leaves on the stack: fd8a0 takes (owner, r, out1, f), as 0x000a1930 declares it. The words
    # compare alike either way; the declaration is wrong, so it fails now)
    "0x000991b0_chained_vcalls": ("fail", "belong to another call"),
    "0x0003a680_base_null_check": ("equivalent", None),
    "0x0008e880_cookie_prologue": ("equivalent", None),
    "0x000d3f10_string_table": ("equivalent", None, 0.75),
    # round 5. A fuzzed function pointer that lands inside the function itself (an unaligned read of a heap
    # pointer and a small int spells 0x000f4004): the original ran its own code from there, ours stubbed a
    # call; and the same in our run (a string read as a vtable gives 0x60000001)
    "0x000f3f00_wild_call": ("equivalent", None, 0.9, {"seeds": list(range(32)) + [7913]}),
    "0x001b7f40_wild_call_ours": ("equivalent", None, 0.9, {"seeds": list(range(32)) + [2726]}),
    # a call through [0xffffffff]: the stub read the target without wrapping around to address 0
    "0x00272df0_wrapped_read": ("equivalent", None, 0.9, {"seeds": list(range(32)) + [1568]}),
    # an unbounded copy into a 4-byte stack buffer overwrites the return address: the original returns into
    # junk (fault kinds differ by frame layout); the run stops where control leaves the function
    "0x0026f290_both_fault": ("equivalent", None, 0.9, {"seeds": list(range(32)) + [203, 335, 543]}),
    # a by-value argument built in place by a stubbed copy constructor (`sub esp, 8; mov ecx, esp; push src;
    # call ctor`): its first word held each side's own dead return address
    "0x001db230_copy_ctor_temp": ("equivalent", None, 0.9, {"seeds": list(range(32)) + [142, 190, 214]}),
    # ... and that dead return-address slot no longer bounds the room the original has there: the local
    # passed to the Event constructor (0x28 bytes) is too small in this source
    "0x001d8350_dead_ret_slot": ("fail", "writes 0x28 bytes through ecx"),
    # `mov edi, edi` (alignment padding) before a lazy `push edi` register save: not an argument word
    "0x00087630_nop_move": ("equivalent", None, 0.9),
    # `dist < 15` on the sqrt of the difference of two stub-filled vectors, a dot product of two others
    # `< -0.9`: directed inputs set every stub float alike (0, +1/-1 by turns, 1000)
    "0x00107410_stub_floats": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    # `push eax; push K; call <jmp [vtable] thunk>; mov ecx, eax; call f (ret 4); push x3; call g; add esp,
    # 0x10`: f pops K and the caller releases eax, so the thunk pops nothing (it popped K, and the stack
    # drifted by a word)
    "0x000c2c20_thunk_shared_push": ("equivalent", None, 0.9),
    # `test eax, eax; jge` on a word behind a stubbed pointer: directed inputs plant -1, not just 0 and 1
    "0x00117150_sign_test": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    # byte out-parameters at odd frame offsets (`char found, flagA, flagB`): filled (and steered) too
    "0x000bfa10_byte_outparams": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    # a float branch leaves the x87 status word in ax and sets only al (`fnstsw ax; ...; mov al, 1; ret`):
    # only al is a result; a wrong al still fails
    "0x000452e0_status_word": ("equivalent", None, 0.9),
    "0x000452e0_status_word_wrong_al": ("fail", "returned 0x00000002"),
    # loop repair patches the loop's back-edge compare first, not the hottest compare (colour clamps inside
    # the loop): a 7 KB vertex emitter went from 182 to about 300 of 382 edges
    # (random input 80 shows a real difference in this source, under the round-5 checker too: a heap write
    # missing when fuzzed pointers alias; round 6 reaches it, so the case stops before it)
    "0x002c96e0_loop_back_edge": ("equivalent", None, 0.75, {"n_inputs": 3000, "seeds": list(range(80))}),
    # the two selftest failures of rounds 3-4: `L"()"` stored without its terminator in the original
    # ("()[]{}" packed pairs), and MSVC's `vector constructor iterator` (our COMDAT copy vs the XBE's
    # FUN_00011520)
    "0x003388d0_unterminated_literal": ("equivalent", None),
    "0x00312db0_vector_ctor_iterator": ("equivalent", None),
    # an RTTI type descriptor (??_R0, a dynamic_cast operand) binds by class name (level 2)
    "0x002867b0_rtti_by_name": ("draft", None, 0, {"max_level": 2}),
    # round 6. The real callee (a Key constructor, static extent 8 bytes through ecx) overwrites a dead spill
    # slot the original's frame has inside the object: filled on both sides, not left as each side's own
    "0x00040550_spill_in_extent": ("equivalent", None, 0.9),
    # a constructor returns `this`: `new (buf) Cue(...)` hands the stub's eax on where the original recomputes
    # `lea ecx, [buf]`
    "0x00081b20_ctor_returns_this": ("equivalent", None, 0.8, {"seeds": list(range(32)) + [341], "n_inputs": 400}),
    # `je L; push x5; call [vt+0x48] (ret 4); push eax; call __RTDynamicCast; add esp, 0x14; L:`: the branch
    # around it fixes the vcall's pop (it was taken for caller-cleaned, and the stack drifted by a word); with
    # --inputs 3000 the directed phase now gets half the time budget
    "0x000ea7c0_dyncast_vcall_pop": ("equivalent", None, 0.8, {"n_inputs": 3000}),
    # `sub esp, 0x14; ...; push x6; call [esp+0x3c]; ...; add esp, 0x14; ret`: the epilogue releases the
    # frame only, so the call through a stack argument pops its six words
    "0x0009b560_epilogue_frame": ("equivalent", None),
    # a running sum kept on the x87 stack across a call: the `fadd` after it doesn't consume a float result
    "0x00295270_x87_live_across_call": ("equivalent", None, 0.9, {"equiv_off": "ftolexact"}),
    # loop repair takes the outer loop's patchable back edge (or a top-tested loop's exit), not the hottest
    # back edge (an inner loop over a constant bound, `cmp edx, 8; jb`)
    # (random input 164 fails, as under the round-5 checker: an aliasing-dependent write to arg2+0x18. Round 9's
    # small loop counts can reach a real difference of this source on seed 128 (128+small: the original writes
    # 0xff000000 through a null-page pointer, ours doesn't), so the case stops before it)
    "0x002cb2b0_loop_exit_order": ("equivalent", None, 0.75, {"n_inputs": 3000, "seeds": list(range(128)), "equiv_off": "ftolexact"}),
    # a float result returned untouched across the /GS cookie check (ours spills it around the call)
    "0x000dfbf0_float_ret_cookie": ("equivalent", None),
    # `rep stosd` over a fuzzed count read from memory: repaired like a loop bound, so 50 inputs complete
    "0x0028c2a0_rep_count": ("equivalent", None, 0, {"n_inputs": 3000}),
    # `~VectorChannel` ends in `jmp ~SimpleChannel` (the original inlined it): the target symbol is picked with
    # the tail-jumped function's bytes appended, and the jump runs in place with its prologue's push known
    "0x0028bcd0_tail_jmp_local": ("equivalent", None, 0.75),
    # a plane count read from this+0x634 times out on fuzzed values: repaired inputs no longer count toward
    # the 32-inconclusive cap of the random phase
    # (round 9: the small-count input 2551+small shows a float difference at fuzzed extremes in this source, -inf
    # where the original stores -5.3e33 for an argument of call #10; the case stops before it)
    "0x0003c1d0_count_cap": ("equivalent", None, 0.75, {"n_inputs": 3000, "seeds": list(range(2500)), "equiv_off": "ftolexact"}),
    # std::_Unguarded_partition over [first, last) of 0x44-byte items: a pointer argument a few elements
    # past the first one, in a step the code advances by (fuzzed ranges ran millions of elements)
    "0x003037f0_iterator_range": ("equivalent", None, 0.75, {"n_inputs": 3000}),
    # `fld [this+0x6c]; call f (void); fstp [this+0x6c]`: the value was on the x87 stack before the call, so the
    # fstp doesn't consume a float result (the stub pushed one, and the original stored 0.25f). Past that, the
    # source passes FUN_00025260's arguments in reverse: the failure the checker must now reach
    "0x001050d0_fstp_after_void_call": ("fail", "to 0x00025260: argument 1 is 0x00000000, expected 0x00000001"),
    # 22 name-hash compares (stub u64 vs a field): the directed phase tried every observation of one compare
    # before the next got a turn, and string plants used the whole budget (82/122 edges)
    "0x000ffef0_compare_chain": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    # `cmp eax, eax; je` after a loop (a compiler artefact): its not-taken side is dead, not uncovered (7/10 ->
    # 7/9 edges)
    "0x000e4470_self_compare": ("equivalent", None, 0.75),
    # a float argument the original stores with fstp and ours copies with `push ecx` from a float local:
    # compared with the float tolerance (the vectors a Vec3 transform fills now differ from (1, 0, 0), and
    # the x87 rounds one side's value once more)
    "0x002b9ac0_float_arg_copied": ("equivalent", None, 0, {"n_inputs": 3000}),
    # a callee whose only "write" to ecx is alignment padding (`lea ecx, [ecx]`) keeps ecx: the original calls
    # the next method with the leftover `this`
    "0x00205860_padding_keeps_ecx": ("equivalent", None),
    # round 7. A float compare whose directed patch (|y| * 1.5) is past float range: skipped, not an
    # OverflowError (two equivalent/ functions crashed)
    "0x0004c1f0_float_range": ("equivalent", None, 0.9),
    # `jmp _ftol` (a tail jump to a CRT helper) from an equiv-conv function: runs for real, so its st0 operand
    # is compared through the return value (it was stubbed: our cdecl's 3 incoming words counted as its
    # arguments, against the original's 1, and a wrong float went unnoticed)
    "0x002208e0_tail_ftol": ("equivalent", None, 0.9),
    "0x002208e0_tail_ftol_wrong": ("fail", "returned 0x00000064"),
    # merged source-tree objects (tools/build_tree.py) wrap a function in `namespace fn_<addr>`: sizeof probes
    # of callee parameter types, equiv-map lines and vftables (by RTTI name) must see through it
    "0x00040550_tree_probe_sizes": ("equivalent", None, 0.9),
    "0x0002b970_tree_explicit_map": ("equivalent", None),
    "0x000306e0_tree_vftable": ("equivalent", None),
    # `lea ecx, [esi + 4]; add esp, 0xc; test ecx, ecx; ...; je` (`if (&tag)`): this == -4 never happens, so
    # the zero side is dead, and so is the code only it reaches (7/20 -> 7/7)
    "0x00203bb0_lea_null": ("equivalent", None, 0.95),
    # a void virtual whose original leaves eax == 0 from a switch's `dec eax; jne` chain: a value tested
    # through the flags is read, so it doesn't count as a result left in eax (0x26ce10_void_eax still fails)
    # four calls through a cdecl writer callback share one `add esp, 0x40` 31 instructions later: it was out
    # of cleanup_after's 24-instruction window, the first call was taken to pop its words, and every input
    # went wild at the final ret (the log blamed stub writes through &byte)
    "0x0021acc0_shared_cleanup": ("equivalent", None),
    "0x0021acc0_shared_cleanup_wrong": ("fail", "differs at +0x0 (0x5a5a5a50, expected 0x5a5a5a51)"),
    # a constructor making 100 objects with 66 stub calls each runs past 50k steps on every input, and the
    # thousands of calls kept the 1M budget away (that rule is for loops a stubbed callee keeps going): one
    # input run with 8M steps shows the code ends, and later inputs get twice its steps
    "0x00280690_step_probe": ("equivalent", None, 0.9, {"n_inputs": 12, "max_inputs": 12}),
    # `mov ax, [buf]; cmp al, 0x42; jne; cmp ah, 0x4d` on a 'BM' magic a stubbed read filled: ah is the
    # loaded word shifted right by 8, so a directed input can plant 'M' after 'B' (3/20 -> 20/20)
    "0x002afa60_ah_magic": ("equivalent", None, 0.95),
    # `v.z == 0` on a vector FUN_0022d240 fills by passing its ecx on to FUN_0022c2b0, which writes it with
    # fstp: capstone marks x87 store operands read-only, so the extent was empty and the word never filled;
    # now filled, a directed input can fill in an exact 0.0 (1/2 -> 2/2)
    "0x00292cc0_fstp_extent": ("equivalent", None, 0.9),
    # `fld [g]; fadd [k]; fst [g]; fcomp [0.95]` on a .data float: the fadd is inverted to steer g (1/2 -> 2/2)
    "0x000fee10_fadd_global": ("equivalent", None, 0.9),
    # an atof-style parser (`cmp al, '.'`, `cmp al, '0'; jl`, `cmp al, '9'; jg` per char): strings made of the
    # chars the loop compares with are planted where it read its first byte (16/22 -> 20/22)
    "0x00260d00_alpha_digits": ("equivalent", None, 0.85),
    # a 0x2c0-byte struct passed by value: the input had only 4 words of it, the rest was STACK_FILL on both
    # sides. Now the input has as many words as the function's `ret 0x2c0` pops, and the source's lua_State
    # field turns out to be at +0x2b8 where the original reads +0x2bc (it passed under round 6, 14/20)
    "0x001d2190_bigstruct_arg": ("fail", "call #1 to 0x002133d0: argument 1 is"),
    # a tail call (`jmp [edx+0x28]`) out of an equiv-conv function (eax esi edi): ours passes on its 3 cdecl
    # stack words, the original none; the original's count is compared (round 6 blamed prologue pushes)
    "0x002adb10_conv_tail_vcall": ("equivalent", None, 0.9),
    # a byte flag passed in cl/dl (equiv-conv) over whatever the caller left in the high bytes: the real
    # callees read only cl/dl, so only the low byte is compared (a wrong flag still fails)
    "0x002d0a50_byte_flag_reg": ("equivalent", None, 0.9),
    "0x002d0a50_byte_flag_reg_wrong": ("fail", "argument 2 is 0x00000002"),
    # `and eax, 0x7fffffff` (fabs) on an argument, stored to a slot, then `fld; fucompp` against pi/2: the
    # mask is exact, so the tie is planted through the argument (1/2 -> 2/2)
    "0x000f1bd0_fabs_tie": ("equivalent", None, 0.9),
    # `p[0] == 'c' && p[1] == 'l' && p[2] == 'a' ...` on a stack copy of a string a stub returned: the
    # keyword spelled by the compares is planted in the string the copy loop read (18/36 -> 29/36)
    "0x0028fbc0_copied_keyword": ("equivalent", None, 0.78),
    # `// equiv-dead: +0x63 taken: ...`: a hand-reviewed dead branch side (here also found by the lea rule),
    # and the code only it reaches, are left out of the coverage count and listed in the report
    "0x00203a80_declared_dead": ("equivalent", None, 0.95),
    # a 16-byte struct passed by value whose 6 uncopied pad bytes hold the previous call's return address on
    # each side (0x001f977a vs 0x600000aa): the same earlier call's return address is equal
    "0x001f9710_stale_retaddr": ("equivalent", None, 0.9),
    "0x0009d1b0_void_dec_chain": ("equivalent", None, 0.75, {"seeds": list(range(32)) + [524, 1598, 1862]}),
    # round 8. `c->u.f(L)` through a fuzzed lua_CFunction (`push esi; call [ecx+0xc]; add esp, 4`): the caller
    # pops the call's words right after it, so the callee is cdecl and ecx isn't its argument (it was compared
    # because ecx == [ecx] on the null page made it look like a virtual call)
    "0x00215790_cdecl_ecx": ("equivalent", None, 0.9, {"seeds": list(range(32)) + [79]}),
    # ... and a later call through the same field ([esi+4], Lua's writer callback) whose cleanup is shared
    # with the next call's (`call [esi+4]; ...; push x4; call [esi+4]; add esp, 0x20`)
    "0x0021a830_cdecl_field": ("equivalent", None, 0.9, {"seeds": list(range(32)) + [50, 99]}),
    # a void virtual whose original leaves a callee's result in eax after only dereferencing it
    # (`cmp [eax+0x221c], ebx`): not evidence that it returns it
    "0x000da930_deref_result": ("equivalent", None, 0, {"seeds": [9]}),
    # an input that times out inside a CRT helper run for real (no jcc of the function counted): the loop
    # repair's candidate list crashed with `max()` of an empty sequence
    "0x0028ff00_helper_timeout": ("equivalent", None, 0.9, {"seeds": list(range(32)) + [105]}),
    # (round 13: the overlap_ub cases on LIBCMT's strncat, 0x003468c0, are gone: library code is never checked, and
    # the rule only applies to a CRT copy routine under test; test_equiv.py's test_copy_overlap tests it)
    # `buf[len] = 0` with a fuzzed len lands on the original's saved ebx: a buffer overrun into saved
    # registers or the return address is undefined behaviour, so the input is inconclusive; a wrong bound
    # still fails
    "0x001f0090_buf_overrun": ("equivalent", None, 0.9),
    "0x001f0090_buf_overrun_wrong": ("fail", "missing call"),
    # `sete byte ptr [esp+0x1c]` (a setcc into memory) was never counted, and `lea ecx, [ebp+3]; cmp ebp, ecx;
    # jae` is taken only when the pointer wraps past 2^32 (15/22 -> 17/19)
    "0x0023c040_wrap_setmem": ("equivalent", None, 0.85, {"n_inputs": 400}),
    # `xor eax, eax` before a list walk, then `test eax, eax; jne`: eax is 0 on every path (constant
    # propagation, with `test r, r; je L` making r 0 at L), so the taken side is dead (22/30 -> 22/28)
    "0x00233990_const_flags": ("equivalent", None, 0.75, {"n_inputs": 3000}),
    # a polygon clipper: 21% of the random inputs run away (fuzzed vertex counts), the 32-inconclusive cap
    # stopped them at 121 completed with 46/72 edges; under 75% the time left goes to more random inputs
    # (~100 s: 66/72)
    "0x00359a80_cov_cap": ("equivalent", None, 0.75, {"n_inputs": 3000}),
    # round 9. `call f; call __ftol2; test eax, eax; jle; cmp eax, 8; jge`: the stub returns a float for the helper
    # to convert (it read an empty x87 stack), and the integer compares are steered through that float (14/20 ->
    # 20/20); `n >= 0` for `n > 0` is caught on the newly reached sides
    "0x000f3dc0_ftol_range": ("equivalent", None, 0.95, {"n_inputs": 3000}),
    "0x000f3dc0_ftol_range_wrong": ("fail", "write to", 0, {"n_inputs": 3000}),
    # `fst [esi+0xb4]; fld [pi/2]; fsubr st(1); fstp [esp+8]; and [esp+8], 0x7fffffff; fld [esp+8]; fcomp [eps]`:
    # a stub's float result through register arithmetic, a store, a fabs in memory and a reload (7/10 -> 10/10)
    "0x00083e60_fabs_fret": ("equivalent", None, 0.95, {"n_inputs": 3000, "equiv_off": "ftolexact"}),
    # `|f218 + step * clamp(f218^2 k) - 0.6| <= 0.02` with the mask in a register (`and [esp+4], edx`); 0.02 is
    # a float the original keeps in .data and ours as a literal: planting it changed the original alone (3 false
    # failures before the plant was limited to words our code reads too) (11/18 -> 17/18)
    "0x000c8f50_fabs_reg_mask": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    # `|sqrt(x*x + y*y + z*z) - 1| < eps` and dot products of a matrix's rows: computed from 9 fields, no single
    # word to invert; the floats the x87 read are planted as an identity matrix, all 1 and all 0 (5/12 -> 11/12)
    "0x0022cf90_matrix_rows": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    # png cHRM: `fabs(x - c) >= tolerance` chains on stored, reloaded floats (22/38 -> 38/38)
    "0x002e8f80_chrm_chain": ("equivalent", None, 0.95, {"n_inputs": 3000}),
    # `bl = (FUN_000443c0() == DAT_004dc0c8)` (a u64: `mov bl, 1` after two jne) tested much later, `test bl, bl;
    # je`: steered through the compares that decided it, one after the other; `cl = (len > 1)` likewise; F == 0.0f
    # on a stub float stored and reloaded; and `lea edi, [esi+0x1f58]` ... calls, branches ... `test edi, edi; je`
    # is dead without the source's equiv-dead line (27/43 -> 40/42)
    # (chk1: 9 of those edges are reached only by directed inputs built on seed 97, whose fuzzed pointer stores into the
    # original's .text on both sides, `code_write`; since maskedges such inputs add no coverage, 31/43. The case tests the
    # steering, so it keeps the old count with maskedges off)
    "0x0010b5b0_flag_via": ("equivalent", None, 0.9, {"n_inputs": 3000, "equiv_off": "maskedges"}),
    # a Lua binding's signature loop: `movsx eax, sig[i]; add eax, -0x56; cmp eax, 0x20; ja; movzx edx, byte
    # [eax + map]; jmp [edx*4 + tab]`, each char read after a call (a new memory epoch); strings of one char per
    # case are planted for every epoch, round robin with the result loop's (28/51 -> 48/51); a wrong Lua type
    # for 'f' is caught
    "0x001d22a0_sig_switch": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    "0x001d22a0_sig_switch_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # `k = node->f(); if (k != wantType) return; switch (k) { case 8..12 }`: the stub result must equal a field
    # and fall in a range at once; a patch of one moves the other (9/18 -> 17/18). The source this came from
    # adds 1.5708f where the original adds pi/2 (1.5707964f): caught on the case it now reaches
    "0x0004cbe0_eq_range": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    "0x0004cbe0_eq_range_wrong": ("fail", "to 0x00224fc0: argument 1", 0, {"n_inputs": 3000}),
    # `char hit = 0; this->v8(&a, &b, &hit); if (hit) ...`: a byte out-parameter the function set itself is left
    # alone by random inputs, a directed input has the callee write it (45/70 -> 70/70); a sign error in the
    # newly reached half is caught
    "0x0015d920_byte_outparam_set": ("equivalent", None, 0.95, {"n_inputs": 3000, "equiv_off": "ftolexact"}),
    "0x0015d920_byte_outparam_set_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # 128 groups, each destroying an array-new'd array whose count is the word before it: every input ran
    # away, and the 8M-step probe took 100 s. The loads that fed the runaway loops' bounds read small counts in
    # a discovery run of the original, then the input runs again with those counts in its memory (unsupported
    # -> 8/8, 63 inputs)
    "0x000e36c0_small_counts": ("equivalent", None, 1.0, {"n_inputs": 3000}),
    # `read(&hdr, 0x1f, 4, 1)` fills 124 bytes; the DXTn fourCC at +0x48 decides a switch, past the 16 bytes a
    # stub fills by default: a directed input has the stub write it (inconclusive 8/35 -> 35/35)
    "0x002de030_fourcc_fill": ("equivalent", None, 0.95, {"n_inputs": 3000}),
    # round 10. `for (i = 0; i < (v->end - v->begin) >> 2; i++) { ...calls... }` with v a stub's result: begin and
    # end are re-read after every call (a new memory epoch each round), so a planted count held for one round only.
    # Small-count steering plants end = begin + a few elements at the `sub`, in every epoch, relative to that epoch's
    # begin (81/122 -> 120/122); a sign error in the newly reached knockback code is caught
    "0x001b4d00_vector_bound": ("equivalent", None, 0.9, {"n_inputs": 3000, "equiv_off": "thisdecl"}),
    "0x001b4d00_vector_bound_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # Lua adjust_varargs: `missing = nfixargs - (L->top - base) / 8` (a stack argument minus a difference of a load
    # and a register), the nil-fill `do {} while (--missing)` writes as it runs away (too_many_pages, not a timeout):
    # the stack argument or the top word is planted (unsupported -> 12/12); a wrong nil tag is caught
    "0x002155f0_diff_bound": ("equivalent", None, 1.0, {"n_inputs": 3000}),
    "0x002155f0_diff_bound_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # tree walks over fuzzed links (`while (n->left != &scene->childNil)`) and a list walk that calls something per
    # entry (`while (e) { f(e); e = e->next; }`, a new epoch each round): a discovery run plants the sentinel into the
    # link it just loaded after 1-3 links, in every epoch (42 -> 90 completed inputs, 44/56 -> 52/56)
    "0x0024a800_walk_end": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    "0x0024a800_walk_end_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # `mov eax, [esp+0xa0]; shl eax, 4; fstp [esp+eax+0x20]`: a count FUN_000f7fe0 fills in its Lay object indexes the
    # cells; a fuzzed -1 stored onto the original's spilled loop counter (input 734+small). Such a fill is drawn 0 or
    # 1 once seen (fail -> 38/38); a wrong store into the indexed cell is caught
    "0x000dcae0_fill_index": ("equivalent", None, 0.95, {"n_inputs": 3000}),
    "0x000dcae0_fill_index_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # 80 lists with fuzzed counts (each loaded once) collect up to 160 points, then an O(n^2) pair loop with a call
    # per pair: counts of 1-4 still give 160 points and a run past the step budget. A round with counts of 0 or 1
    # where the pair loop's bound has no load to plant (26/46, 34 inputs -> 39/46, 79); a swapped coordinate in the
    # pair loop's result is caught
    "0x001fe380_tiny_counts": ("equivalent", None, 0.8, {"n_inputs": 3000}),
    "0x001fe380_tiny_counts_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # round 11. `push 0; call [0x4de948]; ...; push ecx; call [esi+0x18]`: the global function pointer takes no
    # arguments (its other call sites push nothing), so the 0 is the virtual call's second argument. The stub had the
    # pointer pop it, the original's `mov [esp+0x10], eax` then hit its return address and every deep input went
    # wild (inconclusive 7/38 -> 38/38); a wrong second argument of that virtual call is caught
    "0x000e8790_ptr_noargs": ("equivalent", None, 0.95, {"n_inputs": 3000}),
    "0x000e8790_ptr_noargs_wrong": ("fail", "argument 2 is 0x00000001", 0, {"n_inputs": 3000}),
    # `if (start == 0) return;` then ~65k straight-line steps (Perlin tables): inputs 0 and 1 return in 6 steps, so
    # the four timeouts the long budget waited for never came (20 early returns, 1/22). Early returns don't count
    # (inconclusive -> equivalent 21/22); a wrong gradient offset in the newly reached tables is caught
    "0x003572b0_early_returns": ("equivalent", None, 0.9, {"n_inputs": 3000, "equiv_off": "ftolexact"}),
    "0x003572b0_early_returns_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # libpng build_gamma_table: `fld x; fld e; call __CIpow` takes its arguments in x87 registers; the stub left them
    # there, so `end = (int)(pow(...) * n)` was the exponent times n (65536) and the 0x480 path never ended. The stub
    # now replaces them with its result, and a stub float that bounds a runaway loop through __ftol2 is drawn in
    # [0, 1] for that callee (48/80 -> 62/80); a wrong table value in the newly reached 0x480 path is caught
    "0x002dbd90_ftol_unit": ("equivalent", None, 0.72, {"n_inputs": 3000}),
    "0x002dbd90_ftol_unit_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # dlmalloc mallinfo: 10 null-terminated fastbins and 127 circular bins walked at one compare (`for (c =
    # bin->next; c != bin; c = c->next)`), fuzzed nodes shared between bins, heap often in the zero page. Links a
    # walk already loaded are never planted, a bin whose first node's link was loaded before is emptied at its top
    # test, and the long budget isn't spent on walks (unsupported -> 14/14, 116 inputs; the source returns the
    # struct by value, as mallinfo does); a wrong chunk count in the bin walks is caught
    "0x0026bac0_walk_heads": ("equivalent", None, 1.0, {"n_inputs": 3000}),
    "0x0026bac0_walk_heads_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # Lua luaG_symbexec: instruction words from fuzzed memory rarely pass `op < 0x24`, `a < maxstacksize` and the
    # per-mode checks before the switch on op. Runs of words made of field values the compares name (every case of
    # the switch, below each limit) are planted (45/120 -> 92/120); a wrong pc passed to the newly reached
    # FUN_00214250 check is caught
    "0x002142d0_op_words": ("equivalent", None, 0.72, {"n_inputs": 3000}),
    "0x002142d0_op_words_wrong": ("fail", "to 0x00214250: argument 2", 0, {"n_inputs": 3000}),
    # round 12. x87 register arguments of a callee (`fld x; call __CIasin`) are compared like stack arguments;
    # the wrong source drops luaL_checknumber's result and calls asin on an empty x87 stack (x87cmp)
    "0x0033b6d0_x87_arg": ("equivalent", None),
    "0x0033b6d0_x87_arg_wrong": ("fail", "x87 argument st(0) is empty"),
    # a virtual call whose slot's implementations write 8 (16) bytes through a pointer argument: ours must have
    # that room where the original has it (vext); the wrong sources have a 4-byte id and a 12-byte vector
    "0x002a4b00_vslot_room": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    "0x002a4b00_vslot_room_wrong": ("fail", "writes 0x8 bytes through argument 2", 0, {"n_inputs": 3000}),
    "0x002251d0_vslot_room": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    "0x002251d0_vslot_room_wrong": ("fail", "writes 0x10 bytes through argument 2", 0, {"n_inputs": 3000}),
    # slot 0x54 (pop 4): only two implementations write 0x14 bytes through argument 1 (another hierarchy's);
    # pure3d::Camera::vfunc_21 writes nothing there: not an extent to demand
    "0x000a75d0_vslot_unrelated": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    # both sides of `fabs(m[0][0]) > eps` taken by random inputs, never a tie: `>=` differs only there (ties)
    "0x002fbf20_fabs_tie": ("equivalent", None, 0.95, {"n_inputs": 3000}),
    "0x002fbf20_fabs_tie_wrong": ("fail", "this+0x4c", 0, {"n_inputs": 3000}),
    # found by the tie inputs in equivalent/: `time + k <= cutoff` where the original's `test ah, 5; jp` is `<`
    "0x0030e0a0_float_tie": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    "0x0030e0a0_float_tie_wrong": ("fail", "extra call #2 to 0x00319ef0", 0, {"n_inputs": 3000}),
    # a tie never plants a stack address (the other side's frame is elsewhere: Lua gsub's buffer end)
    "0x0033cff0_tie_stack_addr": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    # round 13. `push [eax+4]; call [eax]; pop ecx; ret 4` with no frame: the pop is the cdecl cleanup (it lands on
    # the return-address slot with the call's word left), not an epilogue; the call was taken to pop its word and
    # every input went wild (unsupported -> equivalent); a wrong argument of that call is caught (popret)
    "0x0026dc20_pop_ret_cleanup": ("equivalent", None, 1.0),
    "0x0026dc20_pop_ret_cleanup_wrong": ("fail", "call #2 to", 0),
    # `// cl-flags: /GS` (compare.py now passes it on): a plain `char name[0x20]` gets the compiler's cookie
    # (MATCH 33/34; before, the token was dropped: missing __security_check_cookie); a wrong argument still fails
    "0x000c6d90_gs_flag": ("equivalent", None),
    "0x000c6d90_gs_flag_wrong": ("fail", "argument 2 is"),
    # a struct reached only through a pointer a constructor stub's object holds (`D = B->f5c`, B the allocator
    # stub's result): in the null page, `[D+0x18]` and `[D+0x1c]` both read 0. A directed input points such a
    # pointer at an object whose words all differ (objptr); fx15's pre-fix source reads every field of D 4 bytes
    # too high (round 12: equivalent at 3000 inputs) and fails: `argument 1 is 0x00000808, expected 0x00000707`
    "0x002e22c0_objptr": ("equivalent", None, 0.95, {"n_inputs": 3000}),
    "0x002e22c0_objptr_wrong": ("fail", "to 0x002647e0: argument 1 is", 0, {"n_inputs": 3000}),
    # a float constant a few ulps off the original's (`0.0174533f` = 0x3c8efa39 where the original has pi/180 =
    # 0x3c8efa35): byte-identical code, and level 3's float tolerance passes every input; level 2 compares it with
    # the original's unshared constants (fconst). equivalent/0x000d6b20.cpp as is, and with `0.017453292f`
    "0x000d6b20_float_const": ("equivalent", None),
    "0x000d6b20_float_const_wrong": ("fail", "L2 float_constant_differs __real@3c8efa39"),
    # round 14. A copy constructor looping over `(src.end - src.begin) >> 4` elements (and `>> 2` inside) of fuzzed
    # vectors: 98 of 107 inputs ran away (8 completed, 1 of 24 edges). The `sub; sar` sites are known from the code
    # (staticcount) and inputs start with small element counts once two have run away: 160 inputs, 22/24 edges
    "0x002a4e40_static_count": ("equivalent", None, 0.75, {"n_inputs": 3000}),
    "0x002a4e40_static_count_wrong": ("fail", "argument", 0, {"n_inputs": 3000}),
    # an in-order walk to `&tree.nil` = owner + 0x3c (a lea of a fuzzed pointer, so not in the heap range the walk
    # detector knew): walkaddr; and the owner pointer is not a count to plant small (addrcount; without it 17 inputs
    # completed, 2/30 edges)
    "0x00242da0_nil_addr_walk": ("equivalent", None, 0.9, {"n_inputs": 3000}),
    "0x00242da0_nil_addr_walk_wrong": ("fail", None, 0, {"n_inputs": 3000}),
    # `w->out = 3`: `inc dword [3 + 0x24]` is unaligned; Unicorn delivered the instruction's hook again after its
    # store and the increment was applied twice, in our code only (rmwundo): "write to 0x24 ... was 0x2000000"
    "0x0025b970_rmw_restart": ("equivalent", None, 0.75, {"n_inputs": 3000}),
    # exact floats (ftolexact): the original runs the x87 at 53-bit precision and so do both emulated runs, so equal
    # arithmetic gives equal bits. equivalent/0x00097320 spells `float ar = (float)na` where the original keeps na in
    # a register: returns 15.243244 for 15.243256 (relative 7.5e-7, inside the old 1e-5 tolerance)
    "0x0009faa0_float_exact": ("equivalent", None),
    "0x00097320_float_exact_wrong": ("fail", "returned 15.24", 0, {"n_inputs": 3000}),
    "0x00097320_float_tolerance": ("equivalent", None, 0.9, {"n_inputs": 3000, "equiv_off": "ftolexact"}),
    # round 17 (cl5). A local passed by pointer to a virtual call: its first words are filled by a constructor stub, the
    # rest stored by the function (`ev.type = -1; ev.value = 0`); the growth over the function's stores started at a
    # word it wrote itself and compared only the first word (ptrext). native14 stop 38: the listeners got only the id
    "0x0027dca0_event_words": ("equivalent", None),
    "0x0027dca0_event_words_wrong": ("fail", "the local passed as argument 1 differs at +0x8"),
    # round 15 (cl3). A jump table's coverage counts case indices, not targets (caseidx): 0x0028aea0 has 21 indices
    # over 12 targets; before native10's fix it had no case 0x12110e and 0x121111 in the wrong group, and passed
    "0x0028aea0_case_index": ("equivalent", None, 0.95),
    "0x0028aea0_case_index_wrong": ("fail", None),
    # chained calls (argcall): the stack words a call takes are its callee's `ret N`; `X(a)->M()` for `X()->M(a)`
    # compiles to the same bytes. native10's arg-unshift fixed 0x000f5b20 (v44(t)->setFont() -> v44()->setFont(t))
    # and a second pass moved Lookup's `entry` on to FUN_0027af90 in 0x001c7550 (reverted)
    "0x000f5b20_chained_args": ("equivalent", None),
    "0x000f5b20_chained_args_wrong": ("fail", "belong to another call"),
    "0x001c7550_chained_args": ("equivalent", None),
    "0x001c7550_chained_args_wrong": ("fail", "belong to another call"),
    # a global the source defines, bound to an original address: its initializer must be the original's bytes
    # (initbytes; the relocation is masked and level 3 reads the original's address)
    "0x00047ce0_init_const": ("equivalent", None),
    "0x00047ce0_init_const_wrong": ("fail", "L2 initializer_differs"),
    # float bit patterns in immediates (immfloat): `mov [esi+0x38], 0x3e32b8c3` for 0.17453294f; fx20's old source
    # had 0.17453292f and 1.7453292f, 1 ulp off, and passed 3000 inputs
    "0x00180f00_imm_float": ("equivalent", None),
    "0x00180f00_imm_float_wrong": ("fail", "L2 float_immediate_differs"),
    # equiv-map lines for ??-names (constructors, operators) in a merged tree object (treespecial): the base
    # constructor fell back to pairing and bound the allocator (native10 stop 17)
    "0x0029a190_tree_ctor_map": ("equivalent", None),
    "0x0029a190_tree_ctor_map_wrong": ("fail", "went to 0x00263ea0 instead of 0x002a3480"),
    # (tri2) a tree TU checked --wine: clang's one .text holds the TU's __fastcall block `@FUN_00212bb0@8` too; a call
    # to it is a call to 0x00212bb0 (TREE_EXTERNAL), not a local label of the section run in place
    "0x00212f70_native_tree_fastcall": ("equivalent", None, 0, {"native": True, "n_inputs": 300}),
    "0x00212f70_native_tree_fastcall_wrong": ("fail", "to 0x00212bb0: this (ecx) is", 0, {"native": True, "n_inputs": 300}),
    # (tri2, treeblk) a block-scope `extern const float zero_d94e0;` in a wrapped block: MSVC 7.1 names the global, clang
    # the enclosing namespace's variable; clang's name takes the MSVC object's binding (0x003f335c)
    "0x000d94e0_native_tree_blockextern": ("equivalent", None, 0, {"native": True, "n_inputs": 300}),
    "0x000d94e0_native_tree_blockextern_wrong": ("fail", "argument 5 is 0x004a0c60, expected 0x003f335c", 0,
                                                 {"native": True, "n_inputs": 300}),
    # (tri2, lstaticbr) a function-local static's guard in a wrapped block: the manglings' back-references differ too
    "0x001e2940_native_tree_lstatic": ("equivalent", None, 0, {"native": True, "n_inputs": 300}),
    "0x001e2940_native_tree_lstatic_off": ("fail", "unexpected write to global 0x00421894", 0,
                                           {"src": "0x001e2940_native_tree_lstatic", "native": True, "n_inputs": 300,
                                            "equiv_off": "lstaticbr,lsguard"}),     # (integ3: lsguard pairs it too)
    # (tri2, ptrfacts) `call [0x4de948]` (a .bss function pointer, fuzzed): the code its value happens to hit (0x00200000,
    # thiscall) is not the callee, so ecx is no argument there; seeds where the old rule compared it
    "0x000f8280_native_ptrfacts": ("equivalent", None, 0, {"native": True, "seeds": [341, 503, 1117]}),
    # (tri2, nanquiet64) `__isnan(m[i])`: a signalling float NaN stored as a double stays signalling in the emulated x87,
    # cvtss2sd quiets it (the high word's bit 0x00080000); the input is set aside like nanquiet's float words
    "0x00221f90_native_nanquiet64": ("inconclusive", None, 0, {"native": True, "seeds": [615]}),
    "0x00221f90_native_nanquiet64_off": ("fail", "argument 2 is 0xfffe3a93, expected 0xfff63a93", 0,
                                         {"src": "0x00221f90_native_nanquiet64", "native": True, "seeds": [615],
                                          "equiv_off": "nanquiet64"}),
    "0x000f8280_native_ptrfacts_off": ("fail", "call #1 to 0x00200000: this (ecx) is", 0,
                                       {"src": "0x000f8280_native_ptrfacts", "native": True, "seeds": [341, 503, 1117],
                                        "equiv_off": "ptrfacts"}),
    # round 16 (cl4). reg_writes: a self-recursive callee's writes are a fixpoint, not eax/ecx/edx (rwfix).
    # 0x0030ecb0 calls itself and never writes edx; the original keeps the node in edx across the call
    "0x0030ed60_recursive_edx": ("equivalent", None, 0.95),
    "0x0030ed60_recursive_edx_wrong": ("fail", "before return was 0x3, expected 0x2"),
    # a virtual declared with extra stack words that the next call passes again (vcall): slot 4 of 0x002f2fc0 takes
    # 1 word (the original's call pops 4) and the transform call the other two; the source before native13's fix
    "0x002f2fc0_vcall_words": ("equivalent", None),
    "0x002f2fc0_vcall_words_wrong": ("fail", "belong to another call"),
    # round 18 (cl6): `native=True` checks the object the native build links, clang's -O0 i686 compile of the same source
    # (the MSVC object's symbol binding, clang's reserved call frames, its own helpers), against the original.
    # exp: the original's inline fldl2e/f2xm1/fscale sequence; ours calls exp, run as the same x87 sequence in Unicorn
    # (x87math: Python's libm differs in the last bit for 1 input in 3) - the wrong sources scale the result by 1e-7,
    # and the pre-round-18 model fails the right one
    # (x64eq, argpop) an uninitialised out-parameter (`float angle; FUN_001a54a0(&pos, &angle)`) whose original frame slot
    # still holds a dead temporary: the callee only writes through it, which callee_reads sees once a known `ret 8`
    # callee's analysis no longer speaks for the caller's words past its two arguments
    "0x001a9b10_outparam_stale": ("equivalent", None, 0, {"native": True, "n_inputs": 200}),
    # (rev1) the same function with the bug the rule must still see: a second, never-written local read in place of the
    # out-parameter (fails with argpop; without argpop a false positive on the stale slot masks it)
    "0x001a9b10_outparam_wrong_uninit": ("fail", "0x5a5a5a5a", 0,
                                         {"native": True, "n_inputs": 200}),
    "0x0009f760_native_exp": ("equivalent", None, 0, {"native": True, "n_inputs": 300}),
    "0x0009f760_native_exp_wrong": ("fail", "returned 1.0", 0, {"native": True, "n_inputs": 300}),
    "0x0009f760_native_exp_python": ("fail", "returned 1.01", 0, {"native": True, "n_inputs": 300, "equiv_off": "x87math"}),
    # calls from clang's object: args stored into the reserved area (the words are our declaration's), a callee that pops
    # them re-reserved by `sub esp, N`, virtual calls (clangpop); a stub's bool result tested by bit 0 (boolret)
    "0x0027dca0_native": ("equivalent", None, 0, {"native": True}),
    "0x0027dca0_native_wrong": ("fail", "the local passed as argument 1 differs at +0x8", 0, {"native": True}),
    "0x002b8840_native_bool": ("equivalent", None, 0.9, {"native": True, "n_inputs": 150}),
    "0x002b8840_native_bool_wrong": ("fail", "argument 2", 0, {"native": True, "n_inputs": 150}),
    "0x000f80e0_native_vcall_pop": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x000f80e0_native_vcall_pop_wrong": ("fail", "argument 1", 0, {"native": True, "n_inputs": 100}),
    # the function under test is named by the MSVC object (a `vfunc_3` with no address in its name; the constructor it
    # calls is not it) and the vftable it stores is bound as in the MSVC object (natmap)
    "0x00252d80_native_ctor": ("equivalent", None, 0, {"native": True}),
    "0x00252d80_native_ctor_wrong": ("fail", "write to", 0, {"native": True}),
    # a destructor's last vptr store (the base class's vftable) that clang omits (dtorvptr); a wrong slot is caught
    "0x0028c040_native_dtor_vptr": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x0028c040_native_dtor_vptr_wrong": ("fail", None, 0, {"native": True, "n_inputs": 100}),
    # a switch's jump table lives in clang's .rdata; its section symbol is local data, never an original address
    "0x001837e0_native_jumptable": ("equivalent", None, 0.9, {"native": True, "n_inputs": 150}),
    "0x001837e0_native_jumptable_wrong": ("fail", None, 0, {"native": True, "n_inputs": 150}),
    # clang calls the CRT strcmp the original inlined: the XBE's `_wcscmp` passed the three strcmp probes and was bound as
    # `_strcmp` (crtprobe); `...` calls pass as many words as the original's call site
    "0x000c1790_native_crt_strcmp": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x000c1790_native_crt_strcmp_wrong": ("fail", "argument 2", 0, {"native": True, "n_inputs": 100}),
    # a char out-parameter at an odd frame offset: the bytes behind it are other locals in the original's frame (natwin)
    "0x0025c490_native_scalar_window": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x0025c490_native_scalar_window_wrong": ("fail", None, 0, {"native": True, "n_inputs": 100}),
    # (the pair 0x0033ed90_msvc_cast / 0x0033ed90_native_cast, MSVC 7.1 dropping an explicit `(float)` cast of an x87
    # register value that clang rounds, left with the Bink FFT object 0x0033ed90-0x003440e0 (library code, bink2);
    # a game-code case for that rule is still wanted)
    # a tail jump to a callee that reads a stack word of the original's own caller: MSVC's `jmp` passes it on, clang's
    # `call` has nothing there (the callee reads 2 words, the source declares 1)
    "0x0024b0c0_tail_thunk": ("equivalent", None),
    "0x0024b0c0_native_tail_thunk": ("fail", "argument 2", 0, {"native": True}),
    # the original calls `__CIasin` with the argument in st(0); clang calls `asin(double)` on the stack: the same call (natci).
    # A callee whose pop count is unknown (a thunk) follows our declaration (`ret 4` of FUN_002a07a0 declared 1 argument);
    # an indirect call with five cdecl arguments takes the original's count
    "0x000189c0_native_ci": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x000189c0_native_ci_wrong": ("fail", None, 0, {"native": True, "n_inputs": 100}),
    "0x002a16c0_native_decl_pop": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x002a16c0_native_decl_pop_wrong": ("fail", None, 0, {"native": True, "n_inputs": 100}),
    "0x001df600_native_indirect": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x001df600_native_indirect_wrong": ("fail", "argument", 0, {"native": True, "n_inputs": 100}),
    # native15's parked source (hulk_freg return, the listing's sum order): EQUIVALENT natively at 3000 inputs; summed in the
    # other order it fails (an MSVC-mode pass cannot tell: MSVC 7.1 reassociates the sum itself)
    "0x0022ff50_native_sum_order": ("equivalent", None, 0.9, {"native": True, "n_inputs": 3000}),
    "0x0022ff50_native_sum_order_wrong": ("fail", "returned", 0, {"native": True, "n_inputs": 3000}),
    # round 19 (cl8): gaps nf1 found in --native mode (each switchable with EQUIV_OFF)
    # tailfret: `call Get(); ...; jmp Calc` - the float Calc returns is the function's own result, not Get's
    "0x000354c0_native_tail_fret": ("equivalent", None, 0.9, {"native": True, "n_inputs": 60}),
    "0x000354c0_native_tail_fret_off": ("fail", "x87 stack depth", 0, {"src": "0x000354c0_native_tail_fret", "native": True, "n_inputs": 60, "equiv_off": "tailfret,x87conv"}),
    "0x000354c0_native_tail_fret_wrong": ("fail", "this (ecx)", 0, {"native": True, "n_inputs": 60}),
    # sretret: a struct-returning indirect call; the original reads the result through the returned eax
    "0x001e0230_native_sret": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x001e0230_native_sret_off": ("fail", "write to arg", 0, {"src": "0x001e0230_native_sret", "native": True, "n_inputs": 100, "equiv_off": "sretret"}),
    "0x001e0230_native_sret_wrong": ("fail", "write to arg", 0, {"native": True, "n_inputs": 100}),
    # natfill: a char[257] at an odd frame offset gets the whole word the original's aligned buffer got
    "0x0026f7b0_native_buf": ("equivalent", None, 0.9, {"native": True, "n_inputs": 300}),
    # (round 22: fillsame, ours replaying the original's fill bytes, closes the same gap; both off)
    "0x0026f7b0_native_buf_off": ("fail", None, 0, {"src": "0x0026f7b0_native_buf", "native": True, "n_inputs": 300, "equiv_off": "natfill,fillsame"}),
    "0x0026f7b0_native_buf_wrong": ("fail", None, 0, {"native": True, "n_inputs": 300}),
    # boolub (movzx r32, r8; and r32, 1): clang normalises the bool byte it passes on; a byte other than 0/1 is no bool
    "0x0002e910_native_bool": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x0002e910_native_bool_off": ("fail", "argument 3", 0, {"src": "0x0002e910_native_bool", "native": True, "n_inputs": 100, "equiv_off": "boolub"}),
    "0x0002e910_native_bool_wrong": ("fail", "argument 3", 0, {"native": True, "n_inputs": 100}),
    # natnarrow: a dword load of a partly written stack slot (`mov [esp+16], dl; mov edx, [esp+16]; push edx`)
    "0x001e14b0_native_narrow": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x001e14b0_native_narrow_off": ("fail", "argument 2", 0, {"src": "0x001e14b0_native_narrow", "native": True, "n_inputs": 100, "equiv_off": "natnarrow"}),
    "0x001e14b0_native_narrow_wrong": ("fail", "argument 2", 0, {"native": True, "n_inputs": 100}),
    # tailarity: `jmp g` with g reading more stack words than the wrapper declares; the full parameter list passes
    "0x001e8800_native_tail_arity": ("equivalent", None, 0.9, {"native": True, "n_inputs": 60}),
    "0x0024a370_native_tail_arity_wrong": ("fail", "argument 2", 0, {"native": True, "n_inputs": 60}),
    # ctorvptr: clang stores the base's vptr before the init call of `Base((init(), *this))`
    "0x001a5e50_native_ctor_vptr": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x001a5e50_native_ctor_vptr_off": ("fail", "unexpected write to this+0x0", 0, {"src": "0x001a5e50_native_ctor_vptr", "native": True, "n_inputs": 100, "equiv_off": "ctorvptr"}),
    "0x001a5e50_native_ctor_vptr_wrong": ("fail", None, 0, {"native": True, "n_inputs": 100}),
    # nansign: `x *= -1.0f` is fchs in MSVC 7.1 (flips a NaN's sign) and fmul in clang (keeps it): inputs whose only
    # difference is a NaN sign are inconclusive. A real difference (y not negated) still fails. (perf1: clang's SSE code
    # negates with a sign-mask xor, as fchs does, so the `_off` case needs the x87 build)
    "0x00301410_native_nan_sign": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x00301410_native_nan_sign_off": ("fail", "unexpected write to this+0x14", 0, {"src": "0x00301410_native_nan_sign", "native": True, "n_inputs": 100, "equiv_off": "nansign", "float": "x87"}),
    "0x00301410_native_nan_sign_wrong": ("fail", "this+0x18", 0, {"native": True, "n_inputs": 100}),
    # cdecl0: the words pushed to a cdecl callee that reads no stack word (a no-op printf) are not compared
    "0x002deca0_native_cdecl0": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x002deca0_native_cdecl0_off": ("fail", "argument words", 0, {"src": "0x002deca0_native_cdecl0", "native": True, "n_inputs": 100, "equiv_off": "cdecl0"}),
    "0x002deca0_native_cdecl0_wrong": ("fail", "extra call", 0, {"native": True, "n_inputs": 100}),
    # convshare: a function under test with an equiv-conv note (its original gets a converted copy of the input): the
    # words the original's call site passes to a `...` callee reach our run
    "0x00214900_native_conv_share": ("equivalent", None, 0.7, {"native": True, "n_inputs": 100}),
    "0x00214900_native_conv_share_off": ("fail", "argument words", 0, {"src": "0x00214900_native_conv_share", "native": True, "n_inputs": 100, "equiv_off": "convshare"}),
    "0x00214900_native_conv_share_wrong": ("fail", "argument 4", 0, {"native": True, "n_inputs": 100}),
    # nrvo: clang builds the returned struct in the hidden slot, the original in a local it copies out
    "0x000a92c0_native_nrvo": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x000a92c0_native_nrvo_off": ("fail", "argument 1", 0, {"native": True, "n_inputs": 100, "equiv_off": "nrvo", "src": "0x000a92c0_native_nrvo"}),
    "0x000a92c0_native_nrvo_wrong": ("fail", "returned struct", 0, {"native": True, "n_inputs": 100}),
    # round 20 (cl9)
    # xlocal: n = 13 writes dist[12] into the slot MSVC spills a pointer difference to, then reads it back through the array
    # (seeds 4693, 5061 failed 0x00359a80 at 20000 inputs): undefined behaviour, the input is inconclusive. A wrong lerp still fails
    "0x00359a80_xlocal": ("equivalent", None, 0, {"seeds": list(range(32)) + [4693, 5061], "n_inputs": 5100}),
    "0x00359a80_xlocal_off": ("fail", "missing write to arg3+0x6c", 0, {"src": "0x00359a80_xlocal", "seeds": list(range(32)) + [4693, 5061], "n_inputs": 5100, "equiv_off": "xlocal"}),
    "0x00359a80_xlocal_wrong": ("fail", None, 0, {"seeds": list(range(32)) + [4693, 5061], "n_inputs": 5100}),
    # xlocal must not fire on a local reached through its own address (`lea ebx, [esp+0x10]; mov [ebx], esi`, 0x002165c0: all 98 inputs were
    # marked) or on element 0 of a frame array set by name (0x0008e880: 21 of 72 marked, hiding a real difference at seed 11)
    "0x002165c0_xlocal_ptr": ("equivalent", None, 0, {"n_inputs": 100}),
    # (tri1, xlbyte) per byte: `char buf[0x400] = {0}` is `mov byte [esp+0x18], 0; rep stosd` from esp+0x19, and `mov cl, [esp+0x18]`
    # reads the byte the plain store wrote. Per word every input was frame_overrun (unsupported), so a mutant reading buf[1] "passed"
    "0x00233c50_xlocal_byte": ("equivalent", None, 0.75, {"n_inputs": 200}),
    "0x00233c50_xlocal_byte_off": ("unsupported", None, 0, {"src": "0x00233c50_xlocal_byte", "n_inputs": 200, "equiv_off": "xlbyte,xlfill"}),
    "0x00233c50_xlocal_byte_wrong": ("fail", "call #8 went to 0x00233580", 0, {"n_inputs": 200}),
    # (tri1, xlfill) a byte a `rep stos` of the function filled is an array's own: `args[1] = p` by name into `args[64] = {0}`, read
    # back as args[count-1]. Before, 249 of 373 inputs were frame_overrun and the mutant (no --count when count == 2) was equivalent
    # (tri1, cvarargs) a C-linkage varargs definition with a register convention (`extern "C" f(S*, const char*, ...)`, equiv-conv
    # `esi stack`; the merged tree's shared extern "C" declaration made 0x0021f800 a C name): its fixed parameters from our declaration
    "0x0021f800_cvarargs": ("equivalent", None, 0, {"n_inputs": 100}),
    "0x0021f800_cvarargs_off": ("fail", "argument 1 is 0x00000010", 0, {"src": "0x0021f800_cvarargs", "n_inputs": 100, "equiv_off": "cvarargs"}),
    "0x0021f800_cvarargs_wrong": ("fail", "call #3 to 0x002152b0: argument 2 is 0x00000004", 0, {"n_inputs": 100}),
    # (tri3, strlazy) --wine: clang's strcmp call against the original's inline byte loop; the intrinsic is compared byte by
    # byte to the first difference (seed 2727: a fuzzed name without a terminator in 64 KB, differing at byte 0)
    "0x000e1dd0_native_strlazy": ("equivalent", None, 0, {"native": True, "seeds": list(range(32)) + [2727]}),
    "0x000e1dd0_native_strlazy_off": ("fail", "original ret but ours fault:intrinsic_access", 0,
                                      {"src": "0x000e1dd0_native_strlazy", "native": True, "seeds": list(range(32)) + [2727],
                                       "equiv_off": "strlazy"}),
    "0x000e1dd0_native_strlazy_wrong": ("fail", "returned 0x00000004, expected 0x00000000", 0,
                                        {"native": True, "seeds": list(range(32)) + [2727]}),
    # (tri3, strlazy) --wine: memcmp against the original's inline `repe cmpsb`, byte by byte to the first difference
    "0x0033caa0_native_memlazy": ("equivalent", None, 0, {"native": True, "seeds": list(range(32)) + [120, 421]}),
    "0x0033caa0_native_memlazy_off": ("fail", "original ret but ours fault:intrinsic_access", 0,
                                      {"src": "0x0033caa0_native_memlazy", "native": True,
                                       "seeds": list(range(32)) + [120, 421], "equiv_off": "strlazy"}),
    "0x0033caa0_native_memlazy_wrong": ("fail", "returned 0x000000f9, expected 0x000000f8", 0,
                                        {"native": True, "seeds": list(range(32)) + [120, 421]}),
    # (tri3, memub) --wine: clang's struct copies are memcpy calls; over overlapping fuzzed items (seed 353) the input is
    # inconclusive (copy_overlap), as intrub's strcpy
    "0x002233e0_native_memub": ("equivalent", None, 0, {"native": True, "seeds": list(range(32)) + [353]}),
    "0x002233e0_native_memub_off": ("fail", "write to arg2+0x24 before return was 0x40020060, expected 0x40020064", 0,
                                    {"src": "0x002233e0_native_memub", "native": True, "seeds": list(range(32)) + [353],
                                     "equiv_off": "memub,memfwd"}),
    # (integ1, rev4, memfwd) our overlapping memcpy runs forward dword by dword as the original's inline copy, and the input
    # is compared (seed 353 passes without being set aside); _fwdoff: memub's set-aside alone (the pre-rev4 rule).
    # _hidden (rev4): a field flipped when the items overlap, after the copies; at 1,000 inputs it fails at inputs 461/653
    "0x002233e0_native_memub_fwdoff": ("equivalent", None, 0, {"src": "0x002233e0_native_memub", "native": True,
                                                               "seeds": list(range(32)) + [353], "equiv_off": "memfwd"}),
    "0x002233e0_native_memub_hidden": ("fail", "arg1+0x24", 0, {"native": True, "n_inputs": 1000}),
    # (rev4, memfwd) a field flipped inside a swap only when the swapped items overlap: the difference needs an overlapping
    # memcpy that ran (seed 353). It fails with memfwd; _fwdoff shows the case tests memfwd (memub alone sets 353 aside)
    "0x002233e0_native_memfwd_inswap": ("fail", "write to arg0+0x24 before return was 0x40000001, expected 0x40000000", 0,
                                        {"native": True, "seeds": list(range(32)) + [353]}),
    "0x002233e0_native_memfwd_inswap_fwdoff": ("equivalent", None, 0, {"src": "0x002233e0_native_memfwd_inswap",
                                                                       "native": True, "seeds": list(range(32)) + [353],
                                                                       "equiv_off": "memfwd"}),
    # (integ1, rev4, strcase) rev4's _stricmp-for-strcmp mutant of FELayout's lookup: two non-literal strings the fuzzer never
    # makes equal but for case; the strcase phase plants the key in the other case over the name (input 7+case); _off passes
    "0x000e1dd0_native_strlazy_icmp": ("fail", "expected 0x00000000", 0, {"native": True, "n_inputs": 1000}),
    "0x000e1dd0_native_strlazy_icmp_off": ("equivalent", None, 0, {"src": "0x000e1dd0_native_strlazy_icmp", "native": True,
                                                                   "n_inputs": 1000, "equiv_off": "strcase"}),
    "0x002233e0_native_memub_wrong": ("fail", "missing write to arg1+0x4", 0,
                                      {"native": True, "seeds": list(range(32)) + [353]}),
    # (rev4, memub/strlazy must-fail) memmove is defined on overlap and stays compared (seed 353 as above, memmove
    # in place of the struct copies); memcmp does not stop at a NUL (lmemfind with strncmp); strncmp's n is kept
    # (FELayout's lookup comparing 2 bytes)
    "0x002233e0_native_memub_memmove": ("fail", "write to arg2+0x24 before return was 0x40020060, expected 0x40020064", 0,
                                        {"native": True, "seeds": list(range(32)) + [353]}),
    "0x0033caa0_native_memlazy_strncmp": ("fail", "missing call #2 to 0x00348290", 0,
                                          {"native": True, "seeds": list(range(64))}),
    "0x000e1dd0_native_strlazy_ncmp": ("fail", "returned 0x00100000, expected 0x00000000", 0,
                                       {"native": True, "seeds": list(range(32)) + [152]}),
    # (tri1, codewdata) a store into our object's data (an unbound local static's guard, here with lstatic off) is no store into
    # code: the input is compared (the unbound guard fails it) instead of set aside as code_write (222 of 306 inputs were)
    "0x001e5f10_native_codewdata": ("fail", "missing write to global 0x004e2758", 0, {"native": True, "n_inputs": 200,
                                                                                    "equiv_off": "lstatic"}),
    "0x001e5f10_native_codewdata_off": ("inconclusive", None, 0, {"src": "0x001e5f10_native_codewdata", "native": True,
                                                                  "n_inputs": 200, "equiv_off": "lstatic,codewdata"}),
    # (tri1, boolafter) `f()->g(special)`: clang's `call f; mov ecx, eax; mov al, [special]; and al, 1` is no bool use of f's
    # result: the load into al replaces it (bool_after normalised the returned pointer to 1, the `this` of g)
    "0x000a97e0_native_boolafter": ("equivalent", None, 0, {"native": True, "n_inputs": 300}),
    "0x000a97e0_native_boolafter_off": ("fail", "this (ecx) is 0x00000001", 0, {"src": "0x000a97e0_native_boolafter", "native": True,
                                                                               "n_inputs": 300, "equiv_off": "boolafter"}),
    "0x000a97e0_native_boolafter_wrong": ("fail", "call #12 to 0x001c3c20: argument 1", 0, {"native": True, "n_inputs": 300}),
    "0x0008fca0_xlocal_fill": ("equivalent", None, 0.75, {"n_inputs": 300}),
    "0x0008fca0_xlocal_fill_off": ("equivalent", None, 0, {"src": "0x0008fca0_xlocal_fill", "n_inputs": 300, "equiv_off": "xlfill"}),
    "0x0008fca0_xlocal_fill_wrong": ("fail", "argument 1 is 0x00000002, expected 0x00000001", 0, {"n_inputs": 300}),
    "0x0008fca0_xlocal_fill_wrong_off": ("equivalent", None, 0, {"src": "0x0008fca0_xlocal_fill_wrong", "n_inputs": 300, "equiv_off": "xlfill"}),
    # (integ1, D43 vptrread) vptrkeep's tracker read every loaded word with a page-mapping read: in a call-free loop over a pointer
    # array the original's run mapped pages past the 1000-page limit and returned where ours stopped at too_many_pages (input 7)
    "0x00106290_vptrread": ("equivalent", None, 0.9, {"n_inputs": 200}),
    "0x00106290_vptrread_off": ("fail", "original ret but ours fault:too_many_pages", 0, {"src": "0x00106290_vptrread", "n_inputs": 200,
                                                                                         "equiv_off": "vptrread"}),
    "0x00106290_vptrread_wrong": ("fail", "returned 0x00000003, expected 0xffffffff", 0, {"n_inputs": 200}),
    # (integ1, D39 nanpayload; DROPPED by the user, D50) the rule is gone; its cases stay as checker regressions with the plain
    # checker: NaN words that differ in payload, an int -1/-2, a byte store into a -1 word, a returned-struct word and
    # re-payloaded NaN elements are all differences
    "0x0022ca90_native_nanpayload": ("fail", "write to this+0x4 before return was 0xfff84ab4, expected 0xffeca8b1", 0,
                                     {"native": True, "n_inputs": 1000}),
    "0x0022ca90_native_nanpayload_wrong": ("fail", "this+0x14", 0, {"native": True, "n_inputs": 300}),
    "0x0022ca90_native_nanpayload_nanconst": ("fail", "this+0xc", 0, {"native": True, "n_inputs": 300}),
    "0x00035ce0_native_nanpayload_byte": ("fail", "write to this+0x1cf4 before return was 0xffffff01, expected 0xffffff00", 0,
                                          {"native": True, "n_inputs": 300}),
    "0x000a92c0_native_nanpayload_sret": ("fail", "the returned struct differs at +0x0 (0xfffffffe, expected 0xffffffff)", 0,
                                          {"native": True, "n_inputs": 1000}),
    "0x0022ca90_native_nanpayload_share": ("fail", "write to this+0x0 before return was 0xfffffffe, expected 0xffffffff", 0,
                                           {"native": True, "n_inputs": 1000}),
    # (integ1, proofcap) luaH newkey: its fuzzed tables time out on 1 input in 6, and the random phase stopped at 32
    # inconclusive inputs (535 drawn, 442 compared): a proof-sized run now draws until 3,000 are compared (MIN_RUN 3,000)
    "0x0021a3e0_proofcap": ("equivalent", None, 0.9, {"n_inputs": 3000, "time_budget": 2400}),
    # (integ2, D100, proofwalk) a tree walk over fuzzed nodes ending at &tree.nil: the walk-sentinel inputs keep going
    # while a proof draws on (with EQUIV_OFF=proofwalk: 430 compared of 40,000 drawn); _wrong: those inputs are compared
    "0x0024a280_native_proofwalk": ("equivalent", None, 0, {"native": True, "n_inputs": 3000, "time_budget": 2400}),
    "0x0024a280_native_proofwalk_wrong": ("fail", None, 0, {"native": True, "n_inputs": 300}),
    # (integ1, D53, objkeep; NOT ADOPTED: EQUIV_ON=objkeep until reviewed) --wine: the original reads stream's vptr before the
    # call that computes v3's argument and re-reads this->stream for `this` after it; the stub's havoc fuzzed the re-read
    # word on one side only (input 10: this (ecx) is 3, expected 0). The pointer word is kept across the stub as the vptr is
    "0x00264050_native_objkeep": ("equivalent", None, 0, {"native": True, "n_inputs": 1000, "equiv_on": "objkeep"}),
    "0x00264050_native_objkeep_off": ("fail", "this (ecx)", 0, {"src": "0x00264050_native_objkeep", "native": True,
                                                                "n_inputs": 1000}),
    "0x00264050_native_objkeep_wrong": ("fail", "this (ecx)", 0, {"native": True, "n_inputs": 300, "equiv_on": "objkeep"}),
    "0x00264050_native_objkeep_thischange": ("fail", "unexpected write to this+0x8", 0, {"native": True, "n_inputs": 300, "equiv_on": "objkeep"}),
    # (rev6, D53 review) _stale: this->stream read once before v16 and reused for v3, a third order that differs from the
    # original's and clang's only if a call in between rewrote Reader::stream: objkeep takes all three (the assumption, recorded).
    # 0x000e8790 _pin: this->owner read once and reused across v6 and FUN_002998d0, calls after the virtual call objkeep checked
    # (the keep must end at that call); _ctl: the same split re-reading owner each time; _pin_off: _pin fails without objkeep.
    # _pin FAILS (equivalent) at a4a81138a: the keep is an ("after", epoch) overlay that pins the word for every later epoch
    "0x00264050_native_objkeep_stale": ("equivalent", None, 0, {"native": True, "n_inputs": 1000, "equiv_on": "objkeep"}),
    "0x000e8790_native_objkeep_ctl": ("equivalent", None, 0, {"native": True, "n_inputs": 1000, "equiv_on": "objkeep"}),
    "0x000e8790_native_objkeep_pin": ("fail", "this (ecx)", 0, {"native": True, "n_inputs": 1000, "equiv_on": "objkeep"}),
    "0x000e8790_native_objkeep_pin_off": ("fail", "this (ecx)", 0, {"src": "0x000e8790_native_objkeep_pin", "native": True,
                                                                    "n_inputs": 1000}),
    # (integ1, D54) a `// pre: notnan(...)` contract with HULK_PRE_NOTNAN (include/compat/pre.h): NaN words of the contract are
    # repaired on both sides (390 of 1,004 inputs), --wine checks that a violating input hits the trap; _notrap: the contract
    # without the macro is refused; _nopre: the macro without the contract fails on NaN inputs; _wrong: a wrong element fails
    "0x0022ca90_native_pre": ("equivalent", None, 0, {"native": True, "n_inputs": 1000}),
    "0x0022ca90_native_pre_msvc": ("equivalent", None, 0, {"src": "0x0022ca90_native_pre", "n_inputs": 1000}),
    "0x0022ca90_native_pre_notrap": ("fail", "L2 pre_without_trap", 0, {"native": True, "n_inputs": 200}),
    "0x0022ca90_native_pre_nopre": ("fail", "L2 trap_without_pre", 0, {"native": True, "n_inputs": 1000}),
    "0x0022ca90_native_pre_wrong": ("fail", "write to this+0x14", 0, {"native": True, "n_inputs": 300}),
    "0x0022ca90_native_pre_off": ("fail", "ours fault", 0, {"src": "0x0022ca90_native_pre", "native": True, "n_inputs": 1000,
                                                            "equiv_off": "pre"}),
    # (rev5, D54 review) _partial: the macro checks element 0 of each operand where the contract names all 16 (a NaN in
    # another element computes on untrapped while the checker repaired it): every contract word must reach the trap.
    # _msvc_hidden: MSVC 7.1 compiles the macro to nothing, so an MSVC-mode run must not assume the contract (a branch
    # taken only on a NaN a->m[0][0]); _msvc_hidden_off: the same without the contract fails (the difference is reachable)
    "0x0022ca90_native_pre_partial": ("fail", "pre_trap_missing", 0, {"native": True, "n_inputs": 300}),
    "0x0022ca90_native_pre_msvc_hidden": ("fail", "this+0xc", 0, {"n_inputs": 1000}),
    "0x0022ca90_native_pre_msvc_hidden_off": ("fail", "this+0xc", 0, {"src": "0x0022ca90_native_pre_msvc_hidden",
                                                                      "n_inputs": 1000, "equiv_off": "pre"}),
    # (rev5, D54 re-review) _over64: b's contract words come after the trap check's first 64 (all of a, which the macro
    # checks); b is repaired but never trap-checked and the macro skips it. Must fail (refused or pre_trap_missing)
    "0x0022ca90_native_pre_over64": ("fail", None, 0, {"native": True, "n_inputs": 300}),
    # (integ2, D65) `// pre: defnan(...)` with HULK_PRE_DEFNAN: any NaN is the default NaN 0xffc00000. The checker gives
    # other NaNs a finite value or the default NaN, plants the default NaN in one input of four, and per word checks
    # that another NaN traps and that the default NaN computes as the original. _msvc: MSVC mode (nothing repaired).
    # Must fail: _notnanmacro (a notnan macro under a defnan contract: refused at level 2), _overtrap (a hand trap on
    # any NaN: the default-NaN word check), _nanbranch (ours stores otherwise on a NaN), _partial (element 0 only
    # checked), _off (the contract ignored: the fuzzed NaNs that trap are not repaired)
    "0x0022ca90_native_defnan": ("equivalent", None, 0, {"native": True, "n_inputs": 1000}),
    "0x0022ca90_native_defnan_msvc": ("equivalent", None, 0, {"src": "0x0022ca90_native_defnan", "n_inputs": 1000}),
    "0x0022ca90_native_defnan_notnanmacro": ("fail", "L2 pre_without_trap", 0, {"native": True, "n_inputs": 200}),
    "0x0022ca90_native_defnan_overtrap": ("fail", "pre_trap_missing", 0, {"native": True, "n_inputs": 300}),
    "0x0022ca90_native_defnan_nanbranch": ("fail", None, 0, {"native": True, "n_inputs": 300}),
    "0x0022ca90_native_defnan_partial": ("fail", "pre_trap_missing", 0, {"native": True, "n_inputs": 300}),
    # (integ2, selfnarrow) a recursive call's char argument at its declared width (MSVC pushes the incoming slot whole);
    # _wrong: another low byte must still fail; _off: without the rule the stale upper bytes are a difference
    "0x0030a9d0_native_selfnarrow": ("equivalent", None, 0, {"native": True, "n_inputs": 600}),
    "0x0030a9d0_native_selfnarrow_wrong": ("fail", "argument 7", 0, {"native": True, "n_inputs": 600}),
    "0x0030a9d0_native_selfnarrow_off": ("fail", "argument 7", 0, {"src": "0x0030a9d0_native_selfnarrow", "native": True,
                                                                   "n_inputs": 600, "equiv_off": "selfnarrow"}),
    # (integ2, D85/D86; rev5's mutants) _signblind: a macro that traps only on positive quiet NaNs (another NaN with the
    # sign set computes on; 0x7fc00000, allowed, traps); _onlyneg: D65's first test, allowing only 0xffc00000;
    # _rotnan / _pairnan: ours differs only when several contract words hold NaNs at once (the all-words run)
    "0x0022ca90_native_defnan_signblind": ("fail", "pre_trap_missing", 0, {"native": True, "n_inputs": 300}),
    "0x0022ca90_native_defnan_onlyneg": ("fail", "pre_trap_missing", 0, {"native": True, "n_inputs": 300}),
    "0x0022ca90_native_defnan_rotnan": ("fail", None, 0, {"native": True, "n_inputs": 300}),
    "0x0022ca90_native_defnan_pairnan": ("fail", None, 0, {"native": True, "n_inputs": 300}),
    # (integ2, D78, memwrap) an overlap that wraps around address 0 is copied forward like any other (memfwd); _memmove: a
    # backward-capable copy where the original copies forward must still fail
    "0x00277d60_native_memwrap": ("equivalent", None, 0, {"native": True, "n_inputs": 1500}),
    "0x00277d60_native_memwrap_memmove": ("fail", None, 0, {"native": True, "n_inputs": 1500}),
    # (integ2, D78, argfill) a callee's out pointer to the function's own by-value class parameter is filled over its
    # sizeof, as clang's frame copy of it is; _off: without it the original's slot gets word 0 only (a difference)
    "0x000c9720_native_argfill": ("equivalent", None, 0, {"native": True, "n_inputs": 1000}),
    "0x000c9720_native_argfill_msvc": ("equivalent", None, 0, {"src": "0x000c9720_native_argfill", "n_inputs": 1000}),
    "0x000c9720_native_argfill_off": ("fail", None, 0, {"src": "0x000c9720_native_argfill", "native": True,
                                                        "n_inputs": 1000, "equiv_off": "argfill"}),
    # (rev5 re-review) _oddpay: a macro that misses NaNs with an even payload (the fixed sample had only odd ones);
    # _rotneg: differs only when a's diagonal words all hold 0xffc00000 (the fixed all-0xffc00000 run)
    "0x0022ca90_native_defnan_oddpay": ("fail", "pre_trap_missing", 0, {"native": True, "n_inputs": 300}),
    "0x0022ca90_native_defnan_rotneg": ("fail", None, 0, {"native": True, "n_inputs": 300}),
    # (integ2, D101) rev5's mutant: D3D_BlockOnTime called where the original calls D3D_CheckDeviceFormat. The XDK symbol
    # list (shipped with every job) binds each name to its own export: the wrong callee is a difference
    # (rev5's review) _samepop: D3DDevice_Clear, which pops 24 bytes as D3D_CheckDeviceFormat does: no pop check can
    # catch it, only the binding ("call #2 went to ...")
    "0x00320d30_xdk_samepop": ("fail", "went to", 0, {"n_inputs": 200}),
    "0x00320d30_xdk_samepop_wine": ("fail", "went to", 0, {"src": "0x00320d30_xdk_samepop", "native": True, "n_inputs": 200}),
    "0x00320d30_xdk_wrongcallee": ("fail", None, 0, {"n_inputs": 200}),
    "0x00320d30_xdk_wrongcallee_wine": ("fail", None, 0, {"src": "0x00320d30_xdk_wrongcallee", "native": True,
                                                           "n_inputs": 200}),
    "0x0022ca90_native_defnan_off": ("fail", "ours fault", 0, {"src": "0x0022ca90_native_defnan", "native": True,
                                                               "n_inputs": 1000, "equiv_off": "pre"}),
    # (rev3, D39 review) an int -2 where the original stores -1 (both qNaN-shaped as floats): a difference
    "0x0021e080_native_nanpayload_int": ("fail", "(0xfffffffe, expected 0xffffffff)", 0, {"native": True, "n_inputs": 300}),
    # (wine1) the difference at seed 11 is `f_text[f_n] = 0` with a fuzzed f_n beyond the whole stack, where each frame layout puts
    # the byte elsewhere: since fescape that input is inconclusive in Wine mode, so the case keeps testing xlocal with fescape off
    "0x0008e880_native_xlocal_elem0": ("fail", "unexpected write to 0xbe7ef6d4", 0, {"native": True, "n_inputs": 60,
                                                                                   "equiv_off": "fescape"}),
    # cintrin + tailx87: `jmp __CIfmod` (mov edx, <descriptor>; jmp __cintrindisp2) takes st0 and st1 and no stack word; the original calls it
    "0x00261bb0_tail_fmod": ("equivalent", None, 0.9, {"n_inputs": 300}),
    "0x00261bb0_tail_fmod_off": ("fail", "argument words", 0, {"src": "0x00261bb0_tail_fmod", "n_inputs": 100, "equiv_off": "cintrin"}),
    "0x00261bb0_tail_fmod_off2": ("fail", "x87 stack depth", 0, {"src": "0x00261bb0_tail_fmod", "n_inputs": 100, "equiv_off": "tailx87"}),
    "0x00261bb0_tail_fmod_wrong": ("fail", "x87", 0, {"n_inputs": 100}),
    # cleanframe: `add esp, 0x40; pop ebx; add esp, 8; ret` - the first add is argument cleanup of four calls, the frame goes on its own
    "0x0021acc0_native_cleanframe": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x0021acc0_native_cleanframe_off": ("fail", "argument", 0, {"src": "0x0021acc0_native_cleanframe", "native": True, "n_inputs": 100, "equiv_off": "cleanframe"}),
    "0x0021acc0_native_cleanframe_wrong": ("fail", "argument 3", 0, {"native": True, "n_inputs": 100}),
    # uninitmask: the original saves an uninitialised `push ecx` slot (the caller's ecx) and writes it back; ours holds the fill pattern
    "0x003272f0_native_uninit": ("equivalent", None, 0.9, {"native": True, "n_inputs": 300}),
    "0x003272f0_native_uninit_off": ("fail", "0x5a5a5a5a", 0, {"src": "0x003272f0_native_uninit", "native": True, "n_inputs": 100, "equiv_off": "uninitmask"}),
    "0x003272f0_native_uninit_wrong": ("fail", None, 0, {"native": True, "n_inputs": 300}),
    # round 21 (cl10)
    # natsteps: clang -O0 code needs several times the original's instructions; ours gets 8x the original's step budget in --native
    "0x000f7790_native_steps": ("equivalent", None, 0, {"native": True, "n_inputs": 80}),
    "0x000f7790_native_steps_off": ("fail", "ours timeout", 0, {"src": "0x000f7790_native_steps", "native": True, "n_inputs": 80, "equiv_off": "natsteps"}),
    "0x000f7790_native_steps_wrong": ("fail", None, 0, {"native": True, "n_inputs": 80}),
    # vptrkeep: the original loads the item's vptr before the table lookup call (a stub: its memory havoc replaces the vptr word)
    "0x000cb6f0_native_vptr": ("equivalent", None, 0, {"native": True, "n_inputs": 80}),
    # (round 22: purecall, no havoc after the table lookup that writes nothing, closes it too; both off)
    "0x000cb6f0_native_vptr_off": ("fail", "went to", 0, {"src": "0x000cb6f0_native_vptr", "native": True, "n_inputs": 80, "equiv_off": "vptrkeep,purecall"}),
    "0x000cb6f0_native_vptr_wrong": ("fail", None, 0, {"native": True, "n_inputs": 80}),
    # helpers64: the original calls __allmul, clang multiplies inline
    "0x00096d80_native_int64": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x00096d80_native_int64_off": ("fail", "missing call", 0, {"src": "0x00096d80_native_int64", "native": True, "n_inputs": 60, "equiv_off": "helpers64"}),
    "0x00096d80_native_int64_wrong": ("fail", "returned", 0, {"native": True, "n_inputs": 60}),
    # gstail: `jmp __security_check_cookie` ends the original
    "0x001f6650_native_gstail": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x001f6650_native_gstail_off": ("fail", "missing call", 0, {"src": "0x001f6650_native_gstail", "native": True, "n_inputs": 60, "equiv_off": "gstail"}),
    "0x001f6650_native_gstail_wrong": ("fail", None, 0, {"native": True, "n_inputs": 60}),
    # x87range: fptan of an operand beyond 2^63 pushes nothing, the original's x87 stack is shifted for the rest of the run
    "0x000a0fe0_native_x87range": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x000a0fe0_native_x87range_off": ("fail", "x87 stack depth", 0, {"src": "0x000a0fe0_native_x87range", "native": True, "n_inputs": 60, "equiv_off": "x87range"}),
    "0x000a0fe0_native_x87range_wrong": ("fail", None, 0, {"native": True, "n_inputs": 60}),
    # retwidth: every caller reads only al of the bool this extern "C" function returns; clang leaves 0xffffff00 above it
    "0x000375a0_native_retwidth": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x000375a0_native_retwidth_off": ("fail", "returned 0x", 0, {"src": "0x000375a0_native_retwidth", "native": True, "n_inputs": 60, "equiv_off": "retwidth,cdeclret"}),   # (round 27: the bool declaration says it too)
    "0x000375a0_native_retwidth_wrong": ("fail", None, 0, {"native": True, "n_inputs": 60}),
    # varcleanup: `push n; push fmt; push 0x20; push buf; call f; add esp, 4`: the callee takes all four words, n included
    "0x0007e740_native_varargs": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x0007e740_native_varargs_off": ("fail", "argument words", 0, {"src": "0x0007e740_native_varargs", "native": True, "n_inputs": 60, "equiv_off": "varcleanup"}),
    "0x0007e740_native_varargs_wrong": ("fail", "argument 4", 0, {"native": True, "n_inputs": 60}),
    # wglobals: the original reads writable floats that scripts set (`fcomp [0x4c7df8]`); a source with the load-time value passed
    "0x001f56b0_wglobal": ("equivalent", None, 0, {"n_inputs": 100}),
    "0x001f56b0_wglobal_off": ("equivalent", None, 0, {"src": "0x001f56b0_wglobal_wrong", "n_inputs": 100, "equiv_off": "wglobals"}),
    "0x001f56b0_wglobal_wrong": ("fail", None, 0, {"n_inputs": 100}),
    "0x0007a420_wglobal": ("equivalent", None, 0, {"n_inputs": 100}),
    "0x0007a420_wglobal_wrong": ("fail", None, 0, {"n_inputs": 100}),
    # round 22 (cl11)
    # crtarity: `push 0; push T; push S; push 0; call [vt+0x10]; push eax; call __RTDynamicCast`: the four words are the cast's
    "0x000f1ab0_native_crtarity": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    # (integ3 chk3) thiscallpend reaches the same split by itself (the virtual takes `this` in ecx, so the words the cast's
    # `add esp` releases were the cast's): switched off too, or _off passes
    "0x000f1ab0_native_crtarity_off": ("fail", "argument 1", 0, {"src": "0x000f1ab0_native_crtarity", "native": True, "n_inputs": 60, "equiv_off": "crtarity,vsplit,thiscallpend"}),
    "0x000f1ab0_native_crtarity_wrong": ("fail", None, 0, {"native": True, "n_inputs": 60}),
    # calleext: FUN_00356bf0(.., float *x, float *y, float *z) reads 4 bytes through each; the neighbours of &dir.z are other locals
    "0x002d21c0_native_calleext": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x002d21c0_native_calleext_off": ("fail", "local passed as argument 6", 0, {"src": "0x002d21c0_native_calleext", "native": True, "n_inputs": 60, "equiv_off": "calleext"}),
    "0x002f0780_native_calleext_wrong": ("fail", "local passed as argument 3", 0, {"native": True, "n_inputs": 60}),
    # stackval: `lea ecx, [esp+8]; mov [fs+0x14], ecx`: the stored &local differs by frame; the local itself is compared at the next call
    "0x0021e080_native_stackval": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x0021e080_native_stackval_off": ("fail", "write to", 0, {"src": "0x0021e080_native_stackval", "native": True, "n_inputs": 60, "equiv_off": "stackval"}),
    "0x0021e080_native_stackval_wrong": ("fail", "stored at", 0, {"native": True, "n_inputs": 60}),
    "0x0021e080_stackval_wrong": ("fail", "stored at", 0, {"src": "0x0021e080_native_stackval_wrong", "n_inputs": 60}),
    # tailthis: `sub ecx, 4; jmp Base::~dtor`: the tail callee returns its this
    "0x002786e0_native_tailthis": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x002786e0_native_tailthis_off": ("fail", "returned", 0, {"src": "0x002786e0_native_tailthis", "native": True, "n_inputs": 60, "equiv_off": "tailthis"}),
    "0x002786e0_native_tailthis_wrong": ("fail", "returned", 0, {"native": True, "n_inputs": 60}),
    # noeaxret: an extern "C" void function nobody calls directly that never writes eax: its eax is the caller's
    "0x0035d200_native_noeaxret": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x0035d200_native_noeaxret_off": ("fail", "return type unknown", 0, {"src": "0x0035d200_native_noeaxret", "native": True, "n_inputs": 60, "equiv_off": "noeaxret,cdeclret"}),   # (round 27: the void declaration says it too)
    "0x0035d200_native_noeaxret_wrong": ("fail", "write to", 0, {"native": True, "n_inputs": 60}),
    # fyl2x: Unicorn leaves the x87 stack alone for `fyl2x` of a negative operand (log of a fuzzed negative float)
    "0x0033b8d0_native_fyl2x": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x0033b8d0_native_fyl2x_off": ("fail", "x87 stack depth", 0, {"src": "0x0033b8d0_native_fyl2x", "native": True, "n_inputs": 60, "equiv_off": "fyl2x"}),
    "0x0033b8d0_native_fyl2x_wrong": ("fail", "argument 2", 0, {"native": True, "n_inputs": 60}),
    # nofill: FUN_002f0080 only reads the vectors it gets: no speculative out-parameter fill
    "0x002f0780_native_nofill": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    # (integ2, argfill) &p is the function's own by-value parameter: since argfill the speculative fill covers it on both
    # sides alike, so without nofill the first difference is argument 2's frame local (&d)
    "0x002f0780_native_nofill_off": ("fail", "local passed as argument 2", 0, {"src": "0x002f0780_native_nofill", "native": True, "n_inputs": 60, "equiv_off": "nofill"}),
    "0x002f0780_native_nofill_wrong": ("fail", None, 0, {"native": True, "n_inputs": 60}),
    # fillsame: snprintf(buf, ...) twice: the stub's fill of `char buf[32]` depended on the buffer's alignment
    "0x001ca430_native_fillsame": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x001ca430_native_fillsame_off": ("fail", "local passed as argument 1", 0, {"src": "0x001ca430_native_fillsame", "native": True, "n_inputs": 60, "equiv_off": "fillsame"}),
    "0x001ca430_native_fillsame_wrong": ("fail", None, 0, {"native": True, "n_inputs": 60}),
    # vsplit: `push b; push a; push 0; call [dev+0x48]; push eax; call [vt+0x20]`: who takes a and b is open in the original
    "0x00296160_native_vsplit": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x00296160_native_vsplit_off": ("fail", "argument 2", 0, {"src": "0x00296160_native_vsplit", "native": True, "n_inputs": 60, "equiv_off": "vsplit"}),
    "0x00296160_native_vslotkeep_off": ("fail", "went to", 0, {"src": "0x00296160_native_vsplit", "native": True, "n_inputs": 60, "equiv_off": "vslotkeep"}),
    "0x00296160_native_vsplit_wrong": ("fail", None, 0, {"native": True, "n_inputs": 60}),
    "0x00296160_native_vslotkeep_wrong": ("fail", None, 0, {"native": True, "n_inputs": 60}),
    # ... and a split the original's code can't have (its stack would not balance) is not taken: a real wrong declaration
    # (perf1: under SSE the first difference found is another one, `this` of call #3; the status is the same)
    "0x000f0e60_native_vsplit_wrong": ("fail", "argument 2", 0, {"native": True, "n_inputs": 60, "float": "x87"}),
    # uninitarg, purecall, narrowstruct: a by-value struct whose padding nothing writes, built by a copy constructor that writes only it
    "0x001fe000_native_uninitarg": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x001fe000_native_uninitarg_off": ("fail", "argument 4", 0, {"src": "0x001fe000_native_uninitarg", "native": True, "n_inputs": 60, "equiv_off": "uninitarg"}),
    "0x001fe000_native_purecall_off": ("fail", "this (ecx)", 0, {"src": "0x001fe000_native_uninitarg", "native": True, "n_inputs": 60, "equiv_off": "purecall"}),
    "0x001fe000_native_narrowstruct_off": ("fail", "argument 5", 0, {"src": "0x001fe000_native_uninitarg", "native": True, "n_inputs": 60, "equiv_off": "narrowstruct"}),
    "0x001fe000_native_uninitarg_wrong": ("fail", "argument 3", 0, {"native": True, "n_inputs": 60}),
    "0x001fe000_native_narrowstruct_wrong": ("fail", "argument 5", 0, {"native": True, "n_inputs": 60}),
    "0x001fe000_native_purecall_wrong": ("fail", "this (ecx)", 0, {"native": True, "n_inputs": 60}),
    # round 24 (native19): fretwide - a stubbed float result carries bits beyond a float's 24 (a CRT __CI routine, or a
    # callee declared hulk_freg whose original computes its result): `return (float)asin(x)` rounds what the original
    # returns unrounded (div1's camera-pitch bug, 0x000189c0; the same for acos 0x00018a20). 0x000189c0_native_ci is
    # the fixed source (it returned (float)r and passed before)
    "0x000189c0_native_fretwide_wrong": ("fail", "returned", 0, {"native": True, "n_inputs": 60}),
    "0x000189c0_native_fretwide_off": ("equivalent", None, 0, {"src": "0x000189c0_native_fretwide_wrong", "native": True, "n_inputs": 60, "equiv_off": "fretwide"}),
    "0x00018a20_native_fretwide": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x00018a20_native_fretwide_wrong": ("fail", "returned", 0, {"native": True, "n_inputs": 60}),
    # retarg: the callee returns its first stack argument (`Vec3 *F(Vec3 *out, ...)`); clang's -O0 caller keeps eax in a
    # local and reads through it later, where sretret only saw the original's `call; mov ecx, [eax]` (11 chase-camera
    # sources failed --wine on input 0)
    "0x000a0940_native_retarg": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x000a0940_native_retarg_off": ("fail", None, 0, {"src": "0x000a0940_native_retarg", "native": True, "n_inputs": 60, "equiv_off": "retarg,sretcall"}),
    "0x000a0940_native_retarg_wrong": ("fail", "this+0x", 0, {"native": True, "n_inputs": 60}),
    # (not a checker rule) clang's x87 code leaves `(float)(unsigned)x` unrounded in the register: the original stores the
    # numerator as a float, so the source needs a float local (MATCH either way)
    "0x00266790_native_uitofp": ("equivalent", None, 0, {"native": True, "n_inputs": 300}),
    "0x00266790_native_uitofp_wrong": ("fail", "returned", 0, {"native": True, "n_inputs": 300}),
    # convdef: a register note (`// equiv-conv: FUN_x ecx`) on a callee declared as a free function whose verified
    # definition is a member: the Wine build pushes the word the definition reads from ecx (wine_conv_check check 9).
    # The fixed sources call the member under clang and keep the note for MSVC mode
    "0x000e07c0_native_convdef": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x000e07c0_native_convdef_wrong": ("fail", "L2 conv_note_vs_definition", 0, {"native": True, "n_inputs": 60}),
    "0x000e07c0_native_convdef_off": ("equivalent", None, 0, {"src": "0x000e07c0_native_convdef_wrong", "native": True, "n_inputs": 60, "equiv_off": "convdef"}),
    "0x00334c70_native_convdef": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x00334c70_native_convdef_wrong": ("fail", "L2 conv_note_vs_definition", 0, {"native": True, "n_inputs": 60}),
    # round 25 (nf5), ddtor: the original is a scalar deleting destructor (`call base dtor; if (flags & 1) delete`), which clang
    # does not emit; the clang side gets the function wine_link synthesizes (complete destructor + operator delete) appended,
    # so call #1 is the base destructor on both sides. Before: "call #1 went to 0x0008d330 instead of 0x001d04a0"
    "0x0002cbf0_native_ddtor": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x0002cbf0_native_ddtor_wrong": ("fail", "write to", 0, {"native": True, "n_inputs": 60}),
    # ptrfuzz: a call through a fixed function pointer in .data whose fuzzed value is an address inside the image (0x20000, a
    # `ret 4` function): the pointer's type (no stack words, from its other call sites) decides, not the code it points at. The
    # `push 0` is the next virtual call's second argument. Before: "call #8 to 0x00020000: argument 1 is ..., expected 0"
    "0x000ef4f0_native_ptrfuzz": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x000ef4f0_native_ptrfuzz_wrong": ("fail", "argument 2", 0, {"native": True, "n_inputs": 100}),
    "0x000ef4f0_native_ptrfuzz_off": ("fail", "argument 1 is", 0, {"src": "0x000ef4f0_native_ptrfuzz", "native": True, "n_inputs": 100, "equiv_off": "ptrfuzz"}),
    # sretvt: the call's result is an object whose first word is a vtable it dispatches through (`mov edx,[eax]; mov ecx,eax;
    # call [edx]`), not a struct returned through a hidden pointer: eax is the callee's result, not the first argument.
    # Before: "call #4 to 0x00000000: this (ecx) is 0x40000458, expected stack"
    "0x000f8970_native_sretvt": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x000f8970_native_sretvt_wrong": ("fail", "to 0x", 0, {"native": True, "n_inputs": 100}),
    "0x000f8970_native_sretvt_off": ("fail", None, 0, {"src": "0x000f8970_native_sretvt", "native": True, "n_inputs": 100, "equiv_off": "sretvt"}),
    # sretcall: the original's code after a virtual call reads through eax (`call [eax+0x6c]; mov edx,[eax]`), so the harness
    # returns the call's first argument (a hidden struct pointer); clang's caller stores eax to a local first, which
    # sret_after cannot see, so ours got a fuzzed pointer. The k-th call of ours gets what the original's k-th call got.
    # Before: "write to arg1+0x0 before call #2 was 0x0, expected 0xffffffff"
    "0x00098500_native_sretcall": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x00098500_native_sretcall_wrong": ("fail", "write to", 0, {"native": True, "n_inputs": 100}),
    "0x00098500_native_sretcall_off": ("fail", "write to arg1", 0, {"src": "0x00098500_native_sretcall", "native": True, "n_inputs": 100, "equiv_off": "sretcall"}),
    # rdcap: a pointer the real callee only WRITES through (an out parameter) passes the local's earlier contents to nothing that reads
    # them; only the bytes the callee reads are compared before the call. Before: "the local passed as argument 1 differs at +0x0
    # (0x5a5a5a5a, expected 0x3f800000 (1f))" (the original's stale stack word against ours unset)
    "0x001f7320_native_rdcap": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x001f7320_native_rdcap_wrong": ("fail", None, 0, {"native": True, "n_inputs": 100}),
    "0x001f7320_native_rdcap_off": ("fail", "the local passed as argument 1", 0, {"src": "0x001f7320_native_rdcap", "native": True, "n_inputs": 100, "equiv_off": "rdcap"}),
    # lstatic: a function-local static is `?k1@?HM@??F...` in MSVC's mangling and `?k1@?1??F...` in clang's; the binding the MSVC
    # object's pairing found carries over (clang's own pairing bound `k1` to a float literal: initializer_differs 0.0 vs 40.0)
    "0x000418f0_native_lstatic": ("equivalent", None, 0.9, {"native": True, "n_inputs": 60}),
    "0x000418f0_native_lstatic_wrong": ("fail", None, 0, {"native": True, "n_inputs": 60}),
    # (perf1: the `_off` case shows the x87 object's float-literal pairing taking `k1`; the SSE object pairs differently)
    "0x000418f0_native_lstatic_off": ("fail", "initializer_differs", 0, {"src": "0x000418f0_native_lstatic", "native": True, "n_inputs": 60, "equiv_off": "lstatic", "float": "x87"}),
    # initsize: clang's COFF has no symbol sizes, so a static array was compared over the rest of its section (private constants
    # that follow it); the MSVC object's size for the name is the extent. Before: initializer_differs _kLabel size=256
    "0x000da930_native_initsize": ("equivalent", None, 0.5, {"native": True, "n_inputs": 100}),
    "0x000da930_native_initsize_wrong": ("fail", None, 0, {"native": True, "n_inputs": 100}),
    "0x000da930_native_initsize_off": ("fail", "initializer_differs", 0, {"src": "0x000da930_native_initsize", "native": True, "n_inputs": 100, "equiv_off": "initsize"}),
    # intrwrite/natintr: clang copies a struct through `memcpy`, the original inline (`rep movsd`, which the write hook records). The
    # copy into the frame counts as written (a later stub does not fill it as free room), and the call, which is not one of the
    # original's, runs as the inlined CRT routine. Before: "call #9 to 0x001d6b60: argument 2 is 0x00000003, expected 0x00000000"
    "0x00036480_native_intrwrite": ("equivalent", None, 0.9, {"native": True, "n_inputs": 100}),
    "0x00036480_native_intrwrite_wrong": ("fail", "argument 17", 0, {"native": True, "n_inputs": 100}),
    "0x00036480_native_intrwrite_off": ("fail", "argument 2 is", 0, {"src": "0x00036480_native_intrwrite", "native": True, "n_inputs": 100, "equiv_off": "intrwrite"}),
    "0x0002cbf0_native_ddtor_off": ("fail", "call #1 went to", 0, {"src": "0x0002cbf0_native_ddtor", "native": True, "n_inputs": 60, "equiv_off": "ddtor"}),
    # round 26 (sweep1) retwiden: a char/bool/short declaration whose original callers read all of eax (`cmp eax, 1` at
    # 0x001b28d4) is compared as int; clang (and MSVC from a char source: `mov al, 1`) leave the upper bytes undefined
    "0x001b05a0_retwiden": ("equivalent", None, 0.5, {"n_inputs": 200}),
    "0x001b05a0_retwiden_wrong": ("fail", "returned 0x", 0, {"n_inputs": 200}),
    "0x001b05a0_retwiden_off": ("equivalent", None, 0, {"src": "0x001b05a0_retwiden_wrong", "n_inputs": 200, "equiv_off": "retwiden"}),
    # crash2 vstatic: AnimationPhaseMatchedTrack::vfunc_7 (a plain ret) declared with 3 arguments (the three pushes before
    # the call are 0x225e00's): clang's caller re-reserves 12 bytes the callee never popped and reads its frame 12 bytes
    # off (the play3 crash in CCharacterGolem::vfunc_3). The original's pops come from tools/vcall_scan.py's model
    "0x0013d7b0_native_vstatic": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x0013d7b0_native_vstatic_wrong": ("fail", "original's call takes 0", 0, {"native": True, "n_inputs": 100}),
    "0x0013d7b0_native_vstatic_off": ("equivalent", None, 0, {"src": "0x0013d7b0_native_vstatic_wrong", "native": True, "n_inputs": 100, "equiv_off": "vstatic"}),
    # round 27 (x64-8) cdeclret: a C-linkage definition's return type (and parameters) come from our declaration, as a C++
    # name's from its mangling. Before, Ghidra's guess (build/farm/ghidra_c, absent on mac2: `noghidra` stands for such a
    # host) or nothing: the Wine build's eax of this extern "C" void function was compared, "(return type unknown)"
    "0x002d1b00_native_c_void_ret": ("equivalent", None, 0, {"native": True, "n_inputs": 100, "equiv_off": "noghidra"}),
    "0x002d1b00_native_c_void_ret_off": ("fail", "return type unknown", 0, {"src": "0x002d1b00_native_c_void_ret", "native": True, "n_inputs": 100, "equiv_off": "noghidra,cdeclret"}),
    "0x00096600_native_c_ret_wrong": ("fail", "returned 0x00000002", 0, {"native": True, "n_inputs": 100, "equiv_off": "noghidra"}),
    # round 27 convcname: `// equiv-conv: target ecx esi stack stack` on a definition that took extern "C" (symbol _target):
    # resolved by its C name, and our own argument layout from the declaration's parameters (cdeclret). Before: unresolved
    "0x001687a0_c_conv_self": ("equivalent", None, 0.9, {"n_inputs": 300}),
    "0x001687a0_c_conv_self_wrong": ("fail", "returned", 0, {"n_inputs": 300}),
    "0x001687a0_c_conv_self_off": ("fail", None, 0, {"src": "0x001687a0_c_conv_self", "n_inputs": 300, "equiv_off": "convcname"}),
    # round 27 cdeclret, C-linkage callees: a local passed by pointer to `extern "C" FUN_00202560(Vec3 *origin, ...)` is
    # compared over sizeof(Vec3) from our declaration, as for a C++ callee's mangled types; before, to the next local (+0xc)
    "0x0018f6d0_c_callee_local": ("equivalent", None, 0.8, {"n_inputs": 300}),
    "0x0018f6d0_c_callee_local_wrong": ("fail", "the local passed as argument 1 differs at +0x4", 0, {"n_inputs": 300}),
    "0x0018f6d0_c_callee_local_off": ("fail", "the local passed as argument 1 differs at +0xc", 0, {"src": "0x0018f6d0_c_callee_local", "n_inputs": 300, "equiv_off": "cdeclret"}),
    # (clean2, sufname) callees renamed by the suffix convention (`Intermediate_000592a0`, tools/addr_names.py) bind by
    # the address in their names: two callees of one shape whose names carry each other's addresses are caught (the
    # original calls 0x000592a0 first); without the rule, pairing by position binds each to the original's call there
    "0x000139b0_suffix_names": ("equivalent", None, 0.75, {"n_inputs": 300}),
    "0x000139b0_suffix_names_swapped": ("fail", "call #1 went to 0x00059a30 instead of 0x000592a0", 0, {"n_inputs": 300}),
    "0x000139b0_suffix_names_swapped_off": ("equivalent", None, 0, {"src": "0x000139b0_suffix_names_swapped", "n_inputs": 300, "equiv_off": "sufname"}),
    # (adr1) an address the original references written as an integer: the same bytes on 32-bit, a bogus pointer in
    # the 64-bit image (XGetDeviceChanges(0x3ea820, ...) for XPP's gamepad type); level 2 (EQUIV_OFF=addrlit: off)
    "0x00278060_addrlit_wrong": ("fail", "L2 address_as_integer 0x003ea820", 0, {"n_inputs": 50}),
    "0x00278060_addrlit_wrong_off": ("equivalent", None, 0, {"src": "0x00278060_addrlit_wrong", "n_inputs": 50, "equiv_off": "addrlit"}),
    "0x00278060_addrlit": ("equivalent", None, 0, {"n_inputs": 50}),
    # ... FourCC codes in the data range pushed as keys (`Find('TRA', ...)`) are not addresses
    "0x002acd70_fourcc": ("equivalent", None, 0, {"n_inputs": 100}),
    # round 28 (eqx87, x87conv): a callee's x87 return is the original's (the stub follows the original's code after the
    # call, for ours too), and an empty-register read or a register left at return fails. The five sources the Wine build
    # leaked or underflowed the x87 stack with (afa736c58): normalize 0x0022d110 (returns its length in st0) declared void,
    # 0x0022d180 (returns nothing) declared float, and CPathAgent::vfunc_4 declared float where it returns its avoid
    # behaviour's bool (a virtual pass-through: the slot's implementations say no float). _off: the old rule passed them
    "0x000c72e0_x87conv_wrong": ("fail", "returns a float in st(0)", 0, {"seeds": [0, 1, 2, 3]}),
    "0x000c72e0_x87conv_wrong_off": ("equivalent", None, 0, {"src": "0x000c72e0_x87conv_wrong", "seeds": [0, 1, 2, 3], "equiv_off": "x87conv"}),
    "0x000c72e0_x87conv": ("equivalent", None, 0, {"seeds": [0, 1, 2, 3]}),
    "0x000c72e0_x87conv_wrong_native": ("fail", "returns a float in st(0)", 0, {"src": "0x000c72e0_x87conv_wrong", "native": True, "seeds": [0, 1, 2, 3]}),
    "0x000c72e0_x87conv_native": ("equivalent", None, 0, {"src": "0x000c72e0_x87conv", "native": True, "seeds": [0, 1, 2, 3]}),
    "0x0030c440_x87conv_wrong": ("fail", "x87 stack depth at return 1, expected 0", 0, {"seeds": [0, 1, 2, 3]}),
    "0x0030c440_x87conv": ("equivalent", None, 0, {"seeds": [0, 1, 2, 3]}),
    "0x0030c440_x87conv_wrong_native": ("fail", "returns a float in st(0)", 0, {"src": "0x0030c440_x87conv_wrong", "native": True, "seeds": [0, 1, 2, 3]}),
    "0x0030c440_x87conv_native": ("equivalent", None, 0, {"src": "0x0030c440_x87conv", "native": True, "seeds": [0, 1, 2, 3]}),
    "0x001b05a0_x87conv_wrong": ("fail", "reads an empty x87 register", 0, {"seeds": [8]}),
    "0x001b05a0_x87conv_wrong_off": ("equivalent", None, 0, {"src": "0x001b05a0_x87conv_wrong", "seeds": [8], "equiv_off": "x87conv"}),
    "0x001b05a0_x87conv": ("equivalent", None, 0, {"seeds": [8]}),
    "0x001d8350_x87conv_wrong": ("fail", "returns nothing in st(0)", 0, {"seeds": [0, 1, 2, 3]}),
    "0x001d8350_x87conv": ("equivalent", None, 0, {"seeds": [0, 1, 2, 3]}),
    "0x001d8350_x87conv_wrong_native": ("fail", "reads an empty x87 register", 0, {"src": "0x001d8350_x87conv_wrong", "native": True, "seeds": [0, 1, 2, 3]}),
    "0x001d8350_x87conv_wrong_native_off": ("equivalent", None, 0, {"src": "0x001d8350_x87conv_wrong", "native": True, "seeds": [0, 1, 2, 3], "equiv_off": "x87conv"}),
    "0x001d8350_x87conv_native": ("equivalent", None, 0, {"src": "0x001d8350_x87conv", "native": True, "seeds": [0, 1, 2, 3]}),
    # 0x001050d0 with its early exits returning a value (the equivalent/ source falls off the end there, where clang emits
    # ud2) and the `hulk_freg m` of docs/wine-float.md: the bool source passes --wine, the float one underflows at the tail call
    "0x001050d0_x87_vslot_wrong": ("fail", "ours reads an empty x87 register", 0, {"native": True, "seeds": list(range(8))}),
    "0x001050d0_x87_vslot": ("equivalent", None, 0, {"native": True, "seeds": list(range(8))}),
    # all eight x87 registers in use (`fld st(2); fmul st(3)` at depth 8): TOP alone reads as an empty stack, not an underflow
    "0x0024ce50_x87_full_stack": ("equivalent", None, 0, {"seeds": [0]}),
    # (wine1) Wine-mode inputs no real caller makes, each turned inconclusive (the _off cases: the old failure):
    # numuse's nums[luaO_log2(k)+1] with a stubbed log2 indexes out of the whole stack (fescape);
    "0x00219a60_wine_fescape": ("equivalent", None, 0, {"native": True, "seeds": [55]}),
    "0x00219a60_wine_fescape_off": ("fail", "unexpected write", 0, {"src": "0x00219a60_wine_fescape", "native": True,
                                                                      "seeds": [55], "equiv_off": "fescape"}),
    # luaO_chunkid with `out` at a literal it copies from (rowrite) or `out` == `source` (strcat of overlapping strings: intrub)
    "0x00216340_wine_rowrite": ("equivalent", None, 0, {"native": True, "seeds": [14, 17, 26, 45, 112]}),
    "0x00216340_wine_rowrite_off": ("fail", "write to", 0, {"src": "0x00216340_wine_rowrite", "native": True,
                                                            "seeds": [14, 17, 26, 45, 112], "equiv_off": "rowrite,intrub"}),
    # DumpConstants passes &bits (an int) to D->writer, a callee of unknown reach: the word behind it is another local in
    # each frame (natobj: clang's debug information bounds the object); a wrong value inside the object still fails
    "0x0021aa00_wine_natobj": ("equivalent", None, 0, {"native": True, "seeds": [1, 9, 44]}),
    "0x0021aa00_wine_natobj_off": ("fail", "differs at +0x4", 0, {"src": "0x0021aa00_wine_natobj", "native": True,
                                                                  "seeds": [1, 9, 44], "equiv_off": "natobj"}),
    "0x0021aa00_wine_natobj_wrong": ("fail", "differs at +0x0", 0, {"native": True, "seeds": [1, 9, 44]}),
    # str_format: a directed input plants the original's frame address (its buffer's end - 1) in the luaL_Buffer's p: ours
    # gets the same offset into its own buffer (fillrel)
    "0x0033d400_wine_fillrel": ("equivalent", None, 0, {"native": True, "seeds": [5]}),
    "0x0033d400_wine_fillrel_off": ("fail", None, 0, {"src": "0x0033d400_wine_fillrel", "native": True, "seeds": [5],
                                                      "equiv_off": "fillrel"}),
    # (x64t9) ExportInfoLoader::vfunc_5: MSVC 7.1 inlines memcmp (`repe cmpsb`), clang's object calls it; the call runs as
    # an intrinsic (memcmp). Off, it is a callee the original never calls (the old failure paired it with 0x002669f0)
    "0x002f4eb0_wine_memcmp": ("equivalent", None, 0, {"native": True, "n_inputs": 40}),
    "0x002f4eb0_wine_memcmp_off": ("fail", "missing call", 0, {"src": "0x002f4eb0_wine_memcmp", "native": True,
                                                              "n_inputs": 40, "equiv_off": "memcmp"}),
    # (x64t10, strterm) its unit-name compares: the name a stub filled holds the literal only once the length byte the same
    # stub filled puts `name[n] = 0` right after it (that store replaced the planted word's fill). One directed input plants
    # both; without it (EQUIV_OFF=strterm) coverage stays 22/30 on both sides
    "0x002f4eb0_strterm": ("equivalent", None, 1.0, {"src": "0x002f4eb0_wine_memcmp"}),
    "0x002f4eb0_wine_strterm": ("equivalent", None, 1.0, {"src": "0x002f4eb0_wine_memcmp", "native": True}),
    # (x64t10, smasharg) input 907: `tag[n] = 0` with n = 0xf6 overruns the original's frame past its return address into an
    # argument word, and clang's into its saved ebp: undefined behaviour in the original, inconclusive (round 8's smash)
    "0x002f4eb0_wine_smasharg": ("equivalent", None, 0, {"src": "0x002f4eb0_wine_memcmp", "native": True, "seeds": list(range(8)) + [907]}),
    "0x002f4eb0_wine_smasharg_off": ("fail", "ebp not preserved", 0, {"src": "0x002f4eb0_wine_memcmp", "native": True,
                                                                      "seeds": list(range(8)) + [907], "equiv_off": "smasharg"}),
    # (chk1, smashexpl) rev2's mutants: a different call sequence on the overrun inputs only (M1: before `tag[n] = 0`, M2:
    # after it). The overrun explains a register restored from an overwritten slot, ours going wild, or a value ours read
    # back from a local its own overrun replaced; never a different call. Both passed --wine at 3,000 before (79378/79379)
    "0x002f4eb0_wine_smash_m1": ("fail", "call #3 went to 0x002ecb90", 0, {"native": True, "seeds": list(range(8)) + [907]}),
    "0x002f4eb0_wine_smash_m2": ("fail", "call #3 went to 0x002ecb90", 0, {"native": True, "seeds": list(range(8)) + [907]}),
    # (chk1, boolexpl) M3: Kilometers gives 2, not 3; the one input that reaches it (0+str) also reads a non-bool byte as a
    # bool. Ours runs again with the byte read as a bool and still differs: not explained (passed at 3,000 before, 79385)
    "0x002f4eb0_wine_boolub_m3": ("fail", "argument 1 is 0x00000002, expected 0x00000003", 0, {"native": True, "seeds": [0]}),
    # read_numeral: `b->buffer[b->n++] = c` and `*z->p++` that clang orders store-first, against a buffer overlapping its
    # header (a source fix, not a checker rule: the order the original has)
    "0x0021b230_wine_order": ("equivalent", None, 0, {"native": True, "seeds": [8, 24, 54]}),
    "0x0021b230_wine_order_wrong": ("fail", "write to", 0, {"native": True, "seeds": [8, 24, 54]}),
    # (integ3 chk3, hoist) `push 2; je L; call [edx+0x40]; ... L: call [eax+0x40]`: MSVC hoists the word both calls take
    # above the branch, and vcall_scan's stack-depth model gave each call only the words pushed in its own straight line
    # (feasible pops {0}, so clang's `vf16(2)` was "4 bytes that belong to another call"). _wrong: slot 16 declared with a
    # second (defaulted) word, 8 bytes where the hoisted push gives it at most 4
    "0x00081b20_native_hoist": ("equivalent", None, 0, {"native": True, "n_inputs": 200}),
    "0x00081b20_native_hoist_off": ("fail", "belong to another call", 0, {"src": "0x00081b20_native_hoist", "native": True,
                                                                         "n_inputs": 20, "equiv_off": "hoist"}),
    "0x00081b20_native_hoist_wrong": ("fail", "passes it 8 bytes", 0, {"native": True, "n_inputs": 20}),
    # (integ3 chk3, thiscallpend) fix126's source for 0x002b2040: `push [esi+0x3c]; call [edx+0x4c]` (IsFrozen, a
    # __thiscall virtual with no argument) pushes FUN_002899e0's 8th word early, and the `add esp, 0x20` after that cdecl
    # call releases it. The word was taken for IsFrozen's (caller-cleaned) argument. _wrong: IsFrozen declared taking it
    "0x002b2040_thiscallpend": ("equivalent", None, 0, {"n_inputs": 300}),
    "0x002b2040_wine_thiscallpend": ("equivalent", None, 0, {"src": "0x002b2040_thiscallpend", "native": True, "n_inputs": 300}),
    "0x002b2040_thiscallpend_off": ("fail", "argument 1 is", 0, {"src": "0x002b2040_thiscallpend", "n_inputs": 20,
                                                                 "equiv_off": "thiscallpend"}),
    "0x002b2040_thiscallpend_wrong": ("fail", "the original's call takes 0", 0, {"n_inputs": 20}),
    "0x002b2040_wine_thiscallpend_wrong": ("fail", "the original's call takes 0", 0, {"src": "0x002b2040_thiscallpend_wrong",
                                                                                      "native": True, "n_inputs": 20}),
    # must-pass: a __thiscall virtual that pops its own word, then `push ...; call f; add esp, 4*k` releasing only f's
    # (0x002de520 `push ebx; call [eax+0x38]`, then FUN_00344e74's five words and `add esp, 0x14`; 0x002de3f0's vcall at
    # 0x2de4c4, pending_use ("callee", 3)): thiscallpend leaves the virtual its words, both modes stay equivalent
    "0x002de520_thiscall_own": ("equivalent", None, 0, {"n_inputs": 200}),
    # (0x002de520 --wine fails at HEAD too, `call #2 went to 0x00000000 instead of 0xc5bcba4c`: a source matter, no case)
    "0x002de3f0_thiscall_own": ("equivalent", None, 0, {"src": "0x002de520_thiscall_own", "n_inputs": 200}),
    "0x002de3f0_wine_thiscall_own": ("equivalent", None, 0, {"src": "0x002de520_thiscall_own", "native": True, "n_inputs": 200}),
    # (integ3 chk3, repstep) the original copies with `rep movsd/movsb`, one emulator step per element; the source's element
    # loops take a few steps per word, and input 236 ran out of the 2x budget (MSVC mode). Our run now gets 8 steps per
    # byte the original's rep instructions moved. _slow: a 64-iteration busy loop per word still runs out
    "0x002c84a0_repstep": ("equivalent", None, 0, {"seeds": [236]}),
    "0x002c84a0_repstep_off": ("fail", "ours timeout", 0, {"src": "0x002c84a0_repstep", "seeds": [236], "equiv_off": "repstep"}),
    "0x002c84a0_repstep_slow": ("fail", "ours timeout", 0, {"seeds": [236]}),
    # (integ3 chk3, lsguard) the function-local static guard is clang's `$S1` and MSVC 7.1's `$S3` (0x000418f0): paired by
    # function and order. _bit: k1 no longer static, so k2 takes the guard's bit 1 where the original's tests bit 2
    "0x000418f0_native_lsguard": ("equivalent", None, 0, {"native": True, "n_inputs": 100}),
    "0x000418f0_native_lsguard_off": ("fail", "0x004dc2fc", 0, {"src": "0x000418f0_native_lsguard", "native": True,
                                                                "n_inputs": 100, "equiv_off": "lsguard"}),
    "0x000418f0_native_lsguard_bit": ("fail", "missing write to global", 0, {"native": True, "n_inputs": 100}),
}

# verify_relocs.py cases: name -> (expected status, issue kind it must report or None)
RELOC_CASES = {
    # a wide literal compared only up to its first NUL: L"()" passed for the original's L"()[]{}=;" (native13 stop 34)
    "0x003388d0_literal": ("ok", None),
    "0x003388d0_literal_wrong": ("bad", "string_mismatch"),
    # round 17 (cl5). native14 stop 37: matches/0x00042930 called the member 0x00042890 through `void __stdcall
    # helper(int, float)`; ecx held the caller's `this` in the original, natively it is the first argument
    "0x00042930_thiscall_decl": ("ok", None),
    "0x00042930_thiscall_decl_wrong": ("bad", "free_decl_of_thiscall"),
    "0x00336f10_thiscall_decl_wrong": ("bad", "free_decl_of_thiscall"),      # `void FUN_00019420()` for 0x003352b0
    # (clean2) a callee named by the suffix convention must be the function its name says: Init_001d4320 for the
    # original's call to 0x001d43b0 byte-matches (the relocation is masked) and was ok before
    "0x001d47c0_suffix_name": ("ok", None),
    "0x001d47c0_suffix_name_wrong": ("bad", "name_address_mismatch"),
    # (unb3) Ghidra's placeholders carry an address too: FUN_x / DAT_x names propagated from a function of the same
    # shape (the relocation, net of its addend, must be the name's address; RELOC_OFF=placename turns it off)
    "0x00024170_fun_name": ("ok", None),
    "0x00024170_fun_name_wrong": ("bad", "name_address_mismatch"),
    "0x00068cc0_dat_name": ("ok", None),
    "0x00068cc0_dat_name_wrong": ("bad", "name_address_mismatch"),
    # (adr1) RTTI descriptors passed to __RTDynamicCast as integers: the byte match holds, no relocation (unb4's
    # finding; tools/addr_literal.py, RELOC_OFF=addrlit turns it off); FourCC codes compared in a switch are values
    "0x00050680_addrlit": ("ok", None),
    "0x00050680_addrlit_wrong": ("bad", "address_as_integer"),
    "0x00285650_fourcc": ("ok", None),
}

# (round 23, declarity) decl_arity cases, level 2 only: name -> ({(kind, callee)} the diagnostic must report, exactly;
# verify() keyword arguments plus `equiv_off`, `src` and `strict` (STRICT_DECL: the status must then be "fail"))
DECL_CASES = {
    # FUN_0024ace0 reads six stack words, the source declares four and gives the other two to FUN_00240750 (none)
    "0x001f32b0_declarity_wrong": ({("too_few", "0x0024ace0"), ("too_many", "0x00240750")}, {}),
    "0x001f32b0_declarity_wrong_strict": ({("too_few", "0x0024ace0"), ("too_many", "0x00240750")},
                                          {"src": "0x001f32b0_declarity_wrong", "strict": True}),
    "0x001f32b0_declarity_off": (set(), {"src": "0x001f32b0_declarity_wrong", "equiv_off": "declarity"}),
    "0x001f32b0_declarity": (set(), {}),           # the declarations corrected
    # FUN_00240750 takes nothing: the float is FUN_00243090's second argument
    "0x001e95c0_declarity_wrong": ({("too_few", "0x00243090"), ("too_many", "0x00240750")}, {}),
    # the time function pointer at 0x004de948 takes no stack word (sites call it with nothing pending)
    "0x000f0e60_declarity_wrong": ({("too_many", "0x004de948")}, {}),
    "0x000ef4f0_declarity_wrong": ({("too_many", "0x004de948")}, {}),
    "0x000e1670_declarity_wrong": ({("too_many", "0x004de948")}, {}),
    "0x000e1610_declarity_wrong": ({("too_many", "0x004de948")}, {}),     # a C name: clang's call sites tell
    # FUN_0026fd50(x, align) reads two words; the source declares one (a byte match: the original pushed c earlier)
    "0x00277630_declarity_wrong": ({("too_few", "0x0026fd50")}, {}),
    # correct: one site passes esi on (`push esi`, esi untouched there): an argument, not a register save
    "0x0021b520_declarity_passon": (set(), {}),
    # correct: an 8-byte struct returned in edx:eax, not through a hidden pointer (clang's call sites tell)
    "0x000f2f50_declarity_structret": (set(), {}),
}

# (eq64) the 64-bit check, tools/equiv64.py (`equiv.py --x64`): name -> (status, class or None, text the difference
# must contain or None, minimum completed inputs). The x86-64 object against the 32-bit clang object of the same source.
X64_CASES = {
    # a plain setter: a typed `this`, an int and a byte field
    "0x000ac780_x64_setter": ("equivalent", None, None, 50),
    # vftables of input objects (slot by MS vftable index on both targets), float returns of stubs (st0 / xmm0), an
    # empty member's address (no leaf at its offset)
    "0x00015090_x64_vcall": ("equivalent", None, None, 50),
    # matches/0x0013e520: `operator new(0x10)` for a class of 0x10 bytes on 32-bit and 0x18 on 64-bit (vfptr 8 bytes):
    # a real 64-bit bug; the class comes from the vftable the inline constructor stores at +0
    "0x0013e520_x64_small_new": ("fail", "layout", "allocation of 0x10 bytes holds a TrackFactoryTemplate_13e520", 0),
    # ... and with `operator new(sizeof(...))` it passes
    "0x0013e520_x64_sizeof_new": ("equivalent", None, None, 50),
    # mutants of 0x000ac780: a pointer kept in an int field; a field read at its 32-bit byte offset behind a pointer
    # field; a struct holding a pointer copied by its 32-bit size
    "0x000ac780_x64_ptr_in_int": ("fail", "ptrtrunc", "[0].value", 0),
    "0x000ac780_x64_raw_offset": ("fail", "layout", "of the 8-byte pointer p", 0),
    "0x000ac780_x64_raw_offset_typed": ("equivalent", None, None, 50),
    "0x000ac780_x64_memcpy_size": ("fail", "layout", "[0].a.v", 0),
    # (ptr1) a fight parameter registration: the game's allocator declared with C++ linkage (?FUN_0008d690@@YAPAXI@Z),
    # a template class typed by its vftable at +0 (`??_7?$ParamEnumConstList@...`, llvm-undname), a string literal
    # whose mangled hash holds `PE` (`??_C@_07DIJKPEDD@compare?$AA@`, not a __ptr64 qualifier): 32 bytes for a class
    # of 0x38 on 64-bit ...
    "0x00053220_x64_tmpl_new": ("fail", "layout", "allocation of 0x20 bytes holds a fight::ParamEnumConstList<CCharacterSizeCondition>", 0),
    # ... and with FUN_0008d690(sizeof(...)) it passes
    "0x00053220_x64_tmpl_sizeof": ("equivalent", None, None, 50),
    # (ptr1) a pointer advanced by a byte count inside an `unsigned` array: the same place on both targets
    "0x0026a050_x64_inner_offset": ("equivalent", None, None, 50),
    # (ptr1) pure3d's bump allocator (a member, size first) sized by the 32-bit size; hulk_intptr arguments holding
    # the address of a local compare as stack pointers ...
    "0x0028cfd0_x64_pool_small": ("fail", "layout", "allocation of 0x1c bytes holds a ColourChannel_28cfd0", 0),
    # ... and sized by sizeof it passes
    "0x0028cfd0_x64_pool_sizeof": ("equivalent", None, None, 50),
    # (ptr1) a stub's `void*` result the source casts to a record (`(CClosure *)FUN_00219520(L, n)`) is that record:
    # lua_pushcclosure's closure fields compare by name ...
    "0x002134a0_x64_retcast": ("equivalent", None, None, 8),
    # ... and a store at the closure's 32-bit byte offset is found
    "0x002134a0_x64_retcast_raw": ("fail", None, "[0].f", 0),
    # (ptr1) an array of pointers allocated as `count * 4` bytes (the allocator's result cast to Ref**: typed as an
    # array of pointers; a fuzzed count asking for more than 16 MB sets the input aside) ...
    "0x002d3980_x64_count4": ("fail", "layout", "write past the end of alloc#6(Ref_2d3980*)", 0),
    # ... and `count * sizeof(Ref*)` passes
    "0x002d3980_x64_count_sizeof": ("equivalent", None, None, 40),
    # (ptr1) a pointer-sized integer field (hulk_intptr: core::MemoryDlAllocator's arena bounds) holds a small integer
    # or an object's address: an address compared with the bounds gives the same answer on both targets
    "0x0026cb40_x64_ptr_bounds": ("equivalent", None, None, 50),
    # (x64eq) a scalar deleting destructor the 64-bit object defines itself (a native-only explicit instantiation emits
    # the vftable and clang's ??_G beside it, which calls the sized operator delete): only the 32-bit side gets the
    # synthesized one (was a compile error: the symbol defined twice), and sized and unsized delete are one callee
    "0x00236180_x64_ddtor_native": ("equivalent", None, None, 50),
    # (x64eq, rawint) an int leaf with the same bits on both sides (a byte field's untouched neighbours in a fresh
    # allocation) is the same integer, even where its 32-bit value lands in a heap object (was a false ptrtrunc)
    "0x002fdc90_x64_rawint": ("equivalent", None, None, 50),
    # (x64t9, sitecasts) one allocator cast to two types in one body (the request ring's HulkLoadEntry*, the 256-byte
    # char* buffer): each allocation takes its own call site's cast (EQ64_OFF=sitecasts: the buffer's end read as a
    # HulkLoadEntry array, a false layout difference, +256 against +128). What is left is `int`: a fuzzed count whose
    # `n * sizeof(HulkLoadEntry)` wraps differently on the two targets (not a gating class)
    "0x002656b0_x64_sitecasts": ("fail", "int", None, 50),
    # (x64eq) an adjustor thunk (`?f@C@@W3AEXXZ`) is paired with the 64-bit thunk of the same method (`W7EAA`), typed by
    # the method's declaration (was "function under test not found in the 64-bit object")
    "0x00268010_x64_thunk": ("equivalent", None, None, 50),
    # (x64eq) __chkstk's i386 C name (`_chkstk`) is the probe, not a callee without a signature
    "0x00245b00_x64_chkstk": ("equivalent", None, None, 50),
    # (x64t13) an integer field annotated HULK_RANGE(0, 1) (records.h CoreCementLibrary::bucket, the list index) is
    # drawn from its range: the library list's unlink is equivalent with most inputs used
    "0x002775b0_x64_bucket_range": ("equivalent", None, None, 40),
    # (x64t13) a pointer parameter annotated HULK_INTO(base) points into the array this->base points to (the pool's
    # free: the block index is `value - base`); without the annotation the parameter is an unrelated object
    "0x0008ff00_x64_into_pool": ("equivalent", None, None, 40),
    "0x0008ff00_x64_into_none": ("fail", "layout", "].limit", 0),
    # (integ2, D93, fieldcasts; rev5's review) a pointer field read through the record the code casts it to:
    # _downcast: a complete record derived from the declared pointee, taken outright (equivalent); _view: an incomplete
    # pointee, the view taken on trust (unsupported view_trusted: no clean equivalent; rev5's _wrongview shows any view
    # passes there); _declwins: a complete declared type that lays out the read words wins over a wrong view (fails);
    # _realstraddle (rev5): a view word past the declared end on one target only (unsupported view_straddle)
    # (rev5's re-review, F4/F5) _gendowncast: a downcast to a gen record (RTTI evidence) is taken outright; _downcast and
    # rev5's _wrongderived / _placeholderderived: a locally declared derived record is a view taken on trust;
    # _ambiguous (0x0019e910's shape): a field cast to two records keeps its declared type, the run is view_ambiguous
    "0x000ac780_x64_fieldcast_gendowncast": ("equivalent", None, None, 50),
    "0x000ac780_x64_fieldcast_downcast": ("unsupported", "view_trusted", None, 0),
    "0x000ac780_x64_fieldcast_wrongderived": ("unsupported", "view_trusted", None, 0),
    "0x000ac780_x64_fieldcast_placeholderderived": ("unsupported", "view_trusted", None, 0),
    "0x000ac780_x64_fieldcast_ambiguous": ("unsupported", "view_ambiguous", None, 0),
    "0x000ac780_x64_fieldcast_view": ("unsupported", "view_trusted", None, 0),
    "0x000ac780_x64_fieldcast_wrongview": ("unsupported", "view_trusted", None, 0),
    "0x000ac780_x64_fieldcast_declwins": ("fail", None, None, 0),
    "0x000ac780_x64_fieldcast_realstraddle": ("unsupported", "view_straddle", None, 0),
    # (integ2, D102) a heap-id parameter annotated HULK_RANGE(0, 45) (DAT_00527c60's 46 slots, cited): drawn in range, no
    # 64-bit crash (the object it reaches is a view over a void* allocator: view_trusted); _uncited: refused
    "0x00266f20_x64_paramrange": ("unsupported", "view_trusted", None, 0),
    "0x00266f20_x64_paramrange_uncited": ("unsupported", "tool", "citing its evidence", 0),
    # (rev5's review) a range past the cited table (DAT_00527c60[46]: HULK_RANGE(0, 46)) is refused
    "0x00266f20_x64_paramrange_pasttable": ("unsupported", "tool", "reaches past the cited table", 0),
    # (rev5's spot-check) the table left out of the comment: the body's subscript DAT_00527c60[index] bounds it anyway
    "0x00266f20_x64_paramrange_nocitetable": ("unsupported", "tool", "which the body indexes with it", 0),
    # (rev5's design) every use of the annotated parameter must be a constant-array subscript's whole index, a whole call
    # argument or a comparison / switch operand: a copy, index + 1, index * 2, pointer arithmetic, &T[0] + index and a
    # pointer local are refused ("can't be derived from its uses")
    "0x00266f20_x64_paramrange_local": ("unsupported", "tool", "can't be derived from its uses", 0),
    "0x00266f20_x64_paramrange_plus1": ("unsupported", "tool", "can't be derived from its uses", 0),
    "0x00266f20_x64_paramrange_times2": ("unsupported", "tool", "can't be derived from its uses", 0),
    "0x00266f20_x64_paramrange_ptradd": ("unsupported", "tool", "can't be derived from its uses", 0),
    "0x00266f20_x64_paramrange_addr0": ("unsupported", "tool", "can't be derived from its uses", 0),
    "0x00266f20_x64_paramrange_ptrlocal": ("unsupported", "tool", "can't be derived from its uses", 0),
    # (rev5's d102d) a constructor's member initializer is a use too (index + 1 there); a whole argument bound to a
    # non-const reference (rev5_bump(int&)) can change it: both refused
    "0x000ac780_x64_paramrange_ctorinit": ("unsupported", "tool", "can't be derived from its uses", 0,
                                           {"symbol": "??0Holder_ac780@@QAE@H@Z"}),
    "0x000ac780_x64_paramrange_refarg": ("unsupported", "tool", "can't be derived from its uses", 0),
    # (rev5's d102d) a member operator call counts the object as argument 0: matched to the right parameter, the
    # non-const reference refuses it (opcall2: `operator()(int& x, int y)` with `b(index, 0)`; opcall3: the other way)
    "0x000ac780_x64_paramrange_opcall2": ("unsupported", "tool", "CALL_EXPR", 0),
    "0x000ac780_x64_paramrange_opcall3": ("unsupported", "tool", "CALL_EXPR", 0),
    # (rev5, D61 review) HULK_RANGE whose declaration names no 0x address: unsupported (rangecheck), not drawn from the range
    "0x002775b0_x64_bucket_range_nocite": ("unsupported", None, "writer sites", 0),
    # (integ2, D103) data annotations on a global's declaration. HULK_RANGE on the Perlin permutation table (cited writer
    # 0x003572b0): its words drawn 0..255, equivalent; _none: the control crashes on 64-bit (seed 123); _uncited,
    # _both (HULK_RANGE and HULK_RDATA on one global), _float (a float table), _rdata (HULK_RDATA on a writable
    # .data table) refused; _wide (0..0x7fffffff): no input completes, the annotation is no bypass
    "0x00356fa0_x64_grange": ("equivalent", None, None, 100),
    "0x00356fa0_x64_grange_none": ("fail", "crash64", "not an address", 0, {"seeds": [123]}),
    "0x00356fa0_x64_grange_uncited": ("unsupported", "tool", "citing the writer sites", 0),
    "0x00356fa0_x64_grange_both": ("unsupported", "tool", "different data annotations", 0),
    "0x00356fa0_x64_grange_float": ("unsupported", "tool", "not an integer", 0),
    "0x00356fa0_x64_grange_rdata": ("unsupported", "tool", "read-only data section", 0),
    "0x00356fa0_x64_grange_wide": ("unsupported", "tool", "no input completed", 0),
    # (D103 census, rev5's R3: mandatory) the citation must name every XBE function referencing the table: the writer
    # alone is refused; _c30: a site in no listed function (0x00356de0's loads) needs its own address, not an earlier
    # listed function's (R3a); _below (0x001fe380's table, its reader cited): code words within 0x40 below the table
    # (R3b). R1: _initial, the XBE's initial words outside the range. R2: _rdata_vtable ([8] reaching into the vftable
    # at 0x00425270: no data.json item of that size), _rdata_text (code bytes: no read-only data section)
    "0x00356fa0_x64_grange_census": ("unsupported", "tool", "doesn't cite the XBE's references", 0),
    "0x00356fa0_x64_grange_c30": ("unsupported", "tool", "in no listed function", 0),
    "0x001fe380_x64_grange_below": ("unsupported", "tool", "0x001fdd9c (in 0x001fdc90)", 0),
    "0x001fe380_x64_grange_initial": ("unsupported", "tool", "initial word at +0x8 is 4", 0),
    "0x001fe380_x64_rdata_vtable": ("unsupported", "tool", "no item of 32 bytes", 0),
    "0x001fe380_x64_rdata_text": ("unsupported", "tool", "not file data of a read-only data section", 0),
    # (rev5's R7) an "int" table whose words are image addresses (0x0040cc74): pointers natively, refused
    "0x001fe380_x64_rdata_addrs": ("unsupported", "tool", "an address in the XBE's", 0),
    # (integ2, D107) an allocation of count * sizeof(T) whose 64-bit request outgrows the region the 32-bit request
    # reserved gets its own 64-bit region (no false `layout` on the object after it); a hard-coded 16-byte element size
    # is a real 64-bit overrun and still fails
    "0x002a4cb0_x64_regrow": ("equivalent", None, None, 50),
    "0x002a4cb0_x64_regrow_16": ("fail", "layout", "64-bit write past the end of alloc#", 0),
    # (integ2, D111) an untyped pointer-word global (`void* DAT[1]`) read through `*(T**)&DAT` is generated as a T*: a
    # class of include/gen outright (equivalent), a local stand-in as a view taken on trust (view_trusted); cast two ways
    # it stays untyped (fails here); a larger untyped array is out of scope (stays raw: no input completes)
    "0x001bc0c0_x64_gcast": ("equivalent", None, None, 50),
    "0x001bc0c0_x64_gcast_local": ("unsupported", "view_trusted", "global _DAT_0052c2a4 as Agent_lc", 0),
    "0x001bc0c0_x64_gcast_ambiguous": ("fail", None, None, 0),
    "0x001bc0c0_x64_gcast_array": ("unsupported", "tool", "no input completed", 0),
    # (rev5's review) two casts whose reads don't differ (null checks): view_ambiguous by the rule; a cast of the
    # word's value ((U*)DAT[0]) counts toward ambiguity too
    "0x001bc0c0_x64_gcast_amb2": ("unsupported", "view_ambiguous", None, 0),
    "0x001bc0c0_x64_gcast_valuecast": ("unsupported", "view_ambiguous", None, 0),
    # (integ2, D107 follow-up; rev5's probes) an allocator's size read at its declared width (a pointer-width
    # parameter's upper half counts) and the 64-bit request bounded: past ALLOC_MAX or far above the 32-bit one, layout
    "0x002a4cb0_x64_alloc_wide": ("fail", "layout", "allocation of 0xffff00000070 bytes", 0),
    "0x002a4cb0_x64_alloc_big": ("fail", "layout", "allocation of 0x7ffffff0 bytes", 0),
    # HULK_RDATA on 0x001fe380's const .rdata table {2, 3, 4, 5}: both runs start from the XBE's bytes, equivalent;
    # _none: the control (fuzzed words index lists[] past its end) is inconclusive; refused: a declaration not const, a
    # store into the table, a pointer table, a table in a writable section, an annotation on one parse only
    "0x001fe380_x64_rdata": ("equivalent", None, None, 20),
    "0x001fe380_x64_rdata_none": ("inconclusive", None, None, 0),
    "0x001fe380_x64_rdata_nonconst": ("unsupported", "tool", "not declared const", 0),
    "0x001fe380_x64_rdata_store": ("unsupported", "tool", "stored into DAT_00425260", 0),
    "0x001fe380_x64_rdata_ptrs": ("unsupported", "tool", "size differs between the targets", 0),
    "0x001fe380_x64_rdata_writable": ("unsupported", "tool", "read-only data section", 0),
    "0x001fe380_x64_rdata_oneside": ("unsupported", "tool", "parses disagree", 0),
}

# cases that must also complete this many inputs (the promotion bar is 50)
MIN_RUN = {"0x0028c2a0_rep_count": 50, "0x000e36c0_small_counts": 50, "0x002155f0_diff_bound": 50,
           "0x0024a800_walk_end": 50, "0x001fe380_tiny_counts": 50, "0x002a4e40_static_count": 50,
           "0x00242da0_nil_addr_walk": 50, "0x002165c0_xlocal_ptr": 50,
           "0x0021a3e0_proofcap": 3000, "0x0024a280_native_proofwalk": 3000}    # (integ1, D62) 442 before: the 32-inconclusive stop ended the proof run at 535 drawn


def x64_job(name):
    """(eq64) one X64_CASES case: (ok, status, class, difference or error)."""
    import equiv64
    want, cls, text, min_done = X64_CASES[name][:4]
    kw = X64_CASES[name][4] if len(X64_CASES[name]) > 4 else {}     # (integ2) e.g. {"symbol": "??0C@@QAE@H@Z"}
    r = equiv64.verify64(os.path.join(CASES_DIR, name + ".cpp"), int(name.split("_")[0], 16), n_inputs=100, **kw)
    got = r.get("diff") or r.get("error") or ""
    ok = r["status"] == want and (cls is None or r.get("class") == cls) and (text is None or text in got) and \
        r.get("completed", 0) >= min_done
    return ok, r["status"], r.get("class"), got


def decl_job(name, equiv=None):
    """(round 23) one DECL_CASES case: (ok, status, the reported {(kind, callee)})."""
    equiv = equiv or __import__(os.environ.get("EQUIV_MODULE", "equiv"))
    want, kw = DECL_CASES[name]
    kw = dict(kw)
    off = [x for x in kw.pop("equiv_off", "").split(",") if x]
    strict = kw.pop("strict", False)
    src = kw.pop("src", None) or name
    equiv.EQUIV_OFF.update(off)
    old = equiv.STRICT_DECL
    equiv.STRICT_DECL = strict
    try:
        r = equiv.verify(os.path.join(CASES_DIR, src + ".cpp"), int(name.split("_")[0], 16), max_level=2, **kw)
    finally:
        equiv.EQUIV_OFF.difference_update(off)
        equiv.STRICT_DECL = old
    got = {(d["kind"], d["callee"]) for d in r.get("decl_arity") or []}
    ok = got == want and (r["status"] == "fail") == bool(strict and want) and r["status"] in ("draft", "fail")
    return ok, r["status"], got


def job(name):
    equiv = __import__(os.environ.get("EQUIV_MODULE", "equiv"))
    addr = int(name.split("_")[0], 16)
    kw = dict(CASES[name][3]) if len(CASES[name]) > 3 else {}
    # (round 17) `equiv_off`: switches this case runs with (a source kept for what it tests that also trips a stricter
    # rule: exact floats, ftolexact, or a free-function declaration of a thiscall callee, thisdecl)
    off = [x for x in kw.pop("equiv_off", "").split(",") if x]
    equiv.EQUIV_OFF.update(off)
    # (integ1) `equiv_on`: rules written but not adopted (equiv.EQUIV_ON), for their cases
    on = [x for x in kw.pop("equiv_on", "").split(",") if x]
    on_set = getattr(equiv, "EQUIV_ON", set())
    on_set.update(on)
    # (perf1) `float`: the Wine build's float code this case checks (native cases; default the build's, SSE): a case about an
    # x87-only artefact pins x87
    fl, was = kw.pop("float", None), os.environ.get("HULK_WINE_FLOAT")
    if fl:
        os.environ["HULK_WINE_FLOAT"] = fl
    try:
        return _job(name, equiv, addr, kw)
    finally:
        equiv.EQUIV_OFF.difference_update(off)
        on_set.difference_update(on)
        if fl:
            if was is None:
                os.environ.pop("HULK_WINE_FLOAT", None)
            else:
                os.environ["HULK_WINE_FLOAT"] = was


def _job(name, equiv, addr, kw):
    src = kw.pop("src", None)        # (round 19) the case file when it is another case's source (`_off` variants)
    tree = os.path.join(CASES_DIR, name + ".tree.cpp")
    if os.path.exists(tree):
        # NAME.tree.cpp: the same source wrapped in `namespace fn_<addr>` as tools/build_tree.py merges it; its
        # object is checked with the unwrapped source's equiv-map / equiv-conv lines and sizeof probes
        import tempfile
        with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as d:
            obj = equiv.compile_obj(tree, equiv.DEFAULT_FLAGS, d)
            r = equiv.verify(os.path.join(CASES_DIR, name + ".cpp"), addr, obj_path=obj, **kw)
    else:
        r = equiv.verify(os.path.join(CASES_DIR, (src or name) + ".cpp"), addr, **kw)
    diffs = [d for m in (r.get("level3") or {}).get("mismatches", []) for d in m["diffs"]]
    # (level-2 issues too, as "L2 kind symbol": round 13's float constants fail there)
    diffs += ["L2 %s %s" % (i.get("kind"), i.get("symbol") or i.get("target") or "")
              for i in (r.get("level2") or {}).get("issues", [])]
    cov = (r.get("level3") or {}).get("coverage") or {}
    ratio = cov["edges_covered"] / cov["edges_total"] if cov.get("edges_total") else 1.0
    return name, r["status"], diffs, ratio, (r.get("level3") or {}).get("inputs_run") or 0


def run_jobq(a, names):
    """Shard the cases over the job queue; print the same lines as a local run and the total."""
    import jobq
    per = a.per
    commit = jobq.head_commit()
    files = jobq.collect_files([], True)
    if any(n in X64_CASES for n in names):
        import equiv64
        files.update(equiv64.job_files())     # (libclang's Python binding, for hosts whose venv lacks it)
    jobs = [jobq.make_job(a.name, ["python", "tests/equiv/regress.py", "--names", ",".join(names[i:i + per]), "--jobs", "2"] +
                          (["--module", a.module] if a.module else []),
                          "equiv", files, [], 3600, 2, 3, 0, commit) for i in range(0, len(names), per)]
    ids = jobq.submit_jobs(jobs)
    print("%d cases in %d jobs (%d-%d)" % (len(names), len(ids), ids[0], ids[-1]), flush=True)
    c = jobq.conn()
    pending, bad, total = dict(zip(ids, [names[i:i + per] for i in range(0, len(names), per)])), 0, 0
    while pending:
        for r in c.execute("SELECT id,state,host,reason FROM jobs WHERE id IN (%s)" % ",".join(map(str, pending))).fetchall():
            if r["state"] not in jobq.TERMINAL:
                continue
            ch = pending.pop(r["id"])
            lp = os.path.join(jobq.OUT, str(r["id"]), "log")
            lines = [l for l in open(lp, errors="replace").read().splitlines()] if os.path.exists(lp) else []
            seen = 0
            for l in lines:
                if l.startswith("ok ") or l.startswith("FAIL"):
                    print("%s  [%s]" % (l, r["host"]), flush=True)
                    seen += 1
                    bad += l.startswith("FAIL")
                elif l.startswith("skip:"):
                    print(l)
            if seen < len(ch):
                bad += len(ch) - seen
                print("FAIL job %d (%s): %d of %d cases reported (%s)" % (r["id"], r["state"], seen, len(ch), r["reason"]))
            total += len(ch)
        if pending:
            time.sleep(1)
    print("%d/%d cases ok" % (total - bad, total))
    return 1 if bad else 0


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--jobs", type=int, default=4)
    p.add_argument("--only")
    p.add_argument("--names", help="comma-separated exact case names")
    p.add_argument("--jobq", action="store_true", help="run the cases through tools/jobq.py")
    p.add_argument("--name", default=os.environ.get("USER", "agent"), help="submitter name for --jobq")
    p.add_argument("--per", type=int, default=6, help="cases per job for --jobq")
    p.add_argument("--module", help="checker module to import instead of equiv (tools/NAME.py; a development copy)")
    a = p.parse_args()
    if a.module:
        os.environ["EQUIV_MODULE"] = a.module
    sel = set(a.names.split(",")) if a.names else None
    if a.jobq:
        return run_jobq(a, [n for n in list(CASES) + list(RELOC_CASES) + list(DECL_CASES) + list(X64_CASES)
                            if (not a.only or a.only in n) and (not sel or n in sel)])
    if not os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe")):
        print("skip: no isos/extracted/default.xbe")
        return 0
    names = [n for n in CASES if (not a.only or a.only in n) and (not sel or n in sel)]
    bad = 0
    with Pool(a.jobs) as pool:
        for name, status, diffs, ratio, nrun in pool.imap_unordered(job, names):
            want, text = CASES[name][:2]
            min_cov = CASES[name][2] if len(CASES[name]) > 2 else 0
            ok = status == want and (text is None or any(text in d for d in diffs)) and ratio >= min_cov and \
                nrun >= MIN_RUN.get(name, 0)
            bad += not ok
            print("%-4s %-32s %-12s %3.0f%% %s" % ("ok" if ok else "FAIL", name, status, 100 * ratio,
                                                 "" if ok else (diffs[:2] or "")))
    import verify_relocs
    for name in [n for n in RELOC_CASES if (not a.only or a.only in n) and (not sel or n in sel)]:
        want, kind = RELOC_CASES[name]
        r = verify_relocs.check(os.path.join(CASES_DIR, name + ".cpp"), int(name.split("_")[0], 16))
        ok = r["status"] == want and (kind is None or any(i[0] == kind for i in r["issues"]))
        bad += not ok
        names.append(name)
        print("%-4s %-32s %-12s %s" % ("ok" if ok else "FAIL", name, r["status"], "" if ok else r.get("issues")))
    for name in [n for n in DECL_CASES if (not a.only or a.only in n) and (not sel or n in sel)]:
        ok, status, got = decl_job(name)
        bad += not ok
        names.append(name)
        print("%-4s %-32s %-12s %s" % ("ok" if ok else "FAIL", name, status, "" if ok else sorted(got)))
    for name in [n for n in X64_CASES if (not a.only or a.only in n) and (not sel or n in sel)]:
        ok, status, cls, got = x64_job(name)
        bad += not ok
        names.append(name)
        print("%-4s %-32s %-12s %s" % ("ok" if ok else "FAIL", name, status, "" if ok else "%s: %s" % (cls, got[:300])))
    print("%d/%d cases ok" % (len(names) - bad, len(names)))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
