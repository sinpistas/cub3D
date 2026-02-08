#!/usr/bin/env bash
set -u

BIN="./cub3D"

run_dir () {
  local DIR="$1"
  echo "=== Valgrind: $DIR ==="
  find "$DIR" -type f -name "*.cub" -print0 | sort -z | while IFS= read -r -d '' f; do
    echo "--- $f"
    valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite \
      --error-exitcode=42 "$BIN" --test "$f" 2>&1 | grep -E "(definitely lost|ERROR SUMMARY)"
    if [[ $? -eq 42 ]]; then
      echo "[LEAK] $f"
    else
      echo "[OK  ] $f"
    fi
  done
  echo
}

run_dir "maps/good"
run_dir "maps/bad"
