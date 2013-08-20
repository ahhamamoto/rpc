# Compilar

gcc -o address_book_client address_book_client.c address_book_clnt.c address_book_xdr.c address_book.h

gcc -o address_book_server address_book_server.c address_book_svc.c address_book_xdr.c address_book.h -lmysqlclient

obs.: o último argumento para compilar o servidor é para 'linkar' a lib do MySQL.