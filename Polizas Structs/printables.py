# Ingreso de información inicial
print("------BIENVENIDO A NUESTRA COMPRESIVA EMPRESA DE ASEGURADORAS------")
print("¿Qué servicios le interesan hoy? ")
print("Opciones: ")
print("1. Salud")
print("2. Hogar")
print("3. Automóvil")
print("4. Empresarial")
print("5. Volver")
opcion_servicio = input("Ingrese el número de la opción deseada: ")

if opcion_servicio == '5':
    print("Volviendo al menú principal...")
else:
    # Ingreso de detalles de la póliza
    print("\nIngrese la cobertura requerida: ")
    cobertura = input()
    print("Ingrese el plazo de vigencia: ")
    vigencia = input()
    print("Ingrese el costo estimado: ")
    costo = input()
    print("Ingrese la prima mensual: ")
    prima = input()
    print("Ingrese el nombre del asegurado: ")
    nombre = input()
    print("Ingrese la edad del asegurado: ")
    edad = input()
    print("Ingrese las alergias del asegurado: ")
    alergias = input()
    print("Ingrese la altura del asegurado: ")
    altura = input()
    print("Ingrese las enfermedades cardíacas del asegurado: ")
    cardiopatias = input()
    print("Ingrese el tipo de diabetes del asegurado: ")
    tipo_diabetes = input()
    print("Ingrese los ingresos del asegurado: ")
    ingresos = input()
    print("Ingrese el peso del asegurado: ")
    peso = input()
    print("Ingrese el tipo de sangre del asegurado: ")
    tipo_sangre = input()
    print("Ingrese la suma asegurada: ")
    suma_asegurada = input()
    print("Ingrese la tasa de mortalidad: ")
    tasa_mortalidad = input()

    print(f"\nSu número de póliza es: 1 \n")

    # Menú de operaciones
    while True:
        print("------GRACIAS POR ELEGIR NUESTROS SERVICIOS DE ASEGURANZA------")
        print("¿Qué desea realizar hoy? ")
        print("Opciones: ")
        print("1. Agregar")
        print("2. Eliminar")
        print("3. Buscar")
        print("4. Editar")
        print("5. Ordenar")
        print("6. Mostrar un dato")
        print("7. Mostrar todo")
        print("8. Salir")

        opcion_menu = input("Ingrese el número de la opción deseada: ")

        if opcion_menu == '8':
            print("Cerrando programa...")
            print("Agradecemos su preferencia :)")
            break

        elif opcion_menu == '7':
            folio_consulta = input("Ingrese el número de póliza a consultar: ")

            if folio_consulta == '1':
                print("\nSu póliza corresponde a Servicio de Vida\n")
                print("La cobertura es:", cobertura, "\nLa vigencia es:", vigencia)
                print("\nEl costo es:", costo, "\nLa prima es:", prima)
                print("\nEl nombre es:", nombre, "\nLa edad es:", edad)
                print("\nLas alergias son:", alergias, "\nLa altura es:", altura)
                print("\nLas enfermedades cardíacas son:", cardiopatias)
                print("\nTipo de Diabetes:", tipo_diabetes, "\nIngresos:", ingresos)
                print("\nPeso:", peso, "\nTipo de sangre:", tipo_sangre)
                print("\nSuma asegurada:", suma_asegurada, "\nTasa de mortalidad:", tasa_mortalidad)
            else:
                print("\nLo lamentamos, esta póliza ha sido eliminada o no existe :(\n")

        else:
            print("\nOperación no válida. Intente nuevamente.\n")
