<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

<h1 style="text-align:center">Git - Inspection Comparison</h1>

## Git show

### Description
Shows one or more objects (blobs, trees, tags and commits).</br>
For commits it shows the log message and textual diff. It also presents the merge commit in a special format as produced by git diff-tree --cc.</br>
For tags, it shows the tag message and the referenced objects.</br>
For trees, it shows the names (equivalent to git ls-tree with --name-only).</br>
For plain blobs, it shows the plain contents.</br>
The command takes options applicable to the git diff-tree command to control how the changes the commit introduces are shown.</br>
This manual page describes only the most frequently used options.

### Options
<code1>--format=< format></code1></br>
Pretty-print the contents of the commit logs in a given format, where < format> can be one of oneline, short, medium, full, fuller, reference, email, raw, format:< string> and tformat:< string>. When < format> is none of the above, and has %placeholder in it, it acts as if --pretty=tformat:< format> were given.

<code1>--stat[=< width>[,< name-width>[,< count>]]]</code1></br>
Generate a diffstat. By default, as much space as necessary will be used for the filename part, and the rest for the graph part. Maximum width defaults to terminal width, or 80 columns if not connected to a terminal, and can be overridden by `<width>`. The width of the filename part can be limited by giving another width `<name-width>` after a comma. The width of the graph part can be limited by using `--stat-graph-width=<width>` (affects all commands generating a stat graph) or by setting `diff.statGraphWidth=<width>` (does not affect `git format-patch`). By giving a third parameter `<count>`, you can limit the output to the first `<count>` lines, followed by ... if there are more.

--compact-summary
Output a condensed summary of extended header information such as file creations or deletions ("new" or "gone", optionally "+l" if it’s a symlink) and mode changes ("+x" or "-x" for adding or removing executable bit respectively) in diffstat. The information is put between the filename part and the graph part. Implies --stat.

## Git log

### Description
Shows the commit logs.

List commits that are reachable by following the `parent` links from the given commit(s), but exclude commits that are reachable from the one(s) given with a ^ in front of them. The output is given in reverse chronological order by default.

You can think of this as a set operation. Commits reachable from any of the commits given on the command line form a set, and then commits reachable from any of the ones given with ^ in front are subtracted from that set. The remaining commits are what comes out in the command’s output. Various other options and paths parameters can be used to further limit the result.

## Git diff

### Description
Show changes between the working tree and the index or a tree, changes between the index and a tree, changes between two trees, changes resulting from a merge, changes between two blob objects, or changes between two files on disk.

<code1>git diff [< options>] [--] [< path>…​]</code1></br>
This form is to view the changes you made relative to the index (staging area for the next commit). In other words, the differences are what you could tell Git to further add to the index but you still haven’t. You can stage these changes by using git-add[1].

### Options
<code1>--raw</code1></br>
Generate the diff in raw format.

<code1>--minimal</code1></br>
Spend extra time to make sure the smallest possible diff is produced.

<code1>--compact-summary</code1></br>
Output a condensed summary of extended header information such as file creations or deletions ("new" or "gone", optionally "+l" if it’s a symlink) and mode changes ("+x" or "-x" for adding or removing executable bit respectively) in diffstat. The information is put between the filename part and the graph part. Implies `--stat`.

<code1>--numstat</code1></br>
Similar to `--stat`, but shows number of added and deleted lines in decimal notation and pathname without abbreviation, to make it more machine friendly. For binary files, outputs two - instead of saying `0 0`.

## Git shortlog

### Desciption
Summarizes git log output in a format suitable for inclusion in release announcements. Each commit will be grouped by author and title.

Additionally, "[ PATCH]" will be stripped from the commit description.

If no revisions are passed on the command line and either standard input is not a terminal or there is no current branch, git shortlog will output a summary of the log read from standard input, without reference to the current repository.

## Git describe

### Description
The command finds the most recent tag that is reachable from a commit. If the tag points to the commit, then only the tag is shown. Otherwise, it suffixes the tag name with the number of additional commits on top of the tagged object and the abbreviated object name of the most recent commit. The result is a "human-readable" object name which can also be used to identify the commit to other git commands.

By default (without --all or --tags) `git describe` only shows annotated tags. For more information about creating annotated tags see the -a and -s options to git-tag.

If the given object refers to a blob, it will be described as `<commit-ish>:<path>`, such that the blob can be found at `<path>` in the `<commit-ish>`, which itself describes the first commit in which this blob occurs in a reverse revision walk from HEAD.

### Options
<code1>--all</code1></br>
Instead of using only the annotated tags, use any ref found in refs/ namespace. This option enables matching any known branch, remote-tracking branch, or lightweight tag.

<code1>--tags</code1></br>
Instead of using only the annotated tags, use any tag found in refs/tags namespace. This option enables matching a lightweight (non-annotated) tag.

<code1>--contains</code1></br>
Instead of finding the tag that predates the commit, find the tag that comes after the commit, and thus contains it. Automatically implies --tags.

--debug
Verbosely display information about the searching strategy being employed to standard error. The tag name will still be printed to standard out.






