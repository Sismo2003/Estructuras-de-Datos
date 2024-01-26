//
// Created by Alexis Ortiz ceceña on 22/01/24.
//

#ifndef ESTRUCTURAS_DE_DATOS_AUTOMOVILE_H
#define ESTRUCTURAS_DE_DATOS_AUTOMOVILE_H


class automovile {
    private:
        string year;
        string linces_Plate;
        string model;
        string make;
        string state;
    public:
        string getYear(){
            return year;
        };
        void setYear(){
            cout<<"Ingrese el year de su vehiculo: ";
            cin>>year;
        };
        string getLinces_Plate(){
            return linces_Plate;
        };
        void setLinces_Plate(){
            cout<<"Ingrese las placa de su vehiculo: ";
            cin>>linces_Plate;
        };
        string getModel(){
            return  model;
        };
        void setModel(){
            cout<<"Ingrese el modelo de su vehiculo: ";
            cin>>model;
        };
        string getmake(){
            return make;
        };
        void setMake(){
            cout<<"Ingrese el fabricante de su vehiculo: ";
            cin>>make;
        };
        string getState(){
            return state;
        };
        void setState(){
            cout<<"Ingrese el estado donde su vehiculo opera: ";
            cin>>state;
        };
};


#endif //ESTRUCTURAS_DE_DATOS_AUTOMOVILE_H
