PS C:\Users\user\Desktop\Proiecte\joc_butoane> git add joc_butoane.cpp
PS C:\Users\user\Desktop\Proiecte\joc_butoane> git add joc_butoane_nou.cpp
fatal: pathspec 'joc_butoane_nou.cpp' did not match any files
PS C:\Users\user\Desktop\Proiecte\joc_butoane> git commit -m "Actualizare corecta..."
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    ../../joc_butoane.cpp

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        ../../.vscode/
        ../../Browser Opera.lnk
        ../../Canva.lnk
        "../../Desc\304\203rc\304\203ri - Comand\304\203 rapid\304\203.lnk"
        "../../Desktop - Comand\304\203 rapid\304\203.lnk"
        ../../Discord.lnk
        ../../Index/
        ../../Loading.gif
        ../../MinGW Installer.lnk
        ../../Viber.lnk
        "../../desc\304\203rcare-(4).gif"
        ../../desktop.ini
        ../../dev/
        ../../ex1.txt
        ../../hehhehee.lnk
        ../../joc_butoane/

no changes added to commit (use "git add" and/or "git commit -a")
PS C:\Users\user\Desktop\Proiecte\joc_butoane> cd "C:\Users\user\Desktop\Proiecte\joc_butoane"
PS C:\Users\user\Desktop\Proiecte\joc_butoane> dir


    Directory: C:\Users\user\Desktop\Proiecte\joc_butoane


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----        24.11.2025     22:23             17 .gitignore
-a----        26.11.2025     17:23           3921 joc_butoane.cpp
-a----        26.11.2025     17:15         158638 joc_butoane.exe


PS C:\Users\user\Desktop\Proiecte\joc_butoane> notepad "joc_butoane.cpp"
PS C:\Users\user\Desktop\Proiecte\joc_butoane> git status
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   joc_butoane.cpp
        deleted:    ../../joc_butoane.cpp

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        ../../.vscode/
        ../../Browser Opera.lnk
        ../../Canva.lnk
        "../../Desc\304\203rc\304\203ri - Comand\304\203 rapid\304\203.lnk"
        "../../Desktop - Comand\304\203 rapid\304\203.lnk"
        ../../Discord.lnk
        ../../Index/
        ../../Loading.gif
        ../../MinGW Installer.lnk
        ../../Viber.lnk
        "../../desc\304\203rcare-(4).gif"
        ../../desktop.ini
        ../../dev/
        ../../ex1.txt
        ../../hehhehee.lnk
        ../../joc_butoane/

no changes added to commit (use "git add" and/or "git commit -a")
PS C:\Users\user\Desktop\Proiecte\joc_butoane> git add joc_butoane.cpp
PS C:\Users\user\Desktop\Proiecte\joc_butoane> git commit -m "Actualizareee"
[main 4e73e1c] Actualizareee
 1 file changed, 84 insertions(+), 89 deletions(-)
PS C:\Users\user\Desktop\Proiecte\joc_butoane> git push
Enumerating objects: 9, done.
Counting objects: 100% (9/9), done.
Delta compression using up to 16 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (5/5), 1.56 KiB | 1.56 MiB/s, done.
Total 5 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/romannadea5-collab/joc_butoane.git
   099b5fc..4e73e1c  main -> main
PS C:\Users\user\Desktop\Proiecte\joc_butoane> cum sa vad cum ruleaza
cum : The term 'cum' is not recognized as the name of a cmdlet, function, script file, or operable program. Check the s
pelling of the name, or if a path was included, verify that the path is correct and try again.
At line:1 char:1
+ cum sa vad cum ruleaza
+ ~~~
    + CategoryInfo          : ObjectNotFound: (cum:String) [], CommandNotFoundException
    + FullyQualifiedErrorId : CommandNotFoundException

PS C:\Users\user\Desktop\Proiecte\joc_butoane> cd "C:\Users\user\Desktop\Proiecte\joc_butoane"
PS C:\Users\user\Desktop\Proiecte\joc_butoane> .\joc_butoane.exe


=====================================
         JOC GHICESTE NUMARUL
=====================================

+-----------+
| S = START |
+-----------+
+--------------------------------------+
| Nivel: E = Usor, M = Mediu, H = Greu |
+--------------------------------------+
+------------+
| Q = Iesire |
+------------+

Alege optiunea: S

-------------------------------------
         GHICESTE NUMARUL!
              (1 - 100)
-------------------------------------
Numar (0 = renunt): 56
Prea mare!
Numar (0 = renunt): 9
Prea mic!
Numar (0 = renunt): 8
Prea mic!
Numar (0 = renunt): 34
Prea mare!
Numar (0 = renunt): 22
Prea mare!
Numar (0 = renunt): 12
Prea mic!
Numar (0 = renunt): 15
Prea mic!
Numar (0 = renunt): 17

=====================================
           FELICITARI!!!
         AI GHICIT NUMARUL!
=====================================

Vrei sa joci din nou? (Y/N):

