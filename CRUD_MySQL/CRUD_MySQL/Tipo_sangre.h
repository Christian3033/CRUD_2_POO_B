#include <mysql.h>
#include <iostream>
#include <string>
#include "Conexion.h"
#include "Estudiantes.h"

using namespace std;

class Tipo_sangre : public Estudiantes {
private:
    int id = 0;

public:
    // Constructor sin parámetros (que llama al constructor predeterminado de Estudiantes)
    Tipo_sangre() : Estudiantes() {}

    // Constructor con parámetros
    Tipo_sangre(string cod, string nom, string ape, string dir, int tel, string fn, int i)
        : Estudiantes(cod, nom, ape, dir, tel, fn), id(i) {}

    // Métodos set (modificar)
    void setId(int i) { id = i; }
    void setCodigo(string cod) { codigo = cod; }
    void setNombres(string nom) { nombres = nom; }
    void setApellidos(string ape) { apellidos = ape; }
    void setDireccion(string dir) { direccion = dir; }
    void setTelefono(int tel) { telefono = tel; }
    void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }

    // Métodos get (mostrar)
    int getId() { return id; }
    string getCodigo() { return codigo; }
    string getNombres() { return nombres; }
    string getApellidos() { return apellidos; }
    string getDireccion() { return direccion; }
    int getTelefono() { return telefono; }
    string getFecha_Nacimiento() { return fecha_nacimiento; }

    // Método para borrar
    void borrar() {
        int q_estado;
        Conexion cn = Conexion();

        cn.abrir_conexion();
        string ii = to_string(id);
        if (cn.getConectar()) {
            string borrar = "DELETE FROM estudiantes WHERE id_estudiante = " + ii;
            const char* i = borrar.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Eliminación Exitosa ..." << endl;
            }
            else {
                cout << " xxx Error al Eliminar  xxx: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << " xxx Error en la Conexión xxxx" << endl;
        }
        cn.cerrar_conexion();
    }

    // Método para actualizar
    void actualizar() {
        int q_estado;
        Conexion cn = Conexion();

        cn.abrir_conexion();
        string t = to_string(telefono);
        string ii = to_string(id);
        if (cn.getConectar()) {
            string actualizar = "UPDATE estudiantes SET codigo = '" + codigo + "', nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = " + t + ", fecha_nacimiento = '" + fecha_nacimiento + "' WHERE id_estudiante = " + ii;
            const char* i = actualizar.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Actualización Exitosa ..." << endl;
            }
            else {
                cout << " xxx Error al Actualizar  xxx: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << " xxx Error en la Conexión xxxx" << endl;
        }
        cn.cerrar_conexion();
    }

    // Método para crear
    void crear() {
        int q_estado;
        Conexion cn = Conexion();

        cn.abrir_conexion();
        string t = to_string(telefono);
        if (cn.getConectar()) {
            string insertar = "INSERT INTO estudiantes (codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento) VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "')";
            const char* i = insertar.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Ingreso Exitoso ..." << endl;
            }
            else {
                cout << " xxx Error al Ingresar  xxx: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << " xxx Error en la Conexión xxxx" << endl;
        }
        cn.cerrar_conexion();
    }

    // Método para leer
    void leer() {
        int q_estado;
        Conexion cn = Conexion();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;

        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "------------ Datos de Estudiantes ------------" << endl;
            string consulta = "SELECT * FROM estudiantes";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while ((fila = mysql_fetch_row(resultado))) {
                    cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << endl;
                }
            }
            else {
                cout << " xxx Error al Consultar  xxx: " << mysql_error(cn.getConectar()) << endl;
            }
        }
        else {
            cout << " xxx Error en la Conexión xxxx" << endl;
        }
        cn.cerrar_conexion();
    }
};

