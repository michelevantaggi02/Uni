[[intro_reti-http-ftp-dns-posta.pdf|fonte]]
# Capitolo 1
## Cos’è Internet
Una infrastruttura di comunicazione per applicazioni distribuite come Web, e-mail, giochi, e-commerce, condivisione di file.

Per poter fornire servizi forniti alle applicazioni: 
Servizio non affidabile senza connessione -> UDP dato che non è detto che arrivi qualche pacchetto si concentra più sulla velocità.

Servizio affidabile orientato alla connessione -> TCP che mi da la sicurezza che il messaggio venga ricevuto.

## Protocollo
>Un protocollo definisce il formato e l’ordine dei messaggi scambiati tra due o più entità in comunicazione, così come le azioni intraprese in fase di trasmissione e/o ricezione di un messaggio o di un altro evento

## Struttura di una rete
Ai confini della rete abbiamo applicazioni e sistemi terminali 

Al centro della rete ci sono i router, la rete delle reti

Le reti, dispositivi fisici sono i collegamenti

per esempio la freccia rappresenta il protocollo TCP che comunica con la macchina.
![[TCP.png|250]]

## TCP
_Obiettivo_: trasferimento dati tra sistemi terminali

_handshaking_: messaggi di preparazione all'invio di dati

*__TCP__* acronimo di Transmission Control Protocol è un servizio orientato alla connessione di Interne

_Servizio_ TCP \[RFC 793] offre:
- ==Trasporto affidabile==, consegna “in ordine” del flusso di byte. In caso di perdita: ACK e ritrasmissioni 
- ==Controllo del flusso== ossia il mittente non sovraccarica il destinatario
- ==Controllo di congestione== in caso che i mittenti rallentano il tasso di invio quando la rete è congestionata

## UDP
Obiettivo: trasferimento dati tra sistemi terminali. Come nel caso precedente! 

UDP  acronimo di User Datagram Protocol \[RFC 768]: 
- senza connessione 
- trasferimento dati non affidabile 
- nessun controllo del flusso 
- nessun controllo di congestione

## Applicativi
Applicazioni che usano **TCP**: HTTP (Web), FTP (trasferimento file), Telnet (login remoto), SMTP (e-mail) 

Applicazioni che usano **UDP**: streaming multimediale, videoconferenze, DNS, telefonia Internet

## Il nucleo della rete
Rete magliata di router che interconnettono i sistemi terminali.

Il quesito fondamentale: come vengono trasferiti i dati attraverso la rete? 
- _commutazione di circuito_: circuito dedicato per l’intera durata della sessione 
- _commutazione di pacchetto_: i messaggi di una sessione utilizzano le risorse su richiesta, e di conseguenza potrebbero dover attendere per accedere a un collegamento

![[Nucleo di rete.png|250]]

Gli indirizzi vengono listati in una tabella di instradamento, in cui vengono organizzati per intervalli. 
Un indirizzo è un una quaterna di numeri che vanno da 0 a 255. 
Gli ultimi due numeri che vengono rappresentati da 16 bit sono riferiti ad una sotto-rete detta ==sub-net==.

Una maschera permette di scegliere quale bit devono essere considerate per l'assegnazione a macchine specifiche

Esistono due tipi di indirizzi pubblici e privati dato che le macchine sono troppe. Il NAT è quello che converte i privati in un pubblico unico che viene condiviso da tutti i privati e le risposte vengono riassegnate alla macchina che le ha fatte.

Per ricevere un indirizzo chiedo in broadcast, non a livello IP(liv 3) ma a livello di link(liv 2), chi è il server dhcp per l'assegnazione dell'indirizzo.
## Commutazione di pacchetto
l flusso di dati punto-punto viene suddiviso in pacchetti 
- I pacchetti degli utenti A e B condividono le risorse di rete 
- Ciascun pacchetto utilizza completamente il canale 
- Le risorse vengono usate a seconda delle necessità

Contesa per le risorse 
- La richiesta di risorse può eccedere il quantitativo disponibile 
- congestione: accodamento dei pacchetti, attesa per l’utilizzo del collegamento 
- store and forward: il commutatore deve ricevere l’intero pacchetto prima di poter cominciare a trasmettere sul collegamento in uscita

## Reti locali
Una LAN collega i sistemi terminali di aziende e università all’edge route
![[LAN.png|200]]
Una rete non è detto che sia per forza connessa a internet

### Accesso wireless
LAN wireless con standard 802.11b (WiFi): 11 Mbps

## Reti da abitazione
![[Reti da abitazione.png|350]]
di solito il router casalingo fa sia da cable modem, router, e punto d'accesso senza fili.

## Cause di ritardo
![[Cause di ritardo.png|350]]
_**Traceroute**_: programma diagnostico che fornisce una misura del ritardo dalla sorgente al router lungo i percorsi Internet punto-punto verso la destinazione. 
- invia tre pacchetti che raggiungeranno il router i sul percorso verso la destinazione
- il router i restituirà i pacchetti al mittente
- il mittente calcola l’intervallo tra trasmissione e risposta

