#include <iostream>
#include "cliente.h"
//#include<mysql.h>

//using namespace std;
//int q_estado;
int main()
{
    string nit, nombre, apellido, direccion, fecha_nacimineto;
    int telefono = 0;
    
    cout << "ingrese nit:" << endl;
    getline(cin, nit);
    cout << "ingrese nombres:" << endl;
    getline(cin, nombre);
    cout << "ingrese apellidos:" << endl;
    getline(cin, apellido);
    cout << "ingrese direccion:" << endl;
    getline(cin, direccion);
    cout << "ingrese telefono:" << endl;
    cin >> telefono;
    cin.ignore();
    cout << "ingrese fecha de nacimiento:" << endl;
    cin >> fecha_nacimineto;
    
    cliente c = cliente(nit, nombre, apellido, direccion, telefono, fecha_nacimineto);
    c.crear();
    c.Leer();
    
    
   /* MYSQL* conectar;
    MYSQL_ROW fila; 
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "empres@123", "db_empresa", 3306, NULL, 0);
    if (conectar) {
        /*cout << "coneccion exitosa" << endl;
        string puesto;
        cout << "ingrese puesto" << endl;
        cin >> puesto;
        string insert = "insert into puestos(puesto) values('" + puesto + "')";
        const char* j = insert.c_str();
        q_estado = mysql_query(conectar, j);
        if (q_estado) {
            cout << "ingreso exitoso" << endl;
        }
        else {
            cout << "error al ingresar" << endl;
        }
        
        string consulta = "select * from puestos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << "," << fila[1] << endl; 
            }
        }
        else {
            cout << "error al consultar" << endl;
        }
    }
    else {
        cout << "error en la coneccion" << endl;
    }
    */
    system("pause");
    return 0;
}
