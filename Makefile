gcc:
	gcc main.c list.c -o app.o
clean:
	rm -f app.o
run:
	./app.o