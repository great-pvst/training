#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // file control
#include <string.h> // process char 
#include <unistd.h> // variable types
#include <termios.h> // serial port
#include "/usr/include/mysql/mysql.h"
int Fd; // to map port
struct termios MaConf; // port config

void main () {
        MYSQL *conn;
        char requete[80];
	conn = mysql_init(NULL);
        mysql_real_connect(conn,"db_server","db_user","db_passwd","db_name",0,NULL,0);
        if (mysql_real_connect) { printf("Je suis connecté à la BDD"); }

        // init port ttyUSB0 19200 8 n 1
        Fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
        tcgetattr (Fd, &MaConf);
        MaConf.c_cflag = B19200 | CS8 | CLOCAL | CREAD;
        MaConf.c_iflag = IGNPAR;
        MaConf.c_oflag = 0;
        MaConf.c_lflag = 0;
        tcflush(Fd, TCIFLUSH);
        tcsetattr(Fd, TCSANOW, &MaConf); //Modif config actuelle



        char tab[70] = {0};
        char Temp[5];
        char Volt[5];
        char Pui[6];
        for (int i = 0; i < 70; i++) {
                read(Fd, &tab[i], 1);
                printf("%c", tab[i]);
        }
        int j = 0;
        while ( tab[j] != '=' ) {
                j++;
        }
        j++;
        printf("\nT : ");
        for (int i = 0; i < 4; i++){
                Temp[i] = tab[j];
                printf("%c", Temp[i]);
                j++;
        }
        Temp[4] = 0;

        int Val1 = Temp[0] - '0';
        int Val2 = Temp[1] - '0';
        Val1 *= 10;
        int Val3 = Val1 + Val2;
        printf("\nTempérature: %d\n", Val3);
        if (Val3 > 24) {
                system("$HOME/script_appel.sh"); //to whistle a softphone. This is an alarm system simulation.
        }


        printf("\nV : ");
        for (int i = 0; i < 4; i++){
                Volt[i] = tab[j];
                printf("%c", Volt[i]);
                j++;
        }
        Volt[4] = 0;
        printf("\nP : ");
        for (int i = 0; i < 5; i++){
                Pui[i] = tab[j];
                printf("%c", Pui[i]);
                j++;
        }
        Pui[5] = 0;
        printf("\n");

        strcpy(requete,"INSERT INTO Mesures VALUES (");
        strcat(requete, Temp); strcat(requete,",");
        strcat(requete, Volt); strcat(requete,",");
        strcat(requete, Pui); strcat(requete,")");
        printf("\nma requete = %s \n", requete);
        mysql_query(conn, requete);
        printf("Ajout valeurs dans BD\n");
        mysql_close(conn);

        close(Fd);
}
