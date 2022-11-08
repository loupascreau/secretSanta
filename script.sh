#!/bin/bash

## clear files or init them #

echo "" > allEmails
echo "" > allNames

#### execute secretSanta ####

./secretSanta

### setup nedded variables ##

allEmails=$(cat allEmails)
allNames=$(cat allNames)
messageEnding=$(cat messageEnding)

listName=""
for name in ${allNames}; do
    listName+=$name
    listName+=". "
done

echo "participants : ${listName}"

#### function sendMails() ###

sendMails() {
fileName=$2
fileName+="Content"
sendmail -it << EOF
To: $1
From : loupascreau@gmail.com
Subject: Secret Santa by Lou

$(cat ${fileName})
${messageEnding}

PS : La liste des participants { ${listName} }.
EOF
}

##### loop sending mails ####

i=0
for mail in ${allEmails}; do
    j=0
    for name in ${allNames}; do
        if (( j == i )); then
            echo "sending email to $mail for $name"
            sendMails $mail $name
        fi
        ((j++))
    done
    ((i++))
done

#### remove content files ###

for name in ${allNames}; do
    echo "cleaning ${name} files.."
    fileToRm=$name
    fileToRm+="Content"
    rm -rf ${fileToRm}
    fileToRm=$name
    fileToRm+="Mail"
    rm -rf ${fileToRm}
done

echo "Finished, all emails sent !"
