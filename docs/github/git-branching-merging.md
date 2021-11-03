<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

## Git branch

### Description
If `--list` is given, or if there are no non-option arguments, existing branches are listed; the current branch will be highlighted in green and marked with an asterisk. Any branches checked out in linked worktrees will be highlighted in cyan and marked with a plus sign. Option `-r` causes the remote-tracking branches to be listed, and option `-a` shows both local and remote branches.

### Options
<code1>--delete</code1></br>
Delete a branch. The branch must be fully merged in its upstream branch, or in HEAD if no upstream was set with --track or --set-upstream-to.

<code1>--force</code1></br>
Reset ``<branchname>`` to ``<startpoint>``, even if ``<branchname>`` exists already. Without -f, git branch refuses to change an existing branch. In combination with -d (or --delete), allow deleting the branch irrespective of its merged status, or whether it even points to a valid commit. In combination with -m (or --move), allow renaming the branch even if the new branch name already exists, the same applies for -c (or --copy).

<code1>--move</code1></br>
Move/rename a branch and the corresponding reflog.

<code1>--copy</code1></br>
Copy a branch and the corresponding reflog.

<code1>--color[=< when>]</code1></br>
Color branches to highlight current, local, and remote-tracking branches. The value must be always (the default), never, or auto.

<code1>--remotes</code1></br>
List or delete (if used with -d) the remote-tracking branches. Combine with --list to match the optional pattern(s).

<code1>--all</code1></br>
List both remote-tracking branches and local branches. Combine with --list to match optional pattern(s).

<code1>--verbose</code1></br>
When in list mode, show sha1 and commit subject line for each head, along with relationship to upstream branch (if any). If given twice, print the path of the linked worktree (if any) and the name of the upstream branch, as well (see also git remote show ``<remote>``). Note that the current worktree’s HEAD will not have its path printed (it will always be your current directory).

## Git checkout

### Description
Updates files in the working tree to match the version in the index or the specified tree. If no pathspec was given, git checkout will also update ``HEAD`` to set the specified branch as the current branch.

<code1>git checkout [< branch>]</code1></br>
To prepare for working on ``<branch>``, switch to it by updating the index and the files in the working tree, and by pointing HEAD at the branch. Local modifications to the files in the working tree are kept, so that they can be committed to the ``<branch>``.

If ``<branch>`` is not found but there does exist a tracking branch in exactly one remote (call it ``<remote>``) with a matching name and --no-guess is not specified, treat as equivalent to
```
$ git checkout -b ``<branch>`` --track ``<remote>/<branch>``
```
You could omit ``<branch>``, in which case the command degenerates to "check out the current branch", which is a glorified no-op with rather expensive side-effects to show only the tracking information, if exists, for the current branch.

## Git switch

### Description
Switch to a specified branch. The working tree and the index are updated to match the branch. All new commits will be added to the tip of this branch.

Optionally a new branch could be created with either `-c`, `-C`, automatically from a remote branch of same name (see `--guess`), or detach the working tree from any branch with `--detach`, along with switching.

Switching branches does not require a clean index and working tree (i.e. no differences compared to `HEAD`). The operation is aborted however if the operation leads to loss of local changes, unless told otherwise with `--discard-changes` or `--merge`.

## Git merge

### Description
Incorporates changes from the named commits (since the time their histories diverged from the current branch) into the current branch. This command is used by git pull to incorporate changes from another repository and can be used by hand to merge changes from one branch into another.

## Git log

### Desciption
List commits that are reachable by following the `parent` links from the given commit(s), but exclude commits that are reachable from the one(s) given with a ^ in front of them. The output is given in reverse chronological order by default.

You can think of this as a set operation. Commits reachable from any of the commits given on the command line form a set, and then commits reachable from any of the ones given with ^ in front are subtracted from that set. The remaining commits are what comes out in the command’s output. Various other options and paths parameters can be used to further limit the result.

