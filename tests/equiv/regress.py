#!/usr/bin/env python3
"""Regression cases for tools/equiv.py: sources that a checker bug once got wrong.

  build/venv/bin/python tests/equiv/regress.py [--jobs 4] [--only NAME]

Each case is a source in tests/equiv/cases/ (named 0xADDR_what.cpp) with the status it must get, a
piece of the mismatch text that shows the right thing was caught, and for some a minimum branch coverage.
Skips when the game files are absent.
"""
import argparse
import os
import sys
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
    # a stdcall import (NtClose) after a self-recursive call: the import's pop isn't guessed from later code
    "0x00212641_import_pop": ("equivalent", None),
    # string compares against .rdata literals: directed inputs plant the literal in the compared buffer
    # (`repe cmpsb` against "jp"-style literals; CRT strncmp called with a literal; a chain of
    # strcmp/strncmp where the second compare is only reached once the first matches)
    "0x00206320_repe_cmpsb_literal": ("equivalent", None, 0.95),
    "0x000c1790_strncmp_literal": ("equivalent", None, 0.9),
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
    "0x000991b0_chained_vcalls": ("equivalent", None),
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
    "0x00295270_x87_live_across_call": ("equivalent", None, 0.9),
    # loop repair takes the outer loop's patchable back edge (or a top-tested loop's exit), not the hottest
    # back edge (an inner loop over a constant bound, `cmp edx, 8; jb`)
    # (random input 164 fails, as under the round-5 checker: an aliasing-dependent write to arg2+0x18)
    "0x002cb2b0_loop_exit_order": ("equivalent", None, 0.75, {"n_inputs": 3000, "seeds": list(range(160))}),
    # a float result returned untouched across the /GS cookie check (ours spills it around the call)
    "0x000dfbf0_float_ret_cookie": ("equivalent", None),
    # `rep stosd` over a fuzzed count read from memory: repaired like a loop bound, so 50 inputs complete
    "0x0028c2a0_rep_count": ("equivalent", None, 0, {"n_inputs": 3000}),
    # `~VectorChannel` ends in `jmp ~SimpleChannel` (the original inlined it): the target symbol is picked with
    # the tail-jumped function's bytes appended, and the jump runs in place with its prologue's push known
    "0x0028bcd0_tail_jmp_local": ("equivalent", None, 0.75),
    # a plane count read from this+0x634 times out on fuzzed values: repaired inputs no longer count toward
    # the 32-inconclusive cap of the random phase
    "0x0003c1d0_count_cap": ("equivalent", None, 0.75, {"n_inputs": 3000}),
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
}

# cases that must also complete this many inputs (the promotion bar is 50)
MIN_RUN = {"0x0028c2a0_rep_count": 50}


def job(name):
    equiv = __import__(os.environ.get("EQUIV_MODULE", "equiv"))
    addr = int(name.split("_")[0], 16)
    kw = CASES[name][3] if len(CASES[name]) > 3 else {}
    tree = os.path.join(CASES_DIR, name + ".tree.cpp")
    if os.path.exists(tree):
        # NAME.tree.cpp: the same source wrapped in `namespace fn_<addr>` as tools/build_tree.py merges it; its
        # object is checked with the unwrapped source's equiv-map / equiv-conv lines and sizeof probes
        import tempfile
        with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as d:
            obj = equiv.compile_obj(tree, equiv.DEFAULT_FLAGS, d)
            r = equiv.verify(os.path.join(CASES_DIR, name + ".cpp"), addr, obj_path=obj, **kw)
    else:
        r = equiv.verify(os.path.join(CASES_DIR, name + ".cpp"), addr, **kw)
    diffs = [d for m in (r.get("level3") or {}).get("mismatches", []) for d in m["diffs"]]
    cov = (r.get("level3") or {}).get("coverage") or {}
    ratio = cov["edges_covered"] / cov["edges_total"] if cov.get("edges_total") else 1.0
    return name, r["status"], diffs, ratio, (r.get("level3") or {}).get("inputs_run") or 0


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--jobs", type=int, default=4)
    p.add_argument("--only")
    a = p.parse_args()
    if not os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe")):
        print("skip: no isos/extracted/default.xbe")
        return 0
    names = [n for n in CASES if not a.only or a.only in n]
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
    print("%d/%d cases ok" % (len(names) - bad, len(names)))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
