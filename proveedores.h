#pragma once
#include<iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h"
using namespace std;
class proveedores
{
private:
	string proveedor, nit, direccion;
	int telefono;
public:
	proveedores() {
	}
	proveedores(string pro, string n, string dir, int tel) {
		proveedor = pro;
		nit = n;
		direccion = dir;
		telefono = tel;
	}
	void setProveedor(string pro) { proveedor = pro; }
	void setNit(string n) { nit = n; }
	void setDireccion(string dir){ direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }

	string getProveedor() { return proveedor; }
	string getNit() { return nit; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	
	int q_estado;
	void crear() {
		ConexionBD cnp = ConexionBD();
		cnp.abrir_conexion();
		if (cnp.setConectar()) {
			string t = to_string(telefono);
			string insert = "insert into(id_proveedor,proveedor,nit,direccion,telefono,)VALUES('" + proveedor + "','" + nit + "','" + direccion + "','" + t + "')";
			const char* j = insert.c_str();
			q_estado = mysql_query(cnp.setConectar(), j);
			if (q_estado) {
				cout << "ingreso exitoso" << endl;
			}
			else {
				cout << "error al ingresar" << endl;
			}
		}
		else {
			cout << "conexion fallida" << endl;
		}
		cnp.cerrar_conexion();
	}
	void Leer() {
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.setConectar()) {
			string consulta = "select * from proveedores;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.setConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.setConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << endl;
				}
			}
			else {
				cout << "error al consultar" << endl;
			}
		}
		else {
			cout << "conexion fallida" << endl;
		}
		cn.cerrar_conexion();
	}
	void actaulizar() {
		int ID;
		ConexionBD cnp = ConexionBD();
		cnp.abrir_conexion();
		if (cnp.setConectar()) {
			cout << "ingrese el ID a actualizar" << endl;
			cin >> ID;
			string t = to_string(telefono);
			string id = to_string(ID);
			string update = "update set 'proveedor'='" + proveedor + "', 'nit'='" + nit + "'direccion'='" + direccion + "telefon'='" + t + "where 'id_proveedor' = " + id +";";
			const char* k = update.c_str();
			q_estado = mysql_query(cnp.setConectar(), k);
			if (q_estado) {
				cout << "ingreso exitoso" << endl;
			}
			else {
				cout << "error al ingresar" << endl;
			}
		}
		else {
			cout << "conexion fallida" << endl;
		}
		cnp.cerrar_conexion();
	}
	void borrar() {
		int ID;
		ConexionBD cnp = ConexionBD();
		cnp.abrir_conexion();
		if (cnp.setConectar()) {
			cout << "ingrese el ID a borrar" << endl;
			cin >> ID;
			string id = to_string(ID);
			string deleted = "DELETE FROM proveedores WHERE <" + id + ">; ";
			const char* k = deleted.c_str();
			q_estado = mysql_query(cnp.setConectar(), k);
			if (q_estado) {
				cout << "ingreso exitoso" << endl;
			}
			else {
				cout << "error al ingresar" << endl;
			}
		}
		else {
			cout << "conexion fallida" << endl;
		}
		cnp.cerrar_conexion();
	}
};