<code1>-L:< funcname>:< file></code1></br>
Trace the evolution of the line range given by ``<start>,<end>``, or by the function name regex ``<funcname>``, within the ``<file>``. You may not give any pathspec limiters. This is currently limited to a walk starting from a single revision, i.e., you may only give zero or one positive revision arguments, and ``<start>`` and ``<end>`` (or ``<funcname>``) must exist in the starting revision. You can specify this option more than once. Implies `--patch`. Patch output can be suppressed using `--no-patch`, but other diff formats (namely `--raw, --numstat, --shortstat, --dirstat, --summary, --name-only, --name-status, --check`) are not currently implemented.

## Git stash

### Description
Use `git stash` when you want to record the current state of the working directory and the index, but want to go back to a clean working directory. The command saves your local modifications away and reverts the working directory to match the `HEAD` commit.

The modifications stashed away by this command can be listed with `git stash list`, inspected with `git stash show`, and restored (potentially on top of a different commit) with `git stash apply`. Calling git stash without any arguments is equivalent to `git stash push`. A stash is by default listed as "WIP on branchname …​", but you can give a more descriptive message on the command line when you create one.

The latest stash you created is stored in `refs/stash`; older stashes are found in the reflog of this reference and can be named using the usual reflog syntax (e.g. `stash@{0}` is the most recently created stash, `stash@{1}` is the one before it, `stash@{2.hours.ago}` is also possible). Stashes may also be referenced by specifying just the stash index (e.g. the integer `n` is equivalent to `stash@{n}`).

<code1>push [-p|--patch] [< pathspec>...]</code1></br>
Save your local modifications to a new stash entry and roll them back to HEAD (in the working tree and in the index). The <message> part is optional and gives the description along with the stashed state.

For quickly making a snapshot, you can omit "push". In this mode, non-option arguments are not allowed to prevent a misspelled subcommand from making an unwanted stash entry. The two exceptions to this are `stash -p` which acts as alias for `stash push -p` and pathspec elements, which are allowed after a double hyphen `--` for disambiguation.

<code1>save [-p|--patch] [< message>]</code1></br>
This option is deprecated in favour of git stash push. It differs from "stash push" in that it cannot take pathspec. Instead, all non-option arguments are concatenated to form the stash message.

<code1>list [<log-options>]</code1></br>
List the stash entries that you currently have. Each stash entry is listed with its name (e.g. `stash@{0}` is the latest entry, `stash@{1}` is the one before, etc.), the name of the branch that was current when the entry was made, and a short description of the commit the entry was based on.

<code1>show [-u|--include-untracked|--only-untracked] [< diff-options>] [< stash>]</code1></br>
Show the changes recorded in the stash entry as a diff between the stashed contents and the commit back when the stash entry was first created. By default, the command shows the diffstat, but it will accept any format known to git diff (e.g., `git stash show -p stash@{1}` to view the second most recent entry in patch form). If no ``<diff-option>`` is provided, the default behavior will be given by the `stash.showStat`, and `stash.showPatch` config variables. You can also use `stash.showIncludeUntracked` to set whether `--include-untracked` is enabled by default.

<code1>create</code1></br>
Create a stash entry (which is a regular commit object) and return its object name, without storing it anywhere in the ref namespace. This is intended to be useful for scripts. It is probably not the command you want to use; see "push" above.

<code1>store</code1></br>
Store a given stash created via git stash create (which is a dangling merge commit) in the stash ref, updating the stash reflog. This is intended to be useful for scripts. It is probably not the command you want to use; see "push" above.

<code1>< stash></code1></br>
This option is only valid for `apply, branch, drop, pop, show` commands.

A reference of the form `stash@{<revision>}`. When no `<stash>` is given, the latest stash is assumed (that is, `stash@{0}`).

## Git tag

### Description
Add a tag reference in `refs/tags/`, unless `-d/-l/-v` is given to delete, list or verify tags.

Unless `-f` is given, the named tag must not yet exist.

If one of `-a`, `-s`, or `-u <keyid>` is passed, the command creates a tag object, and requires a tag message. Unless -m <msg> or -F <file> is given, an editor is started for the user to type in the tag message.

If `-m <msg>` or `-F <file>` is given and `-a`, `-s`, and `-u <keyid>` are absent, `-a` is implied.

