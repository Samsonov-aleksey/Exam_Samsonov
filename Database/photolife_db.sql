BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "call" (
	"id"	INTEGER,
	"number"	TEXT,
	"code"	TEXT,
	"doctor_id"	INTEGER,
	"time_rec"	TEXT
);
CREATE TABLE IF NOT EXISTS "doctor" (
	"id"	INTEGER,
	"name"	TEXT,
	"time"	TEXT,
	"specialization"	TEXT
);
COMMIT;
