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
    "0x0010b5b0_flag_via": ("equivalent", None, 0.9, {"n_inputs": 3000}),
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
    # the point of native mode: MSVC 7.1 drops an explicit `(float)` cast of an x87 register value (`x = (float)x * 3.0f`),
    # clang rounds. The same source is EQUIVALENT in MSVC mode (3000 inputs earlier) and fails natively by 1 ulp
    "0x0033ed90_msvc_cast": ("equivalent", None, 0.9, {"n_inputs": 100}),
    "0x0033ed90_native_cast": ("fail", "write to arg2", 0, {"native": True, "n_inputs": 100}),
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
    "0x000354c0_native_tail_fret_off": ("fail", "x87 stack depth", 0, {"src": "0x000354c0_native_tail_fret", "native": True, "n_inputs": 60, "equiv_off": "tailfret"}),
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
    "0x0008e880_native_xlocal_elem0": ("fail", "unexpected write to 0xbe7ef6d4", 0, {"native": True, "n_inputs": 60}),
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
    "0x000375a0_native_retwidth_off": ("fail", "returned 0x", 0, {"src": "0x000375a0_native_retwidth", "native": True, "n_inputs": 60, "equiv_off": "retwidth"}),
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
    "0x000f1ab0_native_crtarity_off": ("fail", "argument 1", 0, {"src": "0x000f1ab0_native_crtarity", "native": True, "n_inputs": 60, "equiv_off": "crtarity,vsplit"}),
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
    "0x0035d200_native_noeaxret_off": ("fail", "return type unknown", 0, {"src": "0x0035d200_native_noeaxret", "native": True, "n_inputs": 60, "equiv_off": "noeaxret"}),
    "0x0035d200_native_noeaxret_wrong": ("fail", "write to", 0, {"native": True, "n_inputs": 60}),
    # fyl2x: Unicorn leaves the x87 stack alone for `fyl2x` of a negative operand (log of a fuzzed negative float)
    "0x0033b8d0_native_fyl2x": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x0033b8d0_native_fyl2x_off": ("fail", "x87 stack depth", 0, {"src": "0x0033b8d0_native_fyl2x", "native": True, "n_inputs": 60, "equiv_off": "fyl2x"}),
    "0x0033b8d0_native_fyl2x_wrong": ("fail", "argument 2", 0, {"native": True, "n_inputs": 60}),
    # nofill: FUN_002f0080 only reads the vectors it gets: no speculative out-parameter fill
    "0x002f0780_native_nofill": ("equivalent", None, 0, {"native": True, "n_inputs": 60}),
    "0x002f0780_native_nofill_off": ("fail", "local passed as argument 1", 0, {"src": "0x002f0780_native_nofill", "native": True, "n_inputs": 60, "equiv_off": "nofill"}),
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

# cases that must also complete this many inputs (the promotion bar is 50)
MIN_RUN = {"0x0028c2a0_rep_count": 50, "0x000e36c0_small_counts": 50, "0x002155f0_diff_bound": 50,
           "0x0024a800_walk_end": 50, "0x001fe380_tiny_counts": 50, "0x002a4e40_static_count": 50,
           "0x00242da0_nil_addr_walk": 50, "0x002165c0_xlocal_ptr": 50}


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
    # (perf1) `float`: the Wine build's float code this case checks (native cases; default the build's, SSE): a case about an
    # x87-only artefact pins x87
    fl, was = kw.pop("float", None), os.environ.get("HULK_WINE_FLOAT")
    if fl:
        os.environ["HULK_WINE_FLOAT"] = fl
    try:
        return _job(name, equiv, addr, kw)
    finally:
        equiv.EQUIV_OFF.difference_update(off)
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
        return run_jobq(a, [n for n in list(CASES) + list(RELOC_CASES) + list(DECL_CASES) if (not a.only or a.only in n) and (not sel or n in sel)])
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
    print("%d/%d cases ok" % (len(names) - bad, len(names)))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
