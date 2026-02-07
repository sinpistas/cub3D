#!/usr/bin/env bash
set -u

BIN="./cub3D"
DIR="maps/good"
EXT="*.cub"

if [[ ! -x "$BIN" ]]; then
  echo "Error: binary not found or not executable: $BIN"
  echo "Run: make"
  exit 1
fi

if [[ ! -d "$DIR" ]]; then
  echo "Error: directory not found: $DIR"
  exit 1
fi

mapfile -d '' FILES < <(find "$DIR" -type f -name "$EXT" -print0 | sort -z)

if (( ${#FILES[@]} == 0 )); then
  echo "No .cub files found in $DIR"
  exit 0
fi

OK=0
KO=0
TOTAL=0

echo "Running ${#FILES[@]} tests from $DIR"
echo

for f in "${FILES[@]}"; do
  ((TOTAL++))
  "$BIN" "$f" > /dev/null 2>&1
  status=$?

  if [[ $status -eq 0 ]]; then
    echo "[OK ] $f"
    ((OK++))
  else
    echo "[KO ] $f"
    ((KO++))
  fi
done

echo
echo "Done."
echo "TOTAL: $TOTAL | OK: $OK | KO: $KO"
