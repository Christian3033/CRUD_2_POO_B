#include "Tipo_sangre.h"

int main() {
    // Crear un objeto de Tipo_sangre
    Tipo_sangre ts("1234", "Juan", "Perez", "Calle Falsa 123", 123456789, "1990-01-01", 1);

    // Probar la creaci�n de un registro
    ts.crear();

    // Probar la lectura de registros
    ts.leer();

    // Probar la actualizaci�n de un registro
    ts.setNombres("Juanito");
    ts.setCodigo("4321");
    ts.actualizar();

    // Probar la eliminaci�n de un registro
    ts.borrar();

    return 0;
}
