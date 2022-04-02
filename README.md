# pam_honey.so

pam_honey.so is a PAM module that denies any login attempt and logs the credentials in a text file. It is intended to set up a honeypot.

## Setup
 1. Install build dependencies (Debian: `gcc make libpam0g-dev`, CentOS: `gcc make pam-devel`)
 2. `make`
 3. Copy `pam_honey.so` to the appropriate location (Debian: `/lib/security/pam_honey.so` or CentOS: `/lib64/security/pam_honey.so`)
 4. Configure PAM to use `pam_honey.so`:
    ```
    auth       required     pam_honey.so /root/honey.txt
    ```
 5. Configure ssh to allow password auth
 6. `tail -f /root/honey.txt`
