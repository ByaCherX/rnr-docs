<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

## Git Cheat Sheet
### SETUP
Configuring user information used across all local repositories
* ``git config --global user.name "[firstname lastname]"``</br>
set a name that is identifiable for credit when review version history
* ``git config --global user.email "[valid-email]"``</br>
set an email address that will be associated with each history marker
* ``git config --global color.ui auto``</br>
set automatic command line coloring for Git for easy reviewing

### SETUP & INIT
Configuring user information, initializing and cloning repositories
* ``git init [repo-name]``</br>
initialize an existing directory as a Git repository
* ``git clone [url]``</br>
retrieve an entire repository from a hosted location via URL

### STAGE & SNAPSHOT
Working with snapshots and the Git staging area
* ``git status``</br>
show modified files in working directory, staged for your next commit
* ``git add [file]``</br>
add a file as it looks now to your next commit (stage)
* ``git reset [file]``</br>
unstage a file while retaining the changes in working directory
* ``git diff``</br>
diff of what is changed but not staged
* ``git diff --staged``</br>
diff of what is staged but not yet commited
* ``git commit -m “[descriptive message]”``</br>
commit your staged content as a new commit snapshot

### BRANCH & MERGE
Isolating work in branches, changing context, and integrating changes
* ``git branch``</br>
list your branches. a * will appear next to the currently active branch
* ``git branch [branch-name]``</br>
create a new branch at the current commit
* ``git checkout``</br>
switch to another branch and check it out into your working directory
* ``git merge [branch]``</br>
merge the specified branch’s history into the current one
* ``git log``</br>
show all commits in the current branch’s history

### INSPECT & COMPARE
Examining logs, diffs and object information
* ``git log``</br>
show the commit history for the currently active branch
* ``git log branchB..branchA``</br>
show the commits on branchA that are not on branchB
* ``git log --follow [file]``</br>
show the commits that changed file, even across renames
* ``git diff branchB...branchA``</br>
show the diff of what is in branchA that is not in branchB
* ``git show [SHA]``</br>
show any object in Git in human-readable format

### TRACKING PATH CHANGES
Versioning file removes and path changes
* ``git rm [file]``</br>
delete the file from project and stage the removal for commit
* ``git mv [existing-path] [new-path]``</br>
change an existing file path and stage the move
* ``git log --stat -M``</br>
show all commit logs with indication of any paths that moved

### IGNORING PATTERNS
Preventing unintentional staging or commiting of files
* ``logs/``</br>
``*.notes``</br>
``pattern*/``</br>
Save a file with desired paterns as .gitignore with either direct string
matches or wildcard globs.
* ``git config --global core.excludesfile [file]``</br>
system wide ignore patern for all local repositories

### SHARE & UPDATE
Retrieving updates from another repository and updating local repos
* ``git remote add [alias] [url]``</br>
add a git URL as an alias
* ``git fetch [alias]``</br>
fetch down all the branches from that Git remote
* ``git merge [alias]/[branch]``</br>
merge a remote branch into your current branch to bring it up to date
* ``git push [alias] [branch]``</br>
Transmit local branch commits to the remote repository branch
* ``git pull``</br>
fetch and merge any commits from the tracking remote branch

### REWRITE HISTORY
Rewriting branches, updating commits and clearing history
* ``git rebase [branch]``</br>
apply any commits of current branch ahead of specified one
* ``git reset --hard [commit]``</br>
clear staging area, rewrite working tree from specified commit

### TEMPORARY COMMITS
Temporarily store modified, tracked files in order to change branches
* ``git stash``</br>
Save modified and staged changes
* ``git stash list``</br>
list stack-order of stashed file changes
* ``git stash pop``</br>
write working from top of stash stack
* ``git stash drop``</br>
discard the changes from top of stash stack



