         q   p       :��������ZϤ*�}Jַ#@�j�K�[A�            u#!/bin/bash
for i in {1..500} 
do
echo $(cat /dev/urandom| tr -dc '0-9a-zA-Z'|head -c 100) >> fileToSearch
done
