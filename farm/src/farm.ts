// Durable matching farm: runs many cheap-model conversations in parallel, one per (function, tier),
// on pi-durable over SQLite. Each worker only has submit_cpp, which compiles and diffs a candidate.
//
// Usage (from repo root): farm/run.sh [--limit N] [--concurrency C] [--queue FILE] [--tiers FILE] [--only 0xADDR,...]

import { execFile } from "node:child_process";
import { appendFileSync, copyFileSync, existsSync, mkdirSync, readdirSync, readFileSync, writeFileSync } from "node:fs";
import { join } from "node:path";
import { promisify } from "node:util";
import { parseArgs } from "node:util";

import { BACKGROUND_CONTEXT } from "@earendil-works/chord/context";
import { Type } from "@earendil-works/pi-ai";
import { createProvider } from "@earendil-works/pi-ai";
import { openAICompletionsApi } from "@earendil-works/pi-ai/api/openai-completions.lazy";
import { createModels } from "@earendil-works/pi-ai/models";
import { openrouterProvider } from "@earendil-works/pi-ai/providers/openrouter";
import {
	createRegistry,
	defineDoc,
	defineExtension,
	defineTool,
	GenerationTask,
	Harness,
	hook,
	section,
	UsageDoc,
} from "@earendil-works/pi-durable";
import { openNodeSqliteStorage } from "@earendil-works/pi-durable/storage/sqlite/node";

import { SYSTEM_PROMPT, taskPrompt } from "./prompt.ts";

const run = promisify(execFile);
const ROOT = new URL("../..", import.meta.url).pathname;
const BUILD = join(ROOT, "build/farm");
const PY = join(ROOT, "build/venv/bin/python");
const ctx = BACKGROUND_CONTEXT;
let MATCHES_DIR = join(ROOT, "matches");
let WORK_TAG = "main";

type Tier = { model: string; thinking?: "off" | "minimal" | "low" | "medium" | "high"; maxAttempts: number };

// Per-conversation job state, committed with the transcript.
type JobState = {
	addr: string;
	tier: number;
	attempts: number;
	maxAttempts: number;
	status: string; // running | match | exhausted
	bestScore: number;
	bestCode: string;
	bestReport: string;
};
const Job = defineDoc<JobState>({
	kind: "hulk.job",
	version: 1,
	scope: "conversation",
	history: "latest",
	fork: "initial",
	initial: () => ({ addr: "", tier: 0, attempts: 0, maxAttempts: 0, status: "running", bestScore: -1, bestCode: "", bestReport: "" }),
});
// Session index: "addr:tier" -> conversation id, so a restart reattaches instead of starting over.
const Index = defineDoc<{ jobs: Record<string, string> }>({
	kind: "hulk.index",
	version: 1,
	scope: "session",
	initial: () => ({ jobs: {} }),
});

async function compare(src: string, addr: string): Promise<{ status: string; score?: number; report: string }> {
	try {
		const { stdout } = await run(PY, [join(ROOT, "tools/compare.py"), src, addr, "--json"], { timeout: 120_000 });
		return JSON.parse(stdout);
	} catch (e: any) {
		// compare.py exits 1 on a non-match but still prints JSON.
		if (e.stdout) return JSON.parse(e.stdout);
		return { status: "tool_error", report: String(e.message).slice(0, 500) };
	}
}

// Matches must come from real C++; inline asm or emitted bytes would "match" trivially.
const FORBIDDEN = /\b(__asm|_asm|asm|_emit|__emit)\b|naked|#\s*pragma/;

const submitCpp = defineTool({
	name: "submit_cpp",
	description: "Compile a complete C++ translation unit with MSVC 7.1 and diff the best-matching function against the target.",
	parameters: Type.Object({ code: Type.String({ description: "Complete .cpp source" }) }),
	replay: "safe",
	executionMode: "sequential",
	execute: async (args, api, context) => {
		const job = (await api.snapshot(Job, api.conversationId, context))!;
		if (FORBIDDEN.test(args.code)) {
			return { content: [{ type: "text", text: "Rejected: inline assembly, _emit, naked functions and #pragma are not allowed. Write plain C++." }], isError: true };
		}
		const n = job.attempts + 1;
		const dir = join(BUILD, "work", WORK_TAG, job.addr);
		mkdirSync(dir, { recursive: true });
		const src = join(dir, `t${job.tier}_a${n}.cpp`);
		writeFileSync(src, args.code);
		const r = await compare(src, job.addr);
		const score = r.status === "match" ? 1 : (r.score ?? 0);
		const matched = r.status === "match";
		const left = job.maxAttempts - n;
		await api.commit(async (tx) => {
			const j = await tx.doc(Job, api.conversationId);
			j.attempts = n;
			if (score > j.bestScore) {
				j.bestScore = score;
				j.bestCode = args.code;
				j.bestReport = r.report;
			}
			if (matched) j.status = "match";
			else if (left <= 0) j.status = "exhausted";
		}, context);
		if (matched) {
			mkdirSync(MATCHES_DIR, { recursive: true });
			copyFileSync(src, join(MATCHES_DIR, `${job.addr}.cpp`));
			return { content: [{ type: "text", text: "MATCH. Done." }], control: { terminate: true } };
		}
		if (left <= 0) {
			return { content: [{ type: "text", text: r.report + "\nNo submissions left." }], control: { terminate: true } };
		}
		return { content: [{ type: "text", text: `${r.report}\n(${left} submissions left)` }] };
	},
});

