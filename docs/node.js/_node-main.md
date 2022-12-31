<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<p align="center"><img alt="node.js" src="../media/nodejs.svg" width="320"/></p>

<h1 style="text-align:left;">Node.js</h1>
<p style="text-align:right">Alpha</p>

--------------------------------------------------------------------------------

<h2 align="center">About this documentation</h2>
Welcome to the official-rds API reference documentation for Node.js!

## Release Types
* <rtype1>**Current**</rtype1></br> Under active development. Code for the Current release is in the
  branch for its major version number (for example,
  [`v15.x`](https://github.com/ByaCherX/node.js-rds/tree/v15.x)). Node.js releases a new
  major version every 6 months, allowing for breaking changes. This happens in
  April and October every year. Releases appearing each October have a support
  life of 8 months. Releases appearing each April convert to LTS (see below)
  each October.
* <rtype2>**LTS**</rtype2></br> Releases that receive Long Term Support, with a focus on stability
  and security. Every even-numbered major version will become an LTS release.
  LTS releases receive 12 months of _Active LTS_ support and a further 18 months
  of _Maintenance_. LTS release lines have alphabetically-ordered code names,
  beginning with v4 Argon. There are no breaking changes or feature additions,
  except in some special circumstances.
* <rtype3>**Nightly**</rtype3></br> Code from the Current branch built every 24-hours when there are
  changes. Use with caution.

## Stability index
Throughout the documentation are indications of a section's stability. Some APIs are so proven and so relied upon that they are unlikely to ever change at all. Others are brand new and experimental, or known to be hazardous.

The stability indices are as follows:

<stability0>**Stability: 0**</stability0> - Deprecated. The feature may emit warnings. Backward compatibility is not guaranteed.

<stability1>**Stability: 1**</stability1> - Experimental. The feature is not subject to Semantic Versioning rules. Non-backward compatible changes or removal may occur in any future release. Use of the feature is not recommended in production environments.

<stability2>**Stability: 2**</stability2> - Stable. Compatibility with the npm ecosystem is a high priority.

<stability3>**Stability: 3**</stability3> - Legacy. The feature is no longer recommended for use. While it likely will not be removed, and is still covered by semantic-versioning guarantees, use of the feature should be avoided.

Use caution when making use of Experimental features, particularly within modules. Users may not be aware that experimental features are being used. Bugs or behavior changes may surprise users when Experimental API modifications occur. To avoid surprises, use of an Experimental feature may need a command-line flag. Experimental features may also emit a warning.

Stability overview

| API                                 | Stability        |
|-------------------------------------|------------------|
| assert                              | (2) Stable       |
| async_hooks                         | (1) Experimental |
| asynchronous_context_tracking       | (2) Stable       |
| buffer                              | (2) Stable       |
| child_process                       | (2) Stable       |
| cluster                             | (2) Stable       |
| console                             | (2) Stable       |
| crypto                              | (2) Stable       |
| dgram                               | (2) Stable       |
| diagnostics_channel                 | (1) Experimental |
| dns                                 | (2) Stable       |
| domain                              | (0) Deprecated   |
| fs                                  | (2) Stable       |
| http                                | (2) Stable       |
| http/2                              | (2) Stable       |
| https                               | (2) Stable       |
| inspector                           | (2) Stable       |
| module                              | (2) Stable       |
| os                                  | (2) Stable       |
| path                                | (2) Stable       |
| performance_measurement_apis        | (2) Stable       |
| punycode                            | (0) Deprecated   |
| querystring                         | (3) Legacy       |
| readline                            | (2) Stable       |
| repl                                | (2) Stable       |
| stream                              | (2) Stable       |
| string_decoder                      | (2) Stable       |
| timers                              | (2) Stable       |
| tls_(ssl)                           | (2) Stable       |
| trace_events                        | (1) Experimental |
| tty                                 | (2) Stable       |
| url                                 | (2) Stable       |
| util                                | (2) Stable       |
| vm                                  | (2) Stable       |
| web_crypto_api                      | (1) Experimental |
| web_streams_api                     | (1) Experimental |
| webassembly_system_interface_(wasi) | (1) Experimental |
| worker_threads                      | (2) Stable       |
| zlib                                | (2) Stable       |

## Status Project

<h2 align="center">Node.js Document Libraries <i class="bi bi-journals"></i></h2>











