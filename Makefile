pam_honey.so : src/pam_honey.c
	gcc -fPIC -DPIC -shared -rdynamic -o pam_honey.so src/pam_honey.c
clean :
	rm pam_honey.so
