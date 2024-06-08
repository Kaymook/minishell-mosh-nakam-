#!/bin/sh

# ARG_MAXの取得
ARG_MAX=$(getconf ARG_MAX)

echo "ARG_MAX: $ARG_MAX"
# printf %0${ARG_MAX}d 0 | xargs > /dev/null
printf '%02097152d' 0 | xargs >/dev/null
# printf "%0$(expr $ARG_MAX)d" 0 | xargs >> hello