// If the model answers in prose instead of submitting, push it back to the tool a couple of times.
const nudges = new Map<string, number>();
const Decomp = defineExtension({
	name: "decomp",
	tools: [submitCpp],
	sections: [section("preamble", () => SYSTEM_PROMPT, { tag: false })],
	hooks: [
		hook(GenerationTask, {
			onYield: async (_answer, api, context) => {
				const job = await api.snapshot(Job, api.conversationId, context);
				if (!job || job.status !== "running" || job.attempts >= job.maxAttempts) return undefined;
				const k = (nudges.get(String(api.conversationId)) ?? 0) + 1;
				nudges.set(String(api.conversationId), k);
				return k <= 2 ? { continue: "Call submit_cpp with your next candidate." } : undefined;
			},
		}),
	],
});

// Free local OpenAI-compatible server (llama.cpp / LM Studio / MLX / Ollama), configured by env:
// LOCAL_LLM_BASE_URL (e.g. http://host:8080/v1), LOCAL_LLM_API_KEY (optional).
// Tiers name its models as "local/<model id>".
function localProvider(modelIds: string[]) {
	const baseUrl = process.env.LOCAL_LLM_BASE_URL;
	if (!baseUrl) throw new Error("tiers use local/... models but LOCAL_LLM_BASE_URL is not set");
	return createProvider({
		id: "local",
		name: "Local",
		baseUrl,
		auth: { apiKey: { name: "Local LLM", resolve: async () => ({ auth: process.env.LOCAL_LLM_API_KEY ? { apiKey: process.env.LOCAL_LLM_API_KEY } : {} }) } },
		models: modelIds.map((id) => ({
			id, name: id, api: "openai-completions" as const, provider: "local", baseUrl,
			reasoning: true, input: ["text" as const],
			cost: { input: 0, output: 0, cacheRead: 0, cacheWrite: 0 },
			contextWindow: 131072, maxTokens: 32768,
		})),
		api: openAICompletionsApi(),
	} as any);
}

const isFree = (model: string) => model.startsWith("local/");

function parseModel(m: string) {
	const i = m.indexOf("/");
	return { provider: m.slice(0, i), modelId: m.slice(i + 1) };
}

