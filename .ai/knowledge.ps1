$ErrorActionPreference = "Stop"

$platformRoot = if ([string]::IsNullOrWhiteSpace($env:KNOWLEDGE_ROOT_PLATFORM)) {
    "C:\Projects\all-knowledge-platform"
} else {
    $env:KNOWLEDGE_ROOT_PLATFORM
}
$router = Join-Path $platformRoot "tools\knowledge.ps1"
$cardPath = Join-Path $PSScriptRoot "knowledge.yaml"

if (-not (Test-Path -LiteralPath $router)) {
    throw "Central knowledge router is unavailable. Set KNOWLEDGE_ROOT_PLATFORM to its checkout path."
}
if (-not (Test-Path -LiteralPath $cardPath)) {
    throw "Local knowledge routing card is missing: $cardPath"
}

$forwardArgs = @($args)
if ($forwardArgs.Count -gt 0 -and $forwardArgs[0] -eq "resolve-context" -and
    -not ($forwardArgs -contains "--current-space-id") -and
    -not ($forwardArgs -contains "--current-location")) {
    $card = Get-Content -LiteralPath $cardPath -Raw | ConvertFrom-Json
    $forwardArgs += @("--current-space-id", $card.space_id)
}

& $router @forwardArgs
exit $LASTEXITCODE
