<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

<h1 style="text-align:center">Git - Creating Project</h1>

## Creating Git Project

### Description
This command creates an empty Git repository - basically a ``.git`` directory with subdirectories for ``objects``, ``refs/heads``, ``refs/tags``, and template files. An initial branch without any commits will be created (see the --initial-branch option below for its name).

If the ``$GIT_DIR`` environment variable is set then it specifies a path to use instead of ``./.git`` for the base of the repository.

If the object storage directory is specified via the ``$GIT_OBJECT_DIRECTORY`` environment variable then the sha1 directories are created underneath - otherwise the default ``$GIT_DIR/objects`` directory is used.

Running git init in an existing repository is safe. It will not overwrite things that are already there. The primary reason for rerunning git init is to pick up newly added templates (or to move the repository to another place if --separate-git-dir is given).

### Options
<code1>--quiet</code1></br>
Only print error and warning messages; all other output will be suppressed.
<code1>--bare</code1></br>
Create a bare repository. If GIT_DIR environment is not set, it is set to the current working directory.

## Clone Git Project

### Description
Clones a repository into a newly created directory, creates remote-tracking branches for each branch in the cloned repository (visible using `git branch --remotes`), and creates and checks out an initial branch that is forked from the cloned repository’s currently active branch.

After the clone, a plain `git fetch` without arguments will update all the remote-tracking branches, and a `git pull` without arguments will in addition merge the remote master branch into the current master branch, if any (this is untrue when "--single-branch" is given; see below).

This default configuration is achieved by creating references to the remote branch heads under `refs/remotes/origin` and by initializing `remote.origin.url` and `remote.origin.fetch` configuration variables.

### Options
<code1>--local</code1></br>
When the repository to clone from is on a local machine, this flag bypasses the normal "Git aware" transport mechanism and clones the repository by making a copy of HEAD and everything under objects and refs directories. The files under `.git/objects/` directory are hardlinked to save space when possible.

If the repository is specified as a local path (e.g., `/path/to/repo`), this is the default, and --local is essentially a no-op. If the repository is specified as a URL, then this flag is ignored (and we never use the local optimizations). Specifying `--no-local` will override the default when `/path/to/repo` is given, using the regular Git transport instead.

> [!NOTE]
> This operation can race with concurrent modification to the source repository, similar to running ``cp -r src dst`` while modifying src.

<code1>--quiet</code1></br>
Operate quietly. Progress is not reported to the standard error stream.

<code1>--verbose</code1></br>
Run verbosely. Does not affect the reporting of progress status to the standard error stream.

<code1>--progress</code1></br>
Progress status is reported on the standard error stream by default when it is attached to a terminal, unless --quiet is specified. This flag forces progress status even if the standard error stream is not directed to a terminal.

<code1>--server-option=< option></code1></br>
Transmit the given string to the server when communicating using protocol version 2. The given string must not contain a NUL or LF character. The server’s handling of server options, including unknown ones, is server-specific. When multiple ``--server-option=<option>`` are given, they are all sent to the other side in the order listed on the command line.

<code1>--mirror</code1></br>
Set up a mirror of the source repository. This implies `--bare`. Compared to `--bare`, `--mirror` not only maps local branches of the source to local branches of the target, it maps all refs (including remote-tracking branches, notes etc.) and sets up a refspec configuration such that all these refs are overwritten by a `git remote update` in the target repository.

<code1>--origin < name></code1></br>
Instead of using the remote name origin to keep track of the upstream repository, use ``<name>``. Overrides clone.defaultRemoteName from the config.

<code1>--branch < name></code1></br>
Instead of pointing the newly created HEAD to the branch pointed to by the cloned repository’s HEAD, point to ``<name>`` branch instead. In a non-bare repository, this is the branch that will be checked out. `--branch` can also take tags and detaches the HEAD at that commit in the resulting repository.









