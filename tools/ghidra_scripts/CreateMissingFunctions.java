// Create functions Ghidra's analysis missed: code reached only through pointers it never resolved
// (vtables, callback tables, element constructors passed to vector helpers).
// Reads candidate entry points (one hex address per line), creates a function at each one that
// disassembles and is not inside an existing function, and writes the new functions as CSV rows in
// the ExportFunctions format, so they can be appended to build/functions.csv without re-exporting
// (and losing the hand-patched sizes in) the existing rows.
// Run: analyzeHeadless build/ghidra hulk -process default.xbe -noanalysis \
//        -scriptPath tools/ghidra_scripts -postScript CreateMissingFunctions.java CANDIDATES OUT.csv
//@category Hulk

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class CreateMissingFunctions extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String in = getScriptArgs()[0];
        String out = getScriptArgs()[1];
        int created = 0, skipped = 0;
        try (BufferedReader r = new BufferedReader(new FileReader(in)); PrintWriter w = new PrintWriter(out)) {
            String line;
            while ((line = r.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;
                Address a = toAddr(Long.parseLong(line.replace("0x", ""), 16));
                if (getFunctionContaining(a) != null) { skipped++; continue; }
                if (getInstructionAt(a) == null) {
                    DisassembleCommand dis = new DisassembleCommand(a, null, true);
                    dis.applyTo(currentProgram, monitor);
                }
                if (getInstructionAt(a) == null) { skipped++; continue; }
                CreateFunctionCmd cmd = new CreateFunctionCmd(a);
                if (!cmd.applyTo(currentProgram, monitor)) { skipped++; continue; }
                Function f = getFunctionAt(a);
                if (f == null) { skipped++; continue; }
                created++;
                int calls = f.getCalledFunctions(monitor).size();
                int xrefs = getReferencesTo(f.getEntryPoint()).length;
                long size = f.getBody().getMaxAddress().subtract(f.getEntryPoint()) + 1;
                int chunks = f.getBody().getNumAddressRanges();
                w.printf("0x%08x,%d,\"%s\",%d,%d,%d,%d%n", f.getEntryPoint().getOffset(), size,
                    f.getName(true).replace("\"", "\"\""), calls, xrefs, f.isThunk() ? 1 : 0, chunks);
            }
        }
        println("created " + created + ", skipped " + skipped + " -> " + out);
    }
}
