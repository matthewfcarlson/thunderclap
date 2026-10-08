// Decompile a list of functions (one hex address per line) into <outdir>/<addr>.c.
// Run: analyzeHeadless build/ghidra hulk -process default.xbe -noanalysis -readOnly \
//        -scriptPath tools/ghidra_scripts -postScript ExportDecomp.java build/farm/queue.txt build/farm/ghidra_c
//@category Hulk

import java.io.File;
import java.io.PrintWriter;
import java.nio.file.Files;

import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

public class ExportDecomp extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        File outDir = new File(args[1]);
        outDir.mkdirs();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        int done = 0, failed = 0;
        for (String line : Files.readAllLines(new File(args[0]).toPath())) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String addr = line.split("[\\s,]")[0];
            File out = new File(outDir, addr + ".c");
            if (out.exists()) continue;
            monitor.checkCancelled();
            Function f = getFunctionAt(toAddr(addr));
            if (f == null) { failed++; continue; }
            DecompileResults r = di.decompileFunction(f, 30, monitor);
            if (r.getDecompiledFunction() == null) { failed++; continue; }
            try (PrintWriter w = new PrintWriter(out)) {
                w.print(r.getDecompiledFunction().getC());
            }
            done++;
        }
        di.dispose();
        println(String.format("ExportDecomp: wrote=%d failed=%d", done, failed));
    }
}
