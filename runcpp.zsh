#!/bin/zsh
set -e

ext=${1##*.}
if [ ${ext} != "cpp" ]; then
  echo "Extension must be .cpp"
  exit 1
fi

gcc $1 -o "${1%%.*}" -lstdc++