Il time to leave è il tempo massimo che un pacchetto può vivere prima di morire. Se il time to leave è 0 il router dice al mittente che il pacchetto è morto e questo messaggio dice in quale router è morto.
![[Time to leave.png|350]]

## Livelli di protocolli Internet 
7. _applicazione_: di supporto alle applicazioni di rete FTP, SMTP, HTTP 
4. _trasporto_: trasferimento dei messaggi a livello di applicazione tra il modulo client e server di un’applicazione TCP, UDP 
3. _rete_: instradamento dei datagrammi dall’origine al destinatario IP, protocolli di instradamento 
2. _link_ (collegamento): instradamento dei datagrammi attaverso una serie di commutatori di pacchetto PPP, Ethernet 
1. _fisico_: trasferimento dei singoli bit

## Incapsulamento
![[Incapsulamento.png|350]]
L'ipsec si trova tra il layer trasporto e rete
tsl si trova tra i layer applicazione e trasporto

# Capitolo 2 Livello di applicazione
Sono programmi che girano su sistemi terminali diversi e comunicano attraverso la rete.

## Architettura client-server
_server_: l'host sempre attivo ha  un indirizzo IP fisso con le server farm per creare un potente server virtuale 
_client_: comunica con il server, può contattare il server in qualunque momento ha indirizzi IP dinamici. Non comunica direttamente con gli altri client

## P2P
non c’è un server sempre attivo si formano coppie arbitrarie di host (peer) comunicano direttamente tra loro. I peer non devono necessariamente essere sempre attivi, e cambiano indirizzo IP.

## Socket
un processo invia/riceve messaggi a/da la sua _socket_

Un socket è analoga a una porta ma diverso dato che il socket è un complesso di informazioni. 
Un processo che vuole inviare un messaggio, lo fa uscire dalla propria “porta” (socket). 
Il processo presuppone l’esistenza di un’infrastruttura esterna che trasporterà il messaggio attraverso la rete fino alla “porta” del processo di destinazione
![[Socket.png|250]]
Come fa il TCP a sapere a quale socket mandare il pacchetto? Utilizzando il numero di porta e IP insieme non basta mai uno solo dei due.

## Web e HTTP(hypertext transfer protocol)
Terminologia 
- Una pagina web è costituita da oggetti
- Un oggetto può essere un file HTML, un’immagine JPEG, Java, un file audio, … 
- Una pagina web è formata da un file base HTML che include diversi oggetti referenziati 
- Ogni oggetto è referenziato da un URL

Il protocollo `HTTP` si basa su un modello modello client/server 
- _client_: il browser che richiede, riceve, “visualizza” gli oggetti del Web. Richiede da una porta a caso e si connette sull'80.
- _server_: il server web invia oggetti in risposta a una richiesta. Il server fa il contrario.

### Connessioni
Connessioni ==non persistenti==
- Almeno un oggetto viene trasmesso su una connessione TCP 
- HTTP/1.0 usa connessioni non persistenti

Connessioni ==persistenti==
- Più oggetti possono essere trasmessi su una singola connessione TCP tra client e server
- HTTP/1.1 usa connessioni persistenti nella modalità di default

Al posto di fare vari _hand-shake_ ne facciamo solo uno e poi vengono mandati gli oggetti.
![[Connessioni non persistente.png|350]]
A sinistra si fa per ogni blocco nero(oggetto) un hand shake mentre a sinistra solo una volta.


## Messaggi HTTP
### Richiesta
![[Messaggi HTTP.png|450]]
il messaggio HTTP è a livello applicativo. Questo messaggio è il body del messaggio del protocollo TCP senza il suo header. Che a sua volta è il body della richiesta IP

![[Forma generale HTTP.png|350]]
### Risposta
![[Risposta HTTP.png|350]]
## Tipi di metodi
`HEAD` chiede al server di escludere l’oggetto richiesto dalla risposta. `GET`, `POST`, `PUT` include il file nel corpo dell’entità e lo invia al percorso specificato nel campo, `URL`, `DELETE` cancella il file specificato nel campo URL.

## HTTP lato client
`telnet cis.poly.edu 80` mi collego ad un server non per forza un sito.

`GET /~ross/ HTTP/1.1`
`Host: cis.poly.edu`
Dato che posso avere più domini su un server quindi devo specificare il dominio

## Cookie
![[Cookie.png]]
Cosa possono contenere i cookie: 
- autorizzazione
- carta per acquisti 
- raccomandazioni 
- stato della sessione dell’utente (e-mail)

## Cache
Soddisfare la richiesta del client senza coinvolgere il server d’origine per esempio facendo richieste ad un proxy salvando pagine statiche.

_cache_: specifica la data della copia dell’oggetto nella richiesta 
`HTTP If-modified-since: <data>`
_server_: la risposta non contiene l’oggetto se la copia nella cache è aggiornata: `HTTP/1.0 304 Not Modified`