Otherwise, a tag reference that points directly at the given object (i.e., a lightweight tag) is created.

A GnuPG signed tag object will be created when `-s` or `-u <keyid>` is used. When `-u <keyid>` is not used, the committer identity for the current user is used to find the GnuPG key for signing. The configuration variable `gpg.program` is used to specify custom GnuPG binary.

Tag objects (created with `-a`, `-s`, or `-u`) are called "annotated" tags; they contain a creation date, the tagger name and e-mail, a tagging message, and an optional GnuPG signature. Whereas a "lightweight" tag is simply a name for an object (usually a commit object).

Annotated tags are meant for release while lightweight tags are meant for private or temporary object labels. For this reason, some git commands for naming objects (like `git describe`) will ignore lightweight tags by default.

### Options

<code1>--annotate</code1></br>
Make an unsigned, annotated tag object

<code1>--sign</code1></br>
Make a GPG-signed tag, using the default e-mail address’s key. The default behavior of tag GPG-signing is controlled by tag.gpgSign configuration variable if it exists, or disabled otherwise. See git-config[1].

<code1>--local-user=< keyid></code1></br>
Make a GPG-signed tag, using the given key.

<code1>--force</code1></br>
Replace an existing tag with the given name (instead of failing)

<code1>--delete</code1></br>
Delete existing tags with the given names.

<code1>--verify</code1></br>
Verify the GPG signature of the given tag names.

<code1>--list</code1></br>
List tags. With optional <pattern>..., e.g. git tag --list 'v-*', list only the tags that match the pattern(s).

Running "git tag" without arguments also lists all tags. The pattern is a shell wildcard (i.e., matched using fnmatch(3)). Multiple patterns may be given; if any of them matches, the tag is shown.

This option is implicitly supplied if any other list-like option such as --contains is provided. See the documentation for each of those options for details.

<code1>< tagname></code1></br>
The name of the tag to create, delete, or describe. The new tag name must pass all checks defined by git-check-ref-format[1]. Some of these checks may restrict the characters allowed in a tag name.

<code1>< object></code1></br>
The object that the new tag will refer to, usually a commit. Defaults to HEAD.

## Git worktree

### Description
Manage multiple working trees attached to the same repository.

A git repository can support multiple working trees, allowing you to check out more than one branch at a time. With `git worktree add` a new working tree is associated with the repository. This new working tree is called a "linked working tree" as opposed to the "main working tree" prepared by git-init[ 1] or git-clone[ 1]. A repository has one main working tree (if it’s not a bare repository) and zero or more linked working trees. When you are done with a linked working tree, remove it with `git worktree remove`.

In its simplest form, `git worktree add <path>` automatically creates a new branch whose name is the final component of `<path>`, which is convenient if you plan to work on a new topic. For instance, `git worktree add ../hotfix` creates new branch hotfix and checks it out at path ../hotfix. To instead work on an existing branch in a new working tree, use git worktree add `<path> <branch>`. On the other hand, if you just plan to make some experimental changes or do testing without disturbing existing development, it is often convenient to create a throwaway working tree not associated with any branch. For instance, `git worktree add -d <path>` creates a new working tree with a detached HEAD at the same commit as the current branch.

If a working tree is deleted without using `git worktree remove`, then its associated administrative files, which reside in the repository (see "DETAILS" below), will eventually be removed automatically (see `gc.worktreePruneExpire` in git-config[ 1]), or you can run `git worktree prune` in the main or any linked working tree to clean up any stale administrative files.

If a linked working tree is stored on a portable device or network share which is not always mounted, you can prevent its administrative files from being pruned by issuing the `git worktree lock` command, optionally specifying `--reason` to explain why the working tree is locked.

### Commands
<code1>add < path> [< commit-ish>]</code1></br>
Create `<path>` and checkout `<commit-ish>` into it. The new working directory is linked to the current repository, sharing everything except working directory specific files such as `HEAD`, `index`, etc. As a convenience, `<commit-ish>` may be a bare "`-`", which is synonymous with `@{-1}`.





