# 🎅 secretSanta

Welcome to my little secret Santa home made.

## 👀 How to use

After cloning the repo, move into it. <br>
First use ``make`` <br>
Then execute ``./secretSanta`` <br>
Follow the prompt indications. <br>
<br>
It will create 2 files per players, one with the player's email and one with the content to send to this player. <br>
<br>
Finally use ``script.sh`` with each of the 2 files of each player <br>

🦄 Exemple : <br>
```sh
[ Player 1 ] 
Name : lou
Mail : loupascreau@gmail.com
```
Will create ``louMail`` and ``louContent``, so execute ``./script.sh louMail louContent`` <br>
The script is going to send the ``louContent`` to ``louMail``, the ``louContent`` contains the name of the player to whom Lou must offer his gift. <br>

## 😊 prerequisite

You will need the ``sendmail`` command.

## 🔧 Build with

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)
