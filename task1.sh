#!/bin/bash
if [ $# -ne 1 ]
    then
        echo "错误：请输入一个文件名"
        exit 1
    else
    if [ -f "$1" ]
        then
            filename="$1"
            set $(ls -il $filename)
            user="$4"
            mon="$7"
	    day="$8"
	    echo "所有者：$user"
	    echo "最后修改日期：$mon$day日"
	    exit 0
    fi
fi
