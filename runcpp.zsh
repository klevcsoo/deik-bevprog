#!/bin/zsh
set -e
set -o localoptions -o localtraps

ext=${1##*.}
outfile=${1%%.*}

trap 'rm ${outfile}' INT

if [ ${ext} != "cpp" ]; then
  echo "script: \e[31;1merror:\e[0m Extension must be .cpp"
  exit 1
fi

gcc ${1} -o ${outfile} -lstdc++
${outfile}
rm ${outfile}
