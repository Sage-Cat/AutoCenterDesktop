Table: customer|
CREATE TABLE IF NOT EXISTS customer (
    id            INTEGER PRIMARY KEY ON CONFLICT REPLACE AUTOINCREMENT,
    name TEXT,
    iban          TEXT,
    bank          TEXT,
    edrpoy        TEXT,
    ipn           TEXT,
    address       TEXT,
    number        TEXT,
    email         TEXT
);

|Table: seller|
CREATE TABLE IF NOT EXISTS seller (
    id          INTEGER PRIMARY KEY ON CONFLICT REPLACE AUTOINCREMENT,
    name TEXT,
    iban        TEXT,
    bank        REAL,
    edrpoy      TEXT,
    ipn         TEXT,
    address     TEXT
);

|Table: user|
CREATE TABLE IF NOT EXISTS user (
    id        INTEGER PRIMARY KEY ON CONFLICT REPLACE AUTOINCREMENT,
    name TEXT,
    ipn       TEXT,
    number    TEXT,
    email     TEXT,
    password  TEXT,
    isAdmin   BOOLEAN
);

|Table: product|
CREATE TABLE IF NOT EXISTS product (
    id           INTEGER PRIMARY KEY AUTOINCREMENT,
    amount         TEXT    UNIQUE ON CONFLICT REPLACE,
    code      TEXT,
    catalog        TEXT,
    tnved TEXT,
    name         TEXT,
    unit         TEXT,
    price         FLOAT
);

|Table: car|
CREATE TABLE IF NOT EXISTS car (
    id          INTEGER PRIMARY KEY AUTOINCREMENT,
    name    TEXT,
    vin         TEXT    NOT NULL,
    customer_id INTEGER REFERENCES customer (ID) ON DELETE CASCADE
);

|Table: user_log|
CREATE TABLE IF NOT EXISTS user_log (
    ID       INTEGER  PRIMARY KEY AUTOINCREMENT,
    DateTime DATETIME DEFAULT (datetime('now') ),
    Message  TEXT,
    ID_User  INTEGER  REFERENCES user (ID) ON DELETE CASCADE
);

|Table: list|
CREATE TABLE IF NOT EXISTS list (
    id          INTEGER  PRIMARY KEY AUTOINCREMENT,
    datetime    DATETIME DEFAULT (datetime('now', 'localtime') )
                         NOT NULL,
    number  INTEGER,
    type    TEXT,
    customer_id INTEGER  REFERENCES customer (ID) ON DELETE CASCADE,
    seller_id   INTEGER  REFERENCES seller (ID) ON DELETE CASCADE
);


|Table: record|
CREATE TABLE IF NOT EXISTS record (
    id         INTEGER PRIMARY KEY AUTOINCREMENT,
    count      INTEGER,
    price      DOUBLE,
    product_id INTEGER REFERENCES product (ID) ON DELETE CASCADE,
    list_id    INTEGER REFERENCES list (ID)
);


|View: list_view|
CREATE VIEW list_view AS
    SELECT list.id,
           list.datetime,
           list.number,
           list.type,
           customer.name,
           seller.name
      FROM list
           INNER JOIN
           customer ON list.customer_id = customer.id
           INNER JOIN
           seller ON list.seller_id = seller.id;
