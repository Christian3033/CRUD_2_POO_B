#include<mysql.h>
#include <iostream>
using namespace std; 

int main(){

    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_estudiantes_1", "Empres@123", "db_estudiantes", 3306, NULL, 0);
    if (conectar) {
        cout << "conexion exitosa..."<<endl;

    }
    else {

        cout << "Error en la conexion...";

    }

 
    
    system("Pause");
    return 0;
}

