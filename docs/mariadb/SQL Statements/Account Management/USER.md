<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../../source.css">

<h1 style="text-align:center">SQL Statements / Account Management - USER</h1>

## CREATE USER
```sql
CREATE [OR REPLACE] USER [IF NOT EXISTS] 
 user_specification [,user_specification ...] 
  [REQUIRE {NONE | tls_option [[AND] tls_option ...] }]
  [WITH resource_option [resource_option ...] ]
  [lock_option] [password_option] 

user_specification:
  username [authentication_option]

authentication_option:
  IDENTIFIED BY 'password' 
  | IDENTIFIED BY PASSWORD 'password_hash'
  | IDENTIFIED {VIA|WITH} authentication_rule [OR authentication_rule  ...]

authentication_rule:
    authentication_plugin
  | authentication_plugin {USING|AS} 'authentication_string'
  | authentication_plugin {USING|AS} PASSWORD('password')

tls_option:
  SSL 
  | X509
  | CIPHER 'cipher'
  | ISSUER 'issuer'
  | SUBJECT 'subject'

resource_option:
  MAX_QUERIES_PER_HOUR count
  | MAX_UPDATES_PER_HOUR count
  | MAX_CONNECTIONS_PER_HOUR count
  | MAX_USER_CONNECTIONS count
  | MAX_STATEMENT_TIME time

password_option:
  PASSWORD EXPIRE
  | PASSWORD EXPIRE DEFAULT
  | PASSWORD EXPIRE NEVER
  | PASSWORD EXPIRE INTERVAL N DAY

lock_option:
    ACCOUNT LOCK
  | ACCOUNT UNLOCK
}

-- IF NOT EXISTS --
CREATE USER IF NOT EXISTS foo2@test IDENTIFIED BY 'password';
```

<h3 class="h3color">Authentication Options</h3>

The optional ``IDENTIFIED BY`` clause can be used to provide an account with a password. The password should be specified in plain text. It will be hashed by the PASSWORD function prior to being stored in the mysql.user/mysql.global_priv_table table.
```sql
-- IDENTIFIED BY 'password'
CREATE USER foo2@test IDENTIFIED BY 'mariadb';

-- IDENTIFIED BY PASSWORD 'password_hash'
CREATE USER foo2@test IDENTIFIED BY PASSWORD '*54958E764CE10E50764C2EECBB71D01F08549980';

-- IDENTIFIED {VIA|WITH} authentication_plugin
CREATE USER foo2@test IDENTIFIED VIA pam;
```

<h3 class="h3color">TLS Options</h3>
By default, MariaDB transmits data between the server and clients without encrypting it. This is generally acceptable when the server and client run on the same host or in networks where security is guaranteed through other means. However, in cases where the server and client exist on separate networks or they are in a high-risk network, the lack of encryption does introduce security concerns as a malicious actor could potentially eavesdrop on the traffic as it is sent over the network between them.<br/><br/>
To mitigate this concern, MariaDB allows you to encrypt data in transit between the server and clients using the Transport Layer Security (TLS) protocol. TLS was formerly known as Secure Socket Layer (SSL), but strictly speaking the SSL protocol is a predecessor to TLS and, that version of the protocol is now considered insecure. The documentation still uses the term SSL often and for compatibility reasons TLS-related server system and status variables still use the prefix ssl_, but internally, MariaDB only supports its secure successors.<br/><br/>
See [Secure Connections Overview](https://mariadb.com/kb/en/secure-connections-overview/) for more information about how to determine whether your MariaDB server has TLS support.

| Option          | Description |
|-----------------|-------------|
| REQUIRE NONE    | TLS is not required for this account, but can still be used. |
| REQUIRE SSL     | The account must use TLS, but no valid X509 certificate is required. |
| REQUIRE X509    | The account must use TLS and must have a valid X509 certificate. | 
| REQUIRE ISSUER  | The account must use TLS and must have a valid X509 certificate. Also, the Certificate Authority must be the one specified via the string issuer |
| REQUIRE SUBJECT | The account must use TLS and must have a valid X509 certificate. Also, the certificate's Subject must be the one specified via the string subject |
| REQUIRE CIPHER  | The account must use TLS, but no valid X509 certificate is required. Also, the encryption used for the connection must use a specific cipher method specified in the string cipher |

<h3 class="h3color">Resource Limit Options</h3>
It is possible to set per-account limits for certain server resources. The following table shows the values that can be set per account:

| Limit Type               | Description |
|--------------------------|-------------|
| MAX_QUERIES_PER_HOUR     | Number of statements that the account can issue per hour (including updates) |
| MAX_UPDATES_PER_HOUR     | Number of updates (not queries) that the account can issue per hour |
| MAX_CONNECTIONS_PER_HOUR | Number of connections that the account can start per hour |
| MAX_USER_CONNECTIONS     | Number of simultaneous connections that can be accepted from the same account; |
| MAX_STATEMENT_TIME       | Timeout, in seconds, for statements executed by the user. |

<h3 class="h3color">Password Expiry</h3>
Besides automatic password expiry, as determined by ``default_password_lifetime``, password expiry times can be set on an individual user basis, overriding the global setting, for example:

```sql
CREATE USER 'monty'@'localhost' PASSWORD EXPIRE INTERVAL 120 DAY;
```

<h3 class="h3color">Account Locking</h3>
Account locking permits privileged administrators to lock/unlock user accounts. No new client connections will be permitted if an account is locked (existing connections are not affected). For example:

```sql
CREATE USER 'marijn'@'localhost' ACCOUNT LOCK;
```



## RENAME USER
```sql
--Syntax--
RENAME USER old_user TO new_user
    [, old_user TO new_user] ...

--Example--
CREATE USER 'donald', 'mickey';
RENAME USER 'donald' TO 'duck'@'localhost', 'mickey' TO 'mouse'@'localhost';
```
The ``RENAME USER`` statement renames existing MariaDB accounts. To use it, you must have the global ``CREATE USER`` privilege or the ``UPDATE`` privilege for the mysql database. Each account is named using the same format as for the ``CREATE USER`` statement; for example, 'jeffrey'@'localhost'. If you specify only the user name part of the account name, a host name part of '%' is used.













