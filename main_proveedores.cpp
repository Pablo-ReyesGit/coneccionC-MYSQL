#include<iostream>
#include"proveedores.h"
using namespace std;
int main() {
    string  proveedor, nit, direccion;
    int telefono = 0;

    cout << "ingrese nit:" << endl;
    getline(cin, proveedor);
    cout << "ingrese nombres:" << endl;
    getline(cin, nit);
    cout << "ingrese apellidos:" << endl;
    getline(cin, direccion);
    cout << "ingrese telefono:" << endl;
    cin >> telefono;
    proveedores p = proveedores(proveedor, nit, direccion, telefono);
    p.crear();
    p.Leer();
    p.actaulizar();
    p.borrar();
    system("pause");
    return 0;
}