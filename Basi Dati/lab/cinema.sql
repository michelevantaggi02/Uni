DROP SCHEMA IF EXISTS cinema CASCADE;

CREATE SCHEMA cinema;
SET SEARCH_PATH cinema;

CREATE TABLE persona(
	id_persona int,
	nome varchar,
	cognome varchar
);

CREATE TABLE film(
	id_film int,
	id_regista int,
	titolo varchar,
	genere varchar,
	anno year
);
