#!/bin/bash

mkdir -p ./bbb/ & find . -maxdepth 1 -name "b*" -type f -exec mv -f {} ./bbb/ \;
