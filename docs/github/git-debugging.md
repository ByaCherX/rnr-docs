<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

## Git bisect

### Description 
The command takes various subcommands, and different options depending on the subcommand:
```git
git bisect start [--term-{new,bad}=<term> --term-{old,good}=<term>]
	  [--no-checkout] [--first-parent] [<bad> [<good>...]] [--] [<paths>...]
git bisect (bad|new|<term-new>) [<rev>]
git bisect (good|old|<term-old>) [<rev>...]
git bisect terms [--term-good | --term-bad]
git bisect skip [(<rev>|<range>)...]
git bisect reset [<commit>]
git bisect (visualize|view)
git bisect replay <logfile>
git bisect log
git bisect run <cmd>...
git bisect help
```
This command uses a binary search algorithm to find which commit in your project’s history introduced a bug. You use it by first telling it a "bad" commit that is known to contain the bug, and a "good" commit that is known to be before the bug was introduced. Then `git bisect` picks a commit between those two endpoints and asks you whether the selected commit is "good" or "bad". It continues narrowing down the range until it finds the exact commit that introduced the change.

In fact, `git bisect` can be used to find the commit that changed any property of your project; e.g., the commit that fixed a bug, or the commit that caused a benchmark’s performance to improve. To support this more general usage, the terms "old" and "new" can be used in place of "good" and "bad", or you can choose your own terms. See section "Alternate terms" below for more information.

> [!IMPORTANT]
> This section talk about later

## Git blame

### Description
Annotates each line in the given file with information from the revision which last modified the line. Optionally, start annotating from the given revision.

When specified one or more times, `-L` restricts annotation to the requested lines.

The origin of lines is automatically followed across whole-file renames (currently there is no option to turn the rename-following off). To follow lines moved from one file to another, or to follow lines that were copied and pasted from another file, etc., see the `-C` and `-M` options.

The report does not tell you anything about lines which have been deleted or replaced; you need to use a tool such as git diff or the "pickaxe" interface briefly mentioned in the following paragraph.

> [!IMPORTANT]
> This section talk about later

## Git grep

### Description
Look for specified patterns in the tracked files in the work tree, blobs registered in the index file, or blobs in given tree objects. Patterns are lists of one or more search expressions separated by newline characters. An empty string as search expression matches all lines.

### Options
<code1>--cached</code1></br>
Instead of searching tracked files in the working tree, search blobs registered in the index file.

<code1>--untracked</code1></br>
In addition to searching in the tracked files in the working tree, search also in untracked files.

<code1>--threads < num></code1></br>
Number of grep worker threads to use. See grep.threads in CONFIGURATION for more information.










