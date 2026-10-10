// Export every function's body ranges and every reference made from inside it, for
// tools/platform_map.py (platform-boundary and subsystem analysis). Read-only.
//
// Output (tab-separated, one record per line):
//   F  <entry>  <name>  <start-end,start-end,...>
//   R  <entry>  <insn>  <target>  <reftype>   (flow refs that leave the body, and all data refs)
//   C  <entry>  <insn>  <mnemonic + operands>  (indirect calls/jumps with no resolved target)
//
// Run: analyzeHeadless build/ghidra hulk -process default.xbe -noanalysis -readOnly \
//        -scriptPath tools/ghidra_scripts -postScript ExportRefs.java build/port/refs.tsv
//@category Hulk

import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.RefType;
import ghidra.program.model.symbol.Reference;

public class ExportRefs extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "build/port/refs.tsv";
        new java.io.File(out).getAbsoluteFile().getParentFile().mkdirs();
        int nf = 0, nr = 0;
        try (PrintWriter w = new PrintWriter(out)) {
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (monitor.isCancelled()) break;
                AddressSetView body = f.getBody();
                long entry = f.getEntryPoint().getOffset();
                StringBuilder rs = new StringBuilder();
                for (AddressRange r : body) {
                    if (rs.length() > 0) rs.append(',');
                    rs.append(String.format("%x-%x", r.getMinAddress().getOffset(), r.getMaxAddress().getOffset()));
                }
                w.printf("F\t%x\t%s\t%s%n", entry, f.getName(true), rs);
                nf++;
                InstructionIterator it = currentProgram.getListing().getInstructions(body, true);
                while (it.hasNext()) {
                    Instruction insn = it.next();
                    boolean resolved = false;
                    for (Reference ref : insn.getReferencesFrom()) {
                        if (!ref.getToAddress().isMemoryAddress()) continue;
                        RefType t = ref.getReferenceType();
                        if (t.isFlow() && body.contains(ref.getToAddress())) continue;
                        if (t.isFlow()) resolved = true;
                        w.printf("R\t%x\t%x\t%x\t%s%n", entry, insn.getAddress().getOffset(),
                            ref.getToAddress().getOffset(), t.getName());
                        nr++;
                    }
                    var ft = insn.getFlowType();
                    if ((ft.isCall() || ft.isJump()) && ft.isComputed() && !resolved) {
                        w.printf("C\t%x\t%x\t%s%n", entry, insn.getAddress().getOffset(), insn.toString());
                    }
                }
            }
        }
        println("wrote " + out + ": " + nf + " functions, " + nr + " refs");
    }
}
