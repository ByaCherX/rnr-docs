<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

<h1 style="text-align:center">Git Main Reference </h1>

### Syntax
```git
git [--version] [--help] [-C <path>] [-c <name>=<value>]
    [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
    [-p|--paginate|-P|--no-pager] [--no-replace-objects] [--bare]
    [--git-dir=<path>] [--work-tree=<path>] [--namespace=<name>]
    [--super-prefix=<path>] [--config-env <name>=<envvar>]
    <command> [<args>]
```

### Description
Git is a fast, scalable, distributed revision control system with an unusually rich command set that provides both high-level operations and full access to internals.

After you mastered the basic concepts, you can come back to this page to learn what commands Git offers. You can learn more about individual Git commands with "git help command". gitcli manual page gives you an overview of the command-line command syntax.

### Git Help
#### Description
With no options and no COMMAND or GUIDE given, the synopsis of the git command and a list of the most commonly used Git commands are printed on the standard output.

If the option `--all` or `-a` is given, all available commands are printed on the standard output.

If the option `--guides` or `-g` is given, a list of the Git concept guides is also printed on the standard output.

If a command, or a guide, is given, a manual page for that command or guide is brought up. The man program is used by default for this purpose, but this can be overridden by other options or configuration variables.

If an alias is given, git shows the definition of the alias on standard output. To get the manual page for the aliased command, use `git COMMAND --help`.

Note that `git --help` ... is identical to `git help ...` because the former is internally converted into the latter.

To display the git[1] man page, use `git help git`.

This page can be displayed with git help help or `git help --help`

#### Options

<code1>--all</code1></br>
Prints all the available commands on the standard output. This option overrides any given command or guide name.

<code1>--verbose</code1></br>
When used with --all print description for all recognized commands. This is the default.

<code1>--config</code1></br>
List all available configuration variables. This is a short summary of the list in git-config[1].

<code1>--guides</code1></br>
Prints a list of the Git concept guides on the standard output. This option overrides any given command or guide name.

<code1>--info</code1></br>
Display manual page for the command in the info format. The info program will be used for that purpose.

<code1>--man</code1></br>
Display manual page for the command in the man format. This option may be used to override a value set in the help.format configuration variable.

<code1>--web</code1></br>
Display manual page for the command in the web (HTML) format. A web browser will be used for that purpose.
