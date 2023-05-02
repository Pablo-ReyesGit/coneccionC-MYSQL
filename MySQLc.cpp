#include <iostream>
#include<mysql.h>

using namespace std;
int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "empres@123", "db_empresa", 3306, NULL, 0);
    if (conectar) {
        cout << "coneccion exitosa" << endl;
    }
    else {
        cout << "error en la coneccion" << endl;
    }

    system("pause");
    return 0;
}
