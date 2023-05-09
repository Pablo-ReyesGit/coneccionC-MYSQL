#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "persona.h"
#include "ConexionBD.h"
class cliente : persona
{
private: string nit;

public:
	cliente() {
	}
	cliente(string nom, string ape, string dic, string fn, int tel, string n) : persona (nom, ape, dic, tel, fn) {
		nit = n;
	}

	void setNit(string n) { nit = n; }
	void setNnombres(string nom) { nombre = nom; }
	void setApellidos(string ape) { apellido = ape; }
	void setDireccion(string dic) { direccion = dic; }
	void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }
	void setTelefono(int tel) { telefono = tel; }

	string getNit() { return nit; }
	string getNombres() { return nombre; }
	string getApellidos() { return apellido; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.setConectar()) {
			string t = to_string(telefono);
			string insert = "select * from clientes(id_clientes,nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES('" + nit + "','" + nombre + "','" + apellido + "','" + direccion + "','" + t + "','" + fecha_nacimiento + "')";
			const char* j = insert.c_str();
			q_estado = mysql_query(cn.setConectar(), j);
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
		cn.cerrar_conexion();
	}
	void Leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.setConectar()) {
			string consulta = "SELECT * FROM clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.setConectar(), c);
			if (q_estado) {
				resultado = mysql_store_result(cn.setConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2]<<"," << fila[3]<<"," << fila[4]<<"," << fila[5]<<"," << fila[6]<< endl;
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

};

