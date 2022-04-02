pam_honey.so : src/pam_honey.c
	gcc -shared -o pam_honey.so src/pam_honey.c
clean :
	rm pam_honey.so
