#!/bin/bash
filename="$1"
of=$(ls -l|grep "^-"|wc -l)
dir=$(ls -l|grep "^d"|wc -l)
exe=$(ls -F|grep "*"|wc -l)
echo "普通文件数：$of"
echo "子目录数：$dir"
echo "可执行文件数：$exe"
exit 0
