<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

<h1 style="text-align:center">Git - Snapshotting</h1>

## Git add

### Description
This command updates the index using the current content found in the working tree, to prepare the content staged for the next commit. It typically adds the current content of existing paths as a whole, but with some options it can also be used to add content with only part of the changes made to the working tree files applied, or remove paths that do not exist in the working tree anymore.

The "index" holds a snapshot of the content of the working tree, and it is this snapshot that is taken as the contents of the next commit. Thus after making any changes to the working tree, and before running the commit command, you must use the `add` command to add any new or modified files to the index.

This command can be performed multiple times before a commit. It only adds the content of the specified file(s) at the time the add command is run; if you want subsequent changes included in the next commit, then you must run `git add` again to add the new content to the index.

The `git status` command can be used to obtain a summary of which files have changes that are staged for the next commit.

The `git add` command will not add ignored files by default. If any ignored files were explicitly specified on the command line, git add will fail with a list of ignored files. Ignored files reached by directory recursion or filename globbing performed by Git (quote your globs before the shell) will be silently ignored. The git add command can be used to add ignored files with the -f (force) option.

Please see git-commit for alternative ways to add content to a commit.

### Options
```git
git add [<options>] [--] <pathspec>
```

<code1>< pathspec >…</code1></br>
Files to add content from. Fileglobs (e.g. `*.c`) can be given to add all matching files. Also a leading directory name (e.g. `dir` to add `dir/file1` and `dir/file2`) can be given to update the index to match the current state of the directory as a whole (e.g. specifying `dir` will record not just a file `dir/file1` modified in the working tree, a file `dir/file2` added to the working tree, but also a file `dir/file3` removed from the working tree). Note that older versions of Git used to ignore removed files; use `--no-all` option if you want to add modified or new files but ignore removed ones.

For more details about the `<pathspec>` syntax, see the pathspec entry in gitglossary

<code1>--verbose</code1></br>
Be verbose.

<code1>--force</code1></br>
Allow adding otherwise ignored files.

<code1>--interactive</code1></br>
Add modified contents in the working tree interactively to the index. Optional path arguments may be supplied to limit operation to a subset of the working tree. See “Interactive mode” for details.

<code1>--patch</code1></br>
Interactively choose hunks of patch between the index and the work tree and add them to the index. This gives the user a chance to review the difference before adding modified contents to the index.

This effectively runs `add --interactive`, but bypasses the initial command menu and directly jumps to the `patch` subcommand. See “Interactive mode” for details.

<code1>--edit</code1></br>
Open the diff vs. the index in an editor and let the user edit it. After the editor was closed, adjust the hunk headers and apply the patch to the index.

The intent of this option is to pick and choose lines of the patch to apply, or even to modify the contents of lines to be staged. This can be quicker and more flexible than using the interactive hunk selector. However, it is easy to confuse oneself and create a patch that does not apply to the index. See EDITING PATCHES below.

<code1>--update</code1></br>
Update the index just where it already has an entry matching ``<pathspec>``. This removes as well as modifies index entries to match the working tree, but adds no new files.

If no ``<pathspec>`` is given when -u option is used, all tracked files in the entire working tree are updated (old versions of Git used to limit the update to the current directory and its subdirectories).

### Example
Adds content from all `*.txt` files under `Documentation` directory and its subdirectories:

```git
$ git add Documentation/\*.txt
```

## Git status

### Description
Displays paths that have differences between the index file and the current HEAD commit, paths that have differences between the working tree and the index file, and paths in the working tree that are not tracked by Git (and are not ignored by gitignore[ 5]). The first are what you would commit by running `git commit`; the second and third are what you could commit by running git add before running git `commit`.

### Options
<code1>--short</code1></br>
Give the output in the short-format.

<code1>--branch</code1></br>
Show the branch and tracking info even in short-format.

<code1>--show-stash</code1></br>
Show the number of entries currently stashed away.

<code1>--long</code1></br>
Give the output in the long-format. This is the default.

<code1>--verbose</code1></br>
In addition to the names of files that have been changed, also show the textual changes that are staged to be committed (i.e., like the output of `git diff --cached`). If `-v` is specified twice, then also show the changes in the working tree that have not yet been staged (i.e., like the output of `git diff`).

## Git diff

### Description
Show changes between the working tree and the index or a tree, changes between the index and a tree, changes between two trees, changes resulting from a merge, changes between two blob objects, or changes between two files on disk.

### Options
<code1>--patch</code1></br>
Generate patch (see section on generating patches). This is the default.

<code1>--raw</code1></br>
Generate the diff in raw format.

<code1>--minimal</code1></br>
Spend extra time to make sure the smallest possible diff is produced.

<code1>--patience</code1></br>
Generate a diff using the "patience diff" algorithm.

<code1>--histogram</code1></br>
Generate a diff using the "histogram diff" algorithm.

<code1>--anchored=< text></code1></br>
Generate a diff using the "anchored diff" algorithm.

<code1>--numstat</code1></br>
Similar to --stat, but shows number of added and deleted lines in decimal notation and pathname without abbreviation, to make it more machine friendly. For binary files, outputs two - instead of saying 0 0.

