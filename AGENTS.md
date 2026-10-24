# AGENTS.md — ROS 2 projects

## Global knowledge routing

For cross-repository questions, read `.ai/knowledge.yaml` and query the central read-only router before opening another repository:

```powershell
.\.ai\knowledge.ps1 search-vector "<question>"     # all project docs, Obsidian notes and learnings by meaning
.\.ai\knowledge.ps1 resolve-context --task "<question>"
.\.ai\knowledge.ps1 search-knowledge "<terms>" --include-excerpts
.\.ai\knowledge.ps1 read-source "<source_uri>"
```

Report Cerebro unavailable only when `.ai/knowledge.ps1` itself fails. The wrapper injects this repository's `space_id`; set `KNOWLEDGE_ROOT_PLATFORM` only when the central checkout is not at its default path. Local code, tests and docs remain the source of truth; central output provides routing and provenance.
