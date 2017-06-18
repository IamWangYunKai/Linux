#!/bin/bash 
n=$#
declare -i sum=0
declare -i max
declare -i min
declare -i temp=0
num=("$@")
max=num[0]
min=num[0]
for ((i=0;i<n;i++))
do
    sum+=num[i]
    if ((max<num[i]));then
        max=num[i]
    fi
    if ((min>num[i]));then
        min=num[i]
    fi
done
echo "总和为：$sum"
echo "最大值为：$max"
echo "最小值为：$min"

for ((i=0;i<n-1;i++))
do
    for ((j=i+1;j<n;j++))
    do
        if ((num[i]>num[j]));then
            temp=${num[$i]}
	    num[$i]=${num[$j]}
	    num[$j]=$temp
	fi
    done
done
echo ${num[@]}
exit 0
