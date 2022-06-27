#!/bin/bash

sendmail -it << EOF
To: $(cat $1)
Subject: Sujet

$(cat $2)
EOF
