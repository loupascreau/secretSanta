#!/bin/bash

file=/home/kali/Documents/secretSanta/$2

sendmail -it << EOF
To: $(cat $1)
Subject: Sujet

$(cat $file)
EOF