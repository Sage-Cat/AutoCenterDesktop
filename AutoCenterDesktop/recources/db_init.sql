Table: customer|
CREATE TABLE IF NOT EXISTS customer (
    id      INTEGER PRIMARY KEY ON CONFLICT REPLACE AUTOINCREMENT,
    name    TEXT,
    iban    TEXT,
    bank    TEXT,
    edrpoy  TEXT,
    ipn     TEXT,
    address TEXT,
    number  TEXT,
    email   TEXT
);


|Table: seller|
CREATE TABLE IF NOT EXISTS seller (
    id         INTEGER PRIMARY KEY ON CONFLICT REPLACE AUTOINCREMENT,
    name       TEXT,
    iban       TEXT,
    bank       REAL,
    edrpoy     TEXT,
    ipn        TEXT,
    address    TEXT,
    number     TEXT,
    isPdvPayer BOOLEAN
);

|Table: user|
CREATE TABLE IF NOT EXISTS user (
    id       INTEGER PRIMARY KEY ON CONFLICT REPLACE AUTOINCREMENT,
    name     TEXT,
    ipn      TEXT,
    number   TEXT,
    email    TEXT,
    password TEXT,
    isAdmin  BOOLEAN
);

|Table: product|
CREATE TABLE IF NOT EXISTS product (
    id             INTEGER PRIMARY KEY AUTOINCREMENT,
    amount         TEXT    DEFAULT (0),
    code           TEXT    UNIQUE ON CONFLICT REPLACE,
    catalog        TEXT,
    tnved          TEXT,
    name           TEXT,
    unit           TEXT,
    purchase_price FLOAT
);

|Table: car|
CREATE TABLE IF NOT EXISTS car (
    id          INTEGER PRIMARY KEY AUTOINCREMENT,
    name        TEXT,
    vin         TEXT,
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
    number      INTEGER,
    type        TEXT,
    customer_id INTEGER  REFERENCES customer (id) ON DELETE CASCADE,
    seller_id   INTEGER  REFERENCES seller (id) ON DELETE CASCADE
);


|Table: record|
CREATE TABLE IF NOT EXISTS record (
    id         INTEGER  PRIMARY KEY AUTOINCREMENT,
    count      INTEGER,
    product_id INTEGER  REFERENCES product (ID) ON DELETE CASCADE,
    list_id    INTEGER  REFERENCES list (id) ON DELETE CASCADE,
    price      FLOAT,
    sum        [FLOAT ] GENERATED ALWAYS AS (count * price)
);

|View: customer_view|
CREATE VIEW IF NOT EXISTS customer_view AS
    SELECT customer.id,
           customer.name,
           COUNT(car.id) AS car_count,
           customer.address,
           customer.number,
           customer.email,
           customer.iban,
           customer.bank,
           customer.edrpoy,
           customer.ipn
      FROM customer
           LEFT JOIN
           car ON customer.id = car.customer_id
     GROUP BY customer.id;


|View: info_customer|
CREATE VIEW IF NOT EXISTS info_customer AS
    SELECT list.customer_id AS id,
           list.datetime,
           product.code,
           product.catalog,
           product.tnved,
           product.name,
           record.price,
           record.count,
           product.unit,
           record.sum
      FROM record
           LEFT JOIN
           product ON record.product_id == product.id
           LEFT JOIN
           list ON record.list_id == list.id
     ORDER BY list.datetime;


|View: list_view|
CREATE VIEW IF NOT EXISTS list_view AS
    SELECT list.id,
           customer.ipn,
           list.datetime,
           list.number,
           list.type,
           customer.name,
           seller.name
      FROM list
           LEFT JOIN
           customer ON list.customer_id = customer.id
           LEFT JOIN
           seller ON list.seller_id = seller.id;

|View: record_view|
CREATE VIEW IF NOT EXISTS record_view AS
    SELECT record.id,
           record.list_id,
           product.code,
           product.catalog,
           product.tnved,
           product.name,
           record.count,
           product.unit,
           record.price,
           record.sum
      FROM record
           LEFT JOIN
           product ON record.product_id == product.id;