<code1>--shortstat</code1></br>
Output only the last line of the --stat format containing total number of modified files, as well as number of added and deleted lines.

## Git commit

### Description
Create a new commit containing the current contents of the index and the given log message describing the changes. The new commit is a direct child of HEAD, usually the tip of the current branch, and the branch is updated to point to it (unless no branch is associated with the working tree, in which case HEAD is "detached" as described in git-checkout[ 1]).

### Options 
<code1>--all</code1></br>
Tell the command to automatically stage files that have been modified and deleted, but new files you have not told Git about are not affected.

<code1>--patch</code1></br>
Use the interactive patch selection interface to choose which changes to commit. See git-add[1] for details.

<code1>--reedit-message=< commit> & -c < commit></code1></br>
Like -C, but with -c the editor is invoked, so that the user can further edit the commit message.

<code1>--squash=< commit></code1></br>
Construct a commit message for use with rebase --autosquash. The commit message subject line is taken from the specified commit with a prefix of "squash! ". Can be used with additional commit message options (`-m/-c/-C/-F`). See git-rebase[1] for details.

<code1>--short</code1></br>
When doing a dry-run, give the output in the short-format. See git-status[1] for details. Implies `--dry-run.`

<code1>--long</code1></br>
When doing a dry-run, give the output in the long-format. Implies `--dry-run.`

<code1>--branch</code1></br>
Show the branch and tracking info even in short-format.

## Git notes

### Description
Adds, removes, or reads notes attached to objects, without touching the objects themselves.

By default, notes are saved to and read from `refs/notes/commits`, but this default can be overridden. See the OPTIONS, CONFIGURATION, and ENVIRONMENT sections below. If this ref does not exist, it will be quietly created when it is first needed to store a note.

A typical use of notes is to supplement a commit message without changing the commit itself. Notes can be shown by git log along with the original commit message. To distinguish these notes from the message stored in the commit object, the notes are indented like the message, after an unindented line saying "Notes (< refname>):" (or "Notes:" for `refs/notes/commits`).

Notes can also be added to patches prepared with `git format-patch` by using the `--notes` option. Such notes are added as a patch commentary after a three dash separator line.

To change which notes are shown by git log, see the "notes.displayRef" configuration in git-log[ 1].

See the "notes.rewrite.< command>" configuration for a way to carry notes across commands that rewrite commits.

### Subcommands

<code1>list</code1></br>
List the notes object for a given object. 

<code1>add</code1></br>
Add notes for a given object (defaults to HEAD). Abort if the object already has notes (use -f to overwrite existing notes).

<code1>copy</code1></br>
Copy the notes for the first object onto the second object (defaults to HEAD). Abort if the second object already has notes, or if the first object has none (use -f to overwrite existing notes to the second object).

<code1>edit</code1></br>
Edit the notes for a given object (defaults to HEAD).

<code1>show</code1></br>
Show the notes for a given object (defaults to HEAD).

<code1>remove</code1></br>
Remove the notes for given objects (defaults to HEAD). When giving zero or one object from the command line, this is equivalent to specifying an empty note message to the edit subcommand.

<code1>get-ref</code1></br>
Print the current notes ref. This provides an easy way to retrieve the current notes ref (e.g. from scripts).

## Git restore

### Description
Restore specified paths in the working tree with some contents from a restore source. If a path is tracked but does not exist in the restore source, it will be removed to match the source.

The command can also be used to restore the content in the index with `--staged`, or restore both the working tree and the index with `--staged --worktree`.

By default, if `--staged` is given, the contents are restored from `HEAD`, otherwise from the index. Use `--source` to restore from a different commit.

See "Reset, restore and revert" in git[ 1] for the differences between the three commands.

> [!IMPORTANT]
> THIS COMMAND IS EXPERIMENTAL. THE BEHAVIOR MAY CHANGE.

## Git rm

### Description
Remove files matching pathspec from the index, or from the working tree and the index. `git rm` will not remove a file from just your working directory. (There is no option to remove a file only from the working tree and yet keep it in the index; use `/bin/rm` if you want to do that.) The files being removed have to be identical to the tip of the branch, and no updates to their contents can be staged in the index, though that default behavior can be overridden with the `-f` option. When `--cached` is given, the staged content has to match either the tip of the branch or the file on disk, allowing the file to be removed from just the index. When sparse-checkouts are in use (see git-sparse-checkout[ 1]), `git rm` will only remove paths within the sparse-checkout patterns.

### Options

<code1>--force</code1></br>
Override the up-to-date check.

<code1>--cached</code1></br>
Use this option to unstage and remove paths only from the index. Working tree files, whether modified or not, will be left alone.

<code1>--quiet</code1></br>
git rm normally outputs one line (in the form of an rm command) for each file removed. This option suppresses that output.

## Git mv

### Desciption
Move or rename a file, directory or symlink.
```git
git mv [-v] [-f] [-n] [-k] <source> <destination>
git mv [-v] [-f] [-n] [-k] <source> ... <destination directory>
```
In the first form, it renames `<source>`, which must exist and be either a file, symlink or directory, to `<destination>`. In the second form, the last argument has to be an existing directory; the given sources will be moved into this directory.








