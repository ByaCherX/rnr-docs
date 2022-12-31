<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

<h1 style="text-align:center">Git - Sharing Updating Project</h1>

## Git fetch

### Description
Fetch branches and/or tags (collectively, "refs") from one or more other repositories, along with the objects necessary to complete their histories. Remote-tracking branches are updated (see the description of `<refspec>` below for ways to control this behavior).

By default, any tag that points into the histories being fetched is also fetched; the effect is to fetch tags that point at branches that you are interested in. This default behavior can be changed by using the --tags or --no-tags options or by configuring remote.`<name>`.tagOpt. By using a refspec that fetches tags explicitly, you can fetch tags that do not point into branches you are interested in as well.

git fetch can fetch from either a single named repository or URL, or from several repositories at once if `<group>` is given and there is a remotes.`<group>` entry in the configuration file. (See git-config).

When no remote is specified, by default the `origin` remote will be used, unless there’s an upstream branch configured for the current branch.

The names of refs that are fetched, together with the object names they point at, are written to `.git/FETCH_HEAD`. This information may be used by scripts or other git commands, such as git-pull.

## Git pull

### Description
Incorporates changes from a remote repository into the current branch. If the current branch is behind the remote, then by default it will fast-forward the current branch to match the remote. If the current branch and the remote have diverged, the user needs to specify how to reconcile the divergent branches with `--rebase` or `--no-rebase` (or the corresponding configuration option in `pull.rebase`).

More precisely, `git pull` runs `git fetch` with the given parameters and then depending on configuration options or command line flags, will call either `git rebase` or `git merge` to reconcile diverging branches.

`<repository>` should be the name of a remote repository as passed to git-fetch. `<refspec>` can name an arbitrary remote ref (for example, the name of a tag) or even a collection of refs with corresponding remote-tracking branches (e.g., refs/heads/*:refs/remotes/origin/*), but usually it is the name of a branch in the remote repository.

Default values for `<repository>` and `<branch>` are read from the "remote" and "merge" configuration for the current branch as set by git-branch `--track`.

## Git push

### Description
Updates remote refs using local refs, while sending objects necessary to complete the given refs.

You can make interesting things happen to a repository every time you push into it, by setting up hooks there. See documentation for git-receive-pack

When the command line does not specify where to push with the `<repository>` argument, branch.*.remote configuration for the current branch is consulted to determine where to push. If the configuration is missing, it defaults to origin.

When the command line does not specify what to push with `<refspec>...` arguments or `--all`, `--mirror`, `--tags` options, the command finds the default `<refspec>` by consulting `remote.*.push` configuration, and if it is not found, honors `push.default` configuration to decide what to push (See git-config for the meaning of `push.default`).

When neither the command-line nor the configuration specify what to push, the default behavior is used, which corresponds to the `simple` value for `push.default`: the current branch is pushed to the corresponding upstream branch, but as a safety measure, the push is aborted if the upstream branch does not have the same name as the local one.

## Git remote

### Commands

<code1>add</code1></br>
Add a remote named < name> for the repository at < url>. The command `git fetch <name>` can then be used to create and update remote-tracking branches < name>/< branch>.

With `-f` option, `git fetch <name>` is run immediately after the remote information is set up.

With `--tags` option, `git fetch <name>` imports every tag from the remote repository.

With `--no-tags` option, `git fetch <name>` does not import tags from the remote repository.

By default, only tags on fetched branches are imported (see git-fetch).

With `-t <branch>` option, instead of the default glob refspec for the remote to track all branches under the `refs/remotes/<name>/` namespace, a refspec to track only `<branch>` is created. You can give more than one `-t <branch>` to track multiple branches without grabbing all branches.

With `-m <master>` option, a symbolic-ref `refs/remotes/<name>/HEAD` is set up to point at remote’s `<master>` branch. See also the set-head command.

When a fetch mirror is created with `--mirror=fetch`, the refs will not be stored in the refs/remotes/ namespace, but rather everything in refs/ on the remote will be directly mirrored into refs/ in the local repository. This option only makes sense in bare repositories, because a fetch would overwrite any local commits.

When a push mirror is created with `--mirror=push`, then `git push` will always behave as if `--mirror` was passed.

<code1>rename</code1></br>
Rename the remote named < old> to < new>. All remote-tracking branches and configuration settings for the remote are updated.

In case < old> and < new> are the same, and < old> is a file under `$GIT_DIR/remotes` or `$GIT_DIR/branches`, the remote is converted to the configuration file format.

<code1>set-head</code1></br>
Sets or deletes the default branch (i.e. the target of the symbolic-ref `refs/remotes/<name>/HEAD`) for the named remote. Having a default branch for a remote is not required, but allows the name of the remote to be specified in lieu of a specific branch. For example, if the default branch for origin is set to `master`, then `origin` may be specified wherever you would normally specify `origin/master`.

<code1>set-branches</code1></br>
Changes the list of branches tracked by the named remote. This can be used to track a subset of the available remote branches after the initial setup for a remote.

The named branches will be interpreted as if specified with the `-t` option on the `git remote add` command line.

With `--add`, instead of replacing the list of currently tracked branches, adds to that list.

show
Gives some information about the remote < name>.

With `-n` option, the remote heads are not queried first with `git ls-remote <name>`; cached information is used instead.

<code1>prune</code1></br>
Deletes stale references associated with < name>. By default, stale remote-tracking branches under < name> are deleted, but depending on global configuration and the configuration of the remote we might even prune local tags that haven’t been pushed there. Equivalent to `git fetch --prune <name>`, except that no new references will be fetched.

See the PRUNING section of git-fetch for what it’ll prune depending on various configuration.

With `--dry-run` option, report what branches would be pruned, but do not actually prune them.

<code1>update</code1></br>
Fetch updates for remotes or remote groups in the repository as defined by `remotes.<group>`. If neither group nor remote is specified on the command line, the configuration parameter remotes.default will be used; if remotes.default is not defined, all remotes which do not have the configuration parameter `remote.<name>.skipDefaultUpdate` set to true will be updated. (See git-config).

With `--prune` option, run pruning against all the remotes that are updated.
















