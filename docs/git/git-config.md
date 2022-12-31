<link rel="stylesheet" href="../source.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">

<h1 style="text-align:center">Git - Config</h1>

### Syntax
```git
git config [<file-option>] [--type=<type>] [--fixed-value] [--show-origin] [--show-scope] [-z|--null] name [value [value-pattern]]
```

## Description
A list of all available configuration variables can be obtained using the <code1>git help --config</code1> command.

## Options
<code1>--replace-all</code1></br>
Default behavior is to replace at most one line. This replaces all lines matching the key (and optionally the `value-pattern`).

<code1>--add</code1></br>
Adds a new line to the option without altering any existing values. This is the same as providing ^$ as the `value-pattern` in `--replace-all`.

<code1>--get</code1></br>
Get the value for a given key (optionally filtered by a regex matching the value). Returns error code 1 if the key was not found and the last value if multiple key values were found.

<code1>--get-all</code1></br>
Like get, but returns all values for a multi-valued key.

<code1>--get-regexp</code1></br>
Like --get-all, but interprets the name as a regular expression and writes out the key names. Regular expression matching is currently case-sensitive and done against a canonicalized version of the key in which section and variable names are lowercased, but subsection names are not.

<code1>--get-urlmatch name URL</code1></br>
When given a two-part name section.key, the value for section.`< url>`.key whose `< url>` part matches the best to the given URL is returned (if no such key exists, the value for section.key is used as a fallback). When given just the section as name, do so for all the keys in the section and list them. Returns error code 1 if no value is found.

<code1>--global</code1></br>
For writing options: write to global `~/.gitconfig` file rather than the repository `.git/config`, write to `$XDG_CONFIG_HOME/git/config` file if this file exists and the `~/.gitconfig` file doesn’t.

For reading options: read only from global `~/.gitconfig` and from `$XDG_CONFIG_HOME/git/config` rather than from all available files.

<code1>--system</code1></br>
For writing options: write to system-wide `$(prefix)/etc/gitconfig` rather than the repository .git/config.

For reading options: read only from system-wide `$(prefix)/etc/gitconfig` rather than from all available files.

<code1>--local</code1></br>
For writing options: write to the repository `.git/config file`. This is the default behavior.

For reading options: read only from the repository `.git/config` rather than from all available files.

<code1>--worktree</code1></br>
Similar to `--local` except that `.git/config.worktree` is read from or written to if `extensions.worktreeConfig` is present. If not it’s the same as `--local`.

<code1>--blob blob</code1></br>
Similar to --file but use the given blob instead of a file. E.g. you can use master:.gitmodules to read values from the file .gitmodules in the master branch. See "SPECIFYING REVISIONS" section in gitrevisions[7] for a more complete list of ways to spell blob names.

<code1>--remove-section</code1></br>
Remove the given section from the configuration file.

<code1>--rename-section</code1></br>
Rename the given section to a new name.

<code1>--unset</code1></br>
Remove the line matching the key from config file.

<code1>--unset-all</code1></br>
Remove all lines matching the key from config file.

<code1>--list</code1></br>
List all variables set in config file, along with their values.

<code1>--fixed-value</code1></br>
When used with the `value-pattern` argument, treat `value-pattern` as an exact string instead of a regular expression. This will restrict the name/value pairs that are matched to only those where the value is exactly equal to the `value-pattern`.

<code1>--type < type></code1></br>
git config will ensure that any input or output is valid under the given type constraint(s), and will canonicalize outgoing values in `<type>`'s canonical form.

<code1>--edit</code1></br>
Opens an editor to modify the specified config file; either --system, --global, or repository (default).

## Values
Values of many variables are treated as a simple string, but there are variables that take values of specific types and there are rules as to how to spell them.

**boolean**</br>
When a variable is said to take a boolean value, many synonyms are accepted for true and false; these are all case-insensitive.

- **true**</br>
Boolean true literals are yes, on, true, and 1. Also, a variable defined without = `<value>` is taken as true.

- **false**</br>
Boolean false literals are no, off, false, 0 and the empty string.</br>
 When converting a value to its canonical form using the --type=bool type specifier, git config will ensure that the output is "true" or "false" (spelled in lowercase).

**integer**</br>
The value for many variables that specify various sizes can be suffixed with k, M,…​ to mean "scale the number by 1024", "by 1024x1024", etc.

**color**</br>
The value for a variable that takes a color is a list of colors (at most two, one for foreground and one for background) and attributes (as many as you want), separated by spaces.

The basic colors accepted are normal, black, red, green, yellow, blue, magenta, cyan and white. The first color given is the foreground; the second is the background. All the basic colors except normal have a bright variant that can be specified by prefixing the color with bright, like brightred.

Colors may also be given as numbers between 0 and 255; these use ANSI 256-color mode (but note that not all terminals may support this). If your terminal supports it, you may also specify 24-bit RGB values as hex, like #ff0ab3.

The accepted attributes are bold, dim, ul, blink, reverse, italic, and strike (for crossed-out or "strikethrough" letters). The position of any attributes with respect to the colors (before, after, or in between), doesn’t matter. Specific attributes may be turned off by prefixing them with no or no- (e.g., noreverse, no-ul, etc).

An empty color string produces no color effect at all. This can be used to avoid coloring specific elements without disabling color entirely.

For git’s pre-defined color slots, the attributes are meant to be reset at the beginning of each item in the colored output. So setting color.decorate.branch to black will paint that branch name in a plain black, even if the previous thing on the same output line (e.g. opening parenthesis before the list of branch names in log --decorate output) is set to be painted with bold or some other attribute. However, custom log formats may do more complicated and layered coloring, and the negated forms may be useful there.

**pathname**</br>
A variable that takes a pathname value can be given a string that begins with "~/" or "~user/", and the usual tilde expansion happens to such a string: ~/ is expanded to the value of $HOME, and ~user/ to the specified user’s home directory.

## Variables
> [!NOTE]
> Note that this list is non-comprehensive and not necessarily complete. For command-specific variables, you will find a more detailed description in the appropriate manual page.

Other git-related tools may and do use their own variables. When inventing new variables for use in your own tool, make sure their names do not conflict with those that are used by Git itself and other popular tools, and describe them in your documentation.


