async function main() {
	const { values } = parseArgs({
		options: {
			limit: { type: "string", default: "10" },
			concurrency: { type: "string", default: "4" },
			queue: { type: "string", default: join(BUILD, "queue.txt") },
			tiers: { type: "string", default: join(ROOT, "farm/tiers.json") },
			only: { type: "string" },
			db: { type: "string", default: join(BUILD, "farm.sqlite") },
			budget: { type: "string", default: "50" }, // USD, all-time across every ledger; free tiers ignore it
			bench: { type: "string" }, // isolated run: own ledger/db/matches dir, ignores existing matches
		},
	});
	const tiers: Tier[] = JSON.parse(readFileSync(values.tiers!, "utf8"));
	const bench = values.bench;
	const ledgerPath = bench ? join(BUILD, "bench", `${bench}.jsonl`) : join(BUILD, "results.jsonl");
	const matchesDir = bench ? join(BUILD, "bench", bench, "matches") : join(ROOT, "matches");
	const dbPath = bench ? join(BUILD, "bench", `${bench}.sqlite`) : values.db!;
	mkdirSync(join(BUILD, "bench"), { recursive: true });
	MATCHES_DIR = matchesDir;
	WORK_TAG = bench ?? "main";

	// Finished (addr, tier) pairs from the ledger; matched addresses are skipped entirely.
	const finished = new Map<string, Set<number>>();
	const budget = Number(values.budget);
	let spent = 0;
	const benchDir = join(BUILD, "bench");
	for (const f of [join(BUILD, "results.jsonl"), ...readdirSync(benchDir).filter((n) => n.endsWith(".jsonl")).map((n) => join(benchDir, n))]) {
		if (!existsSync(f)) continue;
		for (const line of readFileSync(f, "utf8").split("\n")) if (line) spent += JSON.parse(line).cost ?? 0;
	}
	if (existsSync(ledgerPath)) {
		for (const line of readFileSync(ledgerPath, "utf8").split("\n")) {
			if (!line) continue;
			const r = JSON.parse(line);
			if (!finished.has(r.addr)) finished.set(r.addr, new Set());
			finished.get(r.addr)!.add(r.status === "match" ? -1 : r.tier);
		}
	}
	const isDone = (a: string) => existsSync(join(matchesDir, `${a}.cpp`)) || finished.get(a)?.has(-1)
		|| tiers.every((_, t) => finished.get(a)?.has(t));

	let queue = values.only
		? values.only.split(",")
		: readFileSync(values.queue!, "utf8").split("\n").filter(Boolean);
	queue = queue.map((a) => "0x" + parseInt(a, 16).toString(16).padStart(8, "0")).filter((a) => !isDone(a));
	queue = queue.slice(0, Number(values.limit));

	const models = createModels();
	models.setProvider(openrouterProvider());
	const localIds = tiers.filter((t) => isFree(t.model)).map((t) => parseModel(t.model).modelId);
	if (localIds.length) models.setProvider(localProvider(localIds));
	const registry = createRegistry();
	registry.install(Decomp);
	const harness = await Harness.open(await openNodeSqliteStorage(dbPath), {
		models,
		registry,
		settings: {
			extensions: [Decomp],
			stream: { timeoutMs: 240_000 },
			retry: { maxRetries: 3 },
			compaction: { enabled: false },
			toolExecution: "sequential",
		},
	}, ctx);
	harness.resume();

	async function packet(addr: string): Promise<string> {
		const p = join(BUILD, "packets", `${addr}.txt`);
		if (existsSync(p)) return readFileSync(p, "utf8");
		const { stdout } = await run(PY, [join(ROOT, "tools/packet.py"), "show", addr]);
		return stdout;
	}

	async function runTier(addr: string, t: number, previous?: { code: string; report: string }) {
		const tier = tiers[t];
		const key = `${addr}:${t}`;
		const index = await harness.snapshot(Index, ctx);
		let conv = index?.jobs[key] ? await harness.conversation(index.jobs[key] as any, ctx) : undefined;
		if (!conv) {
			conv = await harness.createConversation({
				ownership: { kind: "ownerless" },
				agent: { model: parseModel(tier.model), thinkingLevel: tier.thinking ?? "medium", extensions: [Decomp] },
				init: async (tx, id) => {
					Object.assign(await tx.doc(Job, id), { addr, tier: t, maxAttempts: tier.maxAttempts });
				},
			}, ctx);
			await harness.commit(async (tx) => {
				(await tx.doc(Index)).jobs[key] = String(conv!.id);
			}, ctx);
		}
		const started = Date.now();
		const content = taskPrompt(await packet(addr), tier.maxAttempts, previous);
		const sub = await conv.submit({ type: "input", content, requestId: key }, ctx);
		const settled = await sub.wait(ctx);
		const job = (await harness.snapshot(Job, conv.id, ctx))!;
		const usage = await harness.snapshot(UsageDoc, conv.id, ctx);
		let cost = 0, input = 0, output = 0, cacheRead = 0;
		for (const u of Object.values(usage?.models ?? {}) as any[]) {
			cost += u.cost?.total ?? 0;
			input += u.input ?? 0;
			output += u.output ?? 0;
			cacheRead += u.cacheRead ?? 0;
		}
		const status = job.status === "running" ? (settled.status === "done" ? "gave_up" : "failed") : job.status;
		const rec = {
			addr, tier: t, model: tier.model, status, attempts: job.attempts, bestScore: job.bestScore,
			cost: Number(cost.toFixed(5)), input, output, cacheRead, secs: Math.round((Date.now() - started) / 1000),
			...(settled.status === "unanswered"
				? { reason: (settled as any).reason, detail: JSON.stringify((settled as any).detail ?? null).slice(0, 300) }
				: {}),
		};
		appendFileSync(ledgerPath, JSON.stringify(rec) + "\n");
		spent += rec.cost;
		console.log(`${addr} t${t} ${tier.model.padEnd(32)} ${status.padEnd(9)} att=${job.attempts} best=${job.bestScore.toFixed(2)} $${rec.cost} ${rec.secs}s`);
		return job;
	}

	async function work(addr: string) {
		let previous: { code: string; report: string } | undefined;
		for (let t = 0; t < tiers.length; t++) {
			if (finished.get(addr)?.has(t)) continue;
			if (!isFree(tiers[t].model) && spent >= budget) {
				if (!budgetWarned) console.log(`budget $${budget} reached ($${spent.toFixed(2)} spent): skipping paid tiers`);
				budgetWarned = true;
				continue;
			}
			try {
				const job = await runTier(addr, t, previous);
				if (job.status === "match") return;
				if (job.bestCode) previous = { code: job.bestCode, report: job.bestReport };
			} catch (e: any) {
				console.error(`${addr} t${t} error: ${e?.message ?? e}`);
				return;
			}
		}
	}

	let budgetWarned = false;
	const concurrency = Number(values.concurrency);
	let next = 0;
	console.log(`farm: ${queue.length} functions, concurrency ${concurrency}, tiers ${tiers.map((t) => t.model).join(" -> ")}, budget $${budget} ($${spent.toFixed(3)} spent)`);
	await Promise.all(Array.from({ length: concurrency }, async () => {
		while (next < queue.length) await work(queue[next++]);
	}));
	const total = await harness.usage(ctx);
	let cost = 0;
	for (const u of Object.values(total.models) as any[]) cost += u.cost?.total ?? 0;
	console.log(`session total cost so far: $${cost.toFixed(4)}`);
	await harness.close(ctx);
}

await main();
