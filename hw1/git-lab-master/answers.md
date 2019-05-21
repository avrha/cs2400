Answer 1
git 2.17.1

Answer 2
user.name=Joey Ferenchak
user.email=sjferenchak@gmail.com

"Answer 3
usage: git [--version] [--help] [-C <path>] [-c <name>=<value>]
           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
           [-p | --paginate | --no-pager] [--no-replace-objects] [--bare]
           [--git-dir=<path>] [--work-tree=<path>] [--namespace=<name>]
           <command> [<args>]

These are common Git commands used in various situations:

start a working area (see also: git help tutorial)
   clone      Clone a repository into a new directory
   init       Create an empty Git repository or reinitialize an existing one

work on the current change (see also: git help everyday)
   add        Add file contents to the index
   mv         Move or rename a file, a directory, or a symlink
   reset      Reset current HEAD to the specified state
   rm         Remove files from the working tree and from the index

examine the history and state (see also: git help revisions)
   bisect     Use binary search to find the commit that introduced a bug
   grep       Print lines matching a pattern
   log        Show commit logs
   show       Show various types of objects
   status     Show the working tree status

grow, mark and tweak your common history
   branch     List, create, or delete branches
   checkout   Switch branches or restore working tree files
   commit     Record changes to the repository
   diff       Show changes between commits, commit and working tree, etc
   merge      Join two or more development histories together
   rebase     Reapply commits on top of another base tip
   tag        Create, list, delete or verify a tag object signed with GPG

collaborate (see also: git help workflows)
   fetch      Download objects and refs from another repository
   pull       Fetch from and integrate with another repository or a local branch
   push       Update remote refs along with associated objects

'git help -a' and 'git help -g' list available subcommands and some
concept guides. See 'git help <command>' or 'git help <concept>'
to read about a specific subcommand or concept.

Answer 4
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)

  README.md
  answers.md

nothing added to commit but untracked files present (use "git add" to track)

Answer 5
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

  new file:   README.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)

  answers.md

Answer 6
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

  new file:   README.md
  new file:   answers.md

Answer 7
On branch master
nothing to commit, working tree clean

Answer 8
commit 7f588cd73b683a5126cf2268c11587d11cc49680 (HEAD -> master)
Author: Joey Ferenchak <sjferenchak@gmail.com>
Date:   Fri May 17 16:10:28 2019 -0400

    Initial Commit

Answer 9
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

  modified:   answers.md

no changes added to commit (use "git add" and/or "git commit -a")

Answer 10
No changes were made to my README.md file after editing and commiting the file on github.

Answer 11
Username for 'https://github.com': avrha
Password for 'https://avrha@github.com': 
To https://github.com/avrha/git-lab.git
 ! [rejected]        master -> master (fetch first)
error: failed to push some refs to 'https://github.com/avrha/git-lab.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.

Answer 12
Changes were made after running the command git pull

Username for 'https://github.com': avrha
Password for 'https://avrha@github.com': 
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (3/3), done.
From https://github.com/avrha/git-lab
   1dea57d..14662ad  master     -> origin/master
Updating 1dea57d..14662ad
Fast-forward
 README.md | 7 ++++---
 1 file changed, 4 insertions(+), 3 deletions(-)

Answer 13
.  ..  .git  .gitignore  README.md